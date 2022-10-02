//
// Created by breno on 02/10/2022.
//

#ifndef PROJETO2_INDICE_H
#define PROJETO2_INDICE_H

#include <string>

using namespace std;

class Indice {
public:
    char *id;
    int posicao;

    Indice(char *id, int posicao);

    Indice();

    ~Indice();

};


#endif //PROJETO2_INDICE_H
