#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <iomanip>

using namespace std;

struct Production
{
    string left;
    string right;

    Production(string l, string r) : left(l), right(r) {}
};

struct Item
{
    int prod_num;
    int dot_pos;
    string lookahead;

    Item(int p, int d, string la) : prod_num(p), dot_pos(d), lookahead(la) {}

    bool operator<(const Item &other) const
    {
        if (prod_num != other.prod_num)
            return prod_num < other.prod_num;
        if (dot_pos != other.dot_pos)
            return dot_pos < other.dot_pos;
        return lookahead < other.lookahead;
    }

    bool operator==(const Item &other) const
    {
        return prod_num == other.prod_num && dot_pos == other.dot_pos && lookahead == other.lookahead;
    }
};

struct State
{
    set<Item> items;
    int id;

    State(int i) : id(i) {}
};

class CLRParser
{
private:
    vector<Production> productions;
    vector<State> states;
    map<pair<int, string>, pair<char, int>> action_table; // (state, terminal) -> (action, next_state/production)
    map<pair<int, string>, int> goto_table;               // (state, non-terminal) -> next_state
    set<string> terminals;
    set<string> non_terminals;

public:
    CLRParser()
    {
        // Grammar: E -> E + T | T, T -> T * F | F, F -> ( E ) | id
        // Note: I've corrected the grammar - multiplication should have higher precedence
        productions.push_back(Production("E'", "E"));  // 0: Augmented start production
        productions.push_back(Production("E", "E+T")); // 1: E -> E + T
        productions.push_back(Production("E", "T"));   // 2: E -> T
        productions.push_back(Production("T", "T*F")); // 3: T -> T * F
        productions.push_back(Production("T", "F"));   // 4: T -> F
        productions.push_back(Production("F", "(E)")); // 5: F -> ( E )
        productions.push_back(Production("F", "id"));  // 6: F -> id

        terminals = {"+", "*", "(", ")", "id", "$"};
        non_terminals = {"E'", "E", "T", "F"};
    }

    set<string> first(const string &symbol)
    {
        set<string> first_set;

        if (terminals.count(symbol))
        {
            first_set.insert(symbol);
            return first_set;
        }

        for (const auto &prod : productions)
        {
            if (prod.left == symbol)
            {
                if (prod.right.empty() || prod.right == "ε")
                {
                    first_set.insert("ε");
                }
                else
                {
                    // For simplicity, assume single character symbols
                    string first_symbol = string(1, prod.right[0]);
                    if (prod.right.substr(0, 2) == "id")
                        first_symbol = "id";

                    if (terminals.count(first_symbol))
                    {
                        first_set.insert(first_symbol);
                    }
                }
            }
        }

        return first_set;
    }

