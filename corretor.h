#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>
using namespace std;

class Corretor{
    
    private:
    static int nextId;

    int id;
    string nome;
    string telefone;
    bool avaliador;
    double lat;
    double lng;

    public:
    Corretor(string nome, string telefone, bool avaliador, double lat, double lng);
    Corretor() = default;

    int getId();

    double getLat();
    double getLng();

    bool getAvaliador();

};

#endif