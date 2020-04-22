#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int key;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//int enB = 6;
//int in3 = 5;
//int in4 = 4;
int enB = 11;
int in3 = 10;
int in4 = 12;
  
void setup()
{
  Serial.begin(9600);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
//  keypad.setDebounceTime(1000);
  
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("JARTEKITO");
  lcd.setCursor(3,1);
  lcd.print("REDIETA FZ");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("1 Coagulation");
  lcd.setCursor(0,1);
  lcd.print("2 Flocculation");
  
}
  
void loop()
{
  char key = keypad.waitForKey(); // just print the pressed key
  char number1, number2;
  if (key =='1'){ // if key matches what you are looking for
  lcd.clear(); 
  lcd.print(key);
  delay(1000);

  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("1)15 | 3)45");
  lcd.setCursor(0,1);
  lcd.print("2)30 | 4)60 coa");
  keypad.setDebounceTime(100);

  number1=keypad.waitForKey();
  switch(number1)
  {
    case'1':
    lcd.clear();
    lcd.print(number1);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm:700 coa");
    lcd.setCursor(0,1);
    lcd.print("time:15mnt coa");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (5 * 1 * 1000);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.clear();
    lcd.print("Process DONE");
    break;
   
    case'2':
    lcd.clear();
    lcd.print(number1);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm: 700 coa");
    lcd.setCursor(0,1);
    lcd.print("time: 30mnt coa");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (2 * 1 * 1000);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.clear();
    lcd.print("Process DONE");
    break;
    
    case'3':
    lcd.clear();
    lcd.print(number1);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm: 700 coa");
    lcd.setCursor(0,1);
    lcd.print("time: 45mnt coa");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (3 * 1 * 1000);
    lcd.clear();
    lcd.print("Process DONE");
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    break;
    
    case'4':
    lcd.clear();
    lcd.print(number1);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm: 700 coa");
    lcd.setCursor(0,1);
    lcd.print("time: 60mnt coa");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (4 * 1 * 1000);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.clear();
    lcd.print("Process DONE");
    break;

    default:
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);

  //  if (key =='5' || key =='6' || key =='7' || key =='8' || key =='9' || key =='*' || key =='0' || key =='#');{
  //  lcd.print("false key");
  
    
  }}
  
  if (key =='2'){ // if key matches what you are looking for
  lcd.clear(); 
  lcd.print(key);
  delay(1000);

  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("1)15 | 3)45");
  lcd.setCursor(0,1);
  lcd.print("2)30 | 4)60 floc");
  keypad.setDebounceTime(100);

  number2 = keypad.waitForKey();
  switch(number2)
  {
    case'1':
    lcd.clear();
    lcd.print(number2);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm:5 floc");
    lcd.setCursor(0,1);
    lcd.print("time:15mnt floc");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (1 * 1 * 1000);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.clear();
    lcd.print("Process DONE");
    break;
      
    case'2':
    lcd.clear();
    lcd.print(number2);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm: 5 floc");
    lcd.setCursor(0,1);
    lcd.print("time: 30mnt floc");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (2 * 1 * 1000);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.clear();
    lcd.print("Process DONE");
    break;
    
    case'3':
    lcd.clear();
    lcd.print(number2);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm: 5 floc");
    lcd.setCursor(0,1);
    lcd.print("time: 45mnt floc");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (3 * 1 * 1000);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.clear();
    lcd.print("Process DONE");
    break;
    
    case'4':
    lcd.clear();
    lcd.print(number2);
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("rpm: 4 floc");
    lcd.setCursor(0,1);
    lcd.print("time: 60mnt floc");
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB, 255);
    delay (4 * 1 * 1000);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    lcd.clear();
    lcd.print("Process DONE");
    break;
    
    default:
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);

   // if (key =='5' || key =='6' || key =='7' || key =='8' || key =='9' || key =='*' || key =='0' || key =='#');{
  //  lcd.print("false key");
  
    }
    }
    }
  

  //if (key =='3' || key =='4' || key =='5' || key =='6' || key =='7' || key =='8' || key =='9' || key =='*' || key =='0' || key =='#');{
 // lcd.clear(); 
  //lcd.print("Wrong Input");

  
