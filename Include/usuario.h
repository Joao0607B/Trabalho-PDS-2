#ifndef USUARIO_H
#define USUARIO_H

#include <map>
#include <string>

using namespace std;

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das
 *  informacoes salvas de cada usuario da casa automatizada.
 */

class Usuario {
  private:
  /**
   * @brief Verifica se a senha satisfaz as seguintes condições:
   *
   * Condicao 1: A senha nao pode ter a seguencia '1234'.
   * Condicao 2: A senha nao pode ter mais do que 15 caracteres (no maximo 15).
   * Condicao 3: A senha nao pode ter menos do que 4 caracteres (no minimo 4).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   * Condicao 5: A senha nao pode conter nenhum login cadastrado.
   */
  bool validarSenha(const string& senha, const string& login) const;

  /**
   * @brief Struct que armazena e gerencia as informacoes de todos os usuario.
   *
   */
   struct usuario {
    int nivel;  // Nivel de acesso do usuario.
    string senha;  // senha do usuario.
    string pergunta_seguranca; //pergunta de segurancao do usuario.
    string resposta_seguranca; //resposta da pergunta de segurancao do usuario.
  };

  /**
   * @brief Container que armazena as informacoes salvas dos usuario. Ele
   * utiliza o login do usuario como chave e as informacoes sao do tipo usuario.
   * Logo, um usuario nao pode estar associado a mais de uma senha e nivel.
   */
  map<string, usuario> cadastro;

 public:

  /**
   * @brief Adiciona um novo usuario.
   * @param login Login utilizado no cadastro do usuario.
   * @param senha Senha utilizado no cadastro.
   * @param nivel Nivel de acesso do usuario utilizado no cadastro.
   * @param pergunta_seguranca Pergunta de segurança utilizado no cadastro para caso o usuario esqueça a senha.
   * @param resposta_seguranca Resposta da pergunta de segurança utilizado no cadastro para caso o usuario esqueça a senha.
   */
  void inserir(const string& login, const string& senha, const int& nivel, const string& pergunta_seguranca, const string& resposta_seguranca);

  /**
   * @brief Verifica se ja existe administrador:
   */
  bool existeAdmin() const;
  
  /**
   * @brief Remove uma conta.
   * @param login Login do usuario
   */
  void remover(const string& login);

  /**
   * @brief Altera as credenciais do usuario.
   * @param login Login utilizado no cadastro do usuario.
   * @param senha_antiga Senha utilizado no cadastro.
   * @param senha_nova Novo password que deve ser atualizado.
   */
  void alterar(const string& login, const string& senha_antiga, const string& senha_nova);

    /**
   * @brief Altera as credenciais do usuario apos o usuario esquecer a senha e responder a pergunta de seguranca corretamente.
   * @param login Login utilizado no cadastro do usuario.
   * @param senha_nova Novo password que deve ser atualizado.
   * @param ignorar_senhaantiga Variavel booleana para definir quando e chamada pela funcao esqueciasenha
   */
  void alterar2(const string& login, const string& senha_nova, bool ignorar_senhaantiga);

  /**
   * @brief Ajuda o usuario a entrar em sua conta caso esqueÃ§a sua senha.
   * @param login Login utilizado no cadastro do usuario.
   * @param pergunta_seguranca Pergunta de seguranÃ§a utilizado no cadastro para caso o usuario esqueÃ§a a senha.
   * @param resposta_seguranca Resposta da pergunta de seguranÃ§a utilizado no cadastro para caso o usuario esqueÃ§a a senha.
   */
  void esqueciasenha(const string& login, const string& resposta_seguranca);

  /**
   * @brief Define o primeiro usuario como admin.
   * @param login Login utilizado no cadastro do usuario.
   * @param nivel Nivel de acesso do usuario utilizado no cadastro.
   */
  void defineAdmin(const string& login, const int& nivel);

  /**
   * @brief Define o primeiro usuario como admin.
   * @param adminlogin Login do admin utilizado no cadastro do usuario.
   * @param login Login do usuario que sera modificado pelo admin.
   * @param novonivel Novonivel do usuario definido pelo admin.
   */
  void alteranivel(const string& adminlogin, const string& login, const int& novonivel);

  /**
   * @brief Imprime as informacoes salvas de todos os usuarios.
   */
  void printInfos();
  
   // Métodos getter

  /**
  * @brief Retorna a senha do usuario.
  *
  * @param login Login do usuario.
  * @return Senha do usuario, ou uma string vazia se o usuario nao existir.
  */
  string getSenha(const string& login) const;

  /**
  * @brief Retorna o nivel de acesso do usuario.
  *
  * @param login Login do usuario.
  * @return Nivel de acesso do usuario, ou -1 se o usuario nao existir.
  */
  int getNivel(const string& login) const;

  /**
  * @brief Retorna a pergunta de seguranca do usuario.
  *
  * @param login Login do usuario.
  * @return Pergunta de seguranca do usuario, ou uma string vazia se o usuario nao existir.
  */
  string getPergunta(const string& login) const;

  /**
  * @brief Retorna a resposta da pergunta de seguranca do usuario.
  *
  * @param login Login do usuario.
  * @return Resposta da pergunta de seguranca do usuario, ou uma string vazia se o usuario nao existir.
  */
  string getResposta(const string& login) const;
};
#endif
