#include <stdio.h>

int main() {
    unsigned int i = 5;
    unsigned int j = 10;
    float k = 3.14;
    
    printf("%d %d\n", i); // prints i then a meaningless integer

    printf("%d\n", i, j); // wont show j

    printf("%f %d\n", i, k); // seems like the compiler can figure this one

    return 0;
}
