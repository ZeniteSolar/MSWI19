# GODP
**Guia de Orientação para Desenvolvimento de Projetos**

> Durante a prática projetual lidamos com um desafio que é o grande volume de
> informações, considerando que projetamos algo (produto), para alguém (usuário)
> em algum lugar (contexto).

ref 1: http://ngd.ufsc.br/wp-content/uploads/2018/03/e-book-godp.pdf  
ref 2: https://repositorio.ufsc.br/xmlui/bitstream/handle/123456789/128821/331968.pdf  

Este documento pretende documentar o processo de desenvolvimento deste produto
tendo como principal referência a metodologia contida no GODP, de Giselle Schmidt Alves Díaz Merino.

---

## MOMENTO INSPIRAÇÃO

### [-1] OPORTUNIDADES
Por se tratar de um veículo, o _Barco Solar_ necessita de uma interface que permita que um _piloto_ controle sua navegação, que de modo simplista pode ser atendido com um dispositivo para controlar a direção (geralmente um volante ou timão, conectado mecanicamente à um leme) e um acelerador (geralmente uma alavanca ou um sensor de posição rotacional como um potenciômetro), e se tratando de um veículo de performance para competição, pode ser uma vantagem estratégica ter uma série de outros controles para adaptar o veículo às condições da competição.

Especificamente no _Guarapuvu II_, desenvolvido pela _Equipe Zênite Solar_ (o _Barco Solar do IFSC_, reconhecido como _o barco solar mais inovador na competição nacional quatro vezes consecutivas_, sendo também o _primeiro barco solar open-source do mundo_), o controle de direção é realizado por um volante diretamente acoplado por um conector mecânico de engate rápido em um sensor eletrônico de posicionalmento rotacional (um potenciômetro) localizado em uma parte fixa no casco, em frente ao piloto. 

Uma unidade de controle é responsável por posicionar o leme por meio de um motor elétrico, que utiliza também um potenciômetro para fechar a malha de controle de posicional, direcionando a embarcação de acordo com a angulação do volante de maneira transparente em relação à um volante clássico mecânico conectado ao leme por cabos, porém, sem oferecer um feedback sensorial de resistência mecânica ao movimento rotacional do volante, assim, exigindo praticamente nenhuma força para direcionar a embarcação, independete da velocidade, inércia rotacional do hélice ou das correntes marítimas.

Juntamente ao volante, um painel de controle é posicionado em frente ao piloto, contendo todas os demais controles da embarcação:
* Controle manual de estados ligado e desligado individual para cada uma das 3 bombas de porão, realizado por meio de chaves alavanca.
* Controle manual de estados ligado e desligado para permitir a operação geral da embarcação, conectando a bateria nos demais sistemas de potência.
* Controle manual de estados ligado e desligado para permitir a operação do motor de propulsão.
* Controle manual de estados ligado e desligado para permitir a operação dos controladores de carga, permitindo a carga das baterias por meio da energia dos painéis fotovoltaicos.
* Controle do percentual da tensão média das baterias que é entregue ao motor de propulsão, permitindo o controle de rotação do motor, logo, de propulsão (velocidade) da embarcação.
* Controle da taxa de variação do controle de rotação do motor, criando uma rampa controlada de aceleração para evitar variações bruscas do motor de propulsão.
* Controle da limitação percentual da máxima potência entregue às baterias pelos controladores de carga.
No mesmo painel também é posicionado um dispositivo de emergência (botão cogumelo, vermelho) e dois displays que informam dados dos sensores da embarcação e mensagens de emergência ao piloto.

Além do painel de controle, a embarcação possui também, de acordo com os regulamentos das competições, e não desenvolvidos pela equipe (disponíveis comercialmente): uma unidade de rádio UHF, uma chave de segurança do tipo _dead man's switch_, uma unidade _GPS_ portátil, celular, relógio de pulso, lanterna, remo, sinalizadores fumígenos e luminosos, âncora, cabos de bóia e de reboque.

