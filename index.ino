const int Y0 = 8;
const int Y1 = 9;
const int Y2 = 10;
const int Y3 = 11;

const int CLK = 7;

void writeLookup(int val0,int val1,int val2,int val3){
  digitalWrite(CLK,LOW);
  digitalWrite(Y0,val0);
  digitalWrite(Y1,val1);
  digitalWrite(Y2,val2);
  digitalWrite(Y3,val3);
  delay(1);
  digitalWrite(CLK,HIGH);
  delay(2);
  digitalWrite(CLK,LOW);
  Serial.print("Wrote ");
  Serial.print(val0);
  Serial.print(val1);
  Serial.print(val2);
  Serial.println(val3);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Y0,OUTPUT);
  pinMode(Y1,OUTPUT);
  pinMode(Y2,OUTPUT);
  pinMode(Y3,OUTPUT);
  pinMode(CLK,OUTPUT);
  
  
  Serial.println("1.AND gate");
  Serial.println("2.OR gate");
  Serial.println("3.NAND gate");
  Serial.println("4.NOR gate");
  Serial.println("5.XOR gate");
  
   
} 

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    int x;
    x = Serial.read();
    x -= 48;
    Serial.println(x);
    switch(x){
      case 1 : 
        writeLookup(0,0,0,1);
        break;
      
      case 2 : 
        writeLookup(0,1,1,1);
        break;
      
      case 3 : 
        writeLookup(1,1,1,0);
        break;
  
      case 4 : 
        writeLookup(1,0,0,0);
        break;

      case 5 : 
        writeLookup(0,1,1,0);
        break;
  
      default:
        writeLookup(0,0,0,0);
        break;  
    }
  }
}
