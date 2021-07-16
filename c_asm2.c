#include <stdio.h>

void pass()
{
    void *rbp_addr = 0;
    __asm__ __volatile__(
        "movq %%rbp, %0"
        : "=r"(rbp_addr));
    void *main_rbp_addr = (void *)(*(long *)(rbp_addr));
    int *x_addr = main_rbp_addr - 4;
    *x_addr = 456;
}

int main()
{
    int x = 123;
    printf("x = %d\n", x);
    pass();
    printf("x = %d\n", x);
}