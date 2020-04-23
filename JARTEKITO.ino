#include <LiquidCrystal_I2C.h> // library LCD
#include <Keypad.h> // library keypad

LiquidCrystal_I2C lcd(0x3F,20,4);  
// mengatur alamat lcd 0x3F untuk display 16 karakter dan 2 baris

int key; // deklarasi variabel key dengan kapasitas 16 bit

const byte ROWS = 4; // deklarasi 4 baris
const byte COLS = 3; // deklarasi 3 kolom
char keys[ROWS][COLS] = { // matriks keypad dengan kapasitas 8 bit
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // menghubungkan pinout baris pada keypad
byte colPins[COLS] = {6,7,8}; // menghubungkan pinout kolom pada keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
// deklarasi jenis key pada keypad (pin baris dan kolom)

int enB = 11; 
// deklarasi L298N pin enable B di pin 11 arduino dengan kapasitas 16 bit
int in3 = 10; 
// deklarasi L298N pin enable B di pin 11 arduino dengan kapasitas 16 bit
int in4 = 12; 
// deklarasi L298N pin enable B di pin 11 arduino dengan kapasitas 16 bit

int encoderc1 = 2; // deklarasi pin 2 encoder motor dengan kapasitas 16 bit
int encoderc2 = 4; // deklarasi pin 2 encoder motor dengan kapasitas 16 bit

volatile long encoderValue; // deklarasi nilai encoder

void setup() // program di dalamnya hanya dijalankan 1 kali
{ // pembuka statement void setup
  Serial.begin(9600);
  // mengatur data rate (bit per second) untuk serial data transmission

  pinMode(enB, OUTPUT); 
  // mengonfigurasi pin enable b l298n yang ditentukan sebagai output
  pinMode(in3, OUTPUT);
  // mengonfigurasi pin input 3 l298n yang ditentukan sebagai output
  pinMode(in4, OUTPUT);
  // mengonfigurasi pin input 4 l298n yang ditentukan sebagai output
  
  pinMode(encoderc1, INPUT);
  // mengonfigurasi encoderc1 sebagai input
  pinMode(encoderc2, INPUT);
  // mengonfigurasi encoderc2 sebagai input
  
  lcd.init(); // inisialisasi lcd
  lcd.backlight(); // menyalakan backlight lcd
  lcd.setCursor(4,0); // mengatur cursor lcd: kolom 5 baris 1
  lcd.print("JARTEKITO"); // mencetak tulisan JARTEKITO ke lcd
  lcd.setCursor(3,1); // mengatur cursor lcd: kolom 4 baris 2
  lcd.print("REDIETA FZ"); // mencetak tulisan REDIETA FZ ke lcd
  delay(2000); // menjalankan program sebelumnya selama 2 detik
  lcd.clear();// membersihkan layar lcd

  lcd.setCursor(0,0); // mengatur cursor lcd: kolom 1 baris 1
  lcd.print("1 Coagulation"); // mencetak tulisan 1 Coagulation ke lcd
  lcd.setCursor(0,1); // mengatur cursor lcd: kolom 1 baris 2
  lcd.print("2 Flocculation"); // mencetak tulisan 2 Flocculation ke lcd
  
} // penutup statement void setup
  
void loop() // program di dalamnya hanya dijalankan berkali-kali
{ // pembuka statament void loop
  char key = keypad.waitForKey(); 
  // deklarasi tpe data char untuk key dengan kapasitas 8 bit
  
  char number1, number2; // deklarasi switch case dengan kapasitas 8 bit
  
  if (key =='1') // jika keypad yang ditekan angka 1, maka:
  {
  lcd.clear(); // membersihkan layar lcd
  lcd.print(key); // mencetak key yang ditekan
  delay(1000); // menjalankan program sebelumnya selama 1 detik

  lcd.clear(); // membersihkan layar lcd
  lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
  lcd.print("1)15 | 3)45"); // mencetak tulisan 1)15 | 3)45 ke lcd
  lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
  lcd.print("2)30 | 4)60 coa"); // mencetak tulisan 2)30 | 4)60 coa ke lcd
  keypad.setDebounceTime(100); 
  // mengecek dan memastikan keypad telah ditekan, mengalami delay 0,1 detik

  number1=keypad.waitForKey();
  // deklarasi vaiabel number1 sebagai penghubung dengan statement switch case
  
  switch(number1) // statement pengambilan keputusan dengan beberapa alternatif
  {
    case'1': // pilihan jika menekan key 1, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number1); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:70 coa"); // mencetak tulisan rpm:70 coa pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:15mnt coa"); // mencetak tulisan time:15mnt coa pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 150); // mengatur kecepatan putar motor
    delay (15 * 60 * 1000); // menjalankan program sebelumnya selama 15 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    lcd.clear(); // membersihkan layar lcd
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; // menghentikan program

    case'2': // pilihan jika menekan key 2, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number1); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:70 coa"); // mencetak tulisan rpm:70 coa pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:30mnt coa"); // mencetak tulisan time:30mnt coa pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 150); // mengatur kecepatan putar motor
    delay (30 * 60 * 1000); // menjalankan program sebelumnya selama 30 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    lcd.clear(); // membersihkan layar lcd
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; // menghentikan program

    case'3': // pilihan jika menekan key 3, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number1); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:70 coa"); // mencetak tulisan rpm:70 coa pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:45mnt coa"); // mencetak tulisan time:45mnt coa pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 150); // mengatur kecepatan putar motor
    delay (45 * 60 * 1000); // menjalankan program sebelumnya selama 45 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    lcd.clear(); // membersihkan layar lcd
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; // menghentikan program
    
    case'4': // pilihan jika menekan key 4, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number1); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:70 coa"); // mencetak tulisan rpm:70 coa pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:60mnt coa"); // mencetak tulisan time:60mnt coa pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 150); // mengatur kecepatan putar motor
    delay (60 * 60 * 1000); // menjalankan program sebelumnya selama 60 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    lcd.clear(); // membersihkan layar lcd
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; // menghentikan program
    
    default: // selain pilihan key pada switch case sebelumnya, maka:
    digitalWrite(in3,LOW); // pin input 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin input 4 pada L298N bernilai LOW
    }
  }
  
  if (key =='2') // jika keypad ditekan angka 1, maka:
  { // pembuka statement if
  lcd.clear(); // membersihkan layar lcd
  lcd.print(key); // mencetak key yang ditekan
  delay(1000); // menjalankan progran sebelumnya selama 1 detik

  lcd.clear(); // membersihkan layar lcd
  lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
  lcd.print("1)15 | 3)45"); // mencetak tulisan 1)15 | 3)45 pada LCD
  lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
  lcd.print("2)30 | 4)60 floc"); // mencetak tulisan 2)30 | 4)60 floc pada LCD
  keypad.setDebounceTime(100);
  // mengecek dan memastikan keypad telah ditekan, mengalami delay 0,1 detik

  number2 = keypad.waitForKey();
  // deklarasi variabel number2 sebagai penghubung dengan statement switch case
  
  switch(number2) // statement pengambilan keputusan dengan beberapa alternatif
  { // pembuka statement swict case
    case'1': // pilihan jika menekan key 1, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number2); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:5 floc"); // mencetak tulisan rpm:5 floc pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:15mnt floc"); // mencetak tulisan time:15mnt floc pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 50); // mengatur kecepatan putar motor
    delay (15 * 60 * 1000); // menjalankan program sebelumnya selama 15 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 L298N bernilai LOW
    lcd.clear(); // membersihkan layar LCD
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; //menghentikan program

    case'2': // pilihan jika menekan key 2, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number2); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:5 floc"); // mencetak tulisan rpm:5 floc pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:30mnt floc"); // mencetak tulisan time:30mnt floc pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 50); // mengatur kecepatan putar motor
    delay (30 * 60 * 1000); // menjalankan program sebelumnya selama 30 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 L298N bernilai LOW
    lcd.clear(); // membersihkan layar LCD
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; //menghentikan program

    case'3': // pilihan jika menekan key 3, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number2); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:5 floc"); // mencetak tulisan rpm:5 floc pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:45mnt floc"); // mencetak tulisan time:45mnt floc pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 50); // mengatur kecepatan putar motor
    delay (45 * 60 * 1000); // menjalankan program sebelumnya selama 45 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 L298N bernilai LOW
    lcd.clear(); // membersihkan layar LCD
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; //menghentikan program  

    
    case'4': // pilihan jika menekan key 4, maka:
    lcd.clear(); // membersihkan layar lcd
    lcd.print(number2); // mencetak tulisan yang ditekan oleh keypad
    delay(1000); // menjalankan program sebelumnya selama 1 detik
    lcd.clear(); // membersihkan layar lcd
    lcd.setCursor(0,0); // mengatur cursor lcd kolom 1 baris 1
    lcd.print("rpm:5 floc"); // mencetak tulisan rpm:5 floc pada LCD
    lcd.setCursor(0,1); // mengatur cursor lcd kolom 1 baris 2
    lcd.print("time:60mnt floc"); // mencetak tulisan time:60mnt floc pada LCD
    digitalWrite(in3,HIGH); // pin output 3 pada L298N bernilai HIGH
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
    analogWrite(enB, 50); // mengatur kecepatan putar motor
    delay (60 * 60 * 1000); // menjalankan program sebelumnya selama 60 menit
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 L298N bernilai LOW
    lcd.clear(); // membersihkan layar LCD
    lcd.print("Process DONE"); // mencetak tulisan Process DONE
    break; //menghentikan program
    
    default: // selain pilihan key pada switch case sebelumnya, maka:
    digitalWrite(in3,LOW); // pin output 3 pada L298N bernilai LOW
    digitalWrite(in4,LOW); // pin output 4 pada L298N bernilai LOW
  
    } // penutup statement switch case
   } // penutup statement if
  } // penutup statement void loop
  
  
