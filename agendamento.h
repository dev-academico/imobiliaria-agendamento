#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include "corretor.h"
#include "imovel.h"
#include <vector>

struct Visita {
    Corretor corretor;
    Imovel imovel;
    int horario;
};

class Agendamento {
public:
    void agendar(std::vector<Corretor> corretores, std::vector<Imovel> imoveis);
    void organizarAgenda();

private:
    std::vector<Visita> agenda;
    double haversine(double lat1, double lon1, double lat2, double lon2);
};

#endif

