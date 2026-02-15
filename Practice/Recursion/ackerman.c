#include <stdio.h>

int ackerman(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }

    else if (n == 0)
    {
        return ackerman(m - 1, 1);
    }

    else
        return ackerman(m - 1, ackerman(m, n - 1));
}

int main()
{
    int m, n;
    printf("Enter the value of m and n respectively: \n");
    scanf("%d %d", &m, &n);
    printf("Ackerman(%d, %d) = %d\n", m, n, ackerman(m, n));

    return 0;
}