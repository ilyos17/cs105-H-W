#include <stdio.h>

typedef struct
{
    char name[50];
    int score;
} Student;

int main(void)
{
    Student a[10];
    int n;

    do
    {
        if (scanf("%d", &n) != 1)
        {
            return 1;
        }
    }
    while (n < 3 || n > 10);

    int s = 0;

    for (int i = 0; i < n; i++)
    {
        if (scanf("%49s", a[i].name) != 1)
        {
            return 1;
        }

        do
        {
            if (scanf("%d", &a[i].score) != 1)
            {
                return 1;
            }
        }
        while (a[i].score < 0 || a[i].score > 100);

        s += a[i].score;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int m = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j].score > a[m].score)
            {
                m = j;
            }
        }

        Student t = a[i];
        a[i] = a[m];
        a[m] = t;
    }

    printf("Average: %.2f\n", (double) s / n);
    printf("Top student: %s (%d)\n", a[0].name, a[0].score);
    printf("\nRanking:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d. %s - %d\n", i + 1, a[i].name, a[i].score);
    }

    return 0;
}
