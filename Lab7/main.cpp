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

int main(void) {
  cout << endl << "Task4!" << endl;
  task4();

  cout << endl << "Task5!" << endl;
  task5();

  cout << endl << "Task6!" << endl;
  task6();

  return 0;
}
