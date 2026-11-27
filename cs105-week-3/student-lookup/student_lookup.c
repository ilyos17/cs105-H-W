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
        {101, "Amina", "Computer Science"},
        {102, "Farid", "Mathematics"},
        {103, "Madina", "Economics"},
        {104, "Rustam", "Design"},
        {105, "Zebo", "Computer Science"}
    };

    int n = sizeof a / sizeof a[0];
    int k;

    if (scanf("%d", &k) != 1)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i].id == k)
        {
            printf("Name: %s\n", a[i].name);
            printf("Major: %s\n", a[i].major);
            return 0;
        }
    }

    printf("Student not found.\n");

    return 0;
}
