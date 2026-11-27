#include <stdio.h>

int main(int n, char *a[])
{
    if (n != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *f = fopen(a[1], "rb");

    if (f == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *g = NULL;
    unsigned char b[512];
    char s[16];
    int k = 0;
    int e = 0;

    while (fread(b, 1, sizeof b, f) == sizeof b)
    {
        // A JPEG starts at the beginning of a block.
        if (b[0] == 0xff && b[1] == 0xd8 && b[2] == 0xff &&
            b[3] >= 0xe0 && b[3] <= 0xef)
        {
            if (g != NULL)
            {
                e = fclose(g) != 0;
                g = NULL;

                if (e == 1)
                {
                    break;
                }
            }

            snprintf(s, sizeof s, "%03d.jpg", k);
            g = fopen(s, "wb");

            if (g == NULL)
            {
                e = 1;
                break;
            }

            k++;
        }

        if (g != NULL && fwrite(b, 1, sizeof b, g) != sizeof b)
        {
            e = 1;
            break;
        }
    }

    if (ferror(f))
    {
        e = 1;
    }

    if (g != NULL && fclose(g) != 0)
    {
        e = 1;
    }

    fclose(f);

    if (e == 1)
    {
        printf("Could not recover the JPEG files.\n");
    }

    return e;
}
