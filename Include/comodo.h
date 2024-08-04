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

// Printa os nomes dos elementos existetnte no quarto de um tipo específico
void listar(std::string tipo) const;

public:

//Construtor da classe principal
comodo(int qtd_portas, int qtd_janelas, int qtd_lampadas);

// Nomeia cada elemento baseado na quantidade de cada um e seu tipo
void Nomear_Elemento(int qtd, std::string tipo);

// Atribui um sensor à um elemento do quarto
void atribuir_sensor(const std::string& nome_sensor, const std::string& nome);

// Remove um sensor de um elemento do quarto
void remover_sensor(const std::string& nome_sensor);

// Printa as informações do quarto tais como: suas quantidades de elementos presentes e respectivos nomes
void info(std::vector<comodo::elemento> comodos) const;

// Retorna o nome do sensor associado ao elemento
std::string get_sensor_associado(const std::string& nome) const; 

  
};

class quarto : public comodo
{
  public:
    //Construtor da classe derivada da classe base "comodo"
    quarto (int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int qtd_umidificador) : comodo(qtd_portas, qtd_janelas, 
             qtd_lampadas)
    {
      Nomear_Elemento(qtd_tvs, "tv");
      Nomear_Elemento(qtd_ar_condicionado, "ar_condicionado"); //Possibilita nomear os objetos conforme solicitado
      Nomear_Elemento(qtd_umidificador, "umidificador");
    }

    void info(std::vector<comodo::elemento> comodos) const;  
};

class cozinha : public comodo
{
  public:
    //Construtor da classe derivada da classe base "comodo"
    cozinha(int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_gas, int qtd_ar_condicionado, int qtd_umidificador) : comodo(qtd_portas, qtd_janelas, 
            qtd_lampadas)
    {
      Nomear_Elemento(qtd_ar_condicionado, "ar_condicionado"); //Possibilita nomear os objetos conforme solicitado
      Nomear_Elemento(qtd_umidificador, "umidificador"); 
      Nomear_Elemento(qtd_gas, "gas");  
    }

    void info(std::vector<comodo::elemento> comodos) const;
};

class sala : public comodo
{
  public:
    //Construtor da classe derivada da classe base "comodo"
     sala(int qtd_portas, int qtd_janelas, int qtd_lampadas, int qtd_tvs, int qtd_ar_condicionado, int qtd_umidificador) : comodo(qtd_portas, qtd_janelas, 
          qtd_lampadas)
     {
       Nomear_Elemento(qtd_tvs, "tv");
       Nomear_Elemento(qtd_ar_condicionado, "ar_condicionado"); //Possibilita nomear os objetos conforme solicitado
       Nomear_Elemento(qtd_umidificador, "umidificador");
     }

    void info(std::vector<comodo::elemento> comodos) const;
};

class banheiro : public comodo{
    //Construtor da classe derivada da classe base "comodo"
  banheiro(int qtd_portas, int qtd_janelas, int qtd_lampadas) : comodo(qtd_portas, qtd_janelas, qtd_lampadas){}

  void info(std::vector<comodo::elemento> comodos) const;
};

class garagem : public comodo
{    //Construtor da classe derivada da classe base "comodo"
  garagem(int qtd_portas, int qtd_janelas, int qtd_lampadas) : comodo(qtd_portas, qtd_janelas, qtd_lampadas) {}

  void info(std::vector<comodo::elemento> comodos) const;
};
