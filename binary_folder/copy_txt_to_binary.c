#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *input_filename = "input.txt";
    const char *output_filename = "output.dat";

    // Mở tệp văn bản để đọc
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Could not open file %s for reading\n", input_filename);
        return 1;
    }

    // Mở tệp nhị phân để ghi
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Could not open file %s for writing\n", output_filename);
        fclose(input_file);
        return 1;
    }

    // Đọc từ tệp văn bản và ghi vào tệp nhị phân
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        //printf("\nbyte = %lld", bytes);
        fwrite(buffer, 1, bytes, output_file);
    }
    
    // Đóng các tệp
    fclose(input_file);
    fclose(output_file);

    printf("Successfully converted %s to %s\n", input_filename, output_filename);
    output_file = fopen(output_filename, "rb");
    char a[100];
    size_t t = fread(a, sizeof(char), sizeof(a), output_file);
    for(unsigned i = 0; i < t; i++)
    {
        printf("%c", a[i]);
    }
    return 0;
}
