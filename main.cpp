#include <iostream>
#include <vector>
#include "corretor.h"

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

        Corretor sample = Corretor(nome, telefone, avaliador, lat, lon);

        corretoresVetor.push_back(sample);
    }

    
    // Ler clientes

    // Ler imoveis
    
    // Chamar a função que gera e imprime o agendamento
    
    return 0;
}