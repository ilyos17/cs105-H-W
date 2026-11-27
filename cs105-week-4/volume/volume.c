#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int n, char *a[])
{
    if (n != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    if (strcmp(a[1], a[2]) == 0)
    {
        printf("Use different input and output files.\n");
        return 1;
    }

    FILE *f = fopen(a[1], "rb");

    if (f == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *g = fopen(a[2], "wb");

    if (g == NULL)
    {
        printf("Could not open output file.\n");
        fclose(f);
        return 1;
    }

    double k = atof(a[3]);
    unsigned char h[44];
    int16_t s;
    int e = 0;

    if (fread(h, 1, sizeof h, f) != sizeof h ||
        fwrite(h, 1, sizeof h, g) != sizeof h)
    {
        e = 1;
    }

    while (e == 0 && fread(&s, sizeof s, 1, f) == 1)
    {
        s = (int16_t) (s * k);

        if (fwrite(&s, sizeof s, 1, g) != 1)
        {
            e = 1;
        }
    }

    if (ferror(f))
    {
        e = 1;
    }

    fclose(f);

    if (fclose(g) != 0)
    {
        e = 1;
    }

    if (e == 1)
    {
        printf("Could not process the WAV file.\n");
    }

    return e;
}
