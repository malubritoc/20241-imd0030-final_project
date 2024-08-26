#include "termo.h"
#include <iostream>
#include <algorithm>

Termo::Termo() : termo(""), peso(0) {}

Termo::Termo(std::string termo, long peso) : termo(termo), peso(peso) {}

// metodo p comparar dois termos de forma decrescente pelo peso
int Termo::compararPeloPeso(Termo T1, Termo T2)
{
    if (T1.peso > T2.peso)
    {
        return 1;
    }
    else if (T1.peso < T2.peso)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// metodo p comparar dois termos por ordem alfabetica
int Termo::compararPeloPrefixo(Termo T1, Termo T2)
{
    int minLength;

    if (T1.termo.size() <= T2.termo.size())
    {
        minLength = T1.termo.size();
    }
    else
    {
        minLength = T2.termo.size();
    }

    std::string prefixoT1 = T1.termo.substr(0, minLength);
    std::string prefixoT2 = T2.termo.substr(0, minLength);

    if (prefixoT1 > prefixoT2)
    {
        return 1;
    }
    else if (prefixoT1 < prefixoT2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// sobrecarrega o operador "<" para comparação entre termos
bool Termo::operator<(Termo T2)
{
    return this->termo < T2.termo;
}

// sobrecarrega o operador "<<" para imprimir um termo
std::ostream &operator<<(std::ostream &out, const Termo &t)
{
    out << t.termo << " (" << t.peso << ")";
    return out;
}

// retorna o termo
std::string Termo::getTermo() const
{
    return termo;
}