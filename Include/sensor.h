#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <map>
#include <string>

// Tipos de sensores:
// Umidade, Temperatura, Luminosidade, Presença, Gás, Estado Binário, e Costumizado

class sensor 
{
private:

  std::map<std::string, int> sensor_map_; // Map com o nome dos sensores e seus respectivos valores

public:

// Verifica se o nome do sensor recebido está devidamente nomeado para que se saiba o tipo de sensor e retorna true caso esteja:
bool sensor_valido(const std::string& nome_sensor);

// Adiciona um sensor com valor inicial 0:
void adicionar_sensor(const std::string& nome_sensor);

// Remove um sensor existente no map:
void remover_sensor(const std::string& nome_sensor);

// Retorna o valor do sensor:
int obter_valor_sensor(const std::string& nome_sensor);

// Atualiza o valor do sensor:
void atualizar_valor_sensor(const std::string& nome_sensor, int valor);

};

#endif