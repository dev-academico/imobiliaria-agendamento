#include "corretor.h"

// Iniciando o ID de início
int Corretor::nextId = 1;

// Construtor
Corretor::Corretor(string nome, string telefone, bool avaliador, int lat, int lng){
    id = nextId++;
    nome = nome;
    telefone = telefone;
    avaliador = avaliador;
    lat = lat;
    lng = lng;
}

// Id getter
int Corretor::getId(){
    return this->id;
}
