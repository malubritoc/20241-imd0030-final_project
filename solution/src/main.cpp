#include <iostream>
#include <fstream>
#include <string>
#include "autocompletar.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " <nome_do_arquivo>" << endl;
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
        size_t pos = linha.find('\t'); // Localiza o delimitador de tabulação

        // Extrai o peso e o termo
        string termo = linha.substr(pos + 1);
        string peso = linha.substr(0, pos);

        Termo t(termo, stol(peso));      // Cria um objeto Termo
        autocompletar.adicionarTermo(t); // Adiciona o termo ao autocompletar

        // Imprime o peso e o termo
        cout << "Peso: " << peso << ", Termo: " << termo << endl;
    }

    cout << "Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):\n";

    string prefixo;
    cin >> prefixo;

    while (prefixo != "sair")
    {
        vector<Termo> termos = autocompletar.buscar(prefixo);

        for (int i = 0; i < k; i++)
        {
            cout << termos[i] << endl;
        }

        cout << "Entre com o termo a ser auto-completado: (digite 'sair' para encerrar o programa):\n";
        cin >> prefixo;
    }

    return 0;
}
