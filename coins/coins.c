#include <stdio.h>

int main(void)
{
    int d;

    while (1)
    {
        printf("Change owed (dirams): ");

        d = -1;
        scanf("%d", &d);

        int i = getchar();
        while (i != '\n' && i != EOF)
        {
            if (i != ' ' && i != '\t')
                d = -1;

            i = getchar();
        }

        if (d >= 0 && d % 10 == 0)
            break;

        if (i == EOF)
            return 0;
    }

    int c = d / 500;
    d %= 500;

    c += d / 300;
    d %= 300;

    c += d / 100;
    d %= 100;

    c += d / 50;
    d %= 50;

    c += d / 20;
    d %= 20;

    c += d / 10;

    printf("%d\n", c);
}