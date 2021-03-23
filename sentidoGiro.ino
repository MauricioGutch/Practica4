//Este programa recibe las señales de dos botones que controlan el sentido de giro de un motor, esto con la ayuda del puente H.
//Creamos estas dos variables para leer los botones
float aux1=0, aux2=0;

void setup() {
  pinMode(13, OUTPUT);//Enable del puente H
  pinMode(12, OUTPUT);//Input 1 del puente H
  pinMode(11, OUTPUT);//Input 2 del puente H
  pinMode(10, OUTPUT);//Led 1 
  pinMode(9, OUTPUT);//Led 2
  pinMode(8, INPUT);//Botón 1
  pinMode(7, INPUT);//Botón 2

}

void loop() {
  aux1= digitalRead(8); //Lectura digital de la señal del botón 1
  aux2= digitalRead(7); //Lectura digital de la señal del botón 2
  if (aux1 == 1 & aux2 == 0 ){ //Sólo el botón 1 está activado
    digitalWrite(13, HIGH);//El ENABLE del puente H se activa para permitir la salida del puente H
    digitalWrite(12, HIGH);//El input 1 recibe una señal positiva que determinará el sentido de giro (der)
    digitalWrite(10, HIGH);//Se enciende el led 1 para indicar el sentido de giro (der)
    }

  if (aux1 == 0 & aux2 == 1){//Sólo el botón 2 está activado
    digitalWrite(13, HIGH);//El ENABLE del puente H se activa para permitir la salida del puente H
    digitalWrite(11, HIGH);//El input 2 recibe una señal positiva que determinará el sentido de giro (izq)
    digitalWrite(9, HIGH);//Se enciende el led 2 para indicar el sentido de giro (izq)
    }

  if(aux1 == 1 & aux2 == 1){ //Ambos botones están activados y por lo tanto no debe girar, es un freno activo (gira a la misma intensidad en ambos sentidos)
        digitalWrite(13, HIGH);//El ENABLE del puente H se activa para permitir la salida del puente H
      digitalWrite(12, HIGH);//El input 1 recibe una señal positiva que determinará el sentido de giro (der)
    digitalWrite(10, HIGH);//Se enciende el led 1 para indicar el sentido de giro (der)
    digitalWrite(11, HIGH);//El input 2 recibe una señal positiva que determinará el sentido de giro (izq)
    digitalWrite(9, HIGH);//Se enciende el led 2 para indicar el sentido de giro (izq)
   }
  if (aux1 == 0 & aux2 == 0){ // Ningun botón está activado y por lo tanto no gira en ningún sentido, freno pasivo.
    digitalWrite(13, LOW);//El ENABLE del puente H se desactiva para no permitir la salida del puente H
      digitalWrite(12, LOW);//Input 1 no recibe señal
    digitalWrite(10, LOW);//Led 1 apagado
    digitalWrite(11, LOW);//Input 2 no recibe señal
    digitalWrite(9, LOW);//Led 2 apagado
        }
                           
}
