#include <iostream>
#include <vector>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "agendamento.h"

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
    
    // cria a agenda e chama os métodos de agendamento e organização
    Agendamento ag;
    ag.agendar(corretoresVetor, imovelVetor);
    ag.organizarAgenda();

    return 0;
}
