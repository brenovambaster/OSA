//
// Created by breno on 22/09/2022.
//

#include "File.h"
#include <fstream>

int File::open(ifstream &input) {
    input.open(name, ios_base::in);
    if (!input.is_open()) {
        cerr << "Erro ao abrir arquivo: " << name;
        return 0;
    }
    return 1;
}

int File::open_binary(ifstream &input) {
    input.open(name, ios_base::binary);
    if (!input.is_open()) {
        cerr << "Erro ao abrir arquivo: " << name;
        return 0;
    }
    return 1;
}

int File::open(ofstream &input) {
    input.open(name, ios_base::binary);
    if (!input.is_open()) {
        cerr << "Erro ao abrir arquivo: " << name;
        return 0;
    }
    return 1;
}

File::~File() {
    cout << "Destructor the File\n";
}
