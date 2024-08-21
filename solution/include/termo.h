#ifndef TERMO_H
#define TERMO_H
#include <string>

class Termo
{

private:
    std::string termo;
    long peso;

public:
    // construtor padrão
    Termo();

    // construtor parametrizado pelo termo e pelo peso
    Termo(std::string termo, long peso);

    // compara os dois termos de forma decrescente pelo peso
    // se a ordem de T1 e T2 estiver de forma decrescente em relação ao peso, retorna 1;
    // se T1 e T2 tiverem o mesmo peso, retorna 0;
    // caso contrário, retorna -1;
    static int compararPeloPeso(Termo T1, Termo T2);

    // compara os dois termos por ordem alfabética, usando somente os r primeiros caracteres
    // se a ordem de T1 e T2 estiver de forma decrescente em relação ao prefixo com r caracteres, retorna 1;
    // se T1 e T2 tiverem o mesmo prefixo com r caracteres, retorna 0;
    // caso contrário, retorna -1;
    static int compararPeloPrefixo(Termo T1, Termo T2);

    // sobrecarrega o operador "<" para a classe Termo
    // T1 < T2 se o termo de T1 é menor que o de T2 (comparação de strings)
    bool operator<(Termo T2);

    // sobrecarrega o operador "<<" para a classe Termo. Note que é um método friend
    friend std::ostream &operator<<(std::ostream &out, const Termo &t);

    // retorna o termo
    std::string getTermo() const;
};

#endif