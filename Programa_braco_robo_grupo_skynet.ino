#include <VarSpeedServo.h>  // Biblioteca para servos motores, permite o controle da velocidade


// Define variáveis para os servos motores

VarSpeedServo base;
VarSpeedServo braco1;
VarSpeedServo braco2;
VarSpeedServo antebraco;
VarSpeedServo garra;


// Definir botões e variável de controle do sensor

const int button1 = 12;       // relaciona a variável button1 ao pino 12
const int button2 = 13;       // relaciona a variável button2 ao pino 13
const int sensor = 9;         // relaciona a variável sensor ao pino 9



//Define as entradas dos potencômetros

const int pot1 = A0;      // relaciona a variável pot1 a entrada A0
const int pot2 = A1;      // relaciona a variável pot2 a entrada A1
const int pot3 = A2;      // relaciona a variável pot3 a entrada A2
const int pot4 = A3;      // relaciona a variável pot4 a entrada A3

//Define valores das variáveis dos potenciômetros

int pot1Val=0;
int pot2Val=0;
int pot3Val=0;
int pot4Val=0;

// Define as variáveis de ângulos

int pot1Angle;
int pot2Angle;
int pot3Angle;
int pot4Angle;

// Define os valores das variáveis para cada botão

int button1Pressed = 0;
boolean button2Pressed = false;
boolean sensorP = false;

//Define variável para posições salvas dos servos motores

int basePosSave[]={1,1,1,1,1};
int bracoPosSave[]={1,1,1,1,1};
int antebracoPosSave[]={1,1,1,1,1};
int garraPosSave[]={1,1,1,1,1};

void setup() {
  // Relaciona variáveis aos pinos digitais físicos do arduíno

  base.attach(2);
  braco1.attach(3);
  braco2.attach(4);
  antebraco.attach(5);
  garra.attach(6);

  // Define as variáveis como entradas ou saídas
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(sensor, INPUT);

// Inicia comunicação serial

  Serial.begin(9600);
}

