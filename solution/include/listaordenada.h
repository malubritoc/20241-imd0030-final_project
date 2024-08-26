#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Lista
{
private:
public:
    std::vector<T> itens;

    void inserir(const T &item)
    {
        itens.push_back(item);
    }

    size_t tamanho() const
    {
        return itens.size();
    }

    // sobrecarrega o operador [] para acessar elementos da lista
    T &operator[](size_t indice)
    {
        return itens[indice];
    }

    const T &operator[](size_t indice) const
    {
        return itens[indice];
    }
};

template <typename T>
class ListaOrdenada : public Lista<T>
{
public:
    // ordena a lista usando a função sort da STL
    void ordenar()
    {
        std::sort(Lista<T>::itens.begin(), Lista<T>::itens.end());
    }

    // Método para ordenar a lista com base em uma função de comparação personalizada
    void ordenar(bool (*comp)(const T &, const T &))
    {
        std::sort(Lista<T>::itens.begin(), Lista<T>::itens.end(), comp);
    }
};
