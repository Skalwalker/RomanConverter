#include "romanToArabic.hpp"

int valorLetra(char l){
    switch (l) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }
}

int romanToArabic(char roman[]){
    int tamanho, i, arabic;
    char atual;

    tamanho = strlen(roman);
    for(i=0;i<tamanho;i++){
        atual = roman[i];
        printf("Atual: %c\n", atual);
        arabic = valorLetra(atual);
    }

    printf("Arabic: %d\n", arabic);

    return arabic;
}
