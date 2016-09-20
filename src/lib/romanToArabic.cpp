#include "romanToArabic.hpp"

int valorLetra(char l){
    switch (l) {
        case 'I':
            return 1;
    }
}

int romanToArabic(char roman[]){
    int tamanho, i, arabic;
    char atual;

    tamanho = strlen(roman);
    for(i=0;i<tamanho+1;i++){
        atual = roman[i];

        atual = valorLetra(i);
    }
    arabic = atual;

    return arabic;
}
