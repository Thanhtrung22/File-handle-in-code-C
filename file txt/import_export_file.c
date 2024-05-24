#include <stdio.h>
#include  <string.h>
#include <stdbool.h>
#define MAX 1000

char input_file[1024];
char output_file[1024];

typedef struct
{
    char name[50];
    char id[20];
    float point;
}student;

void import_file(FILE *file, student *list, unsigned *quantity);
void export_file(FILE *file, student *list, unsigned quantity);
void display(student *list, unsigned quantity);
bool check_empty_file(FILE *file);
int main()
{
    student list[MAX];
    FILE *file = NULL;
    printf("Nhap ten file input: ");
    fgets(input_file, sizeof(input_file), stdin);
    if(input_file[strlen(input_file) - 1] == '\n')
    {
        input_file[strlen(input_file) - 1] = '\0';
    }
    file = fopen(input_file, "r");
    if(file == NULL)
    {
        printf("\nError opening");
        return -1;
    }
    unsigned int i = 0;
    while(fscanf(file, "%s,%s", list[i].id, list[i].name ) > 0)
    {
        
        printf("\nNhap diem cho sinh vien thu %u: ", i + 1);
        scanf("%f", &list[i].point);
        i++;
    }
    for(unsigned j = 0; j < i; j++)
    {
        printf("\nten: %s  id: %s   point: %.2f", list[j].id, list[j].name, list[j].point);
    }
   
}

bool check_empty_file(FILE *file)
{
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    if(size > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void import_file(FILE *file, student *list, unsigned *quantity)
{
    if(!check_empty_file(file))
    {
        printf("file is empty\n");
        return;
    }
    char buffer[1024];
    char *token = NULL;
    unsigned i = 0;
    while(fgets(buffer, sizeof(buffer), file) != NULL && *quantity < MAX)
    {
        printf("Nhap thong tin cho sinh vien thu %u: ", i + 1);
        token = strtok(buffer, ",");
        if(token != NULL)
        {
            strcpy(list[i].id, token);
            
        }
        token = strtok(NULL, ",");
        if(token != NULL)
        {
            strcpy(list[i].name, token);
        }
        printf("\nNhap diem cua sinh vien: ");
        scanf("%f", &list[i].point);
        i++;
    }
    *quantity = i;
    token = NULL;
}

void export_file(FILE *file, student *list, unsigned quantity)
{
    if(quantity == 0)
    {
        printf("\nKhong co sinh vien nao");
    }
    else
    {
        fprintf(file, "\t\t\tBANG DIEM SINH VIEN MON TIN DAI CUONG\n");
        fprintf(file, "___________________________________________________________________________________________\n\n");
        fprintf(file, "%-5s %-20s %-10s %-8s\n", "STT", "Ho Ten", "Ma so", "Diem");
        fprintf(file,"------------------------------------------------------------------------------------------------\n");
        for(unsigned i = 0; i < quantity; i++)
        {
            fprintf(file, "%-5u %-20s %-10s %-8.2f\n", i + 1, list[i].name, list[i].id, list[i].point);
        }
        printf("\nWrite output successfully");
    }
}
void display(student *list, unsigned quantity)
{
    printf("%-5s %-20s %-10s %-8s\n", "STT", "Ho Ten", "Ma so", "Diem");
    printf("------------------------------------------------------------------------------------------------\n");
    for(unsigned i = 0; i < quantity; i++)
    {
        printf("%-5d %-20s %-10s %-8.2f\n", i + 1, list[i].name, list[i].id, list[i].point);
    }
}