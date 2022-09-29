//
// Created by breno on 22/09/2022.
//

#ifndef PROJETO2_BUFFER_H
#define PROJETO2_BUFFER_H

#include "Movie.h"


class Buffer {
public:
    Movie m1;

    void GetData(ifstream &F);

    void WriteDataInConsole();

    void WriteBinarySource(ofstream &F);

    /**
     *
     * @return Retorna a posicão no final da leitura de cada registro
     */
    size_t readBinaryFile(ifstream &input);

    void generateIndiceId(ifstream &input);

    virtual ~Buffer();
};


#endif //PROJETO2_BUFFER_H
