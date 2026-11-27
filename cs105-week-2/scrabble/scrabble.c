#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int p[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
    };
    int s[2] = {0, 0};

    for (int i = 0; i < 2; i++)
    {
        char a;

        if (scanf(" %c", &a) != 1)
        {
            return 1;
        }

        int c = (unsigned char) a;

        // Read the rest of the word until a space, newline, or EOF.
        do
        {
            c = toupper(c);

            if (c >= 'A' && c <= 'Z')
            {
                s[i] += p[c - 'A'];
            }

            c = getchar();
        }
        while (c != EOF && !isspace(c));
    }

    if (s[0] > s[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (s[0] < s[1])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
