#include "sensor.hpp"

using namespace std;

std::map<std::string, int> sensor::sensor_map_; // Map com o nome dos sensores no txt e seus respectivos valores
std::map<std::string, std::string> sensor::sensor_nome_map_;

bool sensor::sensor_valido(const std::string& nome_sensor) const
{
    return nome_sensor[0] == 'T' || nome_sensor[0] == 'U' || nome_sensor[0] == 'L' || (nome_sensor[0] == 'E' 
    && nome_sensor[1] == 'B') || nome_sensor[0] == 'G' || nome_sensor[0] == 'C';
}

void sensor::adicionar_sensor(const std::string& nome_sensor)
{
   if(sensor_valido(nome_sensor))
   {
     if(sensor_map_.find(nome_sensor) == sensor_map_.end())
     {
       sensor_map_[nome_sensor] = 0;
       std::cout << "Sensor adicionado com sucesso" << std::endl; 
     }
    else
    {
      std::cout << "Sensor já adicionado" << std::endl;
    }
  }
  else
  {
    std::cout << "Nome do sensor inválido" << std::endl;
  }
}

void sensor::remover_sensor(const std::string& nome_sensor)
{
  if(sensor_map_.find(nome_sensor) != sensor_map_.end())
  {
    sensor_map_.erase(nome_sensor);
    for(auto it = sensor_nome_map_.begin(); it != sensor_nome_map_.end(); ++it)
      {
        if(it->second == nome_sensor)
        {
          sensor_nome_map_.erase(it);
        }
      }
      std::cout << "Sensor removido com sucesso" << std::endl;
  }
  else if(sensor_nome_map_.find(nome_sensor) != sensor_nome_map_.end())
  {
    std::string aux = sensor_nome_map_.at(nome_sensor);
    sensor_nome_map_.erase(nome_sensor);
    sensor_map_.erase(aux);
    std::cout << "Sensor removido com sucesso" << std::endl;
  }
  else
  {
    std::cout << "Sensor não encontrado" << std::endl;
  }
}

int sensor::obter_valor_sensor(const std::string& nome_sensor) 
{
  if(sensor_map_.find(nome_sensor) != sensor_map_.end())
  {
    return sensor_map_[nome_sensor];
  }
  else if(sensor_nome_map_.find(nome_sensor) != sensor_nome_map_.end())
  {
    string aux = sensor_nome_map_.at(nome_sensor);
    return sensor_map_[aux];
  }
  else
  {
    std::cout << "Sensor não encontrado" << std::endl;
  }
  return 0;
}

void sensor::atualizar_valor_sensor(const std::string& nome_sensor, int valor)
{
  if(sensor_map_.find(nome_sensor) != sensor_map_.end())
  {
    sensor_map_[nome_sensor] = valor;
  }
  else if(sensor_nome_map_.find(nome_sensor) != sensor_nome_map_.end())
  {
    string aux = sensor_nome_map_.at(nome_sensor);
    sensor_map_[aux] = valor;
  }
  else
  {
    std::cout << "Sensor não encontrado" << std::endl;
  }
}

void sensor::atualizar_nome_sensor(const std::string& nome_antigo_sensor, const std::string& novo_nome)
{
  if(sensor_nome_map_.find(nome_antigo_sensor) != sensor_nome_map_.end())
  {
    auto it = sensor_nome_map_.find(nome_antigo_sensor); 
    sensor_nome_map_[novo_nome] = it->second;
    sensor_nome_map_.erase(it);
  }
  else
  {
    std::cout << "Sensor não existente" << std::endl;
  }
}

void sensor::atribuir_nome_sensor(const std::string& nome_sensor, const std::string& nome)
{
  if(sensor_map_.find(nome_sensor) != sensor_map_.end())
  {
    sensor_nome_map_[nome] = nome_sensor;
  }
  else
  {
    std::cout << "Sensor não adicionado" << std::endl;
  }
}

std::string sensor::obter_nome_sensor(const std::string& nome_sensor)
{
  for(auto it = sensor_nome_map_.begin(); it != sensor_nome_map_.end(); ++it)
    {
      if(it->second == nome_sensor)
      {
        return it->first;
      }
      else
      {
        std::cout << "Sensor não encontrado" << std::endl;
      }
    }
  return "";
}

void sensor::listar_sensores_txt()
{
  for(auto it = sensor_map_.begin(); it != sensor_map_.end(); ++it)
    {
      std::cout << it->first << std::endl;
    }
}

void sensor::listar_sensores()
{
  for(auto it = sensor_nome_map_.begin(); it != sensor_nome_map_.end(); it++)
    {
      std::cout << it->first << std::endl;
    }
}

