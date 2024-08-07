
#include <iostream>
#include "comodo.hpp"
  
  int comodo::quantidade(std::string tipo) const
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

  void comodo::listar(std::string tipo) const
  {
    for(int i = 0; i < elementos_.size(); i++)
    {
      if(elementos_[i].tipo == tipo)
      {
        std::cout << elementos_[i].nome << std::endl;
      }
    }
  }

  void comodo::Nomear_Elemento(int qtd, std::string tipo)
  {
    for(int i = 0; i < qtd; i++)
      {
        std::cout << "Digite o nome da " << tipo << ':' << std::endl;
        std::cin >> elementos_[i].nome;
        elementos_[i].tipo = tipo;
      }
  }

  void comodo::atribuir_sensor(const std::string& nome_sensor, const std::string& nome)
  {
    for(int i = 0; i < elementos_.size(); i++)
    {
      if(elementos_[i].nome == nome)
      {
        elementos_[i].sensor_associado = nome_sensor;
      }
    }
  }

  void comodo::remover_sensor(const std::string& nome_sensor)
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

  void comodo::info()
  {
    std::cout << "Quantidade de portas: " << quantidade("porta") << std::endl;
    std::cout << "Quantidade de janelas: " << quantidade("janela") << std::endl;
    std::cout << "Quantidade de lampadas: " << quantidade("lampada") << std::endl;
    std::cout << "Portas: " << std::endl;
    listar("porta");
    std::cout << "Janelas: " << std::endl;
    listar("janela");
    std::cout << "Lampadas: " << std::endl;
    listar("lampada");
  }

  std::string comodo::get_sensor_associado(const std::string& nome) const
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

  void comodo::remover_elemento(const std::string& nome)
  {
    for(auto it = elementos_.begin(); it != elementos_.end(); it++)
      {
        if(it->nome == nome)
        {
          elementos_.erase(it);
        }
      }
  }

void quarto::info()
{
    std::cout << "Quantidade de portas: " << quantidade("porta") << std::endl;
    std::cout << "Quantidade de janelas: " << quantidade("janela") << std::endl;
    std::cout << "Quantidade de lampadas: " << quantidade("lampada") << std::endl;
    std::cout << "Quantidade de tvs: " << quantidade("tv") << std::endl;
    std::cout << "Quantidade de ar-condicionado: " << quantidade("ar condicionado") << std::endl;
    std::cout << "Quantidade de umidificadores: " << quantidade("umidificador") << std::endl;
  
    std::cout << "Portas: " << std::endl;
    listar("porta");
    std::cout << "Janelas: " << std::endl;
    listar("janela");
    std::cout << "Lampadas: " << std::endl;
    listar("lampada");
    std::cout << "Tvs: " << std::endl;
    listar("tv");
    std::cout << "Ar-condicionado: " << std::endl;
    listar("ar condicionado");
    std::cout << "Umidificadores: " << std::endl;
    listar("umidificador");
      
}

void sala::info()
{
  std::cout << "Quantidade de portas: " << quantidade("porta") << std::endl;
  std::cout << "Quantidade de janelas: " << quantidade("janela") << std::endl;
  std::cout << "Quantidade de lampadas: " << quantidade("lampada") << std::endl;
  std::cout << "Quantidade de tvs: " << quantidade("tv") << std::endl;
  std::cout << "Quantidade de ar-condicionado: " << quantidade("ar condicionado") << std::endl;
  std::cout << "Quantidade de umidificadores: " << quantidade("umidificador") << std::endl;

  std::cout << "Portas: " << std::endl;
  listar("porta");
  std::cout << "Janelas: " << std::endl;
  listar("janela");
  std::cout << "Lampadas: " << std::endl;
  listar("lampada");
  std::cout << "Tvs: " << std::endl;
  listar("tv");
  std::cout << "Ar-condicionado: " << std::endl;
  listar("ar condicionado");
  std::cout << "Umidificadores: " << std::endl;
  listar("umidificador");
  
}

void cozinha::info()
{
  std::cout << "Quantidade de portas: " << quantidade("porta") << std::endl;
  std::cout << "Quantidade de janelas: " << quantidade("janela") << std::endl;
  std::cout << "Quantidade de lampadas: " << quantidade("lampada") << std::endl;
  std::cout << "Quantidade de ar-condicionado: " << quantidade("ar condicionado") << std::endl;
  std::cout << "Quantidade de umidificadores: " << quantidade("umidificador") << std::endl;
  std::cout << "Quantidade de fluxos de gás: " << quantidade("gas") << std::endl;

  std::cout << "Portas: " << std::endl;
  listar("porta");
  std::cout << "Janelas: " << std::endl;
  listar("janela");
  std::cout << "Lampadas: " << std::endl;
  listar("lampada");
  std::cout << "Ar-condicionado: " << std::endl;
  listar("ar condicionado");
  std::cout << "Umidificadores: " << std::endl;
  listar("umidificador");
  std::cout << "Fluxos de gás: " << std::endl;
  listar("gas");
  
}

void banheiro::info()
{
  std::cout << "Quantidade de portas: " << quantidade("porta") << std::endl;
  std::cout << "Quantidade de janelas: " << quantidade("janela") << std::endl;
  std::cout << "Quantidade de lampadas: " << quantidade("lampada") << std::endl;

  std::cout << "Portas: " << std::endl;
  listar("porta");
  std::cout << "Janelas: " << std::endl;
  listar("janela");
  std::cout << "Lampadas: " << std::endl;
  listar("lampada");
}

void garagem::info() 
{
  std::cout << "Quantidade de portas: " << quantidade("porta") << std::endl;
  std::cout << "Quantidade de janelas: " << quantidade("janela") << std::endl;
  std::cout << "Quantidade de lampadas: " << quantidade("lampada") << std::endl;

  std::cout << "Portas: " << std::endl;
  listar("porta");
  std::cout << "Janelas: " << std::endl;
  listar("janela");
  std::cout << "Lampadas: " << std::endl;
  listar("lampada");
}



