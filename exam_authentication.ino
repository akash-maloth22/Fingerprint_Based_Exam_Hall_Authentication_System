#include <LiquidCrystal.h>                         // include LCD library
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);           // initialize LCD with pin numbers

#include <Adafruit_Fingerprint.h>                  // include fingerprint sensor library
SoftwareSerial mySerial(2, 3);                     // define software serial pins (RX=2, TX=3)

int id;                                            // variable to store fingerprint ID
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial); // create fingerprint object

void setup()
{
  pinMode(A0,OUTPUT);                              // set pin A0 as output
  pinMode(A1,OUTPUT);                              // set pin A1 as output
  digitalWrite(A0,LOW);                            // initialize A0 to LOW
  digitalWrite(A1,LOW);                            // initialize A1 to LOW
  finger.begin(9600);                              // start fingerprint sensor at 9600 baud
  lcd.begin(16, 2);                                // initialize 16x2 LCD
  lcd.setCursor(0, 0);                             // move cursor to first line
  lcd.print("FINGERPRINT     ");                   // print heading on LCD
  lcd.setCursor(0, 1);                             // move to second line
  lcd.print("DETECTOR        ");                   // print second line
  delay(3000);                                     // wait for 3 seconds
  lcd.clear();                                     // clear LCD screen
}

void loop()
{
  lcd.clear();                                     // clear LCD
  lcd.setCursor(0, 0);                             // move to first line
  lcd.print("PLACE THE       ");                   // ask user to place finger
  lcd.setCursor(0, 1);                             // move to second line
  lcd.print("FINGER          ");                   // show message
  id = getFingerprintID();                         // get fingerprint ID from sensor
  
  if (id == 1)                                     // if ID = 1 (Thumb)
  {
    lcd.setCursor(0, 0); lcd.print("THUMB           ");
    lcd.setCursor(0, 1); lcd.print("                ");
    digitalWrite(A0,LOW); digitalWrite(A1,HIGH); delay(50);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,HIGH); digitalWrite(A1,LOW); delay(50);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW);
  }
  
  else if (id == 3)                                // if ID = 3 (Index finger)
  {
    lcd.setCursor(0, 0); lcd.print("INDEX           ");
    lcd.setCursor(0, 1); lcd.print("FINGER          ");
    digitalWrite(A0,LOW); digitalWrite(A1,HIGH); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,HIGH); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW);
  }
  
  else if (id == 5)                                // if ID = 5 (Middle finger)
  {
    lcd.setCursor(0, 0); lcd.print("MIDDLE          ");
    lcd.setCursor(0, 1); lcd.print("FINGER          ");
    digitalWrite(A0,LOW); digitalWrite(A1,HIGH); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,HIGH); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW);
  }
  
  else if (id == 7)                                // if ID = 7 (Ring finger)
  {
    lcd.setCursor(0, 0); lcd.print("RING            ");
    lcd.setCursor(0, 1); lcd.print("FINGER          ");
    digitalWrite(A0,LOW); digitalWrite(A1,HIGH); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,HIGH); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW);
  }
  
  else if (id == 9)                                // if ID = 9 (Little finger)
  {
    lcd.setCursor(0, 0); lcd.print("LITTLE          ");
    lcd.setCursor(0, 1); lcd.print("FINGER          ");
    digitalWrite(A0,LOW); digitalWrite(A1,HIGH); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,HIGH); digitalWrite(A1,LOW); delay(3000);
    digitalWrite(A0,LOW); digitalWrite(A1,LOW);
  }
  
  delay(50);                                       // small delay
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();                   // capture fingerprint image
  switch (p) {
    case FINGERPRINT_OK: break;                    // image captured successfully
    case FINGERPRINT_NOFINGER: return p;           // no finger detected
    case FINGERPRINT_PACKETRECIEVEERR: return p;   // communication error
    case FINGERPRINT_IMAGEFAIL: return p;          // imaging error
    default: return p;                             // unknown error
  }

  p = finger.image2Tz();                           // convert image to template
  switch (p) {
    case FINGERPRINT_OK: break;                    // converted successfully
    case FINGERPRINT_IMAGEMESS: return p;          // image too messy
    case FINGERPRINT_PACKETRECIEVEERR: return p;   // communication error
    case FINGERPRINT_FEATUREFAIL: return p;        // no fingerprint features
    case FINGERPRINT_INVALIDIMAGE: return p;       // invalid image
    default: return p;                             // unknown error
  }

  p = finger.fingerSearch();                       // search for match
  if (p == FINGERPRINT_OK) { }                     // found a match
  else if (p == FINGERPRINT_PACKETRECIEVEERR) return p;
  else if (p == FINGERPRINT_NOTFOUND) return p;
  else return p;

  return finger.fingerID;                          // return matched fingerprint ID
}

// simplified version to quickly get ID
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  return finger.fingerID;                          // return matched ID
}
