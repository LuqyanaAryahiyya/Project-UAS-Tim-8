#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *input, *output;
    char word[100], line[200];
    char words[1000][100];
    int count = 0, found;

    //Membuka file lirik dan file kosa-kata
    input = fopen("lirik.txt", "r");
    output = fopen("kosa-kata.txt", "w");
    
    if (!input || !output) {
        printf("File tidak ditemukan.\n");
        return 1;
    }

    //Membaca judul
    fgets(line, sizeof(line), input);  
    fprintf(output, "%s", line);  

    while (fgets(line, sizeof(line), input)) {
        int i = 0, j = 0;

        while (line[i] != '\0') {
            char c = tolower(line[i]);

            //Menyimpan huruf dan tanda '
