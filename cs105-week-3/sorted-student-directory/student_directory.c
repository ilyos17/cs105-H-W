#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    char major[50];
} Student;

int main(void)
{
    Student a[] = {
        {108, "Kamol", "Physics"},
        {103, "Madina", "Economics"},
        {105, "Zebo", "Computer Science"},
        {101, "Amina", "Computer Science"},
        {107, "Nilufar", "Biology"},
        {102, "Farid", "Mathematics"},
        {106, "Rustam", "Design"},
        {104, "Daler", "Engineering"}
    };

    int n = sizeof a / sizeof a[0];

    for (int i = 0; i < n - 1; i++)
    {
        int m = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j].id < a[m].id)
            {
                m = j;
            }
        }

        Student t = a[i];
        a[i] = a[m];
        a[m] = t;
    }

    printf("Sorted directory:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d - %s\n", a[i].id, a[i].name);
    }

    printf("\n");

    int k;

    if (scanf("%d", &k) != 1)
    {
        return 1;
    }

    int l = 0;
    int r = n - 1;
    int c = 0;

    while (l <= r)
    {
        int m = (l + r) / 2;
        c++;

        if (a[m].id == k)
        {
            printf("Name: %s\n", a[m].name);
            printf("Major: %s\n", a[m].major);
            printf("Comparisons: %d\n", c);
            return 0;
        }

        if (a[m].id < k)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    printf("Student not found.\n");
    printf("Comparisons: %d\n", c);

    return 0;
}
