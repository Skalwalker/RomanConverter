#include "romanToArabic.hpp"

int valorLetra(char l){
    switch (l) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
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
