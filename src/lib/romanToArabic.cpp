/*!
   \file romanToArabic
   \brief Arquivo que contem as devidas funcoes para converter os numeros de romanos para arabicos
   \author Renato Nobre
   \date 20/09/2016
*/

#include "romanToArabic.hpp"

/*!
   \brief Transforma a letra do romanico para arabicos
   @param Caracter para conversao
   \return O valor respectivo em inteiro
*/
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

/*!
   \brief Valida os casos de soma
   @param Vetor de caracteres a ser transformado
   @param Valor inteiro do indice do vetor
   \return Se ocorreu um erro ou nao
*/
int validationSum(char roman[], int i){

    int isFalse = 0;
    int isTrue = 1;

    char atual, atual_offset1, atual_offset2, atual_offset3;

    atual = roman[i];
    atual_offset1 = roman[i+1];
    atual_offset2 = roman[i+2];
    atual_offset3 = roman[i+3];

    if(letterValue(atual) == -1){
        return isFalse;
    }

    /*
        Impossivel somar mais de 3 I, X, C e M
        Impossivel Somar dois valores em que exista um valor correspondente, D, V, L
    */
    if((atual == 'I') && (atual_offset1 == 'I') && (atual_offset2 == 'I') && atual_offset3 == 'I'){
        return isFalse;
    } else if((atual == 'X') && (atual_offset1 == 'X') && (atual_offset2 == 'X') && atual_offset3 == 'X'){
        return isFalse;
    } else if((atual == 'C') && (atual_offset1 == 'C') && (atual_offset2 == 'C') && atual_offset3 == 'C'){
        return isFalse;
    } else if((atual == 'M') && (atual_offset1 == 'M') && (atual_offset2 == 'M') && atual_offset3 == 'M'){
        return isFalse;
    } else if((atual == 'D') && (atual_offset1 == 'D')){
        return isFalse;
    } else if((atual == 'V') && (atual_offset1 == 'V')){
        return isFalse;
    } else if((atual == 'L') && (atual_offset1 == 'L')){
        return isFalse;
    }

    return isTrue;
}

/*!
   \brief Valida os casos de subtracao
   @param Vetor de caracteres a ser transformado
   @param Valor inteiro do indice do vetor
   \return Se ocorreu um erro ou nao
*/
int validationSub(char roman[], int i){
    int isFalse = 0;
    int isTrue = 1;

    char atual, atual_offset1;

    atual = roman[i];
    atual_offset1 = roman[i+1];

    /*
        Impossivel subtrair valores que:
        1- O menor seja = a metade do maior
        2- O maior seja 10 * a mais que o menor
        3- Realizar duas subtracoes seguidas
        4- Subtrair dois valores iguais consecutivos
    */
    if(letterValue(atual_offset1)/2 == letterValue(atual)){
        return isFalse;
    }
    if(letterValue(atual_offset1) > 10*letterValue(atual)){
        return isFalse;
    }
    if((atual == roman[i+2])&&(atual_offset1 == roman[i+3])){
        return isFalse;
    }
    if((atual == atual_offset1)&&(letterValue(roman[i+2])>letterValue(atual))){
        return isFalse;
    }

    return isTrue;
}

/*!
   \brief Transforma o vetor de caracteres de romano para arabico
   @param Vetor de caracteres
   \return Retorna o numero em inteiro
*/
int romanToArabic(char roman[30]){
    int tamanho, i, arabic = 0;
    char atual, atual_offset1;

    tamanho = strlen(roman);

    /*
        Passa pela string até o ultimo elemento
    */
    for(i=0;(i<tamanho) && (roman[i] != '\0');i++){
        atual = roman[i];
        atual_offset1 = roman[i+1];

        /*
            Entra em tres possiveis estados, testa a consistencia da soma, senao
            entra em condicao de soma, senao
            entra em condicao de subtracao.
        */
        if(!validationSum(roman, i)){
            return -1;
        } else if(letterValue(atual) >= letterValue(atual_offset1)){
            if(!validationSub(roman, i)){
                return -1;
            }
            arabic += letterValue(atual);
        } else{
            if(!validationSub(roman, i)){
                return -1;
            }
            arabic = arabic + letterValue(atual_offset1) - letterValue(atual);
            i++;
        }


    }

    return arabic;
}
