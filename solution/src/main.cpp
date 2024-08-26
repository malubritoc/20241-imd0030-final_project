#include <iostream>
#include <fstream>
#include <string>
#include "autocompletar.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Uso: " << argv[0] << " <nome_do_arquivo> <k>" << endl;
        return 1;
    }

    string nomeArquivo = argv[1];
    int k = stoi(argv[2]);
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    Autocompletar autocompletar;

    string linha;
    while (getline(arquivo, linha))
    {
        size_t pos = linha.find('\t');
        if (pos == string::npos)
        {
            cout << "formato inválido na linha: " << linha << endl;
            continue;
        }

        string termo = linha.substr(pos + 1);
        string peso = linha.substr(0, pos);

        Termo t(termo, stol(peso));      // cria um termo
        autocompletar.adicionarTermo(t); // adiciona o termo no autocompletar
    }

    autocompletar.preparar();

    cout << "Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):\n";

    string prefixo;
    cin >> prefixo;

    while (prefixo != "sair")
    {
        ListaOrdenada<Termo> termos = autocompletar.buscar(prefixo);

        for (int i = 0; i < k && i < termos.tamanho(); i++)
        {

            cout << termos.itens[i] << endl;
        }

        cout << "Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):\n";
        cin >> prefixo;
    }

    return 0;
}
