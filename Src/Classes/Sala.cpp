#include "Sala.h"

int Sala::quantidade(std::string tipo)
{
  int count = 0;
   for(int i = 0; i < elementos_.size(); i++)
   {
    if(elementos_[i].tipo == tipo)
    {
      count++; 
    }
   }
  return count;
}

void Sala::listar(std::string tipo)
{
  for(int i = 0; i < elementos_.size(); i++)
  {
    if(elementos_[i].tipo == tipo)
    {
      std::cout << elementos_[i].nome << std::endl;
    }
  }
}

Sala::Sala(std::string nome, int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int qtd_umidificador)
{
  nome_ = nome;
  Nomear_Elemento(qtd_portas, "porta");
  Nomear_Elemento(qtd_janelas, "janela");
  Nomear_Elemento(qtd_lampadas, "lampada");
  Nomear_Elemento(qtd_tvs, "tv");
  Nomear_Elemento(qtd_ar_condicionado, "ar-condicionado");
  Nomear_Elemento(qtd_umidificador, "umidificador");

  std::cout << "Sala criada com sucesso!" << std::endl;
}

void Sala::Nomear_Elemento(int qtd, std::string tipo)
{
  for(int i = 0; i < qtd; i++)
    {
      std::cout << "Digite o nome da " << tipo << ':' << std::endl;
      std::cin >> elementos_[i].nome;
      elementos_[i].tipo = tipo;
    }
}

void Sala::atribuir_sensor(const std::string& nome_sensor, const std::string& nome)
{
  for(int i = 0; i < elementos_.size(); i++)
  {
    if(elementos_[i].nome == nome)
    {
      elementos_[i].sensor_associado = nome_sensor;
    }
  }
}

void Sala::remover_sensor(const std::string& nome_sensor)
{
  for(int i = 0; i < elementos_.size(); i++)
  {
    if(elementos_[i].sensor_associado == nome_sensor)
    {
      elementos_[i].sensor_associado = "Não atribuido";
    }
    else
    {
      std::cout << "Não existe nenhum sensor com esse nome" << std::endl;
    }
  }
}

void Sala::infos_quarto()
{

  std::cout << "Nome do quarto: " << nome_ << std::endl;
  std::cout << "Quantidade de portas: " << quantidade("porta") << std::endl;
  std::cout << "Quantidade de janelas: " << quantidade("janela") << std::endl;
  std::cout << "Quantidade de lampadas: " << quantidade("lampada") << std::endl;
  std::cout << "Quantidade de tvs: " << quantidade("tv") << std::endl;
  std::cout << "Quantidade de ar-condicionados: " << quantidade("ar-condicionado") << std::endl;
  std::cout << "Quantidade de umidificadores: " << quantidade("umidificador") << std::endl;
  std::cout << "Portas: " << std::endl;
  listar("porta");
  std::cout << "Janelas: " << std::endl;
  listar("janela");
  std::cout << "Lampadas: " << std::endl;
  listar("lampada");
  std::cout << "Tvs: " << std::endl;
  listar("tv");
  std::cout << "Ar-condicionados: " << std::endl;
  listar("ar-condicionado");
  std::cout << "Umificadores: " << std::endl;
  listar("umidificador");
  
}

std::string Sala::get_sensor_associado(const std::string& nome)
{
  for(int i = 0; i < elementos_.size(); i++)
  {
    if(elementos_[i].nome == nome)
    {
      return elementos_[i].sensor_associado;
    }
    else
    {
      std::cout << "Não existe nenhum sensor com esse nome" << std::endl;
    }
  }
  return 0;
}