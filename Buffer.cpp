//
// Created by breno on 22/09/2022.
//

#include "Buffer.h"
#include <fstream>
#include <string.h>

using namespace std;

size_t Buffer::GetData(ifstream &F) {
    size_t pos = F.tellg();
    getline(F, m1.show_id, ';');
    getline(F, m1.type, ';');
    getline(F, m1.title, ';');
    getline(F, m1.director, ';');
    getline(F, m1.cast, ';');
    getline(F, m1.country, ';');
    getline(F, m1.date_added, ';');
    getline(F, m1.release_year, ';');
    getline(F, m1.rating, ';');
    getline(F, m1.duration, ';');
    getline(F, m1.listed_in, ';');
    getline(F, m1.description, '\n');
    return pos;
}

/**
 * Escreve a estrutura no console.
 */
void Buffer::WriteDataInConsole() {
    cout << "001 Show_id: " << m1.show_id << endl;
    cout << "002 Type: " << m1.type << endl;
    cout << "003 Title: " << m1.title << endl;
    cout << "004 Director: " << m1.director << endl;
    cout << "005 Cast: " << m1.cast << endl;
    cout << "006 Country: " << m1.country << endl;
    cout << "007 Date_added: " << m1.date_added << endl;
    cout << "008 Release_year: " << m1.release_year << endl;
    cout << "009 Rating: " << m1.rating << endl;
    cout << "010 Duration: " << m1.duration << endl;
    cout << "011 Listedin: " << m1.listed_in << endl;
    cout << "012 Description: " << m1.description << endl;
    cout << endl;
}

void Buffer::WriteBinarySource(ofstream &F) {
    string dummy;

    dummy = m1.show_id + "|" + m1.type + "|" + m1.title + "|" + m1.director + "|" + m1.cast + "|" + m1.country + "|"
            + m1.date_added + "|" + m1.release_year + "|" + m1.rating + "|" + m1.duration + "|" + m1.listed_in + "|"
            + m1.description;

    int dummy_size = dummy.length();
    char array_data[dummy_size + 1]; /*!< Array char gerado para armazenar o registro @example ['t','e','s','t'] */
    strcpy(array_data, dummy.c_str());

    F.write((char *) &dummy_size, sizeof(dummy_size));
    F.write(array_data, sizeof(array_data));
}


/**
 * @brief Gerar 1 arquivo de índices direto mapeando o ID de todos os registros do arquivo.
 *
 * @example | posicao_noArquivo ID_filme |
 *
 * @def Usa a função readBinaryfile() para retornar a posaicao  tellg();
 */
void Buffer::generateIndiceID(ifstream &input) {
    size_t pos = readBinaryFile(input);
}

size_t Buffer::readBinaryFile(ifstream &input) {


    return 0;
}


Buffer::~Buffer() {
    cout << "Destructor the Buffer\n";
}



