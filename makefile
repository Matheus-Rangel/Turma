
#Exemplo mais completo de um Makefile
#Algumas variaveis sao usadas com significado especial:
#$@ nome do alvo (target)
#$^ lista com os nomes de todos os pre-requisitos sem duplicatas
#$< nome do primeiro pre-requisito
# Comandos do sistema operacional
# Linux: rm -rf
# Windows: cmd //C del
RM = rm -rf
# Compilador
CC=g++
# Variaveis para os subdiretorios
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
# Outras variaveis
# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)
# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy
exec: $(OBJ_DIR)/main.o $(OBJ_DIR)/turma.o $(OBJ_DIR)/aluno.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel criado em $(BIN_DIR)] +++"
	@echo "============="
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp 
	$(CC) -c $(CFLAGS) -o $@ $<
$(OBJ_DIR)/aluno.o:$(SRC_DIR)/aluno.cpp $(INC_DIR)/aluno.h 
	$(CC) -c $(CFLAGS) -o $@ $<
$(OBJ_DIR)/turma.o:$(SRC_DIR)/turma.cpp $(INC_DIR)/turma.h
	$(CC) -c $(CFLAGS) -o $@ $<
