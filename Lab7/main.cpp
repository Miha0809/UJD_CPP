#include <cmath>
#include <iostream>

using namespace std;

bool bcdOK(const string &input) {
  for (char c : input) {
    if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
      return false;
    }
  }
  return true;
}
void task4(void) {
  string input1 = "absgdfsr";
  string input2 = "1234ABCF";

  cout << "Czy '" << input1 << "' jest liczba szesnastkowa BCD? "
       << (bcdOK(input1) ? "Tak" : "Nie") << endl;
  cout << "Czy '" << input2 << "' jest liczba szesnastkowa BCD? "
       << (bcdOK(input2) ? "Tak" : "Nie") << endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int compare(int a, int b) {
  if (a == b) {
    return 0;
  } else if (a > b) {
    return 1;
  } else {
    return -1;
  }
}
void task5(void) {
  int x = 5;
  int y = 3;

  cout << "Przed zamianą: x = " << x << ", y = " << y << endl;
  swap(x, y);
  cout << "Po zamianie: x = " << x << ", y = " << y << endl;

  int a = 10;
  int b = 10;
  cout << "Porównanie a i b: " << compare(a, b) << endl;

  a = 15;
  b = 7;
  cout << "Porównanie a i b: " << compare(a, b) << endl;

  a = 3;
  b = 9;
  cout << "Porównanie a i b: " << compare(a, b) << endl;
}

long int squareByValue(long int num) { return num * num; }
void task6(void) {
  long int number = 5;
  long int squared = squareByValue(number);

  cout << "Liczba " << number << " podniesiona do kwadratu wynosi: " << squared
       << endl;
}

struct IPAddress {
  unsigned char bytes[4];
};
IPAddress calculateNetworkAddress(const IPAddress &ip,
                                  const IPAddress &subnetMask) {
  IPAddress networkAddress;

  for (int i = 0; i < 4; ++i) {
    networkAddress.bytes[i] = ip.bytes[i] & subnetMask.bytes[i];
  }

  return networkAddress;
}
void printIPAddress(const IPAddress &ip) {
  cout << (int)ip.bytes[0] << "." << (int)ip.bytes[1] << "." << (int)ip.bytes[2]
       << "." << (int)ip.bytes[3] << endl;
}
void task6a(void) {
  IPAddress ip = {{192, 168, 1, 10}};
  IPAddress subnetMask = {{255, 255, 255, 0}};

  IPAddress networkAddress = calculateNetworkAddress(ip, subnetMask);

  cout << "Adres IP: ";
  printIPAddress(ip);
  cout << "Maska sieci: ";
  printIPAddress(subnetMask);
  cout << "Adres sieci: ";
  printIPAddress(networkAddress);
}

int calculateArea(int side) { return side * side; }
double calculateArea(double length, double width) { return length * width; }
double calculateVolume(double length, double width = 1.0, double height = 1.0) {
  return length * width * height;
}
void task7(void) {
  int choice;
  cout << "Choose an option:\n";
  cout << "1. Area of a square\n";
  cout << "2. Area of a rectangle\n";
  cout << "3. Volume of a cube\n";
  cout << "Your choice: ";
  cin >> choice;

  switch (choice) {
  case 1: {
    int side;
    cout << "Enter the side length of the square: ";
    cin >> side;
    cout << "The area of the square is: " << calculateArea(side) << endl;
    break;
  }
  case 2: {
    double length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "The area of the rectangle is: " << calculateArea(length, width)
         << endl;
    break;
  }
  case 3: {
    double length, width, height;
    cout << "Enter the length of the cube: ";
    cin >> length;
    cout << "Enter the width of the cube (default is 1): ";
    cin >> width;
    cout << "Enter the height of the cube (default is 1): ";
    cin >> height;
    cout << "The volume of the cube is: "
         << calculateVolume(length, width, height) << endl;
    break;
  }
  default:
    cout << "Invalid choice. Please try again." << endl;
  }
}

double square(double x) { return x * x; }
double hypotenuse(double a, double b) {
  if (a <= 0 || b <= 0) {
    return -1;
  }
  return sqrt(square(a) + square(b));
}
void task8(void) {
  double side1, side2;

  cout << "Enter the length of the first side of the right triangle: ";
  cin >> side1;
  cout << "Enter the length of the second side of the right triangle: ";
  cin >> side2;

  double hyp = hypotenuse(side1, side2);

  if (hyp == -1) {
    cout << "The lengths entered are invalid (zero or negative)." << endl;
  } else {
    cout << "The length of the hypotenuse is: " << hyp << endl;
  }
}

int findValue(const int array[], int size, int value) {
  for (int i = 0; i < size; ++i) {
    if (array[i] == value) {
      return i;
    }
  }
  return -1;
}
void task8a(void) {
  int array[] = {2, 5, 7, 1, 4};
  int size = sizeof(array) / sizeof(array[0]);

  int valueToFind = 7;
  int index = findValue(array, size, valueToFind);

  if (index != -1) {
    cout << "Value " << valueToFind << " found at index " << index << endl;
  } else {
    cout << "Value " << valueToFind << " not found in the array." << endl;
  }
}

enum BitMask {
  BIT0 = 0x1,  // 0001
  BIT1 = 0x2,  // 0010
  BIT2 = 0x4,  // 0100
  BIT3 = 0x8,  // 1000
  BIT4 = 0x10, // 0001 0000
  BIT5 = 0x20, // 0010 0000
  BIT6 = 0x40, // 0100 0000
  BIT7 = 0x80  // 1000 0000
};
void decToBin(unsigned int num) {
  for (int bit = sizeof(num) * 8 - 1; bit >= 0; --bit) {
    cout << ((num >> bit) & 1);
  }
  cout << endl;
}
int setBit(int &word, int bitNumber) {
  if (bitNumber < 0 || bitNumber >= sizeof(int) * 8) {
    return -3;
  }

  if (word < 0) {
    return -1;
  }

  word |= (1 << bitNumber);

  return 0;
}
int clearBit(int &word, int bitNumber) {
  if (bitNumber < 0 || bitNumber >= sizeof(int) * 8) {
    return -3;
  }

  if (word < 0) {
    return -1;
  }

  word &= ~(1 << bitNumber);

  return 0;
}
void task10(void) {
  int word = 13;

  cout << "Original value in binary: ";
  decToBin(word);

  int setResult = setBit(word, 2);

  if (setResult == 0) {
    cout << "After setting bit 2, value in binary: ";
    decToBin(word);
  } else {
    cout << "Error setting bit: " << setResult << endl;
  }

  int clearResult = clearBit(word, 3);

  if (clearResult == 0) {
    cout << "After clearing bit 3, value in binary: ";
    decToBin(word);
  } else {
    cout << "Error clearing bit: " << clearResult << endl;
  }
}

void lostab(int t[], int size, int n) {
  srand(time(NULL));

  for (int i = 0; i < size; ++i) {
    t[i] = rand() % (n + 1);
  }
}
int znajdzN(int t[], int size, int n) {
  int count = 0;

  for (int i = 0; i < size; ++i) {
    if (t[i] == n) {
      count++;
    }
  }

  return count;
}
void task12(void) {
  const int SIZE = 10;
  int tablica[SIZE];

  lostab(tablica, SIZE, 5);

  int liczbaN = 5;
  int iloscWystapien = znajdzN(tablica, SIZE, liczbaN);

  cout << "Liczba wystąpień liczby " << liczbaN
       << " w tablicy: " << iloscWystapien << endl;
}

int main(void) {
  cout << endl << "Task4!" << endl;
  task4();

  cout << endl << "Task5!" << endl;
  task5();

  cout << endl << "Task6!" << endl;
  task6();

  cout << endl << "Task6a!" << endl;
  task6a();

  cout << endl << "Task7!" << endl;
  task7();

  cout << endl << "Task8!" << endl;
  task8();

  cout << endl << "Task8a!" << endl;
  task8a();

  cout << endl << "Task10!" << endl;
  task10();

  cout << endl << "Task12!" << endl;
  task12();

  return 0;
}