//
// Created by breno on 22/09/2022.
//

#include "Buffer.h"


using namespace std;

void Buffer::GetData(ifstream &F) {
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

    int dummy_size = (int) dummy.length();// retorna o valor sem o \0;
    F.write((char *) &dummy_size, sizeof(dummy_size));
    F.write(dummy.c_str(), dummy_size);

}


/**
 *
 * @param input arquivo ja aberto
 * @param output arquivo ja aberto
 * @brief Gerar 1 arquivo de índices direto mapeando o ID de todos os registros do arquivo.
 * @example | posicao_noArquivo ID_filme |
 * @def Usa a função readBinaryfile() para retornar a posição  tellg();
 */
void Buffer::generateIndiceIdPimary_Secondary(ifstream &input, ofstream &indiceDireto, ofstream &indiceSecundario) {
    input.seekg(0, ios_base::end);
    int final_arquivo = input.tellg();
    input.seekg(0, ios_base::beg);

    while (input.tellg() < final_arquivo) {
        generateFiles(input, indiceDireto, indiceSecundario);
    }
}

/**
 * @brief Retorna a posição do índice ao final da leitura do registro.
 * O arquivo  que é passado por parâmetro já deve vir aberto;
 * @param input
 * @return  size_t
 *
 */
int

/**
 * @brief 
 * @param input
 * @param indiceDireto
 * @return
 */
Buffer::generateFiles(ifstream &input, ofstream &indiceDireto, ofstream &indiceSecundario) {

    int tamanho = 0, indice = 0, typePosition = 0;
    indice = input.tellg();
    input.read((char *) &tamanho, sizeof(int)); // ler o comprimeoto em binario da string
    char *buffer = new char[tamanho + 1];
    input.read(buffer, tamanho); // ler os dados da string
    buffer[tamanho] = '\0';
    char *id = new char[7];
    char *title = new char[256];

    typePosition = getId(buffer, id);
    getTitle(buffer, title, typePosition);
    indiceDireto << id << '|' << indice << endl;
    indiceSecundario << id << '|' << title << endl;

    delete[] buffer;
    delete[] title;
    delete[]id;
    return indice;
}


Buffer::~Buffer() {
    cout << "Destructor the Buffer\n";
}



