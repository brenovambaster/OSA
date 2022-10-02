//
// Created by breno on 22/09/2022.
//

#ifndef PROJETO2_BUFFER_H
#define PROJETO2_BUFFER_H

#include "Movie.h"
#include "Indice.h"
#include <fstream>
#include <string.h>
#include "File.h"
#include "funcoes.h"


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
    int readBinaryFile(ifstream &input, ofstream &output);

    void generateIndiceId(ifstream &input, ofstream &output);


    virtual ~Buffer();
};


#endif //PROJETO2_BUFFER_H
