//Sketch PK1 Arduino emulando Radiuino

 
int ID; // Nesta variável deve estar o endereço do nó sensor.
byte PacoteRX[52]; // Pacote de 52 bytes que será recebido pelo nó sensor
byte PacoteTX[52]; // Pacote de 52 bytes que será transmitido pelo nó sensor
int LeituraADC0,LeituraADC1,LeituraADC2,LeituraADC3,LeituraADC4,LeituraADC5; // Variáveis para cada um dos conversores analógico digital. Neste exemplo só está usando o ADC 0
int IO0_PIN,IO1_PIN,IO2_PIN,IO3_PIN,IO4_PIN,IO5_PIN; // pinos que podem ser saída ou entrada digital
int IO0_STATUS,IO1_STATUS,IO2_STATUS,IO3_STATUS,IO4_STATUS,IO5_STATUS; // Variáveis de status do IO correspondente. Será usado para funcionar com o toggle (alternância) do ScadaBR
int contador_pacote_TX; // Variável para contar os pacotes transmitidos pelo nó sensor
int MAXTEMP,MINTEMP,MAXLUM,MINLUM,SOMADORTEMP, SOMADORLUM, CONTADOR;
float MEDIATEMP,MEDIALUM;
float temperatura;
int luminosidade;
int luminosidade_map;

// Define os pinos IO igual ao que é feito no Arduino utilizando a nomenclatura IO#_PIN
#define IO3_PIN  3
#define IO4_PIN  4
#define IO5_PIN  5
#define IO6_PIN  6
#define IO9_PIN  9
#define IO10_PIN  10


void setup() {
  
  Serial.begin(9600);
  contador_pacote_TX = 0; // Variável de contador de pacotes transmitidos é zerado
  IO0_STATUS=IO1_STATUS=IO2_STATUS=IO3_STATUS=IO4_STATUS=IO5_STATUS=0;
  ID = 1; // Identificação do nó sensor. É o endereço do nó sensor
  CONTADOR = 0;
  MAXTEMP = 0;
  MEDIATEMP = 0;
  MINTEMP =1024;
  MAXLUM = 0;
  MEDIALUM = 0;
  MINLUM =1024;

  pinMode (IO3_PIN, OUTPUT); 
  pinMode (IO4_PIN, OUTPUT); 
  pinMode (IO5_PIN, OUTPUT); 
  pinMode (IO6_PIN, OUTPUT); 
  // pinMode (IO9_PIN, OUTPUT); 
  pinMode (IO10_PIN, OUTPUT); 
  
}

