<h1 align="center"> Smart Haus </h1>

# User Stories (Histórias de Usuário): Como um usuário, quero ser capaz de controlar certas ações, como a temperatura, umidade, iluminação e segurança de meu domicílio, e monitorar continuamente minha casa, por meio de um sistema inteligente e acessível.

# Descrição do projeto
  A crescente demanda por conforto e dinamismo nas residências têm impulsionado a busca por soluções tecnológicas práticas no cotidiano dos seres humanos. Nesse contexto, a automação residencial emerge como uma ferramenta crucial para otimizar a vida residencial diária, melhorar a segurança e aumentar a conveniência dos moradores. Isto é, diversas vezes no dia a dia as pessoas ficam com inseguranças ao sair de casa, pensando se alguma porta está aberta, se o fogão está ligado ou se as janelas foram devidamente fechadas, ou até mesmo, querem configurar remotamente o ar condicionado e as luzes de seu quarto sem sair do conforto de sua cama.
  Dessa forma, foi idealizado para o projeto uma automação residencial que consiste em um sistema integrado que conecta diversos dispositivos e sistemas domésticos a uma plataforma centralizada. Esta plataforma, acessível através de um terminal que estará disponível para o usuário, permite o controle e monitoramento em tempo real de componentes como iluminação, climatização, segurança e aparelhos eletrodomésticos. O funcionamento básico do sistema envolve a instalação de sensores e atuadores que se comunicam. A central de controle processa as informações recebidas dos sensores, executa comandos de automação previamente configurados e possibilita ajustes manuais pelos usuários, proporcionando uma experiência de uso intuitiva e eficiente.
  Na ideia inicial, será visado, para a construção e desenvolvimento do código, uma determinada planta de domicílio disponível na Internet, figura abaixo, uma vez que apresenta cômodos que estão presentes na maioria das casas, isto é, quartos, banheiro, sala, cozinha e garagem. Dessa forma, caso seja da vontade do usuário incluir outro novo cômodo ou aumentar a quantidade de algum dos repartimentos de casa citados acima, é necessário apenas fazer pequenos ajustes e configurações. 

![Planta padrão utilizado no projeto](https://github.com/Joao0607B/Trabalho-PDS-2/assets/168564497/57882f67-6d86-4757-a151-80d5d2194c39)

Figura 1 - Planta padrão utilizado no projeto (Humanizada-Maraba)
Disponível em: https://plantasdecasas.com/planta-baixa-terreno-estreito/humanizada-maraba/)

  Ademais, foi definido determinados sensores como padrões, sendo esses: sensor de temperatura, de umidade, de luminosidade, de fechamento de janela, porta e portão de garagem. Além disso, assim como definido para os cômodos, caso o usuário deseje adicionar um novo sensor em seu domicílio, ele será capaz de cadastrar e configurar os novos sensores de acordo com suas necessidades.
Outra característica do projeto é reconhecer e separar quais cômodos cada usuário cadastrado pode modificar em seu domicílio, a fim de não gerar conflitos e desavenças entre os familiares. Além disso, a fim de universalizar o projeto, nosso código está disponível em português, inglês e espanhol, isto é, nosso sistema pode ser utilizado em diversos países, sendo necessário apenas pequenas modificações de inicialização.
Assim, haja visto as soluções propostas, os estudantes acreditam que podem auxiliar e facilitar a vida dos usuários do projeto, fazendo com que possam monitorar continuamente seus domicílios e controlar de maneira acessível o estado de cada cômodo da casa. 

# Principais arquivos
. programa
├── Makefile
├── build/
│  └── main.o
│  └── Usuário.o
│  └── BancoDeDados.o
│  └── Autenticação.o
│  └── Sensores.o
│  └── Quarto.o
│  └── Cozinha.o
│  └── Banheiro.o
│  └── Sala.o
│  └── Garagem.o
├── include/
│  └── Usuário.h
│  └── BancoDeDados.h
│  └── Autenticação.h
│  └── Sensores.h
│  └── Quarto.h
│  └── Cozinha.h
│  └── Banheiro.h
│  └── Sala.h
│  └── Garagem.h
└── src/
│  └── Cómodos/
│    └── Usuário.cpp
│    └──  BancoDeDados.cpp
│    └── Autenticação.cpp
│    └── Sensores.cpp
│    └── Quarto.cpp
│    └── Cozinha.cpp
│    └── Banheiro.cpp
│    └── Sala.cpp
│    └── Garagem.cpp
│  └── main.cpp

# Instruções de Instalação

Para instalar o sistema de automação residencial, siga os passos abaixo:
- Clone o repositório do projeto em um arquivo de uso pessoal;
  - Disponível em: https://github.com/Joao0607B/Trabalho-PDS-2.git
- Selecione os sensores necessários para cada cômodo de acordo com o projeto, sendo eles:
  - Sensor de temperatura;
  - Sensor de umidade;
  - Sensor de luminosidade;
  - Sensor de fechamento de janela;
  - Sensor de fechamento de porta;
  - Sensor de fechamento de portão de garagem.
- Posicione os sensores escolhidos conforme manda o fabricante;
- Combine os sensores com o programa e, se necessário, adicione um usuário com novos sensores;
- Compile o código-fonte usando as ferramentas adequadas para seu sistema operacional.

# Instruções de Uso

Para utilizar o sistema de automação residencial:
- Inicie o sistema conforme as instruções de inicialização fornecidas;
- Coloque seus dados e finalize o cadastro das suas informações;
- Acesse a interface de usuário via desktop para monitorar e controlar os dispositivos conectados;
- Personalize as configurações e defina cenários de automação de acordo com suas preferências e necessidades.

# Desenvolvedores
| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/37356058?v=4" width=115><br><sub>Carlos Eduardo Guimarães Coimbra</sub>](https://github.com/duducoimbra) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/30351153?v=4" width=115><br><sub>Igor Gustavo de Souza Araujo</sub>](https://github.com/Igorgu3) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/8989346?v=4" width=115><br><sub>João Pedro Braga da Silva</sub>](https://github.com/Joao0607B) | [<img loading="lazy" src="https://avatars.githubusercontent.com/u/8989346?v=4" width=115><br><sub>Lucas de Araújo Sampaio Latini</sub>](https://github.com/lucas-latini) | [<img loading="lazy" src="https://avatars.githubusercontent.com/u/8989346?v=4" width=115><br><sub>Otavio Henrique da Silva</sub>](https://github.com/Octupuss) | 
| :---: | :---: | :---: |

