# definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contem a função main, sem a extensao)
MAIN 	:= main
# objetos a serem gerados na compilação
OBJECTS := main.o Buffer.o File.o Movie.o funcoes.o Indice.o
# (para C, pode-se usar o padrão ISO 2011 (c11) ou 2018 (c18), dependendo do seu compilador...
# usar -std=c98 no lugar do c++11, c++17, c++20, etc..

FLAGS 	:= -Wall  -Wextra -std=c++17 #-pedantic-errors


# habilitar a depuração
DEBUG :=  -g

# necessário apenas quando se incluir  a biblioteca <math.h> em algum arquivo fonte no projeto
MATH 	:= -lm

# definição do compilador: para C usar o gcc, por exemplo
CC		:= g++

# ajustando alguns parâmetros/comandos ao sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
RM	:= del /q /f
else
OUTPUTMAIN := $(MAIN).out
RM	:= rm -f
endif

# ponto de compilação principal
all: main.exe
	@echo Compiling 'all' complete!

# gerando o arquivo executavel
main.exe: $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)


# gerando o arquivo objeto da função principal... adicionar as dependencias (se houverem)
main.o: $(MAIN).cpp Movie.h File.h Buffer.h
	$(CC) $(FLAGS) -c $(MAIN).cpp

Indice.o: Indice.cpp Indice.h
	$(CC) $(FLAGS) -c Indice.cpp
# gerando o arquivo executavel
File.o: File.cpp File.h
	$(CC) $(FLAGS) -c File.cpp

funcoes.o: funcoes.h funcoes.cpp
	$(CC) $(FLAGS) -c funcoes.cpp
# gerando o arquivo objeto da minha biblioteca 1 (myFunc1.o) que depende dos arquivos myFunc1.c, myFunc1.h
Buffer.o: Buffer.cpp Buffer.h Movie.h
	$(CC) $(FLAGS) -c Buffer.cpp

Movie.o:Movie.cpp Movie.h
	$(CC) $(FLAGS) -c Movie.cpp

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OUTPUTMAIN)
	$(RM) *.dat
	$(RM) *.bin
	@echo Cleanup complete!!!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'all' complete!!!