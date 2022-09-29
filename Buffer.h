//
// Created by breno on 22/09/2022.
//

#ifndef PROJETO2_BUFFER_H
#define PROJETO2_BUFFER_H

#include "Movie.h"


class Buffer {
public:
    Movie m1;

    size_t GetData(ifstream &F);

    void WriteDataInConsole();

    void WriteBinarySource(ofstream &F);

    //String searchTitle(String title);

    /**
     *
     * @return Retorna a posicão no final da leitura de cada registro
     */
    size_t readBinaryFile(ifstream &input);


    void generateIndiceID(ifstream &input);

    virtual ~Buffer();
};


#endif //PROJETO2_BUFFER_H
