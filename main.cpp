#include <iostream>
#include <vector>
#include "quarto.h"
#include "usuario.h"
#include "sensor.h"
#include <string>

using namespace std;

int main() {


    // Declaração de variáveis para armazenar informações do usuário
    string login, senha, pergunta_seguranca, resposta_seguranca;
    int nivel;

    // Solicita ao usuário que insira suas informações
    cout << "Insira os seus dados:" << endl;
    
    // Solicita o login do usuário
    cout << "Login.................: ";
    cin >> login;
    cout << endl;

    // Solicita a senha do usuário
    cout << "Qual senha você gostaria de dar a esse perfil? ";
    cin >> senha;
    cout << endl;

    // Verifica se já existe um administrador e pergunta ao usuário se deseja ser um
    if (Usuario::existeAdmin()) {
        cout << "Gostaria de ser Administrador? (s/n) ";
        char escolha;
        cin >> escolha;
        cout << endl;

        // Se o usuário deseja ser administrador, define o nível como 1 (administrador)
        if (escolha == 's' || escolha == 'S') {
            nivel = 1; // Nível 1 para administrador
        } else {
            nivel = 0; // Nível 0 para usuário comum
        }
    } else {
        nivel = 0; // Nível 0 para usuário comum, caso não haja administrador
    }

    // Solicita a pergunta de segurança para redefinir a senha
    cout << "Qual você gostaria que fosse a pergunta de segurança? Obs: a pergunta de segurança serve para redefinir a sua senha usando a resposta de segurança, então escolha com sabedoria: ";
    cin.ignore(); // Ignora qualquer caractere residual no buffer de entrada
    getline(cin, pergunta_seguranca); // Usa getline para ler a pergunta de segurança com espaços
    cout << endl;

    // Solicita a resposta de segurança
    cout << "Resposta de Segurança: ";
    cin >> resposta_seguranca;
    cout << endl;

    // Cria uma instância da classe Usuario e insere os dados
    Usuario usuario;
    usuario.inserir(login, senha, nivel, pergunta_seguranca, resposta_seguranca);

    



    return 0;
}
