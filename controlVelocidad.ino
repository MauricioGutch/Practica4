//Este programa lee la señal analógica de un potenciómetro, determina si gira hacia la derecha o hacia la izquierda.
//También, con el potenciómetro podemos variar la velocidad de 0 rev/m hasta las máximas revoluciones por minuto.
int analogPin= A0;//Pin A0 configurada como entrada para leer el potenciómetro
float aux1=0, aux2=0;//Variables auxiliares para procesar las señales

void setup() {
  pinMode(12, OUTPUT);//Input1 del puente H
  pinMode(11, OUTPUT);//Input2 del puente H
  pinMode(10, OUTPUT);//Enable configurado para PWM
  pinMode(9, OUTPUT);//Led1
  pinMode(8, OUTPUT);//Led2

}

void loop() {
  aux1= analogRead(analogPin); //Lectura digital de la señal del potenciómetro
  aux2= map(aux1, 0, 1023, -255, 255); //Se mapea la señal del potenciómetro para determinar sentido de giro y la velocidad.
  aux2= abs(aux2);//Se manda señal positivas ya que el puente H no interpreta negativos
  analogWrite(10, aux2 ); //Se manda la señal PWM al Enable del puente H 
  
  if ( aux1 < 512 ){ // Sentido de giro hacia la derecha
      digitalWrite(12, HIGH);//Con este encendido el puente H marca la salida 1.1 como positiva
      digitalWrite(11, LOW);//Con este pin apagado, la salida 1.2 es la parte negativa del motor
      digitalWrite(9, HIGH);//El led 1 enciende indicando el sentido de giro
      digitalWrite(8, LOW);
    }
  if (aux1 > 512){// Sentido de giro hacia la izquierda
    digitalWrite(12, LOW);//Con este pin apagado, la salida 1.1 es la parte negativa del motor
    digitalWrite(11, HIGH);//Con este encendido el puente H marca la salida 1.2 como positiva
    digitalWrite(9, LOW);
    digitalWrite(8, HIGH);//El led 2 enciende indicando el sentido de giro
  }
  
 
                           
}
