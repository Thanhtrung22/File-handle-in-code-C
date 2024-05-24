#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
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
	int soSV = 0, i, soTT = 1, ret;
	char str[25];
	
		
	printf("Hay nhap thong tin sinh vien \n");
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
	
	/*Ghi thong tin len tep nhi phan*/
	fp = fopen("diem.dat","wb");
	
	if(fp == NULL){
		printf("Error: Could not open file.");
		return 0;
	}
	
	for (i = 0; i < soSV; i++){
		ret = fwrite(&bangDiem[i], sizeof(DiemSV), 1, fp);
		if (ret < 1){
			printf("Error: Could not write to file.");
			break;
		}
	}
	fclose(fp);
	
	/*Doc tep vnhi phan*/
	
	fp = fopen("diem.dat","rb");
	
	if(fp == NULL){
		printf("Error: Could not open file.");
		return 0;
	}
	
	DiemSV ketQua[MAX];
	i = 0;
	soSV = 0;
	/*
	while (!feof(fp)){
		if(fread(&ketQua[i], sizeof(DiemSV), 1, fp) < 1)
			break;
		i++;
		soSV++;
	}
	*/
	DiemSV *ptr = NULL;
	fseek(fp, 0, 2);
	long size = ftell(fp);
	rewind(fp);
	soSV = size / sizeof(DiemSV);
	ptr = (DiemSV*)malloc(soSV * sizeof(DiemSV));
int p =	fread(ptr,sizeof(DiemSV), soSV, fp);
	for(i = 0; i < soSV; i++){
		printf("So TT: %d\n", ptr[i].stt);
		printf("Ho va ten: %s\n", ptr[i].hoTen);
		printf("Diem qua trinh: %f\n", ptr[i].diemQT);
		printf("Diem cuoi ky: %f\n", ptr[i].diemCK);
	}
	printf("\np = %d", p);
	free(ptr);
	fclose(fp);
	
	return 0;
}
