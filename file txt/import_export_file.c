#include <stdio.h>
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

}