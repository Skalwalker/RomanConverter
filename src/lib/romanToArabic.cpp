#include "romanToArabic.hpp"

int letterValue(char l){
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

int validation(char roman[], int i){
    /*
        Impossivel somar mais de 3 I, X, C e M
    */
    int isFalse = 0;
    int isTrue = 1;

    char atual, atual_offset1, atual_offset2, atual_offset3;

    atual = roman[i];
    atual_offset1 = roman[i+1];
    atual_offset2 = roman[i+2];
    atual_offset3 = roman[i+3];

    if((atual == 'I') && (atual_offset1 == 'I') && (atual_offset2 == 'I') && atual_offset3 == 'I'){
        return isFalse;
    } else if((atual == 'X') && (atual_offset1 == 'X') && (atual_offset2 == 'X') && atual_offset3 == 'X'){
        return isFalse;
    } else if((atual == 'C') && (atual_offset1 == 'C') && (atual_offset2 == 'C') && atual_offset3 == 'C'){
        return isFalse;
    } else {
        return isTrue;
    }



}

int romanToArabic(char roman[]){
    int tamanho, i, arabic = 0;
    char atual;

    tamanho = strlen(roman);
    for(i=0;i<tamanho;i++){

        if(!validation(roman, i)){
            return -1;
        }

        atual = roman[i];
        printf("Atual: %c\n", atual);
        arabic += letterValue(atual);
    }

    printf("Arabic: %d\n", arabic);

    return arabic;
}
