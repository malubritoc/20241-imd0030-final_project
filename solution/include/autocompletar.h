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

    // Implementação da busca binária para encontrar o primeiro índice do prefixo
    int buscaBinariaPrefixo(const std::string &prefixo, bool buscarFim) const;

public:
    // Método para inserir um termo no autocompletar
    void adicionarTermo(const Termo &termo);

    // Método para preparar os termos para o autocompletar (classificação alfabética)
    void preparar();

    // Método para buscar e retornar os termos que começam com o prefixo dado
    ListaOrdenada<Termo> buscar(const std::string &prefixo) const;
};

#endif