Em resumo, a interface da embarcação exige que o piloto preste atenção na navegação enquanto controla a direção com uma mão e revese a outra mão para ajustar a velocidade da embarcação, se comunicar no rádio, controlar o seu tempo (relógio), verificar as mensagens do display do painel, dentre outros comandos mais exporádicos como ligar ou desligar bombas de porão.

Em uma entrevista com os pilotos (Marcos e Gustavo) sobre como eles controlam a embarcação, foi levantado que:
- Os pilotos passam a maior parte do tempo das provas com a velocidade constante, variando entre duas ou três posições principais quando realizam manobras de contorno de boias, desvio de obstáculos ou ultrapassaagens. Estaas posições geralmente são praticamente as mesmas em todas as provas, mas podem ser diferentes dependendo das condições de navegação.
- Os pilotos preferem não responder ao rádio se tiverem em situação de delicada ou em manobra, para manter a atenção na navegação e controle.
- Para qualquer ajuste de velocidade é necessário tirar uma das mãos do volante, e não necessariamente precisam deslocar a visão para a escala do potenciômetro.
- A escala do potenciômetro facilita a aprendizagem, facilitando a memorização da dinâmica dos controles da embarcação.
- O ajuste de derivada não é utilizado, ficando no máximo possível o tempo inteiro.

A partir disso, a ideia de transpor os controles principais do painel para o volante surgiu naturalmente, abrindo a possibilidade do desenvolvimento de uma nova interface, inspirada no volante de Fórmula 1.

Este tema de projeto foi então proposto como projeto do autor na unidade de Projeto Integrador 3 do curso de Engenharia Eletrônica, possuindo todos os requisitos da disciplina, podendo ser realizado no tempo viável para levar para a próxima competição (dezembro de 2019) e para o prazo de finalização da disciplina.

Este projeto, por ser de interesse da equipe, conta com o orçamento financeiro da equipe, e também pode necessitar de apoio técnico da mesma. Por se tratar de um projeto realizado dentro da equipe, deve cumprir os seguintes requisitos:

* ser desenvolvido de forma open-source.
* ser desenvolvido com o menor custo possível.
* Ter um protótipo estável antes da data da competição (dezembro de 2019).
* Trabalhar em redundância aos controles do painel atual sem causar conflitos.
* Ser robusto e resistente à água.

Deste modo, o autor considera um projeto tecnicamente viável, porém, desafiador.

Considerando que na competição esta seria o primeiro volante com controles integrados, se trata de um projeto de inovação dentro do contexto da competição, contribuindo para um dos objetivos da equipe, que é ganhar o prêmio de inovação tecnológica Fernando Amorim.

### [0] PROSPECÇÃO

A demanda levantada na entrevista foi a melhoria da interface de controle e feedback do piloto por meio da implementação de um volante com controles e feedback visual, principalmente no que se diz respeito ao controle da velocidade da embarcação, que é o ajuste com a maior frequência de uso depois do próprio controle da direção da embarcação. 

Se tratando de um equipamento a ser utilizado fora de quaisquer fins comerciais, não há qualquer limitação quanto à viabilidade legal de qualquer técnica empregada.

Entre a equipe, foi acordado que o próprio piloto Marcos terá atuação no projeto mecânico da direção, buscando otimizar a localização, ergonomia, vedação e montagem da direção.

### [1] LEVANTAMENTO DE DADOS

A partir da identificação da oportunidade, uma etapa de investigação e mapeamento das possíveis interfaces de controle e feedback foi realizado, pegando referências nos volantes se formula 1 e controles de videogame, sumarizado em forma de um mapa mental, pensando em como estas tecnologias poderiam ser explorados para realizar as interfaces identificadas como potenciais soluções, ainda não selecionadas.

Foi feita uma pesquisa na web por imagens de referências, vídeos e matérias que explicam o funcionamento dos volantes de fórmula 1.

<table><td><tr>
    <img src="design/imgs_iteration_1/ref_1.jpeg" alt="Direção de Fórmula 1" width="200"/>
    <img src="design/imgs_iteration_1/ref_2.jpeg" alt="Utilização dos botões" width="200"/>
</tr></td></table>

---

## MOMENTO DE IDEAÇÃO

### [2] ANÁLISE DE DADOS

