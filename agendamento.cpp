#include "agendamento.h"
#include <iostream>
#include <cmath>


using std::cout;
using std::endl;

void Agendamento::agendar(std::vector<Corretor> corretores, std::vector<Imovel> imoveis) {
    
    //seleciona apenas os corretores avaliadores
    std::vector<Corretor> avaliadores;

    for(size_t i = 0; i < corretores.size(); ++i){
        if(corretores[i].getAvaliador()){
            avaliadores.push_back(corretores[i]);
        }
    }

    //round-robin para distribuir os imóveis entre os avaliadores
    size_t count = 0;
    for(size_t i = 0; i < imoveis.size(); ++i){
        Visita visita;
        visita.corretor = avaliadores[count];
        visita.imovel = imoveis[i];
        visita.horario = 540; 
        agenda.push_back(visita);
        
        count++;
        if(count == avaliadores.size()){
            count = 0;
        }
    }
}


void Agendamento::organizarAgenda() {

    //cria um vetor para armazenar os IDs dos corretores já processados
    std::vector<int> idsProcessados;

    for(size_t i = 0; i < agenda.size(); ++i){
        int id = agenda[i].corretor.getId();

        if (std::find(idsProcessados.begin(), idsProcessados.end(), id) != idsProcessados.end())
            continue;

        idsProcessados.push_back(id);
        //imprime o ID do corretor
        std::cout << "Corretor " << id << std::endl;

        //filtra as visitas do corretor atual
        std::vector<Visita*> visitasCorretor;
        for(size_t j = 0; j < agenda.size(); ++j){
            if(agenda[j].corretor.getId() == id && agenda[j].horario == 540){
                visitasCorretor.push_back(&agenda[j]);
            }
        }

        //ordena as visitas do corretor por distância
        double lat = agenda[i].corretor.getLat();
        double lng = agenda[i].corretor.getLng();
        int horaAtual = 540;

        for(size_t j = 0; j < visitasCorretor.size(); ++j){
            for(size_t k = 0; k < visitasCorretor.size() - 1 - j; ++k){
                double dist1 = haversine(lat, lng, visitasCorretor[k]->imovel.getLat(), visitasCorretor[k]->imovel.getLng());
                double dist2 = haversine(lat, lng, visitasCorretor[k+1]->imovel.getLat(), visitasCorretor[k+1]->imovel.getLng());

                //bubble sort para ordenar as visitas por distância, vizinho mais proximo 
                if (dist2 < dist1) {
                    Visita* aux = visitasCorretor[k];
                    visitasCorretor[k] = visitasCorretor[k+1];
                    visitasCorretor[k+1] = aux;
                }
            }

            // calcula o deslocamento e atualiza o horário da visita
            Visita* visita = visitasCorretor[j];
            double dist = haversine(lat, lng, visita->imovel.getLat(), visita->imovel.getLng());
            int deslocamento = dist * 2;
            horaAtual += deslocamento;
            visita->horario = horaAtual;

            int horas = visita->horario / 60;
            int minutos = visita->horario % 60;

            //imprime o resto dos dados da visita
            if (horas < 10) std::cout << "0";
            std::cout << horas << ":";
            if (minutos < 10) std::cout << "0";
            std::cout << minutos << " Imóvel " << visita->imovel.getId() << std::endl;

            horaAtual += 60;
            //atualiza a localização do corretor
            lat = visita->imovel.getLat();
            lng = visita->imovel.getLng();
        }

        std::cout << std::endl;
    }
}

//calculo da distancia entre duas localizações
double Agendamento::haversine(double lat1, double lon1, double lat2, double lon2) {
    constexpr double EARTH_R = 6371.0;
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}
