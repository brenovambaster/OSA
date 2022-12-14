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
    int generateFiles(ifstream &input, ofstream &indiceDireto, ofstream &indiceSecundario);

    void generateIndiceIdPimary_Secondary(ifstream &input, ofstream &primaryIndexFile, ofstream &secondaryIndexFile);

    int searchShowId(string id);

    int searchTitle(string titler);

    void showRegister(int posicao);

    virtual ~Buffer();
};


#endif //PROJETO2_BUFFER_H
