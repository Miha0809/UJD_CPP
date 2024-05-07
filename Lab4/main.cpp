#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;

void taskA1() {
  double x = 0;
  double alfa = 0;

  cout << "Enter x: ";
  cin >> x;

  cout << "Enter alfa: ";
  cin >> alfa;

  if (x <= 0 || alfa <= 0) {
    cout << "x <= 0 || alfa <= 0" << endl;
    ;
  }

  x = x * M_PI / 180.0;
  alfa = alfa * M_PI / 180.0;

  double result = (sqrt(pow(x, 2) + 7)) / (2 * x) - pow(x, 2) +
                  (sin(alfa)) / (abs(pow(x, 3)));

  cout << "Result: " << result << endl;
}

void taskA2() {
  double a, x, b;

  cout << "Enter a: ";
  cin >> a;

  cout << "Enter x: ";
  cin >> x;

  cout << "Enter b: ";
  cin >> b;

  double y = a * x + b;

  cout << "y = " << y << endl;
}

void taskA3() {
  double a, x, b, c;

  cout << "Enter a: ";
  cin >> a;

  cout << "Enter x: ";
  cin >> x;

  cout << "Enter b: ";
  cin >> b;

  cout << "Enter c: ";
  cin >> c;

  double y = a * pow(x, 2) + b * x + c;

  cout << "y = " << y << endl;
}

void taskA4() {
  // TODO: make
}

long convertToBinary(int decimal_number) {
  long binary = 0, remainder, f = 1;

  while (decimal_number != 0) {
    remainder = decimal_number % 2;
    binary = binary + remainder * f;
    f = f * 10;
    decimal_number = decimal_number / 2;
  }

  return binary;
}

void task6() {
  int num1 = 15;
  int num2 = -128;
  int num3 = 11;

  num1 = num1 << 4;
  cout << num1 << endl;

  num2 = num2 >> 1;
  cout << num2 << endl;

  num2 = -128 << 1;
  cout << num2 << endl;
}

void task7() {
  char a = 126;

  char b = a >> 1;
  cout << (int)b << " : " << convertToBinary((int)b) << endl;

  b = a << 1;
  cout << (int)b << " : " << convertToBinary((int)b) << endl;

  b = a << 3;
  cout << (int)b << " : " << convertToBinary((int)b) << endl;
}

void task8() {
  const unsigned char bin_value = 0b00001011;
  long long value = (int)bin_value;

  cout << "Start value (binary): " << convertToBinary(value)
       << " (decimal): " << value << endl;

  value &= ~(1 << 0);
  cout << "After LSB (binary): " << convertToBinary(value)
       << " (decimal): " << value << endl;

  value |= (1 << 7);
  cout << "After MSB (binary): " << convertToBinary(value)
       << " (decimal): " << value << endl;

  value |= (1 << 2);
  cout << "After set bit nr 2 (binary): " << convertToBinary(value)
       << " (decimal): " << value << endl;

  int fourthBitSet = (value >> 3) & 1;
  cout << "4 bit is " << (fourthBitSet ? "set" : "not set") << endl;

  int fifthBitSet = (value >> 5) & 1;
  int sixthBitSet = (value >> 6) & 1;
  cout << "Bit 5 and 6 are "
       << ((fifthBitSet && sixthBitSet) ? "set" : "not set") << endl;

  value ^= (1 << 3);
  cout << "After bit 3 inversion (binary): " << convertToBinary(value)
       << " (decimal): " << value << endl;

  value ^= (1 << 3);
  cout << "After bit 3 inversion again nr 3 (binary): "
       << convertToBinary(value) << " (decimal): " << value << endl;

  value <<= 2;
  cout << "After shifting 2 bits to the left (binary): "
       << convertToBinary(value) << " (decimal): " << value << endl;
}

int multiXOR(int array[], int size) {
  int result = 0;

  for (int i = 0; i < size; i++) {
    result ^= array[i];
  }

  return result;
}
void task9() {
  int array[100];
  int size = 100;

  for (int i = 0; i < size; i++) {
    array[i] = i;
  }

  int result = multiXOR(array, size);

  cout << "Result: " << result << endl;
}

