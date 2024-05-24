#include <stdio.h>
#include <conio.h>
#include <string.h>

#define FILE_PATH "diem.txt"
#define MAX 50

typedef struct DiemSV{
	int stt;
	char hoTen[25];
	float diemQT;
	float diemCK;
} DiemSV;

int main(){
	FILE *fp;
	DiemSV bangDiem[MAX];
	int soSV = 0, i, soTT = 1, nbytes;
	char str[25];
	
		
	printf("Hay nhap thong tin sinh vien\n");
	i = 0;
	while(soSV < MAX){
		printf("Nhap thong tin sinh vien thu %d\n", soTT);
		
		fflush(stdin);
		printf("Ho va ten(Nhap xau rong de ket thuc): ");
		gets(str);
		if (strlen(str) == 0) break;
		strcpy(bangDiem[i].hoTen, str);
		
		printf("Diem qua trinh: ");
		scanf("%f", &bangDiem[i].diemQT);
		
		printf("Diem cuoi ky: ");
		scanf("%f", &bangDiem[i].diemCK);
		
		bangDiem[i].stt = soTT;
		
		soTT++;
		soSV++;
		i++;
	}
	
	/*Ghi thong tin len tep van ban*/
	fp = fopen("diem.txt","w");
	
	if(fp == NULL){
		printf("Error: Could not open file.");
		return 0;
	}
	
	fprintf(fp, "DIEM TIN DAI CUONG\n");
	fprintf(fp, "___________________________________________\n");
	for(i = 0; i < soSV; i++){			
		nbytes = fprintf(fp,"%-4d%-25s%-4.1f%-4.1f\n", bangDiem[i].stt, bangDiem[i].hoTen, bangDiem[i].diemQT, bangDiem[i].diemCK);
		if (nbytes < 0){
			printf("Error: Could not write to file.");
			break;
		}
	}
	
	fclose(fp);
	
	/*Doc tep van ban*/
	
	fp = fopen("diem.txt","r");
	
	if(fp == NULL){
		printf("Error: Could not open file.");
		return 0;
	}
	
	char line[100];
	while (!feof(fp))
		if(fgets(line, 1024, fp) != NULL)
			printf("%s", line);
	fclose(fp);
	
	return 0;
}
