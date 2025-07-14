#include <iostream>
#include <vector>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#define _USE_MATH_DEFINES
#include <cmath>

struct Visita {
    Corretor corretor;
    std::vector<Imovel> imovel;
};


constexpr double EARTH_R = 6371.0; // Raio da Terra em km

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

void agendar(std::vector<Corretor> corretores, std::vector<Imovel> imoveis, std::vector<Visita>& agenda){
    size_t count=0;

    //[ [corretor 1], [corretor 2] ]
    for(size_t i = 0; i< corretores.size(); ++i){
       if(corretores[i].getAvaliador()){
            Visita visita;
            visita.corretor = corretores[i];
            agenda.push_back(visita);
            count++; 
        }
    }

    //[ [corretor 1, imovel 1, imovel 3], [corretor 2, imovel 2] ]
    count = 0;
    for(size_t i = 0; i< imoveis.size(); ++i){
    
        agenda[count].imovel.push_back(imoveis[i]);
        count ++;
        
        if(count == agenda.size()){
            count = 0;
        }
    }

    for(size_t i = 0; i < agenda.size(); ++i){
        cout << "Corretor " << agenda[i].corretor.getId() << endl;
        for(size_t j = 0; j < agenda[i].imovel.size(); j++){
            cout << "Imovel " << agenda[i].imovel[j].getId() << endl;
        }
        cout << endl;
    }



}
int main() {

    // Ler corretores
    std::vector<Corretor> corretoresVetor;
    int numCorretores;
    std::cin >> numCorretores;
    for (int i = 0; i < numCorretores; ++i) {
        std::string linha;
        // ler telefone, avaliador, lat, lon
        std::string telefone; int avaliador; double lat, lon;
        std::cin >> telefone >> avaliador >> lat >> lon;
        std::string nome;
        std::getline(std::cin >> std::ws, nome);

        if(avaliador==1){
            corretoresVetor.push_back(Corretor(nome, telefone, true, lat, lon));
        }
        if(avaliador==0){
            corretoresVetor.push_back(Corretor(nome, telefone, false, lat, lon));
        }

    }

    
    // Ler clientes
    std::vector<Cliente> clientesVetor;
    int numClientes;
    std::cin >> numClientes;
    for (int i = 0; i < numClientes; ++i) {
        std::string linha;
        // ler telefone, avaliador, lat, lon
        std::string telefone;
        std::cin >> telefone;
        std::string nome;
        std::getline(std::cin >> std::ws, nome);

        clientesVetor.push_back(Cliente(nome, telefone));
    }
    // Ler imoveis
    std::vector<Imovel> imovelVetor;
    int numImovel;
    std::cin >> numImovel;
    for (int i = 0; i < numImovel; ++i) {
        std::string linha;
        // ler telefone, avaliador, lat, lon
        std::string tipo; int propId; double lat, lon, preco;
        std::cin >> tipo >> propId >> lat >> lon >> preco;
        std::string endereco;
        std::getline(std::cin >> std::ws, endereco);

        if(tipo == "Casa"){
            imovelVetor.push_back(Imovel(Tipo::CASA, propId, lat, lon, endereco, preco));
        }
        if(tipo == "Apartamento"){
            imovelVetor.push_back(Imovel(Tipo::APARTAMENTO, propId, lat, lon, endereco, preco));
        }
        if(tipo == "Terreno"){
            imovelVetor.push_back(Imovel(Tipo::TERRENO, propId, lat, lon, endereco, preco));
        }
        
    }
    // Chamar a função que gera e imprime o agendamento
    std::vector<Visita> agenda;

    agendar(corretoresVetor, imovelVetor, agenda);
    
    return 0;
}