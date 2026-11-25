#include <stdio.h>

int main(void)
{
    unsigned long long n;

    printf("Number: ");
    if (scanf("%llu", &n) != 1)
    {
        printf("INVALID\n");
        return 0;
    }

    int s = 0;
    int l = 0;
    int f = 0;

    while (n > 0)
    {
        if (n >= 10 && n <= 99)
            f = n;

        int d = n % 10;

        if (l % 2 == 1)
        {
            d *= 2;
            d = d / 10 + d % 10;
        }

        s += d;
        l++;
        n /= 10;
    }

    if (s % 10 != 0)
        printf("INVALID\n");
    else if (l == 15 && (f == 34 || f == 37))
        printf("AMEX\n");
    else if (l == 16 && f >= 51 && f <= 55)
        printf("MASTERCARD\n");
    else if ((l == 13 || l == 16) && f / 10 == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");

    return 0;
}