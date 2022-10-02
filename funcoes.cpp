//
// Created by breno on 02/10/2022.
//

#include "funcoes.h"

void getId(char *registro, char *id) {
    int i = 0;
    while (registro[i] != '|') {
        id[i] = registro[i];
        i++;
    }
    id[i] = '\0';
}
int tamanho_cadeia(char *cadeia) {
    int i = 0, count = 0;
    while (cadeia[i] != '\0') {
        count++;
        i++;
    }
    return count;
}
