#include "Usuario.h"

#include <iostream>

using namespace std;

bool Usuario::validarSenha(const string& senha, const string& login) const {
    string sequencia = "1234";
    int t_senha = senha.size();
    int t_1234 = sequencia.size();
    int t_login = login.size();
    int x = 0;
    int z = 0;

    if (t_senha > 15 || t_senha < 4){
      return false;
    }

    for(int a = 0; a < t_senha; a++){
        if (senha [a] == sequencia [x]){
          x++;
        
          if (x == t_1234){
              return false;
          }
        }

        else{
          x = 0;
        }
    }

    for(int j = 0; j < t_senha; j++){
        if (senha [j] == ' '){
          return false;
        }
    }

    for(int y = 0; y < t_senha; y++){
        if (senha [y] == login [y]){
          z++;
        
          if (x == t_login){
              return false;
          }
        }

        else{
          z = 0;
        }
    }
    return true;
}

bool Usuario::existeAdmin() const {
    for (auto a : cadastro) {
        if (a.second.nivel == 1) {
            return true;
        }
    }
    return false;
}

void Usuario::inserir(const string& login, const string& senha, const int& nivel, const string& pergunta_seguranca, const string& resposta_seguranca) {
  bool usuarioencontrado = false;
  bool v = validarSenha(senha, login); 

    if (nivel == 1 && existeAdmin()) {
        cout << "Já existe um adminstrador. Não é possível inserir outro usuário como admin." << endl;
        return;
    }

    if (v == false){
      return;
    }

    usuario Usuario;
    Usuario.nivel = nivel;
    Usuario.senha = senha;
    Usuario.pergunta_seguranca = pergunta_seguranca;
    Usuario.resposta_seguranca = resposta_seguranca;

    for (auto a : cadastro){
      if (a.first == login){
          usuarioencontrado = true;
          cout << "Login já existe, tente novamente" << endl;
          break;
      }
    }

    if (usuarioencontrado == false){
      cadastro.insert({login, Usuario});
    } 
}

void Usuario::remover(const string& login) {
    bool usuarioencontrado = false;

     for (auto a : cadastro){
          if (a.first == login){
            usuarioencontrado = true;
            break;
        }
     }

    if (usuarioencontrado == true){
        cadastro.erase(login);
    }
}

void Usuario::alterar(const string& login, const string& senha_antiga, const string& senha_nova) {
    bool senhaencontrada = false;
    bool v = validarSenha(senha_nova, login);  
    
    if (v == true){
        for (auto& a : cadastro){
            if (a.first == login){
                if (a.second.senha == senha_antiga){
                  senhaencontrada = true;
                  a.second.senha = senha_nova;
                  return;
                }
            }
        }
    }

    else if (v == false){
      cout << "Senha nova inválida, tente novamente" << endl;
      return;
    }

    else if (senhaencontrada == false){
      cout << "A senha antiga não corresponde a nenhuma senha salva, tente novamente" << endl;
    }
}





