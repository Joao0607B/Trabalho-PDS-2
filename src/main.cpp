#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include "usuario.hpp"
#include "sensor.hpp"
#include "comodo.hpp"
#include "automacao.hpp"

  std::string usuario_logado, nome_txt;
  std::map<std::string, double> all_sensor;
  std::map<std::string, comodo> comodos;
  std::map<const std::string, automacao> automacoes;
  std::string nome_comodo_2;
  int desligar = 1;

std::vector<std::string> splitStringBySpace(const std::string& str) {
    std::vector<std::string> elements;
    std::istringstream iss(str);
    std::string item;

    // Lê cada elemento separado por espaço e adiciona ao vetor
    while (iss >> item) {
        elements.push_back(item);
    }

    return elements;
}

double stringToDouble(const std::string& str) 
{
        return std::stod(str);
}



void Lista_TXT(const std::string& nomeArquivo) {
    // Cria um objeto ifstream para ler o arquivo
    std::ifstream arquivo(nomeArquivo);

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
        return;
    }

  std::string linha;
  std::string key;
  double value;
  // Lê o arquivo linha por linha
  while (getline(arquivo, linha)) {

     key = splitStringBySpace(linha)[0];
     value = stringToDouble(splitStringBySpace(linha)[1]);
     all_sensor[key] = value;
    std::cout << linha << std::endl;
  }

  // Fecha o arquivo
  arquivo.close();
}


void clearScreen() {
    // Comando ANSI para limpar a tela
    std::cout << "\033[2J\033[1;1H";
}

std::string cadastro(bool user)
{
  std::string login, senha, senha_confirma, pergunta_seguranca, resposta_seguranca;
  bool senha_coincide = false;
  if(!user) //Cadastro do Admin
  {
    std::cout << "Realizar o Cadastro da conta Administradora" << std::endl;
    sleep(1);
    std::cout << "Insira o seu nome de usuário(login): " << std::endl;
    std::cin >> login;
    sleep(1);
    while(!senha_coincide)
    {
      std::cout << "Insira a sua senha : " << std::endl;
      std::cin >> senha;
      std::cout << "Confirme sua senha: " << std::endl;
      std::cin >> senha_confirma;
      if(senha == senha_confirma)
      {
        senha_coincide = true;
      }
      else
      {
        std::cout << "Senhas Não Coincidentes, repita as senhas" << std::endl;
      }
    }
    std::cout << "Insira uma pergunta de segurança para recuperar sua senha em caso de esquecimento" << std::endl;
    std::cin >> pergunta_seguranca;
    std::cout << "Insira a resposta para a pergunta de segurança: " << std::endl;
    std::cin >> resposta_seguranca;
    Usuario a;
    a.inserir(login, senha, 1, pergunta_seguranca, resposta_seguranca);
    std::cout << "Insira o nome do arquivo txt que conterá as informações dos sensores: " << std::endl;
    std::cin >> nome_txt;
    std::cout << "Cadastro Realizado com sucesso" << std::endl;
  }
  else // Cadastro do usuário
  {
    std::cout << "Realizar o Cadastro da conta" << std::endl;
    sleep(1);
    std::cout << "Insira o seu nome de usuário(login): " << std::endl;
    std::cin >> login;
    sleep(1);
    while(!senha_coincide)
    {
      std::cout << "Insira a sua senha : " << std::endl;
      std::cin >> senha;
      std::cout << "Confirme sua senha: " << std::endl;
      std::cin >> senha_confirma;
      if(senha == senha_confirma)
      {
        senha_coincide = true;
      }
      else
      {
        std::cout << "Senhas Não Coincidentes, repita as senhas" << std::endl;
      }
    }
    std::cout << "Insira uma pergunta de segurança para recuperar sua senha em caso de esquecimento" << std::endl;
    std::cin >> pergunta_seguranca;
    std::cout << "Insira a resposta para a pergunta de segurança: " << std::endl;
    std::cin >> resposta_seguranca;
    Usuario b;
    b.inserir(login, senha, 4, pergunta_seguranca, resposta_seguranca);
    usuario_logado = login;
    std::cout << "Cadastro Realizado com sucesso" << std::endl;
  }
 return login;
}