void loop() {
  
        // Medida da intensidade sonora
/*        CONTADOR = CONTADOR + 1; // Contador do número de medidas da intensidade sonora
        LeituraADC2 = analogRead(A2); // leitura instantânea da temperatura
        MAXTEMP = LeituraADC2; // Algoritmo para determinar o valor máximo        
        SOMADORTEMP = LeituraADC0 + SOMADORTEMP;//totalização do valor
        MEDIATEMP = SOMADORTEMP/CONTADOR;// Calcula a média
        MINTEMP = 0;
        
        LeituraADC3 = analogRead(A3); // leitura instantânea da luminosidade
        MAXLUM = LeituraADC2; // Algoritmo para determinar o valor máximo        
        SOMADORLUM = LeituraADC0 + SOMADORTEMP;//totalização do valor
        MEDIALUM = SOMADORLUM/CONTADOR;// Calcula a média
        MINLUM = 0;*/
        // Algoritmo para determinar o mínimo
        
  
  
        // Verifica se existem 52 bytes no buffer da serial
	if (Serial.available() >=52)   // recebe pacote que entrou pela USB
	{
		
   // Leitura do buffer da serial e zera pacote de transmissão
      for (int i = 0; i < 52; i++) // PacoteTX[#] é preenchido com zero e PacoteRX[#] recebe os bytes do buffer
		  {
			    PacoteTX[i] = 0; // Zera o pacote de transmissão
			    PacoteRX[i] = Serial.read();  // Faz a leitura dos bytes que estão no buffer da serial
          delay(1); // Intervalo de 1 ms para cada ciclo do for para estabilidade
		  }
		
      if ( PacoteRX[8] == ID && PacoteRX[10] == 0) //Checa se o pacote é para este nó sensor  
      {
      // troca de endereços para que no pacote que vai ser transmitido o destino seja a base
          PacoteTX[8] = PacoteRX[10]; // Endereço de destino de transmissão é igual ao endereço de origem da recepção
          PacoteTX[10] = PacoteRX[8]; // Endereço de origem de transmissão é igual ao endereço de destino da recepção      		
// Pacote RX acionando atuadores

  if (PacoteRX[34] == 1)  // PK1 LED verde
  {
    digitalWrite (IO4_PIN, HIGH); // Liga led vermelho no DK101
  }
  else 
  {
    digitalWrite (IO4_PIN, LOW); // Desliga led vermelhor no DK101
  }
   
 
  if (PacoteRX[1] == 1)  // PK1 LED amarelo
  {
    digitalWrite (IO5_PIN, HIGH);
  }
  else 
  {
    digitalWrite (IO5_PIN, LOW);
  }

  // IO2 - pino 18 do BE900
  if (PacoteRX[2] == 1)  // PK1 LED vermelho
  {
    digitalWrite (IO6_PIN, HIGH);
  }
  else 
  {
    digitalWrite (IO6_PIN, LOW);
  }
 
  if (PacoteRX[3] == 1)  // Este é o byte 43
  {
    tone(IO9_PIN, 1000, 1000);
  }
  else 
  {
    //tone(IO9_PIN, 500, 1000);
  }


// Sensores de temperatura, luminosidade e botão
          temperatura = 100*((float(analogRead(A3))*5/(1023))/0.01);
     // Escreve a média entre requisições da temperatura lida no ADC2 da Placa 1 no pacote
          PacoteTX[16] = 0; // Pode ser utilizado para indicar o tipo de sensor no byte 16
          PacoteTX[17] = (byte) ((int)(temperatura)/256); // Valor inteiro no byte 17
          PacoteTX[18] = (byte) ((int)(temperatura)%256); // Resto da divisão no byte 18
          
     // Valor máximo temperatura
          PacoteTX[19] = 0; // Pode ser utilizado para indicar o tipo de sensor no byte 19
          PacoteTX[20] = (byte) ((int)(temperatura)/256); // Valor inteiro no byte 20
          PacoteTX[21] = (byte) ((int)(temperatura)%256); // Resto da divisão no byte 21
          
     // Valor mínimo temperatura
          PacoteTX[22] = 0; // Pode ser utilizado para indicar o tipo de sensor no byte 16
          PacoteTX[23] = (byte) ((int)(MINTEMP)/256); // Valor inteiro no byte 17
          PacoteTX[24] = (byte) ((int)(MINTEMP)%256); // Resto da divisão no byte 18          

          luminosidade = analogRead(A3);
          luminosidade_map = 100 - map(luminosidade, 100, 1023, 0, 100);
     // Escreve a média entre requisições da luminosidade lida no ADC3 da Placa 1 no pacote
          PacoteTX[25] = 0; // Pode ser utilizado para indicar o tipo de sensor no byte 19
          PacoteTX[26] = (byte) ((int)(luminosidade_map)/256); // Valor inteiro no byte 20
          PacoteTX[27] = (byte) ((int)(luminosidade_map)%256); // Resto da divisão no byte 21
                      
     // Valor máximo luminosidade
          PacoteTX[28] = 0; // Pode ser utilizado para indicar o tipo de sensor no byte 19
          PacoteTX[29] = (byte) ((int)(luminosidade)/256); // Valor inteiro no byte 20
          PacoteTX[30] = (byte) ((int)(luminosidade)%256); // Resto da divisão no byte 21
          
     // Valor mínimo luminosidade
          PacoteTX[31] = 0; // Pode ser utilizado para indicar o tipo de sensor no byte 16
          PacoteTX[32] = (byte) ((int)(MINLUM)/256); // Valor inteiro no byte 17
          PacoteTX[33] = (byte) ((int)(MINLUM)%256); // Resto da divisão no byte 18          
                           		
      // Contador de pacotes transmitidos
         contador_pacote_TX = contador_pacote_TX + 1;
         PacoteTX[12] = contador_pacote_TX;
                        
      // Transmissão do pacote pela serial do Arduino que vai ser enviado para o ScadaBR via USB
         for (int i = 0; i < 52; i++)
        			{
        			Serial.write(PacoteTX[i]);
        			}
 
     } // if do endereço do sensor		
	} // if do recebimento do pacote
} // fim do lopp()

    

       		
 
     
