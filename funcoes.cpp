//
// Created by breno on 02/10/2022.
//

#include "funcoes.h"

/**
 *
 * @param registro
 * @param id
 * @return Retorna a  posicao de onde se inicia o título do registro
 */
int getId(const char *registro, char *id) {
    int i = 0;
    while (registro[i] != '|') {
        id[i] = registro[i];
        i++;
    }
    id[i] = '\0';
    return i + 1;
}

int tamanho_cadeia(char *cadeia) {
    int i = 0, count = 0;
    while (cadeia[i] != '\0') {
        count++;
        i++;
    }
    return count;
}

/**
 *
 * @param registro cadeia de caracter que contem o registro
 * @param title cadeia de caracter de onde se armazenará o título
 * @param initialPosition posicao inicial do atributo type;
 */
void getTitle(const char *registro, char *title, int initialPosition) {
    int initialTitle = inicio_title(registro, initialPosition);
    int i = initialTitle;
    int aux = 0;
    while (registro[i] != '|') {
        title[aux] = registro[i];
        i++;
        aux++;
    }
    title[aux] = '\0';
}

/**
 *
 * @param registro
 * @param inicio_type posicao de onde se incia o atributo type
 * @return retorna a posicao de onde se inicia o atributo title;
 */
int inicio_title(const char *registro, int inicio_type) {
    int i = inicio_type;
    while (registro[i] != '|') {
        i++;
    }
    return i + 1;
}
