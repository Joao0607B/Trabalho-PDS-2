#include "automacao.hpp"

void automacao::criar_automacao(std::string nome_automacao, std::string elemento, std::string tipo_de_comparacao, double limite)
{
  automacao_ novo_elemento;
  novo_elemento.nome_ = nome_automacao;
  novo_elemento.tipo_ = tipo_de_comparacao;
  novo_elemento.elemento_associado_ = elemento;
  novo_elemento.limite_ = limite;
  elementos_[nome_automacao] = novo_elemento;
}

void automacao::remover_automacao(std::string nome_automacao)
{
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    {
      if(it->first == nome_automacao)
      {
        elementos_.erase(it);
      }
      else
      {
        std::cout << "NÃ£o existe nenhuma automaÃ§Ã£o com esse nome" << std::endl;
      }
    }
}

void automacao::alterar_automacao(std::string nome_automacao, std::string elemento, std::string novo_tipo_de_comparacao, double novo_limite)
{
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    {
      if(it->first == nome_automacao)
      {
        it->second.elemento_associado_ = elemento;
        it->second.tipo_ = novo_tipo_de_comparacao;
        it->second.limite_ = novo_limite;
      }
      else
      {
        std::cout << "NÃ£o existe nenhuma automaÃ§Ã£o com esse nome" << std::endl;
      }
    }
}

bool automacao::usar_automacao(std::string nome_automacao, double valor_analisado)
{
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
  {
    if(it->first == nome_automacao)
    {
      if(it->second.tipo_ == "maior" && it->second.limite_ < valor_analisado)
      {
        return true;
      }
      else if(it->second.tipo_ == "menor" && it->second.limite_ > valor_analisado)
      {
        return true;
      }
      else if(it->second.tipo_ == "igual" && it->second.limite_ == valor_analisado)
      {
        return true;
      }
      else if(it->second.tipo_ == "maior ou igual" && it->second.limite_ <= valor_analisado)
      {
        return true;
      }
      else if(it->second.tipo_ == "menor ou igual" && it->second.limite_ >= valor_analisado)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  return false;
}



void automacao::listar_automacoes()
{
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    {
      std::cout << "Nome: " << it->second.nome_ << "Tipo: " << it->second.tipo_ << "Sensor associado: " << it->second.elemento_associado_ << "Valor Limite: " << it->second.limite_ <<std::endl;
    }
}

std::string automacao::get_sensor_associado(std::string& nome_automacao) 
{
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    {
      if(it->first == nome_automacao)
      {
        return it->second.elemento_associado_;
      }
    }
  return "";
}

std::string automacao::get_nome_automacao(std::string& nome)
{
  for(auto it = elementos_.begin(); it != elementos_.end(); it++)
    {
      if(it->first == nome)
      {
        return it->second.nome_;
      }
    }
  return "";
 
}
