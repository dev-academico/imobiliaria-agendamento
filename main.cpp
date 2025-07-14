#include <iostream>
using std::cout;
using std::endl;
#include <vector>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "agendamento.h"


struct Visita {
    Corretor corretor;
    std::vector<Imovel> imovel;
};


void ordenarImoveisPorDistancia(Corretor corretor, std::vector<Imovel>& imoveis) {
    for(size_t j = 0; j < imoveis.size(); j++){
        for(size_t k = j+1; k < imoveis.size(); k++){
            if(Agendamento::haversine(corretor.getLat(), corretor.getLng(), imoveis[j].getLat(), imoveis[j].getLng()) > 
               Agendamento::haversine(corretor.getLat(), corretor.getLng(), imoveis[k].getLat(), imoveis[k].getLng())){
                Imovel aux = imoveis[j];
                imoveis[j] = imoveis[k];
                imoveis[k] = aux;
            }
        }   
    }
};

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
}

void organizarAgenda(std::vector<Visita>& agenda){
    for(size_t i = 0; i < agenda.size(); ++i){
        int horaInicial = 540;
        // Imprimir corretor
        cout << "Corretor " << agenda[i].corretor.getId() << endl;
        // Lat e lng do corretor, para não mudar o local da casa do corretor
        double corretorLat = agenda[i].corretor.getLat();
        double corretorLng = agenda[i].corretor.getLng();

        // lista ordenada de imoveis por distancia
        ordenarImoveisPorDistancia(agenda[i].corretor, agenda[i].imovel);   
        
        for(size_t j = 0; j < agenda[i].imovel.size(); j++){
            // Imprimir imovel mais proximo
            Imovel imovelMaisProximo = agenda[i].imovel[j];
            Agendamento agendamento(agenda[i].corretor, corretorLat, corretorLng, imovelMaisProximo, horaInicial);

            // Tempo de agendamento + 60 minutos de trabalho
            horaInicial = horaInicial + agendamento.getTempo() + 60;

            agendamento.mostrarAgendamento();

            // Atualizar lat e lng do corretor para o próximo imóvel
            corretorLat = imovelMaisProximo.getLat();
            corretorLng = imovelMaisProximo.getLng();
        }
        if(i != agenda.size() - 1){
            cout << endl;
        }
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
    organizarAgenda(agenda);

    return 0;
}