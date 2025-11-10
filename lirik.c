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
