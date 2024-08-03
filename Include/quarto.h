#ifndef QUARTO_H
#define QUARTO_H

#include <iostream>
#include <string>
#include <vector>

class quarto{

protected:

// Nome do quarto
std::string nome_; 

// Struct com as informações de cada elemento
struct elemento
{
 std::string nome;
 std::string tipo;
 std::string *sensor_associado;
};

// Vector de elementos do quarto 
std::vector<quarto::elemento> elementos_; 

// Retorna a quantidade de elementos de um certo tipo  
int quantidade(std::string tipo);

// Printa os nomes dos elementos existetnte no quarto de um tipo específico
void listar(std::string tipo);

public:

// Construtor quantadade de portas, janelas, lampadas, tvs ar-condicionados umidificador, cada um com um nome 
quarto(std::string nome, int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int 
       qtd_umidificador);

// Nomeia cada elemento baseado na quantidade de cada um e seu tipo
void Nomear_Elemento(int qtd, std::string tipo);

// Atribui um sensor a um elemento do quarto
void atribuir_sensor(const std::string& nome_sensor, const std::string& nome);

// Remove um sensor de um elemento do quarto
void remover_sensor(const std::string& nome_sensor);

// Printa as informações do quarto tais como: nome do quarto e suas quantidades de elementos
void infos_quarto();

};

#endif













