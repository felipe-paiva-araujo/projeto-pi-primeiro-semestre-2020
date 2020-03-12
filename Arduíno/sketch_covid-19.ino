int pinoSensor = 5; // Saída do  sensor na A5.
int valorLido = 0; //Variável  auxiliar.
float temperatura = 0; //Variável que armazenará a temperatura lida
String linha = ""; //Variável que se refere as linhas do excel

void setup () {//Função que será executada uma
  Serial.begin(9600); //Inicia a comunicação serial a 9600 bauds.
  Serial.println ("CLEARDATA"); //reset comunicação serial
  Serial.println ("Temperatura"); //nomeia a coluna
}
void loop () {//Função que será executada continuamente.
valorLido = analogRead(pinoSensor);//Leitura analógica da porta A5
temperatura = (valorLido * 0.00488); // 5 volts/ 1023 = 0,0048 precisão do A/D
temperatura = temperatura * 100;// converte milivolts para celsius = cada 10mV ==1 grau C
Serial.print(temperatura);
Serial.println(linha);

if(linha >100) // loop para limitar a quantidade de dados
{
  linha = "";
  Serial.println("ROW,SET,2");//alimentação das linhas sempre com os dados iniciados
}
delay(1000); //Tempo 5 segundos para realizar utra leitura
}
