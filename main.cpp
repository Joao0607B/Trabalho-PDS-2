#include <iostream>
#include <unistd.h>
#include <string>
#include 'usuario.h'


void clearScreen() {
    // Comando ANSI para limpar a tela
    std::cout << "\033[2J\033[1;1H";
}

std::string cadastro(bool user)
{
  std::string login, senha, senha_confirma, pergunta_seguranca, resposta_seguranca, usuario_logado;
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
    Usuario::inserir(login, senha, 1, pergunta_seguranca, resposta_seguranca);
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
    Usuario::inserir(login, senha, 4, pergunta_seguranca, resposta_seguranca);
    usuario_logado = login;
    std::cout << "Cadastro Realizado com sucesso" << std::endl;
  }
 return login;
}

std::string login()
{
  std::string login, senha, resposta;
  char yes_no;
  int count = 0;
  std::cout << "Insira o seu login: " << std::endl;
  std::cin >> login;
  std::cout << "Insira a sua senha: " << std::endl;
  std::cin >> senha;

  if (senha == Usuario::get_senha(login))
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
    std::cout << Usuario::get_pergunta(login) << std::endl;
    std:: cin >> resposta;
    Usuario::esqueciasenha(login, resposta);
    return login;
  }
}

void menu(int permissao)
{
  if(permissao == 1) // Admin
  {
    std::cout << "1.Ver Usuários cadastrados    2.Alterar nivel de permissão de um usuário" << std::endl;
    std::cout << "3.Excluir um usuário          4.Adicionar sensor" << std::endl;
    std::cout << "5.Remover sensor              6.Ver sensores" << std::endl;
    std::cout << "7.Remover Cômodo              8.Acessar cômodo" << std::endl;
    std::cout << "9.Ver cômodos                 10.Criar cômodo" << std::endl;
    std::cout << "11.Criar automação             12.Ver automações" << std::endl;
    std::cout << "13.Remover automação" << std::endl;          
    
  }
  else // Usuário
  {
    std::cout << "1.Ver Usuários cadastrados    2.Alterar nivel de permissão de um usuário" << std::endl;
    std::cout << "3.Excluir um usuário          4.Adicionar sensor" << std::endl;
    std::cout << "5.Remover sensor              6.Ver sensores" << std::endl;
    std::cout << "7.Remover Cômodo              8.Acessar cômodo" << std::endl;
    std::cout << "9.Ver cômodos                 10.Criar cômodo" << std::endl;
    std::cout << "11.Criar automação             12.Ver automações" << std::endl;
    std::cout << "13.Remover automação" << std::endl;    
    
  }
  
}










int main()
{
 std::string usuario_logado;
 clearScreen();

  std::cout << "Seja Bem Vindo a Smart Haus" << std::endl;
  std::cout << "Aqui você poderá integrar diversor sistemas de automação e controle remoto" << std::endl;
  std::cout << "Para começar, escolha uma das opções abaixo:" << std::endl;
  
  if(existeAdmin())
  {
    int resposta;
    do
    {
      resposta = 0;
      std::cout << "1. Realizar o Cadastro de um novo Usuário    2.Realizar login em um usuário já existente" << std::endl;
      std::cin >> resposta;
        if (resposta == 1)
        {
          usuario_logado = cadastro(existeAdmin());
        }
        else if(resposta == 2)
        {
          usuario_logado = login();
        }
        else
        {
          std::cout << "Opção inválida" << std::endl;
          clearScreen();
        }
      } while(resposta != 1 || resposta != 2);
      
  } 
  else
  {
    usuario_logado = cadastro(existeAdmin());
  }
  std::cout << "Bem vindo, " << usuario_logado << std::endl;
  std::cout << "O que deseja fazer?" << std::endl;
  menu(get_permissao(usuario_logado));

  
}
  























  
