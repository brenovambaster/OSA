#include <iostream>
#include "Movie.h"
#include "File.h"
#include "Buffer.h"
#include <fstream>

#define  DEBUG 1
using namespace std;

int main() {
    Movie movie;
    Buffer b;


    File f1, f2;
    f1.name = "netflix_titles.csv";
    f2.name = "Binary_transcription.bin";

    ifstream data;
    ofstream source;

    f1.open(data);
    f2.open(source);

    // LENDO O ARQUIVO E EXTRAINDO OS DADOS:
    int cabecalho = 1; // estratégia para não ler o cabecaho do arquivo.
    while (!data.eof()) {
        if (cabecalho)
            b.GetData(data);
        b.GetData(data);
        b.WriteBinarySource(source);


    }


    data.close();
    source.close();
    return 0;
}