void rightShiftChar(char value) {
  cout << endl << "\trightShiftChar" << endl;

  for (int i = 0; i < 8; i++) {
    value >>= 1;
    cout << (value & 0xFF) << endl;
  }
}
void leftShiftChar(char value) {
  cout << endl << "\tleftShiftChar" << endl;

  for (int i = 0; i < 8; i++) {
    value <<= 1;
    cout << (value & 0xFF) << endl;
  }
}
void rightShiftUnsignedChar(unsigned char value) {
  cout << endl << "\trightShiftUnsignedChar" << endl;

  for (int i = 0; i < 8; i++) {
    value >>= 1;
    cout << value << endl;
  }
}
void leftShiftUnsignedChar(unsigned char value) {
  cout << endl << "\tleftShiftUnsignedChar" << endl;

  for (int i = 0; i < 8; i++) {
    value <<= 1;
    cout << value << endl;
  }
}
void rightShiftInt(int value) {
  cout << endl << "\trightShiftInt" << endl;

  for (int i = 0; i < 32; i++) {
    value >>= 1;
    cout << value << endl;
  }
}
void leftShiftInt(int value) {
  cout << endl << "\tleftShiftInt" << endl;

  for (int i = 0; i < 32; i++) {
    value <<= 1;
    cout << value << endl;
  }
}
void task10() {
  char charValue = 127;
  unsigned char unsignedCharValue = 255;
  int intValue = 100000;

  rightShiftChar(charValue);
  leftShiftChar(charValue);

  rightShiftUnsignedChar(unsignedCharValue);
  leftShiftUnsignedChar(unsignedCharValue);

  rightShiftInt(intValue);
  leftShiftInt(intValue);
}

void task11() {
  unsigned char decimalNumber = 156;
  long long value = (int)decimalNumber;
  cout << "Decimal number " << value
       << " in binary system: " << convertToBinary(value) << endl;
}

void task12() {
  int userInput;
  int bitToCheck;

  cout << "Enter number (0..255): ";
  cin >> userInput;

  if (userInput < 0 || userInput > 255) {
    cout << "Number is not between 0 and 255" << endl;
    return;
  }

  cout << "Enter bit to check (0..7): ";
  cin >> bitToCheck;

  if (bitToCheck < 0 || bitToCheck > 7) {
    cout << "Enter is not currect bit" << endl;
    return;
  }

  switch (bitToCheck) {
  case 0:
    userInput &= 1;
    break;
  case 1:
    userInput &= 2;
    break;
  case 2:
    userInput &= 4;
    break;
  case 3:
    userInput &= 8;
    break;
  case 4:
    userInput &= 16;
    break;
  case 5:
    userInput &= 32;
    break;
  case 6:
    userInput &= 64;
    break;
  case 7:
    userInput &= 128;
    break;
  }

  if (userInput != 0) {
    cout << "YES" << endl;
  } else {
    cout << "NOK" << endl;
  }
}

void test1() {
  /*
  - Zachowaj dokładność do 4 miejsca po przecinku z uwzględnieniem standardowej
  metody zaokrąglania.
  - Nie wpisuj końcowych zer (np. jeśli wynik to 3,23 to tak wpisz w oknie
  odpowiedzi ale nie 3,2300)
  - Podczas wpisywania wyniku użyj przecinka do oddzielenia części całkowitej od
  rzeczywistej wyniku.
  - Pamiętaj, że większość języków programowania obliczenia funkcji
  trygonometrycznych wykonuje w radianach! Przelicz zatem miarę stopniową kąta
  alfa w radiany przed wstawieniem danych do wzoru!
  */
  double x = 4.29383;
  double a = 7.39434;
  double alfa = 45.5;

  alfa = (alfa * M_PI) / 180.0;

  double result = (sqrt((pow(x, 2) - (2 * a)))) / (2 * x) -
                  (sin(alfa)) / (pow(x, 2)) + (tan(alfa)) / (2 * a);

  printf("%.4f\n", result);
}

int check_bit(int number, int bit_position) {
  int mask = 1 << bit_position;

  if ((number & mask) != 0) {
    return 1;
  } else {
    return 0;
  }
}
void test2() {
  int number, bit_position;

  printf("Enter the number: ");
  scanf("%d", &number);
  printf("Enter the bit position: ");
  scanf("%d", &bit_position);

  if (check_bit(number, bit_position)) {
    printf("Bit at position %d in the number %d is set.\n", bit_position,
           number);
  } else {
    printf("Bit at position %d in the number %d is not set.\n", bit_position,
           number);
  }
}

int main() {
  cout << endl << "TaskA1!" << endl;
  taskA1();

  cout << endl << "TaskA2!" << endl;
  taskA2();

  cout << endl << "TaskA3!" << endl;
  taskA3();

  cout << endl << "TaskA4!" << endl;
  taskA4();

  cout << endl << "Task6!" << endl;
  task6();

  cout << endl << "Task7!" << endl;
  task7();

  cout << endl << "Task8!" << endl;
  task8();

  cout << endl << "Task9!" << endl;
  task9();

  cout << endl << "Task10!" << endl;
  task10();

  cout << endl << "Task11!" << endl;
  task11();

  cout << endl << "Task12!" << endl;
  task12();

  cout << endl << "\t\tTests" << endl;

  cout << endl << "Test1!" << endl;
  test1();

  cout << endl << "Test2!" << endl;
  test2();

  return 1;
}
