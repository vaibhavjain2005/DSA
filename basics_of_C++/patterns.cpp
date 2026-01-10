#include<iostream>
#include<stdlib.h>
using namespace std;
//size_t is unsigned long long int
void line_gap(void){
    cout<<"\n---------------------------------\n\n";
}
void pattern_1(size_t n){
    /* ****
       ****
       **** 
    */
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void pattern_2(size_t n){
    /*right angle triangle
     *
     **
     ***/
    for(size_t i{};i<n;i++){
        for(size_t j{};j<=i;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}
void pattern_3(size_t n){
    /*
    1
    12
    123
    1234
    */
    for(size_t i{};i<n;i++){
        for(size_t j{};j<=i;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}
void pattern_4(size_t n){
    /*1
      22
      333
      4444    
    */
    for(size_t i{};i<n;i++){
        for(size_t j{};j<=i;j++){
              cout<<i+1;
        }
        cout<<endl;
    }
}

void patter_5(size_t n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<=n-i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern_6(size_t n){
    for(size_t i{};i<n;i++){
        for(size_t j{};j<=n-i-1;j++){
            cout<<j+1;
        }
        cout<<endl;
    }
}
void pattern_7(size_t n){
    for(size_t i{};i<n ;i++){
        for(size_t j{};j<n-i+1;j++){
            cout<<" ";
        }
        for(size_t k{};k<(2*i+1);k++){
            cout<<"*";
        }
        for(size_t l{};l<n-i+1;l++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void pattern_8(size_t n){
    for(size_t i=0;i<n;i++){
        for(size_t a=0;a<i;a++){
            cout<<" ";
        }
        for(int b=0;b<=(2*(n-i-1));b++){
            cout<<"*";
        }
        for(int c=0;c<i;c++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void pattern_9(size_t n){
    for(size_t i=0;i<n;i++){
        for(size_t a=0;a<n-i-1;a++){
            cout<<" ";
        }
        for(size_t b=0;b<(2*i+1);b++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(size_t j=0;j<n;j++){
        for(size_t a=0;a<j;a++){
            cout<<" ";
        }
        for(size_t b=0;b<(2*(n-j)-1);b++ ){
            cout<<"*";
        }
        cout<<endl;
    }
    
}
void pattern_10(size_t n){
    for(size_t i=1;i<=n;i++){
        for(size_t j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;

    }
    for(size_t i=1;i<n;i++){
        for(size_t j=1;j<=n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern_11(size_t n){
    bool a=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(a){
                cout<<1<<" ";
                a=!a;
            }
            else{
                cout<<0<<" ";
                a=!a;
            }
        }
        cout<<endl;
    }
}
void pattern_12(size_t n){
    for(size_t i=1;i<=n;i++){
        for(size_t j=1;j<=i;j++){
            cout<<j;
        }
        for(size_t j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        for(size_t k=i;k>=1;k--){
            cout<<k;
        }
        cout<<endl;
    }
}
void pattern_13(size_t n){
    size_t a=1;
    for(size_t i=1;i<=n;i++){
        for(size_t j=1;j<=i;j++){
            cout<<a++<<" ";
        }
        cout<<endl;
    }
}
void pattern_14(size_t n){
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<=i;j++){
            cout<<static_cast<char>(65+j);
        }
        cout<<endl;
    }
}
//The issue is with the loop condition in pattern_15: the comparison between char and size_t is incorrect; you should compare char a to 'A' + (n-i-1) instead.
void pattern_15(size_t n){
    for(size_t i=0;i<n;i++){
        for(char a{'A'};a<='A'+(n-i-1);a++){
            cout<<a;
        }
        cout<<endl;
    }
}
void pattern_16(size_t n){
    size_t a=65;
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<=i;j++){
            cout<<(static_cast<char>(a+i));
        }
        cout<<endl;
    }
}
void pattern_17(size_t n){
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(char a{'A'};a<='A'+i;a++){
            cout<<a;
        }
        for(char a{'A'};a<'A'+i;a++){
            cout<<a;
        }
        cout<<endl;
    }
}
void pattern_18(size_t n){
    for(size_t i=0;i<n;i++){
        for(char s='E'-i;s<='E';s++){
            cout<<s;
        }
        cout<<endl;
    }
}
void pattern_19(size_t n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int k=0;k<(2*i);k++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        for(int k=0;k<2*(n-i-1);k++){
            cout<<" ";
        }
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern_20(size_t n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        for(int k=0;k<2*(n-i-1);k++){
            cout<<" ";
        }
        for(int l=0;l<i+1;l++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int k=0;k<2*i;k++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern_21(size_t n){
    for(int i=0;i<n;i++){
        cout<<"*";
    }
    cout<<endl;
    for(int j=0;j<n-2;j++){
        cout<<"*";
        for(int k=0;k<n-2;k++){
            cout<<" ";
        }
        cout<<"*";
        cout<<endl;
    }
    for(int l=0;l<n;l++){
        cout<<"*";
    }
}
void pattern_22(size_t n){
    
}
int main(){
    size_t n;
    cin>>n;
    pattern_1(n);
    line_gap();
    pattern_2(n);
    line_gap();
    pattern_3(n);
    line_gap();
    pattern_4(n);
    line_gap();
    patter_5(n);
    line_gap();
    pattern_6(n);
    line_gap();
    pattern_7(n);
    line_gap();
    pattern_8(n);
    line_gap();
    pattern_9(n);
    line_gap();
    pattern_10(n);
    line_gap();
    pattern_11(n);
    line_gap();
    pattern_12(n);
    line_gap();
    pattern_13(n);
    line_gap();
    pattern_14(n);
    line_gap();
    pattern_15(n);
    line_gap();
    pattern_16(n);
    line_gap();
    pattern_17(n);
    line_gap();
    pattern_18(n);
    line_gap();
    pattern_19(n);
    line_gap();
    pattern_20(n);
    line_gap();
    pattern_21(n);
    return 0;
}