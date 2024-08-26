#include "autocompletar.h"
#include "termo.h"
#include <algorithm>

// busca binária p encontrar o primeiro índice do prefixo
int Autocompletar::buscaBinariaPrefixo(const std::string &prefixo, bool buscarUltimo) const
{
    int esquerda = 0, direita = termos.tamanho() - 1;
    int resultado = -1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        std::string termoAtual = termos.itens[meio].getTermo().substr(0, prefixo.size());

        if (termoAtual > prefixo)
        {
            esquerda = meio + 1;
        }
        else if (termoAtual < prefixo)
        {
            direita = meio - 1;
        }
        else
        {
            resultado = meio;
            if (buscarUltimo)
            {
                esquerda = meio + 1;
            }
            else
            {
                direita = meio - 1;
            }
        }
    }

    return resultado;
}

// insere um termo no autocompletar
void Autocompletar::adicionarTermo(const Termo &termo)
{
    termos.inserir(termo);
}

// ordena os termos em ordem alfabetica
void Autocompletar::preparar()
{
    termos.ordenar([](const Termo &a, const Termo &b)
                   { return Termo::compararPeloPrefixo(a, b) > 0; });
}

// busca e retorna os termos que começam com o prefixo do parametro
ListaOrdenada<Termo> Autocompletar::buscar(const std::string &prefixo) const
{
    ListaOrdenada<Termo> resultados;

    int inicio = buscaBinariaPrefixo(prefixo, false);
    if (inicio == -1)
    {
        return resultados;
    }

    int fim = buscaBinariaPrefixo(prefixo, true);

    for (int i = inicio; i <= fim; ++i)
    {
        resultados.inserir(termos.itens[i]);
    }

    // ordena os termos encontrados por peso em ordem decrescente
    resultados.ordenar([](const Termo &a, const Termo &b) -> bool
                       { return Termo::compararPeloPeso(a, b) > 0; });

    return resultados;
}
