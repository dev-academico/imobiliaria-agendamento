#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente{
    
    private:
    static int nextId;

    int id;
    string nome;
    string telefone;

    public:
    Cliente(string nome, string telefone);
    Cliente() = default;

};

#endif