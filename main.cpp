#include <iostream>
#include "Movie.h"
#include "File.h"
#include "Buffer.h"
#include <fstream>

#define  DEBUG 1
using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    Movie movie;
    Buffer b;


    File f1, f2, f3, f4;
    f1.name = "netflix_titles.csv";
    f2.name = "Binary_transcription.bin";
    f3.name = "IndicePrimario.bin";
    f4.name = "Binary_transcription.bin";

    ifstream data, input;
    ofstream source, indiceDireto;

    f1.open(data);
    f2.open(source);
    f3.open(indiceDireto);
    f4.open_binary(input);



    // LENDO O ARQUIVO E EXTRAINDO OS DADOS:
    int cabecalho = 1; // estratégia para não ler o cabecaho do arquivo.
    while (!data.eof()) {
        if (cabecalho) {
            b.GetData(data);
            cabecalho = 0;
        } else {
            b.GetData(data);
            b.WriteBinarySource(source);
        }

    }
    source.close();
    b.generateIndiceId(input, indiceDireto);

    data.close();
    input.close();
    indiceDireto.close();

    return 0;
}
