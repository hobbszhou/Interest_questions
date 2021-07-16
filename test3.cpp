#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void pass()
{

    int tmp_val = 0;
    for (int i = 0; i < 20; ++i)
    {
        printf("22222===%d = %p, %d\n", i, ((&tmp_val) + i), *((&tmp_val) + i));
        if (*((&tmp_val) + i) == 123)
        {
            *((&tmp_val) + i) = 456;
        }
    }
}

int main()
{

    int x = 123;

    printf("1111===%d,   %p\n", x, &x);
    pass();
    printf("输出: %d\n", x);

    return 0;
}