Que elementos de interface são utilizadas num volante de Fórmula 1 e o no que elas atuam? Onde ficam localizadas?

* Visual
    * Displays LCD
        * proposta: multi-funções, centralizando informações: mostrar menus, configurações, mensagens de erro, gráficos de mudança de marcha, kers, velocidade, tempo de volta, rpm do motor, etc.
            * posicionamento: central
    * Displays de 7 segmentos
        * proposta: tempo de volta, códigos de erro, kers disponíveis, velocidade
            * posicionamento vertical: superior
    * Leds
        * fila / barras colorida
            * proposta: ponto de mudança de marcha (limites de RPM) e sinalizam diversos erros no sistema
                * posicionamento: superior
* Controle
    * Chaves
        * rotacionais de multi-posições
            * proposta: seleção de diferentes contextos para os botões da direção
                * posicionamento: central
            * proposta: seleção do mapeamento da mistura de combustível
                * posicionamento: inferior
            * proposta: seleção do mapeamento da dinâmica da suspensão
                * posicionamento: inferior
        * rotacionais tipo thumb-wheel
            * proposta: configuração do diferencial
            * proposta: configuração do freio
    * Potenciômetros
        * rotacionais
            * proposta: mapeamento da suspensão, diferencial, ou pedal de aceleração.
                * posicionamento: lateral, acessível sem retirar a mão da posição de controle da direção do veículo 
    * Botões
        * proposta: modificar parâmetros em geral
            * posicionamento: lateral, perto dos dedos
    * Alavancas / borboletas
        * proposta: embreagem
            * posicionamento: lateral, traseira


Elementos estruturais de um volante com interface:

* Volante
    * Estrutura mecânica
        * Frame de plástico, metal ou de material compósito
        * Carcaça com indicações visuais textuais e simbólicas
        * Engate com 
    * Elementos de interface
        * Chaves
        * Botões
        * Displays
        * Leds
        * Potenciômetros
    * Placa de circuito impresso
        * Componentes eletrônicos passivos
        * Microcontrolador
            * Programa
    * Cabeamento
        * Cabo condutor elétrico para energia e transferência de dados


Foi realizado, com o projetista e o piloto, uma avaliação quanto ao grau de importãncia sobre a presença no volante de cada um dos comandos da embarcação, utilizado um diagrama de Mudge, concluindo que:

* Mudge quanto à ordem de prioridade da presença dos comandos no volante:
    1 Vel Motor
    2 Cronômetro
    3 dVel/dt Motor
    4 ON/OFF Motor
    5 ON/OFF Bombas de porão
    6 pmax MPPT
    7 Emergência
    8 ON/OFF Geral
    9 ON/OFF MPPTs

Foi também realizado uma avaliação comparativa das características visibilidade (no sol), flexibilidade (de uso) e complexidade de implementação de cada um dos elementos visuais:

Quais são os elementos de interface visuais disponíveis?
* Elementos Visuais
    * Bargraph
        * visibilidade no sol: NENHUMA
        * flexibilidade: BAIXA
        * complexidade de implentação: BAIXA
    * Leds de alto brilho
        * visibilidade no sol: BOA
        * flexibilidade: BAIXA
        * complexidade de implentação: BAIXA
    * Display OLED
        * visibilidade no sol: BOA
        * flexibilidade: ALTA
        * complexidade de implentação: MÉDIA
    * Display LCD
        * visibilidade no sol: À TESTAR
        * flexibilidade: MÉDIA
        * complexidade de implentação: MÉDIA



---

### [3] CRIAÇÃO

Após racionalizar sobre os itens levantados na entrevista com os pilotos, foi investigado, em um segundo momento, se um controle que permitisse uma mudança fácil para o máximo seria interessante e ambos concordaram com entusiasmo, seguido de uma série de projeções quanto ao seu uso durante as provas, indicando uma melhoria que agregaria valor.

