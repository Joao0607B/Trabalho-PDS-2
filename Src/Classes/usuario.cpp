#include "usuario.h"

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

void Usuario::alterar2(const string& login, const string& senha_nova, bool ignorar_senhaantiga) {
    bool v = validarSenha(senha_nova, login);  
    
    if (v == true){
        for (auto& a : cadastro){
            if (a.first == login){
              a.second.senha = senha_nova;
              cout << "Senha alterada com sucesso!" << endl;
              return; 
            }
        }
    }

    else if (v == false){
      cout << "Senha nova invÃ¡lida, tente novamente" << endl;
      return;
    }
}

void Usuario::esqueciasenha(const string& login, const string& resposta_seguranca) {
    bool respostadesegurancaencontrada = false;

    for (auto& a : cadastro){
      if (a.first == login){
        if (a.second.resposta_seguranca == resposta_seguranca){
          respostadesegurancaencontrada = true;
          
          string senha_nova;
          cout << "Resposta correta! Por favor, insira a nova senha: ";
          cin >> senha_nova;

          if (validarSenha(senha_nova, login)) {
            alterar2(login, senha_nova, true);
            cout << "Senha alterada com sucesso!" << endl;
          } 
          
          else {
            cout << "Senha nova invalida, tente novamente" << endl;
          }

          return;
        }
      }
    }
    
    if (respostadesegurancaencontrada == false){
      cout << "A resposta de seguranca digitada para este login esta incorreta, tente novamente" << endl;
    }   
}

void Usuario::defineAdmin(const string& login, const int& nivel) {        
    bool usuarioencontrado = false;
    for (auto& a : cadastro){
      if (a.first == login){
        usuarioencontrado = true;
        if (!existeAdmin() && nivel == 1){             
          cout << "O usuÃ¡rio " << login << " agora Ã© o admin." << endl;
          return;
        }
        else{
          cout << "JÃ¡ existe um adminstrador. NÃ£o Ã© possÃ­vel inserir outro usuÃ¡rio como admin." << endl;
          return;
        }
      }
    }

    if (usuarioencontrado == false){
      cout << "UsuÃ¡rio nÃ£o encontrado" << endl;
    }      
}

void Usuario::alteranivel (const string& adminlogin, const string& login, const int& novonivel) {        
  bool adminEncontrado = false; 
  bool usuarioEncontrado = false; 

  for (const auto& a: cadastro){
	  if (a.first == adminlogin && a.second.nivel== 1){
	    adminEncontrado = true;
    }
  }

  if (adminEncontrado == false){
    cout << "Apenas o admin pode alterar o nÃ­vel de acesso de outros usuÃ¡rios." << endl;
    return;
  }

  for (auto& x : cadastro) {
    if (x.first == login) {
      usuarioEncontrado = true;
      x.second.nivel = novonivel;
      cout << "NÃ­vel de acesso do usuÃ¡rio " << login << " alterado para " << novonivel << "." << endl;
      return;
    }
  }
}

void Usuario::printInfos() {
    int n = 0;
    
    for (auto& x : cadastro){
      n++;
    }
    cout << n << endl;

    for (auto& g : cadastro){
      cout << g.first << " :" << g.second.nivel << endl;
    }
}

string Usuario::getSenha(const string& login) const {
    if (cadastro.find(login) != cadastro.end()) {
        return cadastro.at(login).senha;
    }
    return "";
}

int Usuario::get_permissao(const string& login) const {
    if (cadastro.find(login) != cadastro.end()) {
        return cadastro.at(login).nivel;
    }
    return -1;
}

string Usuario::getPergunta(const string& login) const {
    if (cadastro.find(login) != cadastro.end()) {
        return cadastro.at(login).pergunta_seguranca;
    }
    return "";
}

string Usuario::getResposta(const string& login) const {
    if (cadastro.find(login) != cadastro.end()) {
        return cadastro.at(login).resposta_seguranca;
    }
    return "";
}
