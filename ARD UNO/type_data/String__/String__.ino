String stringOne1 = "Hello String";                    // using a constant String
String stringOne2 = String('a');                       // converting a constant char into a String
String stringOne3 = String("This is a string");        // converting a constant string into a String object
String stringOne4 = String(stringOne3 + " with more");  // concatenating two strings
String stringOne5 = String(13);                        // using a constant integer
String stringOne6 = String(analogRead(0), DEC);        // using an int and a base
String stringOne7 = String(45, HEX);                   // using an int and a base (hexadecimal)
String stringOne8 = String(255, BIN);                  // using an int and a base (binary)
String stringOne9 = String(millis(), DEC);             // using a long and a base
String stringOne10 = String(5.698, 3);                  // using a float and the decimal places

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}
