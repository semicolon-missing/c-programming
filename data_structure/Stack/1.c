#include <stdio.h>
void f(int n)
{
    if (n <= 1)
    {
        printf("%d", n);
    }
    else
    {
        f(n / 3);
        printf("%d", n % 3);
    }
}
int main()
{
    f(1743);
    return 0;
}