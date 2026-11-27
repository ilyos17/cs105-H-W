#include <stdio.h>
#include <string.h>

int main(int n, char *a[])
{
    if (n != 2 || a[1][0] == '\0')
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int k = 0;

    for (int i = 0; a[1][i] != '\0'; i++)
    {
        char c = a[1][i];

        if (c < '0' || c > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        // Only the remainder matters when rotating 26 letters.
        k = (k * 10 + (c - '0')) % 26;
    }

    char s[256];

    if (fgets(s, sizeof s, stdin) == NULL)
    {
        return 1;
    }

    s[strcspn(s, "\n")] = '\0';

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        if (c >= 'A' && c <= 'Z')
        {
            s[i] = 'A' + (c - 'A' + k) % 26;
        }
        else if (c >= 'a' && c <= 'z')
        {
            s[i] = 'a' + (c - 'a' + k) % 26;
        }
    }

    printf("ciphertext: %s\n", s);

    return 0;
}
