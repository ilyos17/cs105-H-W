#include "helpers.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grayscale(int h, int w, RGBTRIPLE a[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            RGBTRIPLE p = a[i][j];
            int c = round((p.rgbtRed + p.rgbtGreen + p.rgbtBlue) / 3.0);

            a[i][j].rgbtRed = c;
            a[i][j].rgbtGreen = c;
            a[i][j].rgbtBlue = c;
        }
    }
}

void reflect(int h, int w, RGBTRIPLE a[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w / 2; j++)
        {
            int k = w - 1 - j;
            RGBTRIPLE p = a[i][j];
            a[i][j] = a[i][k];
            a[i][k] = p;
        }
    }
}

void blur(int h, int w, RGBTRIPLE a[h][w])
{
    RGBTRIPLE (*b)[w] = malloc(h * sizeof *b);

    if (b == NULL)
    {
        fprintf(stderr, "Could not allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    // Every average must use the original pixels.
    memcpy(b, a, h * sizeof *b);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int r = 0;
            int g = 0;
            int c = 0;
            int n = 0;

            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x >= 0 && x < h && y >= 0 && y < w)
                    {
                        r += b[x][y].rgbtRed;
                        g += b[x][y].rgbtGreen;
                        c += b[x][y].rgbtBlue;
                        n++;
                    }
                }
            }

            a[i][j].rgbtRed = round((double) r / n);
            a[i][j].rgbtGreen = round((double) g / n);
            a[i][j].rgbtBlue = round((double) c / n);
        }
    }

    free(b);
}

void sepia(int h, int w, RGBTRIPLE a[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int r = a[i][j].rgbtRed;
            int g = a[i][j].rgbtGreen;
            int b = a[i][j].rgbtBlue;

            int x = round(0.393 * r + 0.769 * g + 0.189 * b);
            int y = round(0.349 * r + 0.686 * g + 0.168 * b);
            int z = round(0.272 * r + 0.534 * g + 0.131 * b);

            if (x > 255)
            {
                x = 255;
            }

            if (y > 255)
            {
                y = 255;
            }

            if (z > 255)
            {
                z = 255;
            }

            a[i][j].rgbtRed = x;
            a[i][j].rgbtGreen = y;
            a[i][j].rgbtBlue = z;
        }
    }
}
