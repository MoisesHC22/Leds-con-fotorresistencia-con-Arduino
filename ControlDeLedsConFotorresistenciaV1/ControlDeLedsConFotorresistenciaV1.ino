
// Declaración de variables. 

  // Para los leds.
    int L1 = 3;
    int L2 = 4;
    int L3 = 5;
    int L4 = 6;
    int L5 = 7;

  // Para la fotorresistencia.
    int FotoR = A5;


void setup()
{
  
 // Configuraciones de pines de salida. 
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  Serial.begin(9600);
  
}


// Función en donde recibe un valor para prender y apagar además del pin del led en un segundo.

void OnOff(bool Opc ,int Pin)
{
  if(Opc == true)
  {
   digitalWrite(Pin, HIGH);
   delay(3000);
  }
  else
  {
   digitalWrite(Pin, LOW);
  }
}

void loop()
{
  
  // Se crea un arreglo en donde contendrá los pines de salida.
  int leds[] = {L1, L2, L3, L4, L5};
  
  // Creamos una variable en donde obtendrá el número de elementos del arreglo. 
  int NumLeds = sizeof(leds) / sizeof(leds[0]);
  
  // Declaramos una variable en donde optenemos del valor de la fotorresistencia.
  int Valor_F = analogRead(FotoR);
  
  // Imprimimos el valor de la fotorresistencia en el serial Monitor.
  Serial.println(Valor_F);
  
  
  /* 
     Realizamos una validación en donde si el valor de la fotorresistencia es menor o igual que
     "942" se realizara un ciclo for en donde se enviara los pines de salida de los leds a prender
     y si no cumple con la condición se realizara otro ciclo for para apagar los leds.
  */
  
    if(Valor_F <= 942)
    {
        for(int i = 0; i < NumLeds; i++)
        {
         OnOff(true,leds[i]);
        }
    }
    else
    {
        for(int i = 0; i < NumLeds; i++)
        {
         OnOff(false,leds[i]);
        }
    }
}
