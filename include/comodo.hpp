#ifndef COMODO_H
#define COMODO_H
#include <iostream>
#include <string>
#include <vector>

class comodo
{
  protected:


// Struct com as informações de cada elemento
struct elemento
{
 std::string nome;
 std::string tipo;
 std::string sensor_associado;
};

// Vector de elementos do comodo
std::vector<comodo::elemento> elementos_; 

// Retorna a quantidade de elementos de um certo tipo  
int quantidade(std::string tipo) const;

// Printa os nomes dos elementos existetnte no comodo de um tipo específico
void listar(std::string tipo) const;

public:

//Construtor
comodo(int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int qtd_umidificador, int qtd_gas)
{
  Nomear_Elemento(qtd_portas,"porta");
  Nomear_Elemento(qtd_janelas,"janela");
  Nomear_Elemento(qtd_lampadas,"lampada");
  Nomear_Elemento(qtd_tvs,"tv");
  Nomear_Elemento(qtd_ar_condicionado,"ar_condicionado");
  Nomear_Elemento(qtd_umidificador,"umidificador");
  Nomear_Elemento(qtd_gas,"gas");
}

comodo() : comodo(0, 0, 0, 0, 0, 0, 0) {
}

// Nomeia cada elemento baseado na quantidade de cada um e seu tipo
void Nomear_Elemento(int qtd, std::string tipo);

// Atribui um sensor a um elemento do quarto
void atribuir_sensor(const std::string& nome_sensor, const std::string& nome);

// Remove um sensor de um elemento do quarto
void remover_sensor(const std::string& nome_sensor);

// Printa as informações do quarto tais como: suas quantidades de elementos e respectivos nomes
virtual void info();

// Retorna o nome do sensor associado ao elemento
std::string get_sensor_associado(const std::string& nome) const;

void remover_elemento(const std::string& nome);

  
};

class quarto : public comodo
{
  public:
  quarto(int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int qtd_umidificador) 
    : comodo(qtd_portas, qtd_janelas, qtd_lampadas, qtd_tvs, qtd_ar_condicionado, qtd_umidificador, 0) {
}
    void info() override;  
};

class cozinha : public comodo
{
  public:
    cozinha(int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_ar_condicionado, int qtd_umidificador, int qtd_gas)
: comodo(qtd_portas, qtd_janelas, qtd_lampadas, 0, qtd_ar_condicionado, qtd_umidificador, qtd_gas) {
}
    void info() override;
};

class sala : public comodo
{
  public:
     sala(int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int qtd_umidificador) 
    : comodo(qtd_portas, qtd_janelas, qtd_lampadas, qtd_tvs, qtd_ar_condicionado, qtd_umidificador, 0) {
}
    void info() override;
};

class banheiro : public comodo
{
  public:
  banheiro(int qtd_portas, int qtd_janelas, int qtd_lampadas) 
    : comodo(qtd_portas, qtd_janelas, qtd_lampadas, 0, 0, 0, 0) {
}

  void info() override;
};

class garagem : public comodo
{
  public:
  garagem(int qtd_portas, int qtd_janelas, int qtd_lampadas) 
    : comodo(qtd_portas, qtd_janelas, qtd_lampadas, 0, 0, 0, 0) {
}

  void info() override;
};
#endif
