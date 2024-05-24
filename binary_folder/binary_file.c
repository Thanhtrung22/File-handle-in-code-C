#include <stdio.h>
#include <stdlib.h>
void write_file(FILE *f, int *a, size_t size)
{
    if(fwrite(a, sizeof(int), size, f) != size)
    {
        printf("\nwrite_file failed");
    }
    else
    {
        printf("\nwrite_file succeeded");
    }
}

void read_file(FILE *f, int *a, size_t size)
{
    if(fread(a, sizeof(int), size, f) != size)
    {
        printf("\nread_file failed");
    }
    else
    {
        printf("\nread_file succeeded\n");
    }
}

int main()
{
    int a[] = { 0, 1, 2, 3, 4, 5};
    int *b = NULL;
    size_t size = sizeof(a) / sizeof(a[0]);
    FILE *file = NULL;
    file = fopen("array.dat", "wb");
    if(file != NULL)
    {
        write_file(file, a, size);
        b = (int*) malloc(size * sizeof(int));
    }
    else
    {
        printf("\nOpen file failed");
    }
    fclose(file);
    file = fopen("array.dat", "rb");
    if(file == NULL)
    {
        printf("Open file failed");
        return -1;
    }
    read_file(file, b, size);
    for(int i = 0; i < size; i++)
    {
            printf("b[%d] = %d\n", i, b[i]);
    }
    free(b);
    fclose(file);
    
    

    return 0;
}