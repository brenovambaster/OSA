//
// Created by breno on 22/09/2022.
//

#ifndef PROJETO2_FILE_H
#define PROJETO2_FILE_H

#include <iostream>

using namespace std;

/**
 * \class Apenas para abrir arquivo e veriricar se não houve erros.
 *
 */
class File {
public:
    string name;

    int open(ifstream &input);

    int open(ofstream &input);

    virtual ~File();
};


#endif //PROJETO2_FILE_H
