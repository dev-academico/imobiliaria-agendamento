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
    int lat;
    int lng;

    public:
    //construtor com saldo inserido=0 a fim de tornar opcional
    Corretor(string nome, string telefone, bool avaliador, int lat, int lng);

    int getId();

};

#endif