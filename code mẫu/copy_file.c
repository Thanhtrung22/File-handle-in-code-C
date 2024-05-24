#include <stdio.h>
#include <conio.h>

#define BUFF_SIZE 4096

int main(){
	FILE *sfile, *dfile;
	char sfilePath[1024], dfilePath[1024];
	int buff[BUFF_SIZE];
	int rbytes, wbytes;
	fflush(stdin);
	printf("Nhap ten tep nguon: ");
	gets(sfilePath);
	
	sfile = fopen(sfilePath, "rb");
	if(sfile == NULL){
		printf("Error: Could not open file %s.\n", sfilePath);
		return 0;
	}
	
	fflush(stdin);
	printf("Nhap ten tep dich: ");
	gets(dfilePath);
	
	dfile = fopen(dfilePath, "wb");
	if(dfile == NULL){
		printf("Error: Could not open file %s.\n", dfilePath);
		return 0;
	}
	
	while(1){
		rbytes = fread(buff, sizeof(int), BUFF_SIZE, sfile);
		if (rbytes < 0){
			printf("Error: Could not read file %s", sfilePath);
			break;
		}
		
		wbytes = fwrite(buff, sizeof(int), rbytes, dfile);
		if (wbytes < 0){
			printf("Error: Could not write file %s", dfilePath);
			break;
		}
		
		if (rbytes < BUFF_SIZE) break;
		
	}
	
	fclose(sfile);
	fclose(dfile);
	
	return 0;
}
