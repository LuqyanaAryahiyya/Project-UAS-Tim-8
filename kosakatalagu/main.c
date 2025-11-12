#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *input, *output;
    char data[100], baris[200], kosaKata[1000][100];
    int n = 0, cari;

    //Membuka file lirik dan kosa-kata
    input = fopen("lirik.txt", "r");        
    output = fopen("kosa-kata.txt", "w");   
    
    if (input == NULL|| output == NULL) {
        printf("File tidak ditemukan.\n");
        return 0;
    }

    fgets(baris, sizeof(baris), input);     
    fprintf(output, "%s", baris);  

    while (fgets(baris, sizeof(baris), input)) {
        int i = 0, j = 0;

        //Menyimpan huruf dan tanda '
        while (baris[i] != '\0') {
            char c = tolower(baris[i]);
            if ((c >= 'a' && c <= 'z') || c == '\'') {      
                data[j] = c;
                j++;
            } 
            else if (j > 0) {
                data[j] = '\0';
                cari = 0;

                //Mengecek kata yang sudah pernah muncul
                for (int k = 0; k < n; k++) {              
                    if (strcmp(kosaKata[k], data) == 0) {
                        cari = 1;
                        break;
                    }
                }
                if (cari == 0) {
                    strcpy(kosaKata[n], data);
                    n++;
                }
                j = 0;
            }
            i++;
        }
    }

    //Menulis daftar kata ke file output
    for (int i = 0; i < n; i++) {               
        fprintf(output, "%s=\n", kosaKata[i]);
    }

    //Menutup file lirik dan kosa-kata
    fclose(input);          
    fclose(output);         
    printf("Program berhasil, silahkan cek file kosa-kata.txt\n");
    return 0;
}

