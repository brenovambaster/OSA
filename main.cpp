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


    while (!data.eof()) {
        size_t pos = b.GetData(data);
        //b.WriteDataInConsole();
        b.WriteBinarySource(source);
    }


    data.close();
    source.close();
    return 0;
}
