#include <iostream>
#include <vector>
#include <algorithm> // Para a função std::sort

// Classe genérica Lista
template <typename T>
class Lista
{
private:
    std::vector<T> itens; // Armazena os itens da lista

public:
    // Método para inserir um item na lista
    void inserir(const T &item)
    {
        itens.push_back(item);
    }

    // Método para retornar o tamanho da lista
    size_t tamanho() const
    {
        return itens.size();
    }

    // Método para imprimir a lista na tela
    void imprimir() const
    {
        for (const auto &item : itens)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }

    // Sobrecarga do operador [] para acessar elementos da lista
    T &operator[](size_t indice)
    {
        return itens[indice];
    }

    const T &operator[](size_t indice) const
    {
        return itens[indice];
    }
};

// Classe ListaOrdenada que herda de Lista
template <typename T>
class ListaOrdenada : public Lista<T>
{
public:
    // Método para ordenar a lista usando a função sort da STL
    void ordenar()
    {
        std::sort(Lista<T>::itens.begin(), Lista<T>::itens.end());
    }

    // Método para ordenar a lista com base em uma função de comparação personalizada
    void ordenar(bool (*comp)(const T &, const T &))
    {
        std::sort(Lista<T>::itens.begin(), Lista<T>::itens.end(), comp);
    }

    // void ordenarComParametro(std::function<int(const T &, const T &)> comparacao)
    // {
    //     std::sort(Lista<T>::itens.begin(), Lista<T>::itens.end(), [comparacao](const T &a, const T &b)
    //               { return comparacao(a, b) < 0; });
    // }
};
