#include <stdio.h>

void read_file(FILE *f)
{
    int temp = 0;
    while (fscanf(f, "%d", &temp) > 0)
    {

        printf("%d ", temp);
    }
}

void write_file(FILE *f)
{
    int temp = 0;
    int a = 2;
    switch (a)
    {
        case 3:
        {
            int b;
        }
        /* code */
        break;

        default:
            break;
    }
    for (int i = 0; i < 100; i++)
    {
        temp = 2 * i + 1;
        int check = fprintf(f, "%d ", temp);
        if (check < 0)
        {
            printf("\nError writing file");
            break;
        }
    }
}
int main()
{
    FILE *file = fopen("file.txt", "w+");
    if (file == NULL)
    {
        printf("\nOpen file failed");
        return -1;
    }
    write_file(file);
    rewind(file);
    read_file(file);
    fclose(file);

    return 0;
}