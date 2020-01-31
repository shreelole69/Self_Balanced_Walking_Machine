/*

                              Project Name:   Self Balace Walking
                              Author List:   Shree Lole
                                  
                              Filename:  Self Balance   
                            
                           
*/
int forward_tigh = 4 ;
int forward_knee = 5;
int forward_ankel = 6;

int reverse_tigh = 8 ;
int reverse_knee = 9 ;
int reverse_ankel = 10;

int VRx = A0;
int VRy = A1;
int SW = 0;

int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode( forward_tigh , OUTPUT);
  pinMode( forward_knee , OUTPUT);
  pinMode( forward_ankel , OUTPUT);
  pinMode(reverse_tigh , OUTPUT);
  pinMode(reverse_knee , OUTPUT);
  pinMode(reverse_ankel , OUTPUT);
  digitalWrite(forward_tigh , HIGH);
  digitalWrite(forward_knee , HIGH);
  digitalWrite(forward_ankel , HIGH);
  digitalWrite(reverse_tigh , HIGH);
  digitalWrite(reverse_knee , HIGH);
  digitalWrite(reverse_ankel , HIGH);

}

void loop() {
  SW_state = digitalRead(SW);
  mapX = map(analogRead(VRx), 0, 1023, -512, 512);
  Serial.print("X: ");
  Serial.print(mapX);
  if (SW_state == 1 && mapX >= 300)
  {
    digitalWrite(forward_tigh , LOW);
    delay(200);
    digitalWrite(forward_tigh , HIGH);
  }
  if (SW_state == 1 && mapX <= -300)
  {
    digitalWrite(reverse_tigh , LOW);
    delay(200);
    digitalWrite(reverse_tigh , HIGH);
  }
  mapY = map(analogRead(VRy), 0, 1023, -512, 512);

  if (SW_state == 1 && mapY >= 300)
  {
    digitalWrite(forward_ankel , LOW);
    delay(300);
    digitalWrite(forward_ankel , HIGH);
  }
  if (SW_state == 1 && mapY <= -300)
  {
    digitalWrite(reverse_ankel , LOW);
    delay(300);
    digitalWrite(reverse_ankel , HIGH);
  }
  if (SW_state == 0 && mapX >= 300)
  {
    digitalWrite(reverse_knee , LOW);
    delay(200);
    digitalWrite(reverse_knee , HIGH);
  }
  if (SW_state == 0 && mapX <= -300)
  {
    digitalWrite(forward_knee , LOW);
    delay(200);
    digitalWrite(forward_knee , HIGH);
  }
  delay(100);

}