std::string login()
{
  std::string login, senha, resposta;
  Usuario usuario_l;
  char yes_no;
  int count = 0;


  while(1)
    {
      std::cout << "Insira o seu login: " << std::endl;
      std::cin >> login;
      std::cout << "Insira a sua senha: " << std::endl;
      std::cin >> senha;
      
      if (senha == usuario_l.get_senha(login))
      {
        std::cout << "Login efetuado com sucesso" << std::endl;
        return login;
      }
      else
      {
        std::cout << "Login ou senha incorretos" << std::endl;
        count++;
      }
      if(count > 3)
      {
        std::cout << "Deseja recuperar sua senha? (s/n)" << std::endl;
        std::cin >> yes_no;
      }
      if(yes_no == 's'|| yes_no == 'S')
      {
        count = 0;
        std::cout << usuario_l.get_pergunta(login) << std::endl;
        std:: cin >> resposta;
        usuario_l.esqueciasenha(login, resposta);
        return login;
      }
    }
  return "";
}

void menu(int permissao)
{
  int escolha = 0;
  Usuario usuario_menu;
  sensor sensor_menu;
  automacao automacao_menu;

  if(permissao == 1) // Admin
  {
    clearScreen();
    std::cout << "1.Ver Usuários cadastrados    2.Alterar nivel de permissão de um usuário" << std::endl;
    std::cout << "3.Excluir um usuário          4.Adicionar sensor" << std::endl;
    std::cout << "5.Remover sensor              6.Nomear Sensores" << std::endl;
    std::cout << "7.Ver sensores                8.Acessar cômodo" << std::endl;
    std::cout << "9.Ver cômodos                 10.Criar cômodo" << std::endl;
    std::cout << "11.Remover Cômodo             12.Ver automações" << std::endl;
    std::cout << "13.Remover automação          14.Criar automação" << std::endl;
    std::cout << "15.Deslogar" << std::endl;

    std::cin >> escolha;
    switch(escolha)
    {
      case 1:{
        clearScreen();
        usuario_menu.printInfos();
        break;
      }
      case 2:{
        clearScreen();
        std::string login;
        int nivel_permissao;
        std::cout << "Qual o login do usuário que deseja alterar o nivel de permissão?" << std::endl;
        std::cin >> login;
        std::cout << "Qual o novo nivel de permissão?" << std::endl;
        std::cin >> nivel_permissao;
        usuario_menu.alteranivel(usuario_logado, login, nivel_permissao);
        clearScreen();
        break;
      }
      case 3:{
        clearScreen();
        std::string login_excluir;
        std::cout << "Qual o login do usuário que deseja excluir?" << std::endl;
        std::cin >> login_excluir;
        usuario_menu.remover(login_excluir);
        clearScreen();
        break;
      }
      case 4:{
        clearScreen();
        Lista_TXT(nome_txt);
        char yes_no;
        std::cout << "Deseja adicionar algum desses sensores? (s/n)" << std::endl;
        std::cin >> yes_no;
        if(yes_no == 's' || yes_no == 'S')
        {
          std::string nome_sensor;
          std::cout << "Digite o nome do sensor, assim como está no TXT, que deseje adicionar: " << std::endl;
          std::cin >> nome_sensor;
          sensor_menu.adicionar_sensor(nome_sensor);
        }  
        break;
      }
      case 5:{
        clearScreen();
        std::string nome_sensor_remover;
        std::cout << "Digite o nome do sensor que deseja remover: " << std::endl;
        std::cin >> nome_sensor_remover;
        sensor_menu.remover_sensor(nome_sensor_remover);
        break;
      }
      case 6:{
        clearScreen();
        std::string sensor_id, nome_sensor;
        std::cout << "Digite o nome do sensor do txt que deseja atribuir a um outro nome: " << std::endl;
        std::cin >> sensor_id;
        std::cout << "Digite o novo nome do sensor: " << std::endl;
        std::cin >> nome_sensor;
        sensor_menu.atribuir_nome_sensor(sensor_id, nome_sensor);
        break;
      }
      case 7:{
        clearScreen();
        std::cout << "Sensores adicionados do TXT" << std::endl;
        sensor_menu.listar_sensores_txt();
        std::cout << "Sensores atribuidos nomes: " << std::endl;
        sensor_menu.listar_sensores();
        break;
      }
      case 8:{
        clearScreen();
        std::string nome_comodo_2;
        int escolha_2 = 0;
        std::cout << "Digite o nome do cômodo que deseja acessar: " << std::endl;
        std::cin >> nome_comodo_2;
        std::cout << "O que deseja acessar do cômodo? " << std::endl;
        std::cout << "1.Ver informações do cômodo     2.Atribuir um sensor a um elemento do cômodo específico 3.Remover sensor associado a um elemento do cômodo" << std::endl;
        std::cout << "4.Adicionar elementos ao cômodo 5. Remover elementos do cômodo      6.Saber se um sensor está associado a um elemento específico do cômodo" << std::endl; 
        std::cin >> escolha_2;
        clearScreen();
        if(escolha_2 == 1)
        {
          auto it = comodos.find(nome_comodo_2);
          if (it != comodos.end()){
            it->second.info();
          } 
          break;
        } 

        else if(escolha_2 == 2)
        {
            std::string nome_sensor_2;
            std::cout << "Digite o nome do sensor que deseja atribuir a um elemento do cômodo: " << std::endl;
            std::cin >> nome_sensor_2;
            comodos.find(nome_comodo_2)->second.atribuir_sensor(nome_sensor_2, nome_comodo_2);
            break;
        } 

        else if(escolha_2 == 3)
        {
            std::string nome_sensor_remover;
            std::cout << "Digite o nome do sensor que deseja remover do elemento do cômodo: " << std::endl;
            std::cin >> nome_sensor_remover;
            comodos.find(nome_comodo_2)->second.remover_sensor(nome_sensor_remover);
            break;
        }

        else if(escolha_2 == 4)
        {
              std::string tipo;
              std::cout << "Digite o nome do cômodo que deseja adicionar elementos: " << std::endl;
              std::cin >> nome_comodo_2;
              std::cout << "Digite o tipo do elemento que deseja adicionar: " << std::endl;
              std::cin >> tipo;
              comodos.find(nome_comodo_2)->second.Nomear_Elemento(1, tipo);
              break;
        } 

        else if (escolha_2 == 5)
        {
              std::string nome_comodo_2, nome_elemento;
              std::cout << "Digite o nome do elemento que deseja remover elementos: " << std::endl;
              std::cin >> nome_elemento;
              comodos.find(nome_comodo_2)->second.remover_elemento(nome_elemento);
              break;
        } 
 
        else if(escolha_2 == 6)
        {
              std::string nome_comodo_2, nome_elemento;
              std::cout << "Digite o nome do elemento que deseja saber se está associado a um sensor: " << std::endl;
              std::cin >> nome_elemento;
              comodos.find(nome_comodo_2)->second.get_sensor_associado(nome_elemento);
              break;
        }

        else
        {
          std::cout << "Opção inválida" << std::endl;
        }
        break;
      }
      case 9:{
        clearScreen();
        for (const auto& a : comodos) {
        std::cout << "Nome do comodo: " << a.first << std::endl;
        }
        break;
      }
      case 10:{
        std::string nome_comodo_3;
        int qtd_portas = 0, qtd_janelas = 0, qtd_lampadas = 0, qtd_tvs = 0, qtd_ar_condicionado = 0, qtd_umidificador = 0, qtd_gas = 0;
        int escolha_3 = 0;
        clearScreen();
        std::cout << "Qual tipo de cômodo, você deseja inserir?" << std::endl;
        std::cout << "1.Quarto    2.Cozinha 3.Banheiro" << std::endl;
        std::cout << "4.Garagem   5. Sala" << std::endl; 
        std::cin >> escolha_3;
        clearScreen();

        if(escolha_3 == 1)
        {
          std::cout << "Digite o nome do novo quarto: " << std::endl;
          std::cin >> nome_comodo_3;
          std::cout << "Digite a quantidade de portas: ";
          std::cin >> qtd_portas;
          std::cout << "Digite a quantidade de janelas: ";
          std::cin >> qtd_janelas;
          std::cout << "Digite a quantidade de lâmpadas: ";
          std::cin >> qtd_lampadas;
          std::cout << "Digite a quantidade de TVs: ";
          std::cin >> qtd_tvs;
          std::cout << "Digite a quantidade de ar-condicionados: ";
          std::cin >> qtd_ar_condicionado;
          std::cout << "Digite a quantidade de umidificadores: ";
          std::cin >> qtd_umidificador;

          quarto novoquarto(qtd_portas, qtd_janelas, qtd_lampadas, qtd_tvs, qtd_ar_condicionado, qtd_umidificador);
          comodos[nome_comodo_3] = novoquarto;
          break;
        } 

        else if(escolha_3 == 2)
        {
            std::cout << "Digite o nome da nova cozinha: " << std::endl;
            std::cin >> nome_comodo_3;
            std::cout << "Digite a quantidade de portas: ";
            std::cin >> qtd_portas;
            std::cout << "Digite a quantidade de janelas: ";
            std::cin >> qtd_janelas;
            std::cout << "Digite a quantidade de lâmpadas: ";
            std::cin >> qtd_lampadas;
            std::cout << "Digite a quantidade de ar-condicionados: ";
            std::cin >> qtd_ar_condicionado;
            std::cout << "Digite a quantidade de umidificadores: ";
            std::cin >> qtd_umidificador;
            std::cout << "Digite a quantidade de fluxos de gás: ";
            std::cin >> qtd_gas;
            
            cozinha novacozinha(qtd_portas, qtd_janelas, qtd_lampadas, qtd_ar_condicionado, qtd_umidificador, qtd_gas);
            comodos[nome_comodo_3] = novacozinha; 
            break;
        } 

        else if(escolha_3 == 3)
        {
            std::cout << "Digite o nome do novo banheiro: " << std::endl;
            std::cin >> nome_comodo_3;
            std::cout << "Digite a quantidade de portas: ";
            std::cin >> qtd_portas;
            std::cout << "Digite a quantidade de janelas: ";
            std::cin >> qtd_janelas;
            std::cout << "Digite a quantidade de lâmpadas: ";
            std::cin >> qtd_lampadas;

            banheiro novobanheiro(qtd_portas, qtd_janelas, qtd_lampadas);
            comodos[nome_comodo_3] = novobanheiro;
            break;
        }

        else if(escolha_3 == 4)
        {
            std::cout << "Digite o nome da nova garagem: " << std::endl;
            std::cin >> nome_comodo_3;
            std::cout << "Digite a quantidade de portas: ";
            std::cin >> qtd_portas;
            std::cout << "Digite a quantidade de janelas: ";
            std::cin >> qtd_janelas;
            std::cout << "Digite a quantidade de lâmpadas: ";
            std::cin >> qtd_lampadas;

            garagem novagaragem(qtd_portas, qtd_janelas, qtd_lampadas);
            comodos[nome_comodo_3] = novagaragem; 
            break;
        } 

        else if (escolha_3 == 5)
        {
            std::cout << "Digite o nome da nova sala: " << std::endl;
            std::cin >> nome_comodo_3;
            std::cout << "Digite a quantidade de portas: ";
            std::cin >> qtd_portas;
            std::cout << "Digite a quantidade de janelas: ";
            std::cin >> qtd_janelas;
            std::cout << "Digite a quantidade de lâmpadas: ";
            std::cin >> qtd_lampadas;
            std::cout << "Digite a quantidade de TVs: ";
            std::cin >> qtd_tvs;
            std::cout << "Digite a quantidade de ar-condicionados: ";
            std::cin >> qtd_ar_condicionado;
            std::cout << "Digite a quantidade de umidificadores: ";
            std::cin >> qtd_umidificador;
            sala novasala(qtd_portas, qtd_janelas, qtd_lampadas, qtd_tvs, qtd_ar_condicionado, qtd_umidificador);
            comodos[nome_comodo_3] = novasala;
            break;
        } 

        else
        {
          std::cout << "Opção inválida" << std::endl;
        }
        break;
      }
      case 11:{
        std::string nome_comodo_remover;
        std::cout << "Digite o nome do cômodo que deseja remover: ";
        std::cin >> nome_comodo_remover;

        auto it = comodos.find(nome_comodo_remover);
        if (it != comodos.end()) {
          comodos.erase(it);
          std::cout << "Cômodo " << nome_comodo_remover << " removido com sucesso." << std::endl;
        } 
        else {
          std::cout << "Cômodo não encontrado." << std::endl;
        }
        break;
      }
      case 12:{
        clearScreen();
        automacao_menu.listar_automacoes();
        break;
      }
      case 13:{
        clearScreen();
        std::string nome_automacao_remover;
        std::cout << "Digite o nome da automacao que deseja remover: " << std::endl;
        std::cin >> nome_automacao_remover;
        automacao_menu.remover_automacao(nome_automacao_remover);
        break;
      }
      case 14:{
        clearScreen();
        std::string nome_comodo_4;
        std::cout << "Digite o nome do cômodo que deseja atribuir um sensor: " << std::endl;
        std::cin >> nome_comodo_4;
        std::string nome_sensor_2;
        std::cout << "Digite o nome do sensor que deseja atribuir a um elemento do cômodo: " << std::endl;
        std::cin >> nome_sensor_2;
        std::string nome_elemento_2;
        comodos.find(nome_comodo_4)->second.info();
        std::cout << "Digite o nome do elemento que deseja atribuir o sensor: " << std::endl;
        std::cin >> nome_elemento_2;
        comodos.find(nome_comodo_4)->second.atribuir_sensor(nome_sensor_2, nome_elemento_2);
        clearScreen();
        int escolha_2;
        std::cout << "Qual tipo de automação deseja realizar?" << std::endl;
        std::cout << "1.Maior 2.Menor 3.Igual 4.Maior ou Igual 5.Menor ou Igual" << std::endl;
        std::cin >> escolha_2;
        
        if(escolha_2 == 1)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "maior", limite); 
          break;
        }
        else if(escolha_2 == 2)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "menor", limite); 
          break;
        }
        else if(escolha_2 == 3)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "igual", limite); 
          break;
        }
        else if(escolha_2 == 4)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "maior ou igual", limite);
          break;
        }
        else if(escolha_2 == 5)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "menor ou igual", limite); 
          break;
        }
        else
        {
          std::cout << "Opção inválida" << std::endl;
        }
        break;
      }
      case 15:{
        clearScreen();
        char yes_no;
        cout << "Você realmente deseja deslogar de sua conta? (s/n)" << endl;
        cin >> yes_no;
        if(yes_no == 's' || yes_no == 'S'){
          usuario_logado = "";
          desligar = 2;
          return;
        }
        break;
      }
      default:
      std::cout << "Opção inválida" << std::endl;
    }  
  }
  else // Usuário
  {
    std::cout << "1.Ver Usuários cadastrados    2.Ver sensores" << std::endl;
    std::cout << "3.Acessar cômodos             4.Ver cômodos" << std::endl;             
    std::cout << "5.Ver automação               6.Remover automações" << std::endl;
    std::cout << "7.Criar automação             8.Deslogar" << std::endl;    

    std::cin >> escolha;
    switch(escolha){
      case 1:{
        clearScreen();
        usuario_menu.printInfos();
        break;
      }
      case 2:{
        clearScreen();
        std::cout << "Sensores adicionados do TXT" << std::endl;
        sensor_menu.listar_sensores_txt();
        std::cout << "Sensores atribuidos nomes: " << std::endl;
        sensor_menu.listar_sensores();
        break;
      }
      case 3:{
        clearScreen();
        std::string nome_comodo_2;
        int escolha_2 = 0;
        std::cout << "Digite o nome do cômodo que deseja acessar: " << std::endl;
        std::cin >> nome_comodo_2;
        std::cout << "O que deseja acessar do cômodo? " << std::endl;
        std::cout << "1.Ver informações do cômodo     2.Atribuir um sensor a um elemento do cômodo específico 3.Remover sensor associado a um elemento do cômodo" << std::endl;
        std::cout << "4.Adicionar elementos ao cômodo 5. Remover elementos do cômodo      6.Saber se um sensor está associado a um elemento específico do cômodo" << std::endl; 
        std::cin >> escolha_2;
        clearScreen();
        if(escolha_2 == 1)
        {
          auto it = comodos.find(nome_comodo_2);
          if (it != comodos.end()){
            it->second.info(); 
          } 
          break;
        } 

        else if(escolha_2 == 2)
        {
            std::string nome_sensor_2;
            std::cout << "Digite o nome do sensor que deseja atribuir a um elemento do cômodo: " << std::endl;
            std::cin >> nome_sensor_2;
            comodos.find(nome_comodo_2)->second.atribuir_sensor(nome_sensor_2, nome_comodo_2);
            break;
        } 

        else if(escolha_2 == 3)
        {
            std::string nome_sensor_remover;
            std::cout << "Digite o nome do sensor que deseja remover do elemento do cômodo: " << std::endl;
            std::cin >> nome_sensor_remover;
            comodos.find(nome_comodo_2)->second.remover_sensor(nome_sensor_remover);
            break;
        }

        else if(escolha_2 == 4)
        {
              std::string tipo;
              std::cout << "Digite o nome do cômodo que deseja adicionar elementos: " << std::endl;
              std::cin >> nome_comodo_2;
              std::cout << "Digite o tipo do elemento que deseja adicionar: " << std::endl;
              std::cin >> tipo;
              comodos.find(nome_comodo_2)->second.Nomear_Elemento(1, tipo);
              break;
        } 

        else if (escolha_2 == 5)
        {
              std::string nome_comodo_2, nome_elemento;
              std::cout << "Digite o nome do elemento que deseja remover elementos: " << std::endl;
              std::cin >> nome_elemento;
              comodos.find(nome_comodo_2)->second.remover_elemento(nome_elemento);
              break;
        } 

        else if(escolha_2 == 6)
        {
              std::string nome_comodo_2, nome_elemento;
              std::cout << "Digite o nome do elemento que deseja saber se está associado a um sensor: " << std::endl;
              std::cin >> nome_elemento;
              comodos.find(nome_comodo_2)->second.get_sensor_associado(nome_elemento);
              break;
        }

        else
        {
          std::cout << "Opção inválida" << std::endl;
        }
        break;
      }
      case 4:{
        clearScreen();
        for (const auto& a : comodos) {
        std::cout << "Nome do comodo: " << a.first << std::endl;
        }
        break;
      }
      case 5:{
        clearScreen();
        automacao_menu.listar_automacoes();
        break;
      }
      case 6:{
        clearScreen();
        std::string nome_automacao_remover;
        std::cout << "Digite o nome da automacao que deseja remover: " << std::endl;
        std::cin >> nome_automacao_remover;
        automacao_menu.remover_automacao(nome_automacao_remover);
        break;
      }
      case 7:{
        clearScreen();
        std::string nome_comodo_4;
        std::cout << "Digite o nome do cômodo que deseja atribuir um sensor: " << std::endl;
        std::cin >> nome_comodo_4;
        std::string nome_sensor_2;
        std::cout << "Digite o nome do sensor que deseja atribuir a um elemento do cômodo: " << std::endl;
        std::cin >> nome_sensor_2;
        std::string nome_elemento_2;
        comodos.find(nome_comodo_4)->second.info(); 
        std::cout << "Digite o nome do elemento que deseja atribuir o sensor: " << std::endl;
        std::cin >> nome_elemento_2;
        comodos.find(nome_comodo_4)->second.atribuir_sensor(nome_sensor_2, nome_elemento_2);
        clearScreen();
        int escolha_2;
        std::cout << "Qual tipo de automação deseja realizar?" << std::endl;
        std::cout << "1.Maior 2.Menor 3.Igual 4.Maior ou Igual 5.Menor ou Igual" << std::endl;
        std::cin >> escolha_2;
        
        if(escolha_2 == 1)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "maior", limite); 
          break;
        }
        else if(escolha_2 == 2)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "menor", limite); 
          break;
        }
        else if(escolha_2 == 3)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "igual", limite); 
          break;
        }
        else if(escolha_2 == 4)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "maior ou igual", limite); 
          break;
        }
        else if(escolha_2 == 5)
        {
          std::string nome_automacao;
          std::cout << "Digite o nome da automação que deseja criar: " << std::endl;
          std::cin >> nome_automacao;
          double limite;
          std::cout << "Digite o limite da automação: " << std::endl;
          std::cin >> limite;
          automacao_menu.criar_automacao(nome_automacao, nome_elemento_2, "menor ou igual", limite); 
          break;
        }
        else
        {
          std::cout << "Opção inválida" << std::endl;
        }
        break;
      }
      case 8:{
        clearScreen();
        char yes_no;
        cout << "Você realmente deseja deslogar de sua conta? (s/n)" << endl;
        cin >> yes_no;
        if(yes_no == 's' || yes_no == 'S'){
          usuario_logado = "";
          desligar = 2;
          return;
        }
        break;
      }
        default:
        std::cout << "Opção inválida" << std::endl;
    }       
  } 
}

