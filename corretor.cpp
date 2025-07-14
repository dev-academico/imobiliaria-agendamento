#include "corretor.h"

// Iniciando o ID de início
int Corretor::nextId = 1;

// Construtor
Corretor::Corretor(string nome_inserido, string telefone_inserido, bool avaliador_inserido, double lat_inserido, double lng_inserido){
    id = nextId++;
    nome = nome_inserido;
    telefone = telefone_inserido;
    avaliador = avaliador_inserido;
    lat = lat_inserido;
    lng = lng_inserido;
}

// Getters
int Corretor::getId(){
    return this->id;
}
double Corretor::getLat(){
    return this->lat;
}
double Corretor::getLng(){
    return this->lng;
}
bool Corretor::getAvaliador(){
    return this->avaliador;
}

