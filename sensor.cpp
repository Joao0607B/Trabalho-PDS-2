#include "sensor.h"

bool sensor::sensor_valido(const std::string& nome_sensor)
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
     }
    else
    {
      std::cout << "Sensor já adicionado" << std::endl;
    }
  }
  else
  {
    std::cout << "Sensor inválido" << std::endl;
  }
}
  

void sensor::remover_sensor(const std::string& nome_sensor)
{
  if(sensor_map_.find(nome_sensor) != sensor_map_.end())
  {
    sensor_map_.erase(nome_sensor);
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
  else
  {
    std::cout << "Sensor não encontrado" << std::endl;
  }
}

