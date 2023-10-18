const int Trigger = 2;   // Pin digital 2 para el Trigger del sensor
const int Echo = 3;      // Pin digital 3 para el Echo del sensor

void setup() {
  Serial.begin(9600);  // inicializamos la comunicación
  pinMode(Trigger, OUTPUT); // pin como salida
  pinMode(Echo, INPUT);     // pin como entrada
  digitalWrite(Trigger, LOW); // Inicializamos el pin con 0
}

void loop()
{
  long t; // tiempo que demora en llegar el eco
  long d; // distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          // Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH);  // obtenemos el ancho del pulso
  d = t/59;                 // escalamos el tiempo a una distancia en cm

  // Calcular lo lleno del bote
  long porcentaje = (50 - d) * 2;  // multiplicamos por 2 para escalar el valor al rango 0-100
  String value = "#" + roundToSetValues(porcentaje) + "!";

  Serial.print(value);
  Serial.println();

  delay(200); // Hacemos una pausa de 200ms
}
String roundToSetValues(long value) {
  if (value <= 10) return "0";
  else if (value <= 30) return "20";
  else if (value <= 45) return "40";
  else if (value <= 55) return "50";
  else if (value <= 70) return "60";
  else if (value <= 90) return "80";
  else return "100";
}

