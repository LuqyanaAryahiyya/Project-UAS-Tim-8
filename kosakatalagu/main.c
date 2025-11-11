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
    
    if (input == NULL || output == NULL) {
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
            if (isalpha(c) || c == '\'') {
                word[j++] = c;
            } else if (j > 0) {
                word[j] = '\0';
                //Mengecek kata yang sudah pernah muncul
                found = 0;
                for (int k = 0; k < count; k++) {
                    if (strcmp(words[k], word) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(words[count++], word);
                }
                j = 0;
            }
            i++;
        }
    }

    //Menulis daftar kata ke file output
    for (int k = 0; k < count; k++) {
        fprintf(output, "%s=\n", words[k]);
    }

    //Menutup file lirik dan file kosa-kata
    fclose(input);
    fclose(output);
    printf("File kosa-kata.txt berhasil dibuat!\n");
    return 0;
}