Contextualizando e já res​​gatando um histórico, de 2014 para 2015 um controle que permitia uma mudança fácil para o nível máximo tinha sido implementado utilizando uma chave alavanca de duas posições como uma medida de redundância, para permitir que o piloto tivesse algum controle caso o potenciômetro apresentasse falhas, que foi um problema recorrente em 2014. Tal chave foi removida do painel em 2016 por ser considerado não mais necessária se outras medidas para aumentar a confiabilidade fossem tomadas.

Já em 2018, a fim de garantir o bom funcionamento do controle de velocidade, os potenciômetros do painel foram montados em suportes fixados atrás do painel, expondo à água um segundo eixo, que de um lado era acoplado no eixo do potenciômetro, e do outdo, em um knob no painel na face acessível ao piloto, contendo uma borracha de vedação entre a parte fica do  ficando altamente protegido da água.

Outro ponto levantado foi a melhoria da performance durante as provas implementando um relógio/cronômetro diretamente no volante, que traria agilidade ao piloto em relação à operação de um relógio de pulso.

[ documentar propostas..... ]

#### Primeira itearção no design

Inspirado nas dimensões do volante já existente na embarcação e na forma dos volantes de Fórmula 1 atuais, uma primeira iteração no design foi realizada, iniciando com uma forma simples de um retângulo, com rasgos para o posicionamento dos dedos do piloto.

<table><td>
    <tr>
        <img src="design/imgs_iteration_1/sw_1.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/imgs_iteration_1/sw_1_.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/imgs_iteration_1/sw_1_technical_drawing.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
</td></table>

Realizando uma redução de área possivlemente não útil, gerou-se uma segunda alternativa:

<table><td>
    <tr>
        <img src="design/imgs_iteration_1/sw_2.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/imgs_iteration_1/sw_2_.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/imgs_iteration_1/sw_2_technical_drawing.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
</td></table>

A partir disso, a pega reduzida para caber dentro da palma da mão do piloto, gerando três variações, das quais a terceira foi a preferida. Desta terceira opção, uma área foi reservada para a placa de circuito impresso, buscando um bom aproveitamento de área

<table><td>
    <tr>
        <img src="design/imgs_iteration_1/sw_3_alt_1.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/imgs_iteration_1/sw_3_alt_2.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/imgs_iteration_1/sw_3_alt_3.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/imgs_iteration_1/sw_3_alt_3_with_pcb.jpeg" alt="Utilização dos botões" width="200"/>
    </tr>
</td></table>

Para verificar a viabilidade de roteamento, o formato da placa foi importada para o _KiCAD_ usando um arquivo `.dwg` exportado pelo _SolidWorks_ e os principais componentes de interface foram posicionados arbitrariamente, indicando que há espaço suficiente para o circuito na área reservada:

<img src="design/imgs_iteration_1/sw_3_pcb_only_mounted.jpeg" alt="Utilização dos botões" width="200"/>

---

## MOMENTO IMPLEMENTAÇÃO

### [4] EXECUÇÃO

#### Hardware parte 1: Projeto do Circuito Eletrônico

