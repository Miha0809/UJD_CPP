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

void task5(void) {
  int a[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}};
  char b[2][20] = {"Poniedzialek", "Wtorek"};
  char znaki[] = "Programowanie";

  cout << "Array 'a' using indexing:" << endl;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  cout << "\nArray 'a' using pointers:" << endl;
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << *(*(a + i) + j) << " ";
    }
    cout << endl;
  }

  cout << "\nArray 'b' using indexing:" << endl;
  for (int i = 0; i < 2; ++i) {
    cout << b[i] << endl;
  }

  cout << "\nArray 'b' using pointers:" << endl;
  for (int i = 0; i < 2; ++i) {
    cout << *(b + i) << endl;
  }

  cout << "\nArray 'znaki' using indexing:" << endl;
  for (int i = 0; znaki[i] != '\0'; ++i) {
    cout << znaki[i];
  }
  cout << endl;

  cout << "\nArray 'znaki' using pointers:" << endl;
  for (char *ptr = znaki; *ptr != '\0'; ++ptr) {
    cout << *ptr;
  }
  cout << endl;
}

void task6(void) {
  char imie[6] =
      "Pawel"; // Poprawienie wielkości tablicy, aby pomieścić "Pawel" i '\0'
  int *wsk = nullptr; // Inicjalizacja wskaźnika jako nullptr
  float podatek;
  char napis[124];
  int licznik = 5;
  int x, y, z;
  x = y = z = 3; // Poprawne przypisanie wartości do zmiennych x, y i z

  wsk = new int; // Alokacja pamięci dla wskaźnika
  *wsk = 35;
  licznik = 1;
  // podatek = "23%";  // To przypisanie jest błędne, więc je usuwamy
  podatek =
      0.23; // Przykładowe poprawne przypisanie wartości do zmiennej podatek
  cout << *wsk << endl; // Poprawne użycie wskaźnika do wyświetlenia wartości

  delete wsk; // Zwolnienie pamięci przydzielonej wskaźnikowi
}

void task7(void) {
  char x[2] = "z"; // Poprawiono rozmiar tablicy
  char z[2] = "a"; // Użyto cudzysłowów do przypisania ciągu znaków
  char y = 'z';    // Użyto apostrofów do przypisania pojedynczego znaku

  cout << "x: " << x << endl;
  cout << "z: " << z << endl;
  cout << "y: " << y << endl;
}

void task8(void) {
  // C
  char staticText[256] = "This is a static long text in C.";
  printf("Static text: %s\n", staticText);

  char *dynamicText = (char *)malloc(256 * sizeof(char));
  if (dynamicText != NULL) {
    strcpy(dynamicText, "This is a dynamically allocated long text in C.");
    printf("Dynamic text: %s\n", dynamicText);
    free(dynamicText); // Freeing the allocated memory
  } else {
    printf("Memory allocation failed.\n");
  }

  // C++
  string longText = "This is a long text stored in a std::string in C++.";
  cout << "Long text: " << longText << endl;

  char cStyleText[256] = "This is a C-style char array in C++.";
  cout << "C-style text: " << cStyleText << endl;
}

void task9(void) {
  int num;

  cout << "Enter a number: ";
  cin >> num;

  cout << "Address of variable 'num': " << &num << endl;

  for (int i = 0; i < 5; ++i) {
    int *dynamicNum = new int;
    *dynamicNum = i;

    cout << "Address of dynamically allocated variable: " << dynamicNum << endl;

    delete dynamicNum;
  }
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

  cout << "Task5!" << endl;
  task5();

  cout << "Task6!" << endl;
  task6();

  cout << "Task7!" << endl;
  task7();

  cout << "Task8!" << endl;
  task8();

  cout << "Task9!" << endl;
  task9();

  return 0;
}
