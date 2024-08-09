#ifndef AUTOMACAO_H
#define AUTOMACAO_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

class automacao
{
  private:

   struct automacao_
   {
      std::string nome_;
      std::string tipo_;
      std::string elemento_associado_;
      double limite_;
   };

   std::map<std::string, automacao::automacao_> elementos_;

  public:

  void criar_automacao(std::string nome_automacao, std::string elemento, std::string tipo_de_comparacao, double limite);

  void remover_automacao(std::string nome_automacao);

  void alterar_automacao(std::string nome_automacao, std::string elemento, std::string novo_tipo_de_comparacao, double novo_limite);

  bool usar_automacao(std::string nome_automacao, double valor_analisado);

  std::string get_sensor_associado(std::string& nome_automacao);

  std::string get_nome_automacao(std::string& nome);

  void listar_automacoes();
};

#endif
