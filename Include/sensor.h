#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <map>
#include <string>

// Tipos de sensores:
// Umidade, Temperatura, Luminosidade, Presença, Gás, Estado Binário

class sensor 
{
private:

  std::map<std::string, int> sensor_map_; // Map com o nome dos sensores no txt e seus respectivos valores
  std::map<std::string, std::string> sensor_nome_map_; // Map com o nome dos sensores e seus respectivos nomes no txt (first = nome do sensor second = nome txt)

public:

// Verifica se o nome do sensor recebido do txt está devidamente nomeado para que se saiba o tipo de sensor e retorna true caso esteja:
bool sensor_valido(const std::string& nome_sensor);

// Adiciona um sensor a partir do txt com valor inicial 0 e e nome "Não atribuido";
void adicionar_sensor(const std::string& nome_sensor);

// Remove um sensor existente nos dois map:
void remover_sensor(const std::string& nome_sensor);

// Retorna o valor do sensor caso exista ou retorna 0 caso contrário:
int obter_valor_sensor(const std::string& nome_sensor);

// Atualiza o valor do sensor:
void atualizar_valor_sensor(const std::string& nome_sensor, int valor);

// Atualiza o nome do sensor:
void atualizar_nome_sensor(const std::string& nome_antigo_sensor, const std::string& novo_nome);

// Associa um nome dado ao sensor pelo usuário a um sensor vindo do txt
void atribuir_nome_sensor(const std::string& nome_sensor, const std::string& nome);

};

#endif
