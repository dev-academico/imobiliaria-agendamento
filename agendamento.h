#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include "corretor.h"
#include "imovel.h"
#include <string>
using std::string;

class Agendamento{
    private:
    Corretor corretor;
    Imovel imovel;
    int hora;
    int tempo;

    public:
    Agendamento(Corretor corretor, double corretorLat, double corretorLng, Imovel imovel, int hora);
    Agendamento() = default;
    double haversine(double lat1, double lon1, double lat2, double lon2);
    void mostrarAgendamento();
    int getTempo();
};

#endif