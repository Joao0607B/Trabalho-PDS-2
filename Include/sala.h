#ifndef SALA_H
#define SALA_H

#include <iostream>
#include <string>
#include <vector>

class Sala{

private:

// Nome da Sala
std::string nome_; 

// Struct com as informações de cada elemento
struct elemento
{
 std::string nome;
 std::string tipo;
 std::string sensor_associado;
};

// Vector de elementos da Sala
std::vector<Sala::elemento> elementos_; 

// Retorna a quantidade de elementos de um certo tipo
int quantidade(std::string tipo);

// Printa os nomes dos elementos existetnte na Sala de um tipo específico
void listar(std::string tipo);

public:

// Construtor quantadade de portas, janelas, lampadas, tvs ar-condicionados umidificador, cada um com um nome 
Sala(std::string nome, int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int 
       qtd_umidificador);

// Nomeia cada elemento baseadprotectedo na quantidade de cada um e seu tipo
void Nomear_Elemento(int qtd, std::string tipo);

// Atribui um sensor a um elemento da Sala
void atribuir_sensor(const std::string& nome_sensor, const std::string& nome);

// Remove um sensor de um elemento da Sala
void remover_sensor(const std::string& nome_sensor);

// Printa as informações da Sala tais como: nome da e suas quantidades de elementos
void infos_quarto();

// Retorna o nome do sensor associado ao elemento
std::string get_sensor_associado(const std::string& nome);

};

#endif