void loop() {
  
// Realiza leitura dos ptotênciometros e o mapeamento do ângulo
  
  pot1Val = analogRead(pot1);
  pot1Angle = map(pot1Val, 0, 1023, 0, 179);    // ângulo da base definido como sendo de 0° a 179°

  pot2Val = analogRead(pot2);
  pot2Angle = map(pot2Val, 0, 1023, 0, 120);    // Ângulo do braço definido como sendo de 0° a 120°

  pot3Val = analogRead(pot3);
  pot3Angle = map(pot3Val, 0, 1023, 0, 179);    // Ângulo do antebraço definido como sendo de 0° a 180°

  pot4Val = analogRead(pot4);
  pot4Angle = map(pot4Val, 0, 1023, 0, 90);     // Ângulo da garra definido como sendo de 0º a 90º

// Posiciona os servos motores de acordo com o potênciometro

  base.write(pot1Angle);              // Posiciona o servo da base
  braco1.write(pot2Angle);            // Posiciona o servo1 do braço
  braco2.write(pot2Angle);            // Posiciona o servo2 do braço
  antebraco.write(pot3Angle);         // Posiciona o servo do antebraço
  garra.write(pot4Angle);             // Posiciona o servo da garra


// Verifica se o botão1 foi pressionado

  if(digitalRead(button1) == HIGH){  // se botão1 pressionado

    button1Pressed++;   // Incrementa a variável em 1 unidade


// Salva as posições

    switch(button1Pressed){
        case 1:           // caso a variável em 1

          basePosSave[0]= pot1Angle;          // salva a posição da variável da base na posição 0 do vetor
          bracoPosSave[0]= pot2Angle;         // salva a posição da variável do braço na posição 0 do vetor
          antebracoPosSave[0]= pot3Angle;     // salva a posição da variável do antebraço na posição 0 do vetor
          garraPosSave[0]= pot4Angle;         // salva a posição da variável da garra na posição 0 do vetor
          
          Serial.println("Posição #1 Salvo"); // informa que a posição número 1 foi salva
          break;
          
       case 2:
       
          basePosSave[1]= pot1Angle;          // salva a posição da variável da base na posiação 1 do vetor
          bracoPosSave[1]= pot2Angle;         // salva a posição da variável do braço na posição 1 do vetor
          antebracoPosSave[1]= pot3Angle;     // salva a posição da variável do antebraço na posição 1 do vetor
          garraPosSave[1]= pot4Angle;         // salva a posição da variável da garra na posição 1 do vetor
          

          Serial.println("Posição #2 Salvo"); // informa que a posição número 2 foi salva
          break;

        case 3:

        
          basePosSave[2]= pot1Angle;          // salva a posição da variável da base na posição 2 do vetor       
          bracoPosSave[2]= pot2Angle;         // salva a posição da variável do braço na posição 2 do vetor
          antebracoPosSave[2]= pot3Angle;     // salva a posição da variável do antebraço na posição 2 do vetor
          garraPosSave[2]= pot4Angle;         // salva a posição da variável da garra na posição 2 do vetor
          
          Serial.println("Posição #3 Salvo"); // informa que a posição número 3 foi salva
          break;


      case 4:

          basePosSave[3]= pot1Angle;          // salva a posição da variável da base na posição 3 do vetor
          bracoPosSave[3]= pot2Angle;         // salva a posição da variável do braço na posição 3 do vetor
          antebracoPosSave[3]= pot3Angle;     // salva a posição da variável do antebraço na posição 3 do vetor
          garraPosSave[3]= pot4Angle;         // salva a posição da variável da garra na posição 3 do vetor

          Serial.println("posição #4 Salvo"); // informa que a posição número 3 foi salva
          break;


      case 5:
      
          basePosSave[4]= pot1Angle;          // salva a posição da variável da base na posição 4 do vetor
          bracoPosSave[4]= pot2Angle;         // salva a posição da variável do braço na posição 4 do vetor
          antebracoPosSave[4]= pot3Angle;     // salva a posição da variável do antebraço na posição 4 do vetor
          garraPosSave[4]= pot4Angle;         // salva a posição da variável da garra na posição 4 do vetor
          

          Serial.println("Posição #5 Salvo"); // informa que a posição número 4 foi salva
          break;
  }

}

//  Verifica se o botão2 foi pressionado

  if(digitalRead(button2) == HIGH){

    button2Pressed = true;                   // Altera a variável booleana para verdadeiro
    Serial.println("Executando");           // Informa que o processo de repetição ja está sendo executado
  }


// Realiza a repetição enquanto a variável for verdadeira
  while(button2Pressed){

  if(digitalRead(sensor)==LOW){          // Se o sensor estiver acionado (em nivel lógico baixo) realiza os movimentos
   
    for(int i=0; i<5; i++){

        base.slowmove(basePosSave[i],40);     // posiciona o servo da base na posição salva, fazendo-o se mover em determinada velocidade
        delay(500);                           // Aguarda 500 milissegundos
        braco1.slowmove(bracoPosSave[i],40);    // posiciona o servo braço1 na posição salva, fazendo-o se mover em determinada velocidade
        braco2.slowmove(bracoPosSave[i],40);    // posiciona o servo braço2 na posição salva, fazendo-o se mover em determinada velocidade
        antebraco.slowmove(antebracoPosSave[i],40);   // posiciona o do antebraço da base na posição salva, fazendo-o se mover em determinada velocidade
        delay(500);                             // Aguarda 500 milissegundos
        garra.slowmove(garraPosSave[i],40);     // posiciona o servo da garra na posição salva, fazendo-o se mover em determinada velocidade
        
        delay(2000);                            // aguarda 2000 milissegundos (2 segundos)
      }

    }
    
  }

}












