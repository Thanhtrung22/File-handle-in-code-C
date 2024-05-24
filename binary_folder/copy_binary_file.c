#include <stdio.h>
#define INPUT_FILE "100_so_nguyen.dat"
#define OUTPUT_FILE "file_copy.dat"
#define SO_LUONG 100
void copy_file(FILE *p1, FILE *p2)
{
    int temp = 0;
    while(!feof(p1))
    {
        if(fread(&temp, sizeof(int), 1, p1) > 0)
        {
            fwrite(&temp, sizeof(int), 1, p2);
        }
        
    }
    printf("\nCopied file successfully\n");
}

int main()
{
    FILE *file1, *file2;
    file1 = fopen(INPUT_FILE, "wb");
    if(file1 == NULL)
    {
        printf("Error opening input file\n");
        return -1;
    }
    for(int i = 1; i <= 100; i++)
    {
        if(fwrite(&i, sizeof(int), 1, file1) < 1)
        {
            printf("\nError writing file1\n");
            break;
        }
    }
    fclose(file1);

    file2 = fopen(OUTPUT_FILE,"wb");
    if(file2 == NULL)
    {
        printf("Error opening output file\n");
        return -1;
    }
    file1 = fopen(INPUT_FILE, "rb");
    if(file1 == NULL)
    {
        printf("\nError open file input\n");
        return -1;
    }
    copy_file(file1, file2);
    fclose(file1);
    fclose(file2);
    /*Add 100 intergers to file1*/
    
}