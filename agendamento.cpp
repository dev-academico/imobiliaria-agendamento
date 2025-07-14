#include "agendamento.h"
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

constexpr double EARTH_R = 6371.0; // Raio da Terra em km

Agendamento::Agendamento(Corretor corretor, double corretorLat, double corretorLng, Imovel imovel, int hora) {
    this->corretor = corretor;
    this->imovel = imovel;
    this->hora = hora;

    //calcular distancia entre corretor e imovel
    double distancia = haversine(corretorLat, corretorLng, imovel.getLat(), imovel.getLng());

    this->tempo = distancia * 2;
}

double Agendamento::haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

//mostrar agendamento
void Agendamento::mostrarAgendamento() {

    // Exibir no formato [HH:MM] Imóvel [ID]
    int minutos = (this->tempo + this->hora) / 60;
    int segundos = (this->tempo + this->hora) % 60;
    if (minutos < 10) cout << "0";
    cout << minutos << ":";
    if (segundos < 10) cout << "0";
    cout << segundos << " Imóvel " << imovel.getId() << endl;
}

int Agendamento::getTempo() {
  return this->tempo;
}