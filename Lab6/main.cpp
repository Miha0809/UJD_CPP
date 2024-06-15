#include <cstring>
#include <iostream>

using namespace std;

int globalInt;
char globalChar;
float globalFloat;
char globalCharArray[10];

void task1(void) {
  int localInt;
  char localChar;
  float localFloat;
  char localCharArray[10];

  cout << "Memory layout of automatic variables:\n";
  cout << "Address of localInt:       " << &localInt << "\n";
  cout << "Address of localChar:      " << (void *)&localChar << "\n";
  cout << "Address of localFloat:     " << &localFloat << "\n";
  cout << "Address of localCharArray: " << (void *)&localCharArray << "\n";

  cout << "\nMemory layout of global variables:\n";
  cout << "Address of globalInt:       " << &globalInt << "\n";
  cout << "Address of globalChar:      " << (void *)&globalChar << "\n";
  cout << "Address of globalFloat:     " << &globalFloat << "\n";
  cout << "Address of globalCharArray: " << (void *)&globalCharArray << "\n";

  cout << "\nDefault values of automatic variables (uninitialized):\n";
  cout << "localInt:       " << localInt << "\n";
  cout << "localChar:      " << (int)localChar << "\n";
  cout << "localFloat:     " << localFloat << "\n";
  cout << "localCharArray: ";

  for (char c : localCharArray) {
    cout << (int)c << " ";
  }

  cout << "\n";

  cout << "\nDefault values of global variables (initialized to zero):\n";
  cout << "globalInt:       " << globalInt << "\n";
  cout << "globalChar:      " << (int)globalChar << "\n";
  cout << "globalFloat:     " << globalFloat << "\n";
  cout << "globalCharArray: ";

  for (char c : globalCharArray) {
    cout << (int)c << " ";
  }

  cout << "\n";
}

void task2(void) {
  char *charPtr = new char[10];
  int *intPtr = new int[3];

  cout << "Contents of the first memory area (char): " << charPtr << endl;

  cout << "Contents of the second memory area (int): ";

  for (int i = 0; i < 3; ++i) {
    cout << intPtr[i] << " ";
  }
  cout << endl;

  strcpy(charPtr, "Microsoft");

  cout << "Contents of the first memory area after writing 'Microsoft': "
       << charPtr << endl;

  intPtr[0] = 10;
  intPtr[1] = 20;
  intPtr[2] = 30;

  cout << "Contents of the second memory area after writing values: ";

  for (int i = 0; i < 3; ++i) {
    cout << intPtr[i] << " ";
  }
  cout << endl;

  delete[] charPtr;
  delete[] intPtr;
}

void task3(void) {
  char tab[10] = "Cisco";

  cout << *&tab << endl;
}

void task4(void) {
  char m[6] = {'C', 'i', 's', 'c', 'o', '\0'};
  char n[10] = "Microsoft";

  cout << *&m << endl;
}

int main(void) {
  cout << "Task1!" << endl;
  task1();

  cout << "Task2!" << endl;
  task2();

  cout << "Task3!" << endl;
  task3();

  cout << "Task4!" << endl;
  task4();

  return 0;
}
