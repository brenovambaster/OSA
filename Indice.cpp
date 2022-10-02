//
// Created by breno on 02/10/2022.
//

#include "Indice.h"

Indice::Indice() {

}

Indice::Indice(char *id, int posicao) : id(id), posicao(posicao) {}

Indice::~Indice() {
    delete[]id;
}
