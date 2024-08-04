<h1 align="center"> Smart Haus </h1>

# User Stories (Histórias de Usuário): 
  Como usuário, quero ser capaz de monitorar certas ações, como a temperatura, umidade, iluminação e segurança de meu domicílio, e visualizar continuamente minha casa, por meio de um sistema inteligente e acessível.

# Descrição do projeto
<p align="justify"> A crescente demanda por conforto e dinamismo nas residências têm impulsionado a busca por soluções tecnológicas práticas no cotidiano dos seres humanos. Nesse contexto, a automação residencial emerge como uma ferramenta crucial para otimizar a vida residencial diária, melhorar a segurança e aumentar a conveniência dos moradores. Isto é, diversas vezes no dia a dia as pessoas ficam com inseguranças ao sair de casa, pensando se alguma porta está aberta, se o fogão está ligado ou se as janelas foram devidamente fechadas, ou até mesmo, querem configurar remotamente o ar condicionado e as luzes de seu quarto sem sair do conforto de sua cama.</p>
<p align="justify"> Dessa forma, foi idealizado para o projeto uma automação residencial que consiste em um sistema integrado que conecta diversos dispositivos e sistemas domésticos a uma plataforma centralizada. Esta plataforma, acessível através de um terminal que estará disponível para o usuário, permite o controle e monitoramento em tempo real de componentes como iluminação, climatização, segurança e aparelhos eletrodomésticos. O funcionamento básico do sistema envolve a instalação de sensores e atuadores que se comunicam. A central de controle processa as informações recebidas dos sensores, executa comandos de automação previamente configurados e possibilita ajustes manuais pelos usuários, proporcionando uma experiência de uso intuitiva e eficiente.</p>
<p align="justify"> Na ideia inicial, será visado, para a construção e desenvolvimento do código, uma determinada planta de domicílio disponível na Internet, figura abaixo, uma vez que apresenta cômodos que estão presentes na maioria das casas, isto é, quartos, banheiro, sala, cozinha e garagem. Dessa forma, caso seja da vontade do usuário incluir outro novo cômodo ou aumentar a quantidade de algum dos repartimentos de casa citados acima, é necessário apenas fazer pequenos ajustes e configurações.</p>

<p align="center">
<img loading="lazy" src="https://plantasdecasas.com/wp-content/uploads/2019/02/Humanizada-Maraba-300x126.jpg"/>
</p>

<p align="center">Figura 1 - Planta padrão utilizado no projeto (Humanizada-Maraba)</p>

<p align="center"> Disponível em: https://plantasdecasas.com/planta-baixa-terreno-estreito/humanizada-maraba/)</p>

<p align="justify"> Ademais, foi definido determinados sensores como padrões, sendo esses: sensor de temperatura, de umidade, de luminosidade, de fechamento de janela, porta e portão de garagem. Além disso, assim como definido para os cômodos, caso o usuário deseje adicionar um novo sensor em seu domicílio, ele será capaz de cadastrar e configurar os novos sensores de acordo com suas necessidades. Para a garantia do funcionamento correto do código e suas ferramentas, aconselha-se que todos os sensores depositem seus valores em um documento do tipo ".txt" no seguinte formato: id do sensor " "(separados por um espaço) valor lido pelo sensor; caso os valores não estejam organizados desta forma, o programa identifica um erro e não será possível analisar as informações dos sensores adequadamente, além disso, vale ressaltar que o usuário terá a capacidade de nomear os sensores da forma que desejar tornando mais fácil o manuseio dos equipamentos adquiridos. </p>
<p align="justify"> Outra característica do projeto é reconhecer e separar quais cômodos cada usuário cadastrado pode modificar em seu domicílio, a fim de não gerar conflitos e desavenças entre os familiares. </p>
<p align="justify"> Assim, haja visto as soluções propostas, os estudantes acreditam que podem auxiliar e facilitar a vida dos usuários do projeto, fazendo com que possam monitorar continuamente seus domicílios e controlar de maneira acessível o estado de cada cômodo da casa. </p>

# Principais arquivos
. programa
- Makefile
- build/
  - main.o
  - usuário.o
  - comodo.o
  - sensores.o
  - quarto.o
  - cozinha.o
  - banheiro.o
  - sala.o
  - garagem.o

- include/  
  - usuário.h
  - sensores.h
  - comodo.h
  - quarto.h
  - cozinha.h
  - banheiro.h
  - sala.h
  - garagem.h

- src/
  - Classes/
    - usuário.cpp
    - sensores.cpp
    - comodo.cpp
    - quarto.cpp
    - cozinha.cpp
    - banheiro.cpp
    - sala.cpp
    - garagem.cpp
  - main.cpp

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
| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174884404?v=4" width=100><br><sub>Carlos Coimbra</sub>](https://github.com/duducoimbra) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174391290?s=400&u=563703186cd45436cfbe4b6789dfb0fd9afdf356&v=4" width=100><br><sub>Igor Araujo</sub>](https://github.com/Igorgu3) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/168564497?v=4" width=100><br><sub>João Silva</sub>](https://github.com/Joao0607B) | [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174884410?v=4" width=100><br><sub>Lucas Latini</sub>](https://github.com/lucas-latini) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174884515?v=4" width=100><br><sub>Otávio Silva</sub>](https://github.com/octoposs)  | 
| :---: | :---: | :---: | :---: | :---: | 




