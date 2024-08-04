<h1 align="center"> Smart Haus </h1>

# User Stories (Histórias de Usuário): 
  Como usuário, quero ser capaz de monitorar certas ações, como a temperatura, umidade, iluminação e segurança de meu domicílio, e visualizar continuamente minha casa, por meio de um sistema inteligente e acessível.

# Descrição do projeto
<p align="justify"> A crescente demanda por conforto e dinamismo nas residências têm impulsionado a busca por soluções tecnológicas práticas no cotidiano dos seres humanos. Nesse contexto, a automação residencial emerge como uma ferramenta crucial para otimizar a vida residencial diária, melhorar a segurança e aumentar a conveniência dos moradores. Isto é, diversas vezes no dia a dia as pessoas ficam com inseguranças ao sair de casa, pensando se alguma porta está aberta, se o fogão está ligado ou se as janelas foram devidamente fechadas, ou até mesmo, querem configurar remotamente o ar condicionado e as luzes de seu quarto sem sair do conforto de sua cama.</p>
<p align="justify"> Dessa forma, foi idealizado para o projeto uma automação residencial que consiste em um sistema integrado que conecta diversos dispositivos e sistemas domésticos a uma plataforma centralizada. Esta plataforma, acessível através de um terminal que estará disponível para o usuário, permite o controle e monitoramento em tempo real de componentes como iluminação, climatização, segurança e aparelhos eletrodomésticos. O funcionamento básico do sistema envolve a instalação de sensores e atuadores que se comunicam. A central de controle processa as informações recebidas dos sensores, executa comandos de automação previamente configurados e possibilita ajustes manuais pelos usuários, proporcionando uma experiência de uso intuitiva e eficiente.</p>
<p align="justify"> Na ideia inicial, foi visado, para a construção e desenvolvimento do código, uma determinada planta de domicílio disponível na Internet, figura abaixo, uma vez que apresentava cômodos que estão presentes na maioria das casas, isto é, quartos, banheiro, sala, cozinha e garagem. Todavia, durante a codificação do projeto, foi discutido pelos estudantes que seria melhor fazer um projeto que se adequasse a qualquer domicílio, generalizando todo o projeto. Dessa forma, o usuário pode incluir qualquer cômodo e adicionar sensores em todos os repartimento de sua casa.</p>

<p align="center">
<img loading="lazy" src="https://plantasdecasas.com/wp-content/uploads/2019/02/Humanizada-Maraba-300x126.jpg"/>
</p>

<p align="center">Figura 1 - Planta padrão utilizado no projeto (Humanizada-Maraba)</p>

<p align="center"> Disponível em: https://plantasdecasas.com/planta-baixa-terreno-estreito/humanizada-maraba/)</p>

<p align="justify"> Ademais, foi definido determinados sensores como padrões, sendo esses: sensor de temperatura, de umidade, de luminosidade, de fechamento de janela, porta e portão de garagem. Além disso, assim como definido para os cômodos, caso o usuário deseje adicionar um novo sensor em seu domicílio, ele será capaz de cadastrar e configurar os novos sensores de acordo com suas necessidades. Para a garantia do funcionamento correto do código e suas ferramentas, aconselha-se que todos os sensores depositem seus valores em um documento do tipo ".txt" no seguinte formato: id do sensor " "(separados por um espaço) valor lido pelo sensor; caso os valores não estejam organizados desta forma, o programa identifica um erro e não será possível analisar as informações dos sensores adequadamente. Além disso, vale ressaltar que o usuário terá a capacidade de nomear os sensores da forma que desejar, tornando mais fácil o manuseio dos equipamentos adquiridos. </p>
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

- include/  
  - usuário.h
  - sensores.h
  - comodo.h

