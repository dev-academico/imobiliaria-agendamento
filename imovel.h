#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
using namespace std;

enum class Tipo{
    CASA,
    APARTAMENTO,
    TERRENO
};

class Imovel{
    private:
    static int nextId;

    int id;
    Tipo tipo;
    int proprietarioId;
    double lat, lng;
    string endereco;
    double preco;

    public:

    Imovel(Tipo tipo, int proprietarioId, double lat, double lng, string endereco, double preco);
    Imovel() = default;

    int getId();

    double getLat();
    double getLng();

};

#endif