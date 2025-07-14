#include "cliente.h"
// Iniciando o ID de início
int Cliente::nextId = 1;
// Construtor
Cliente::Cliente(string nome_inserido, string telefone_inserido){
    id = nextId++;
    nome = nome_inserido;
    telefone = telefone_inserido;
}