int main()
{
  int loop = 1;
  Usuario usario_main;
  automacao automacao_main;

  while(loop == 1)
  {
    clearScreen();
    std::cout << "Seja Bem Vindo a Smart Haus!" << std::endl;
    std::cout << "Aqui você poderá integrar diversor sistemas de automação e controle remoto!" << std::endl;
    std::cout << "Para começar, escolha uma das opções abaixo:" << std::endl;

    if(usario_main.existeAdmin())
    {
    int resposta;
    do
    {
      resposta = 0;
      std::cout << "1. Realizar o Cadastro de um novo Usuário    2.Realizar login em um usuário já existente" << std::endl;
      std::cin >> resposta;
        if (resposta == 1)
        {
          usuario_logado = cadastro(usario_main.existeAdmin());
          resposta = 4;
        }
        else if(resposta == 2)
        {
          usuario_logado = login();
          resposta = 4;
        }
        else
        {
          std::cout << "Opção inválida" << std::endl;
          clearScreen();
        }
    } while(resposta > 0 && resposta < 3);

    } 
    else //Cadastro do admin
    {
      usuario_logado = cadastro(usario_main.existeAdmin());
    }
    std::cout << "Bem vindo, " << usuario_logado << std::endl;
    std::cout << "O que deseja fazer?" << std::endl;

    desligar = 1;

    while (desligar == 1)
    {
      menu(usario_main.get_nivel(usuario_logado));
     
      
      for(auto it = automacoes.begin(); it != automacoes.end(); it++)
        {
          //double valor = sensor::obter_valor_sensor(it->second.get_sensor_associado(it->second.get_nome_automacao(it->first)));
          //automacao_main.usar_automacao(it->first, valor);
        }
    }
    cout << "Usuário deslogado" << endl;
    clearScreen();
    cout << "Você gostaria de encerrar o programa?" << endl;
    cout << "Se sim, digite 1. Se não, digite 2" << endl;
    cin >> loop;

    if (loop == 1){
      loop = 2;
    }

    else{
      loop = 1;
    }
  }
  return 0;
}