    set<Item> closure(const set<Item> &items)
    {
        set<Item> closure_set = items;
        bool changed = true;

        while (changed)
        {
            changed = false;
            set<Item> new_items = closure_set;

            for (const auto &item : closure_set)
            {
                const Production &prod = productions[item.prod_num];

                if (item.dot_pos < prod.right.length())
                {
                    string next_symbol;
                    if (prod.right.substr(item.dot_pos, 2) == "id")
                    {
                        next_symbol = "id";
                    }
                    else
                    {
                        next_symbol = string(1, prod.right[item.dot_pos]);
                    }

                    if (non_terminals.count(next_symbol))
                    {
                        // Calculate FIRST of beta alpha where beta is symbols after next_symbol
                        string beta = "";
                        int pos = item.dot_pos + (next_symbol == "id" ? 2 : 1);
                        if (pos < prod.right.length())
                        {
                            beta = prod.right.substr(pos);
                        }

                        set<string> first_beta_alpha;
                        if (beta.empty())
                        {
                            first_beta_alpha.insert(item.lookahead);
                        }
                        else
                        {
                            // Simplified: just use the lookahead for now
                            first_beta_alpha.insert(item.lookahead);
                        }

                        for (int i = 0; i < productions.size(); i++)
                        {
                            if (productions[i].left == next_symbol)
                            {
                                for (const string &la : first_beta_alpha)
                                {
                                    Item new_item(i, 0, la);
                                    if (new_items.find(new_item) == new_items.end())
                                    {
                                        new_items.insert(new_item);
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            closure_set = new_items;
        }

        return closure_set;
    }

    set<Item> goto_state(const set<Item> &items, const string &symbol)
    {
        set<Item> goto_items;

        for (const auto &item : items)
        {
            const Production &prod = productions[item.prod_num];

            if (item.dot_pos < prod.right.length())
            {
                string next_symbol;
                int advance = 1;

                if (prod.right.substr(item.dot_pos, 2) == "id")
                {
                    next_symbol = "id";
                    advance = 2;
                }
                else
                {
                    next_symbol = string(1, prod.right[item.dot_pos]);
                }

                if (next_symbol == symbol)
                {
                    Item new_item(item.prod_num, item.dot_pos + advance, item.lookahead);
                    goto_items.insert(new_item);
                }
            }
        }

        return closure(goto_items);
    }

    void construct_states()
    {
        // Initial state
        set<Item> initial_items;
        initial_items.insert(Item(0, 0, "$"));
        states.push_back(State(0));
        states[0].items = closure(initial_items);

        vector<set<Item>> state_items;
        state_items.push_back(states[0].items);

        bool changed = true;
        while (changed)
        {
            changed = false;
            int current_size = states.size();

            for (int i = 0; i < current_size; i++)
            {
                set<string> symbols_to_process;

                // Collect all symbols that can be shifted
                for (const auto &item : states[i].items)
                {
                    const Production &prod = productions[item.prod_num];

                    if (item.dot_pos < prod.right.length())
                    {
                        string next_symbol;
                        if (prod.right.substr(item.dot_pos, 2) == "id")
                        {
                            next_symbol = "id";
                        }
                        else
                        {
                            next_symbol = string(1, prod.right[item.dot_pos]);
                        }
                        symbols_to_process.insert(next_symbol);
                    }
                }

                for (const string &symbol : symbols_to_process)
                {
                    set<Item> new_state_items = goto_state(states[i].items, symbol);

                    if (!new_state_items.empty())
                    {
                        // Check if this state already exists
                        int existing_state = -1;
                        for (int j = 0; j < state_items.size(); j++)
                        {
                            if (state_items[j] == new_state_items)
                            {
                                existing_state = j;
                                break;
                            }
                        }

                        if (existing_state == -1)
                        {
                            // New state
                            states.push_back(State(states.size()));
                            states.back().items = new_state_items;
                            state_items.push_back(new_state_items);
                            existing_state = states.size() - 1;
                            changed = true;
                        }

                        // Add to action/goto table
                        if (terminals.count(symbol))
                        {
                            action_table[{i, symbol}] = {'s', existing_state};
                        }
                        else
                        {
                            goto_table[{i, symbol}] = existing_state;
                        }
                    }
                }

                // Add reduce actions
                for (const auto &item : states[i].items)
                {
                    const Production &prod = productions[item.prod_num];

                    if (item.dot_pos >= prod.right.length())
                    {
                        if (item.prod_num == 0 && item.lookahead == "$")
                        {
                            action_table[{i, "$"}] = {'a', 0}; // Accept
                        }
                        else
                        {
                            action_table[{i, item.lookahead}] = {'r', item.prod_num};
                        }
                    }
                }
            }
        }
    }

    void print_states()
    {
        cout << "\nCLR States:\n";
        cout << "===========\n";

        for (const auto &state : states)
        {
            cout << "State " << state.id << ":\n";
            for (const auto &item : state.items)
            {
                const Production &prod = productions[item.prod_num];
                cout << "  " << prod.left << " -> ";

                for (int i = 0; i < prod.right.length();)
                {
                    if (i == item.dot_pos)
                        cout << ".";

                    if (i < prod.right.length())
                    {
                        if (prod.right.substr(i, 2) == "id")
                        {
                            cout << "id";
                            i += 2;
                        }
                        else
                        {
                            cout << prod.right[i];
                            i++;
                        }
                    }
                }
                if (item.dot_pos >= prod.right.length())
                    cout << ".";
                cout << ", " << item.lookahead << "\n";
            }
            cout << "\n";
        }
    }

    void print_parsing_table()
    {
        cout << "\nCLR Parsing Table:\n";
        cout << "==================\n";

        // Print header
        cout << setw(6) << "State";
        for (const string &term : terminals)
        {
            cout << setw(8) << term;
        }
        for (const string &non_term : non_terminals)
        {
            if (non_term != "E'")
            {
                cout << setw(8) << non_term;
            }
        }
        cout << "\n";

        // Print table rows
        for (int i = 0; i < states.size(); i++)
        {
            cout << setw(6) << i;

            // Action table
            for (const string &term : terminals)
            {
                auto it = action_table.find({i, term});
                if (it != action_table.end())
                {
                    cout << setw(8) << (string(1, it->second.first) + to_string(it->second.second));
                }
                else
                {
                    cout << setw(8) << "";
                }
            }

            // Goto table
            for (const string &non_term : non_terminals)
            {
                if (non_term != "E'")
                {
                    auto it = goto_table.find({i, non_term});
                    if (it != goto_table.end())
                    {
                        cout << setw(8) << it->second;
                    }
                    else
                    {
                        cout << setw(8) << "";
                    }
                }
            }
            cout << "\n";
        }
    }

    vector<string> tokenize(const string &input)
    {
        vector<string> tokens;
        string current_token = "";

        for (char c : input)
        {
            if (c == ' ')
                continue;

            if (c == '+' || c == '(' || c == ')')
            {
                if (!current_token.empty())
                {
                    tokens.push_back(current_token);
                    current_token = "";
                }
                tokens.push_back(string(1, c));
            }
            else
            {
                current_token += c;
            }
        }

        if (!current_token.empty())
        {
            tokens.push_back("id"); // Replace actual identifier with "id"
        }

        tokens.push_back("$");
        return tokens;
    }

    bool parse(const string &input)
    {
        vector<string> tokens = tokenize(input);

        cout << "\nParsing string: " << input << "\n";
        cout << "Tokens: ";
        for (const string &token : tokens)
        {
            cout << token << " ";
        }
        cout << "\n\n";

        stack<int> state_stack;
        stack<string> symbol_stack;

        state_stack.push(0);
        symbol_stack.push("$");

        int token_index = 0;

        cout << setw(10) << "Step" << setw(15) << "Stack" << setw(15) << "Input" << setw(15) << "Action\n";
        cout << string(55, '-') << "\n";

        int step = 1;

        while (true)
        {
            int current_state = state_stack.top();
            string current_token = tokens[token_index];

            // Print current step
            cout << setw(10) << step++;

            // Print stack
            stack<string> temp_symbol = symbol_stack;
            string stack_str = "";
            while (!temp_symbol.empty())
            {
                stack_str = temp_symbol.top() + stack_str;
                temp_symbol.pop();
            }
            cout << setw(15) << stack_str;

            // Print remaining input
            string input_str = "";
            for (int i = token_index; i < tokens.size(); i++)
            {
                input_str += tokens[i];
            }
            cout << setw(15) << input_str;

            auto action_it = action_table.find({current_state, current_token});

            if (action_it == action_table.end())
            {
                cout << setw(15) << "ERROR\n";
                return false;
            }

            char action = action_it->second.first;
            int value = action_it->second.second;

            if (action == 's')
            {
                cout << setw(15) << ("shift " + to_string(value)) << "\n";
                state_stack.push(value);
                symbol_stack.push(current_token);
                token_index++;
            }
            else if (action == 'r')
            {
                const Production &prod = productions[value];
                cout << setw(15) << ("reduce " + to_string(value)) << "\n";

                // Pop symbols and states
                int pop_count = 0;
                for (char c : prod.right)
                {
                    if (c == 'i')
                        pop_count++; // for "id", we count it as 1 pop
                }
                if (prod.right.find("id") != string::npos)
                {
                    pop_count = 1; // "id" counts as 1 symbol
                }
                else
                {
                    pop_count = prod.right.length();
                }

                for (int i = 0; i < pop_count; i++)
                {
                    state_stack.pop();
                    symbol_stack.pop();
                }

                symbol_stack.push(prod.left);
                int goto_state = goto_table[{state_stack.top(), prod.left}];
                state_stack.push(goto_state);
            }
            else if (action == 'a')
            {
                cout << setw(15) << "accept\n";
                return true;
            }
        }

        return false;
    }

    void run()
    {
        cout << "CLR Parser for Grammar:\n";
        cout << "E' -> E\n";
        cout << "E -> E + T | T\n";
        cout << "T -> T * F | F\n";
        cout << "F -> ( E ) | id\n";

        construct_states();
        print_states();
        print_parsing_table();

        string input = "(id*id)+(id*id)+id";
        bool result = parse(input);

        cout << "\nParsing result: " << (result ? "ACCEPTED" : "REJECTED") << "\n";
    }
};

int main()
{
    CLRParser parser;
    parser.run();
    return 0;
}