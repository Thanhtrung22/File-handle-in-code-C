#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct
{
    char name[50];
    char id[20];
    float point;
} student;

void import_file(FILE *file, student *list, unsigned *quantity);
void export_file(FILE *file, student *list, unsigned quantity);
void display(student *list, unsigned quantity);
bool check_empty_file(FILE *file);
void menu();
int main()
{
    student list[MAX];
    unsigned quantity = 0;
    char input_file[1024];
    char output_file[1024];
    FILE *file_input = NULL, *file_output = NULL;
    char sel = '\0';
    while (1)
    {
        system("cls");
        menu();
        printf("\nNhap lua chon cua ban: ");
        sel = (char)getche();
        switch (sel)
        {
        case '1':
        {
            printf("\nNhap ten file input: ");
            // while(getchar() != '\n');
            fgets(input_file, sizeof(input_file), stdin);
            if (input_file[strlen(input_file) - 1] == '\n')
            {
                input_file[strlen(input_file) - 1] = '\0';
            }
            puts(input_file);
            file_input = fopen(input_file, "r");
            if (file_input == NULL)
            {
                printf("\nError: Could not open input file");
                return -1;
            }
            import_file(file_input, list, &quantity);

            fclose(file_input);
            break;
        }
        case '2':
        {
            printf("\nNhap ten file output can ghi ra: ");
            while (getchar() != '\n')
                ;
            fgets(output_file, sizeof(output_file), stdin);
            if (output_file[strlen(output_file) - 1] == '\n')
            {
                output_file[strlen(output_file) - 1] = '\0';
            }
            file_output = fopen(output_file, "w");
            if (file_output == NULL)
            {
                printf("\nError: Could not open output file");
                return -1;
            }
            export_file(file_output, list, quantity);
            fclose(file_output);
            break;
        }
        case '3':
        {
            printf("\n\t\tBANG DIEM SINH VIEN MON TIN DAI CUONG\n\n");
            display(list, quantity);
            break;
        }
        case '4':
        {
            printf("\nSee you again");
            return 0;
        }
        default:
        {
            printf("\nBan dan nhap sai");
        }
        }
        getch();
    }
}
void menu()
{
    printf("\n\t\t\tPOINT MANAGEMENT SYSTEM\n\n");
    printf("----------------------------------------------------------------\n\n");
    printf("1.Import file list of students\n");
    printf("2.Print list into output file\n");
    printf("3.Display list of students fail\n");
    printf("4.Exit program\n");
}
bool check_empty_file(FILE *file)
{
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    if (size > 0)
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
    if (!check_empty_file(file))
    {
        printf("file is empty\n");
        return;
    }

    char buffer[1024];
    char *token = NULL;
    unsigned i = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL && *quantity < MAX)
    {
        buffer[strlen(buffer) - 1] = '\0'; // remember this
        printf("\nNhap thong tin cho sinh vien thu %u: ", i + 1);
        // token = strtok(buffer, ",");
        // if (token != NULL)
        // {
        //     strcpy(list[i].id, token);
        // }
        // token = strtok(NULL, ",");
        // if (token != NULL)
        // {
        //     strcpy(list[i].name, token);
        // }
        sscanf(buffer,"%[^,],%[a-zA-z ]", list[i].id, list[i].name);
        printf("\nNhap diem cua sinh vien: ");
        scanf("%f", &list[i].point);
        i++;
    }
    *quantity = i;
    token = NULL;
    printf("\nImport file successfully");
}

void export_file(FILE *file, student *list, unsigned quantity)
{
    if (quantity == 0)
    {
        printf("\nKhong co sinh vien nao");
    }
    else
    {
        fprintf(file, "\t\t\tBANG DIEM SINH VIEN MON TIN DAI CUONG\n");
        fprintf(file, "___________________________________________________________________________________________\n\n");
        fprintf(file, "%-5s %-20s %-10s %-8s\n", "STT", "Ho Ten", "Ma so", "Diem");
        fprintf(file, "------------------------------------------------------------------------------------------------\n");
        for (unsigned i = 0; i < quantity; i++)
        {
            fprintf(file, "%-5u %-20s %-10s %-8.2f\n", i + 1, list[i].name, list[i].id, list[i].point);
        }
        printf("\nWrite output successfully");
    }
}
void display(student *list, unsigned quantity)
{
    if (quantity == 0)
    {
        printf("\nKhong co sinh vien nao");
        return;
    }
    printf("%-5s %-20s %-10s %-8s\n", "STT", "Ho Ten", "Ma so", "Diem");
    printf("------------------------------------------------------------------------------------------------\n");
    for (unsigned i = 0; i < quantity; i++)
    {
        printf("%-5d %-20s %-10s %-8.2f\n", i + 1, list[i].name, list[i].id, list[i].point);
    }
}