#include <stdio.h>

int main() {
    int j = 2;
    for (int i = 0; i < 3; i++) {
        if (i == j)
            continue;
        if (i + j >= 3)
            break;
        printf("%d %d ", i, j);
    }
    return 0;
}