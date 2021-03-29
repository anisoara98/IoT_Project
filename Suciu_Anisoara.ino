//Suciu Anisoara
//constante

const int buttonPin1 = 8; //pinul asociat luminii de frana

const int buttonPin2 = 9; //pinul asociat semnalizarii de stanga

const int buttonPin3 = 10; //pinul asociat semnalizarii de dreapta

const int buttonPin4 = 11; //pinul asociat avariei

const int buttonPin5 = 12; //pinul asociat sirenei

const int ledPin1 = 2; //primul led folosit

const int ledPin2 = 3; //al doilea led folosit

const int ledPin3 = 4; //al treilea led folosit

const int ledPin4 = 5;//al patrulea led folosit

const int buzzer = 7; //piezo

//variabile

int buttonState1 = 0; //setez frana ca fiind oprita

int buttonState2 = 0; //setez semnalizarea stanga ca fiind oprita

int buttonState3 = 0; //setez semnalizarea dreapta ca fiind oprita

int buttonState4 = 0; //setez avaria ca fiind oprita

int buttonState5 = 0; //setez sirena oprita


//setarea pinilor

void setup()

{
	
	Serial.begin(9600);
	
	pinMode(buttonPin1, INPUT);
	
	pinMode(buttonPin2, INPUT);
	
	pinMode(buttonPin3, INPUT);
	
	pinMode(buttonPin4, INPUT);
	
	pinMode(buttonPin5, INPUT);
	
	pinMode(ledPin1, OUTPUT);
	
	pinMode(ledPin2, OUTPUT);
	
	pinMode(ledPin3, OUTPUT);
	
	pinMode(ledPin4, OUTPUT);
	
	pinMode(buzzer,OUTPUT);
	
}




void loop()

{
	
	buttonState1 = digitalRead(buttonPin1); // verific daca frana este actionata
	
	buttonState2 = digitalRead(buttonPin2); // verific daca semnalizarea stanga este actionata
	
	buttonState3 = digitalRead(buttonPin3); //verific daca semnalizarea dreapta este actionata
	
	buttonState4 = digitalRead(buttonPin4); // verific daca avaria este actionata
	
	buttonState5 = digitalRead(buttonPin5); // verific daca sirena este actionata
	
	//actionare frana
	
	if (buttonState1 == LOW)
		
	{
		
		Serial.println("Actionare frana");
		
		//setez toate cele 3 led-uri ca fiind pornite
		
		digitalWrite(ledPin1, HIGH);
		digitalWrite(ledPin2, HIGH);
		digitalWrite(ledPin3, HIGH);
		delay(500);
		
	}
	else
	{
		//actionare semnal stanga
		
		if (buttonState2 == LOW) 
		{
			
			Serial.println("Actionare semnal stanga");
			
			digitalWrite(ledPin1, HIGH); //setez primul led ca fiind pornit
			
			delay(500);
			
			digitalWrite(ledPin1, LOW); //opresc led 1
			
			digitalWrite(ledPin2, HIGH); //setez al doilea led ca fiind pornit
			
			delay(500);
			
			digitalWrite(ledPin2, LOW); //opresc led2
			
			digitalWrite(ledPin3, HIGH); //setez al treilea led ca fiind pornit
			
			delay(500);
			
			digitalWrite(ledPin3, LOW); //opresc led3
			
		}
		
		else
		{
			//actionare semnal dreapta
			
			if (buttonState3 == LOW) 
			{
				
				Serial.println("Actionare semnal dreapta");
				
				digitalWrite(ledPin3, HIGH); //setez al treilea led ca fiind pornit
				
				delay(500);
				
				digitalWrite(ledPin3, LOW); //opresc led3
				
				digitalWrite(ledPin2, HIGH); //setez al doilea led ca fiind pornit
				
				delay(500);
				
				digitalWrite(ledPin2, LOW); //opresc led2
				
				digitalWrite(ledPin1, HIGH); //setez primul led ca fiind pornit
				
				delay(500);
				
				digitalWrite(ledPin1, LOW); //opresc led1
				
			}
			
			else
			{
				if (buttonState5 == LOW)
					//actionam sirena
				
				{
				Serial.println("Actionare sirena");
				
					int timp=5; //timp de 5 de secunde sirena va functiona
					while(timp)
					{	timp--; //decrementez timpul cu o secunda
						
						digitalWrite(ledPin3, HIGH); //setez primul led ca fiind pornit
						digitalWrite(ledPin4, LOW); //opresc led4
						delay(500);
						
						
						
						for(int i=700;i<800;i++)
						{	
							
							tone(buzzer,i);
							delay(15);
						}
						
						digitalWrite(ledPin3, LOW); //opresc led3
						digitalWrite(ledPin4, HIGH); //pornesc led4
						delay(500);
						
						for(int i=800;i>700;i--)
						{ 	
							tone(buzzer,i);
							delay(15);
						}
						
						
						
					}
					digitalWrite(ledPin4, LOW); //opresc led4
					digitalWrite(ledPin3, LOW); //opresc led3
					noTone(buzzer);//se opreste sunetul
				}	
				
				else 
				{
					if(buttonState4 == LOW)
						//actionam avaria
					{
						
						Serial.println("Actionare avarie");
						
						int timp=5; //timp de 5 de secunde avaria va actiona
						
						while(timp) //cat timp variabila timp este diferita de 0 se tot repeta avaria
							
						{
							
							delay(500);
							
							timp--; //decrementez timpul cu o secunda
							
							if(timp%2==0) //daca variabila timp este un numar par
								
							{
								
								digitalWrite(ledPin1, LOW);
								
								digitalWrite(ledPin2, LOW);
								
								digitalWrite(ledPin3, LOW);
								
							}
							
							else 
							{
								
								digitalWrite(ledPin1, HIGH);
								
								digitalWrite(ledPin2, HIGH);
								
								digitalWrite(ledPin3, HIGH);
								
							}
							
						}
						
					}
					
					else {
						
						// oprim toate led-urile
						
						digitalWrite(ledPin1, LOW);
						
						digitalWrite(ledPin2, LOW);
						
						digitalWrite(ledPin3, LOW);
						digitalWrite(ledPin4, LOW);
						
					}
				}
			}
		}
	}
}