O projeto foi desenhado no [KiCAD](http://www.kicad-pcb.org/) enquanto suas partes fundamentais foram simuladas no [LTSpice](https://www.analog.com/en/design-center/design-tools-and-calculators/ltspice-simulator.html), divindo o circuito na seguinte estrutura:  
* mswi.sch (MSWI)  
    * POWER SUPPLY (design: supplies.sch, simulations: input.asc, input_alt.asc)  
    * MCU (design: atmega328p.sch, simulations: buzzer.asc)  
        * SWITCHES (design: swiches.sch, simulations: switches_and_leds.asc)  
    * CANBUS (design: canbus.sch)  
    * CANBUS CONN (design: canbus_connector.sch)  


##### POWER SUPPLY (supplies.sch, input.asc, input_alt.asc)

Na embarcação, no cabo que leva o barramento can aos módulos, há um barramento de alimentação de 18V, que utilizaremos como nossa fonte de alimentação.

Primeiramente a potência consumida pelo circuito foi estimada considerando uma estimativa de carga de trabalho de 10% para os leds (7.7mA médio) e buzzer (3mA médio), enquanto o display foi considerado 30mA médio e o microcontrolador 10mA, somando uma potência de 250mW para uma saída de +5V.

Para converter 18V para 5V para esta potência, um simples regulador linear pode ser utilizado, implementado com um PNP (simulado em input_alt.asc) ou com um circuito integrado (simulado em input.asc). As vantagens de se utilizar um circuito integrado são sua robustez, proteção de sobre-corrente e temperatura.

Para melhorar a robustez da fonte, foram adicionados uma proteção de polaridade utilizando um NMOS, de sobrecorrente na entrada utilizando um fusível rearmável (500mA) e de surto utilizando um diodo ESD (24V).

O circuito foi simulado em diversas situações e se comportou como o esperado, sem oscilações ou picos de corrente no transitório. 

##### SWITCHES (switches.sch, switches_and_leds.asc)

Para que o piloto possa ter um feedback visual dos botões (além do próprio feedback tátil que o botão possui), um circuito de interface foi implementado, de maneira a permitir que os leds de cada botão liguem quando os botões forem pressionados, mas também permite que os leds sejam ativados pela mesma porta do microcontrolador. 

Esta interface conta com o pull-up do microcontrolador e portanto as portas do microcontrolaor precisam estar com o pull-up ativo para que funcionem corretamente quando configuradas como entradadas. Para controlar os leds, basta serem configuradas como saída, e esta alternância entre entrada e saída pode ser realizado em uma frequência suficientemente alta para não que seja percebido pelo piloto.

A possível oscilação no ligar e desligar das chaves foi tratado de maneira analógica com um filtro RC passa-baixa, não sendo necessário ser tratado digitalmente.

Tal circuito de interface foi simulado (switches_and_leds.asc) no LTSpice e se comportou conforme o esperado.

##### MCU (atmega328p.sch)

Para que o sistema possa emitir sinais luminosos arbitrários, quatro leds foram utilizados, além de um buzzer, que serão utilizados como alarmes visuais e sonoros para a interface, em especial, para o cronômetro.

O display OLed foi representado pelo conector J303, conectado no i2c.

Para gravar o microcontrolador, o SPI0 + reset foram disponibilizados no conector J301, que infelizmente não pode seguir o padrão da AVR por restrições espaciais da PCB.

Além disso, o USART0 + reset foi disponibilizado no conector J302, caso seja gravado um bootloader que permita gravar firmwares pela interface serial.

##### Final

O esquemático final pode ser acessado [aqui (PDF)](https://github.com/joaoantoniocardoso/boat-steering-wheel/raw/master/pcb/mswi/PDF/mswi.pdf).

#### Hardware parte 2: Projeto da Placa de Circuito Impresso

Primeiramente a especificação mecânica da forma da PCB, posição dos botões e do display foram importadas para o KiCAD. 

Os componentes foram agrupados por sua funcionalidade e cada pequeno grupo foi roteado individualmente, buscando prover caminho para as entradas e saídas para pelo menos dois lados por ambas as camadas, deixando sua integração de forma simples.

Em seguida o microcontrolador e os CIs do CAN foram posicionados numa região mais centralizada, e então os blocos foram conectados por trilhas.

Regras iniciais foram definidas pensando numa fabricação utilizando a Freza do IFSC, mas posteriormente foram trocadas para a capabilidade padrão industrial (6/6mils), pois foi decidido que sua fabricação seria feita em alguma empresa, fora do IFSC, especialmente por que a capabilidade da Fresa do IFSC não garante que não fiquem pequenas regiões de cobre de micrômetros entre as trilhas do microcontrolador, que tem um encapsulamento com pitch de 5mm (espaçamento de 2mm entre os pads).

O Layout finalizado pode ser verificado nas figuras abaixo.

<table><td>
    <tr>
        <img src="design/pcb_traces.png" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/pcb_top.png" alt="Utilização dos botões" width="200"/>
    </tr>
    <tr>
        <img src="design/pcb_bottom.png" alt="Utilização dos botões" width="200"/>
    </tr>
</td></table>

#### Hardware parte 3: Projeto das Partes Mecânicas

#### Firmware

### [5] VIABILIZAÇÃO

### [6] VERIFICAÇÃO FINAL


