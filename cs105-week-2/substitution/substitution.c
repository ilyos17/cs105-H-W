#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int n, char *a[])
{
    if (n != 2 || strlen(a[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int b[26] = {0};
    char k[26];

    for (int i = 0; i < 26; i++)
    {
        int c = toupper((unsigned char) a[1][i]);

        if (c < 'A' || c > 'Z' || b[c - 'A'] == 1)
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        // Mark each letter so a repeated letter is rejected.
        b[c - 'A'] = 1;
        k[i] = c;
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
            s[i] = k[c - 'A'];
        }
        else if (c >= 'a' && c <= 'z')
        {
            s[i] = tolower(k[c - 'a']);
        }
    }

    printf("ciphertext: %s\n", s);

    return 0;
}
