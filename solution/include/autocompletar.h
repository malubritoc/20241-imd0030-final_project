#ifndef AUTOCOMPLETAR_H
#define AUTOCOMPLETAR_H

#include "termo.h"
#include <vector>
#include <string>
#include "listaordenada.h"

class Autocompletar
{
private:
    ListaOrdenada<Termo> termos;

    int buscaBinariaPrefixo(const std::string &prefixo, bool buscarFim) const;

public:
    void adicionarTermo(const Termo &termo);

    void preparar();

    ListaOrdenada<Termo> buscar(const std::string &prefixo) const;
};

#endif
