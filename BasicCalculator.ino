l
#include<Keypad.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
//Sometimes lcd(0x27,20,4) works instead.

boolean firstNumState = true;
String firstNum = "";
String secondNum = "";
float answer = 0.0;
char function = ' ';

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("   ARITHMETIC");
  lcd.setCursor(0, 1);
  lcd.print("   CALCULATOR");
  delay(5000);
  userInput();
}

void loop() {
  char newKey = myKeypad.getKey();
  anyKey == '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || '0';
  if (newKey != NO_KEY && newKey = anyKey){
    if (firstNumState == true) {
      firstNum = firstNum + newKey;

      lcd.print(newKey);
    }
    else {
      secondNum = secondNum + newKey;

      lcd.print(newKey);
    }
  }
  if (newKey != NO_KEY && (newKey == '+' || newKey == '-' || newKey == '*' || newKey == '/')) {
    if (firstNumState == true) {
      function = newKey;
      firstNumState = false;
      lcd.setCursor(15, 0);
      lcd.print(function);
      lcd.setCursor(5, 1);
    }
  }

  if (newKey != NO_KEY && newKey == '=') {
    if (function == '+') {
      answer = firstNum.toFloat() + secondNum.toFloat();
    }

    if (function == '-') {
      answer = firstNum.toFloat() - secondNum.toFloat();
    }

    if (function == '*') {
      answer = firstNum.toFloat() * secondNum.toFloat();
    }

    if (function == '/') {
      answer = firstNum.toFloat() / secondNum.toFloat();
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(firstNum);
    lcd.print(function);
    lcd.print(secondNum);
    lcd.setCursor(0, 1);
    lcd.print("=");
    lcd.print(answer);
    firstNumState = true;
  }

  if (newKey != NO_KEY && newKey == 'C') {
    userInput();
  }
}

void scrollDisplay() {
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  delay(1000);

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }
  delay(2000);
}

void userInput() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1st: ");
  lcd.setCursor(12, 0);
  lcd.print("op ");
  lcd.setCursor(0, 1);
  lcd.print("2nd: ");
  lcd.setCursor(5, 0);
  firstNum = "";
  secondNum = "";
  answer = 0;
  function = ' ';
}
