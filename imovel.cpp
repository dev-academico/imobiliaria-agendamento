#include "imovel.h"
// Iniciando o ID de início
int Imovel::nextId = 1;
// Construtor
Imovel::Imovel(Tipo tipo_inserido, int proprietarioId_inserido, double lat_inserido, double lng_inserido, string endereco_inserido, double preco_inserido){
    id = nextId++;
    tipo = tipo_inserido;
    proprietarioId = proprietarioId_inserido;
    lat = lat_inserido;
    lng = lng_inserido;
    endereco = endereco_inserido;
    preco = preco_inserido;
}

// Getters
int Imovel::getId(){
    return this->id;
}
double Imovel::getLat(){
    return this->lat;
}
double Imovel::getLng(){
    return this->lng;
}