- src/
  - Classes/
    - usuário.cpp
    - sensores.cpp
    - comodo.cpp
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
O projeto Smart Haus tem o objetivo de ser uma automação residencial simples e de fácil acesso, dessa forma, preza-se pela aplicabilidade do código tanto quanto pelo seu funcionamento e customização. Assim sendo, dividimos as instruções de uso em cinco frentes de ação contemplando as seguintes vertentes:
1. Requisitos Iniciais do Sistema:
   - <p align="justify">Requisitos de Hardware e Software:
     Para iniciar as preparações do sistema Smart Haus, primeiramente, certifique-se de possuir um dispositivo com um compilador que suporte a linguagem de programação chamada de “C + +” (Recomenda-se o uso de compiladores como GCC para sistemas baseados em Unix e MSVC para sistemas baseados em Windows).</p>
   - <p align="justify">Requisitos de Sensores:
     Sobre os sensores, recomenda-se inicialmente a compra dos seguintes sensores base recomendados para o monitoramento residencial: sensor de temperatura, sensor de umidade, sensor de fechamento (em estado binário) e sensor de gás. Além da compra, também é necessário sincronizá-los ao computador da forma descrita, também é importante conectar os sensores ao seu computador conforme as instruções do fabricante e, dessa forma, pode concluir a instalação de drivers ou softwares específicos dos sensores (lembre-se de verificar a compatibilidade dos sensores com seu sistema operacional antes de prosseguir.</p>

2. Acesso ao Repositório GitHub do código do projeto:
   - <p align="justify">Acessando o Repositório do GitHub:
     Abra seu navegador de internet e vá para o link que disponibiliza os arquivos principais do código fonte do projeto Smart Haus: https://github.com/Joao0607B/Trabalho-PDS-2.git.</p>
   - <p align="justify">Clonando o Repositório:
     Certifique-se de ter o Git instalado em seu computador. Caso não o possua, você pode tentar baixá-lo e instalá-lo a partir de https://git-scm.com/.</p>
     <p align="justify">Para clonar, na prática, abra um terminal (ou prompt de comando no Windows), navegue até o diretório onde deseja clonar o repositório. Após escolher o local, execute o comando ”git clone https://github.com/Joao0607B/Trabalho-PDS-2.git”, dessa forma, ele criará uma nova pasta chamada “Trabalho-PDS-2” dentro do diretório atual e baixará todos os arquivos do repositório para essa pasta. Após clonar, certifique-se de que todos os arquivos importantes foram baixados (Você deve ver pastas e arquivos como “Makefile”, “src/” e “include/”).</p>

3. Configuração do Ambiente de Desenvolvimento:
   - <p align="justify">Compilação do código:
     No diretório do projeto, utilize o “Makefile” para compilar o código-fonte e execute o comando “make”, isso criará arquivos binários necessários para a execução do sistema.</p>
   - <p align="justify">Configuração dos Sensores no Sistema:
     Antes de tudo, é importante se certificar de que os sensores estão bem sincronizados e se comunicam-se corretamente com o sistema. Para a configuração dos arquivos de tipo “.txt” que serão lidos pelo programa para extrair as informações dos sensores, é absolutamente recomendado que as informações estejam organizadas da seguinte forma e, caso não estejam organizados dessa forma, é possível que o código apresente um erro e não funcione corretamente:</p>
     - Cada linha deve representar um sensor diferente com seu respectivo valor;
     - Cada linha deve possuir um sensor que virá antes de seu valor, sendo assim, a configuração seguirá o exemplo (“id do sensor” separado por um espaço de seu “valor”).

4. Configuração e Personalização do Sistema:
   - <p align="justify">Cadastro e Configuração de Usuários:
     Execute o programa e siga as instruções para criar um novo usuário. Inicialmente, você deverá fazer o primeiro cadastro com suas informações, como nome, senha, nível de permissão, uma pergunta de segurança e sua respectiva resposta (a pergunta de segurança funciona como uma forma de você lembrar a resposta de segurança que será útil para redefinir sua senha caso tenha esquecido). Após o cadastro, faça login para acessar a interface principal.</p>
   - <p align="justify">Configuração dos Cômodos e Sensores:
     Utilize a interface para configurar os sensores e os cômodos da casa. Defina quais sensores estão associados a quais cômodos e ajuste as configurações conforme necessário.</p>

5. Uso e Monitoramento:
   - <p align="justify">Acesso à Interface de Controle:
     Após a configuração, acesse a interface de usuário no desktop para monitorar em tempo real os dados dos sensores. A interface permite visualizar a temperatura, umidade, e status dos sensores de fechamento e sensor de gás (de acordo com os sensores base recomendados na seção 1).</p>
   - <p align="justify">Definição de Cenários e Automação:
     Configure cenários de automação, como acender as luzes ao anoitecer ou ajustar a temperatura durante a noite. Utilize as opções disponíveis para criar rotinas personalizadas que atendam às suas necessidades.</p>
   - <p align="justify">Ajustes e Manutenção:
     Monitore o desempenho do sistema e ajuste as configurações conforme necessário. Adicione novos sensores ou modifiquem os existentes através da interface de configuração para manter o sistema atualizado com as suas preferências.</p>


  
# Principais Dificuldades:
<p align="justify"> No desenvolvimento da Smart Haus, enfrentamos diversos desafios, tanto técnicos quanto na integração do sistema. Uma das principais dificuldades foi padronizar os arquivos dos cômodos. Inicialmente, separamos as classes (Sala, Quarto, Cozinha, Banheiro e Garagem) e definimos as variáveis para os sensores. No entanto, ao implementar todas as classes dos cômodos no menu de opções para o usuário, percebemos que a navegação nessa interface se tornaria inviável. Além disso, a função de implementar sensores também se complicaria significativamente para cada classe dos cômodos citados.</p>
<p align="justify"> Para solucionar esse problema, adotamos o uso de herança entre as classes, o que simplificou a construção do código, melhorando a compreensão e a legibilidade. Dessa forma, conseguimos manter a padronização necessária e facilitar a manutenção e expansão do sistema.</p>
<p align="justify"> Outro desafio enfrentado foi a leitura dos sensores, que inicialmente eram fornecidos em um arquivo .txt definido pelo usuário. Esse arquivo contém duas informações por linha: o nome do sensor e o valor correspondente. Cada linha do arquivo .txt apresenta um par de nome e valor. O problema estava na leitura do arquivo linha por linha, na identificação do nome e valor do sensor, na atribuição desses parâmetros às variáveis e na conversão do valor de string para double. Investimos um bom tempo para encontrar a solução completa, mas conseguimos desenvolver uma função que resolve todos esses problemas no código.</p>
<p align="justify"> Também tivemos dificuldade na definição das classes "Usuario" e "BancoDeDados", pois havia conflitos de funções e algumas atividades semelhantes entre elas. Tentamos refinar essas classes definindo melhor seus papéis no sistema, mas concluímos que seria mais vantajoso unir as duas classes para aumentar a sinergia e a eficiência no código.</p>

  
# Desenvolvedores
| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174884404?v=4" width=100><br><sub>Carlos Coimbra</sub>](https://github.com/duducoimbra) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174391290?s=400&u=563703186cd45436cfbe4b6789dfb0fd9afdf356&v=4" width=100><br><sub>Igor Araujo</sub>](https://github.com/Igorgu3) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/168564497?v=4" width=100><br><sub>João Silva</sub>](https://github.com/Joao0607B) | [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174884410?v=4" width=100><br><sub>Lucas Latini</sub>](https://github.com/lucas-latini) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/174884515?v=4" width=100><br><sub>Otávio Silva</sub>](https://github.com/octoposs)  | 
| :---: | :---: | :---: | :---: | :---: | 



