#include <cmath>
#include <iostream>

using namespace std;

const int LENGTH = 11;

void init_array(int *numbers, int length) {
  for (int i = 0; i < length; i++) {
    int random = rand() % 1000;
    numbers[i] = random;
  }
}

void print_array(int *numbers, int length) {
  for (int i = 0; i < length; i++) {
    cout << numbers[i] << " ";
  }

  cout << endl;
}

void task4(void) {
  int numbers[LENGTH];

  init_array(numbers, LENGTH);

  for (int i = 0; i < LENGTH; i++) {
    for (int j = i + 1; j < LENGTH; j++) {
      if (numbers[i] > numbers[j]) {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
      }
    }
  }

  print_array(numbers, LENGTH);
}

void reverse(int *numbers, int length) {
  int end = length % 2 == 0 ? length / 2 - 1 : length / 2;

  for (int i = 0; i < end; i++) {
    int temp = numbers[end - i - 1];
    numbers[end - i - 1] = numbers[i];
    numbers[i] = temp;
  }
}

void task6(void) {
  int numbers[LENGTH];

  init_array(numbers, LENGTH);

  int middle = floor(LENGTH / 2);

  if (LENGTH % 2 != 0) {
    cout << numbers[middle] << endl << middle << endl;
  } else {
    cout << numbers[middle - 1] << ", " << numbers[middle] << endl;
  }

  cout << "BEFORE" << endl;
  print_array(numbers, LENGTH);

  reverse(numbers, LENGTH);

  cout << endl << "AFTER" << endl;
  print_array(numbers, LENGTH);
}

void task7(void) {
  const int length = 1000;
  int numbers[length];
  int countEvent = 0;
  int sumaEvent = 0;
  int countNotEvent = 0;
  int sumaNotEvent = 0;
  int count3 = 0;

  init_array(numbers, length);

  for (int i = 0; i < length; i++) {
    if (numbers[i] % 2 == 0) {
      countEvent++;
      sumaEvent++;
    } else if (numbers[i] % 2 != 0) {
      countNotEvent++;
      sumaNotEvent++;
    }

    if (numbers[i] % 3 == 0) {
      count3++;
    }
  }

  cout << "count event: " << countEvent << endl;
  cout << "suma event: " << sumaEvent << endl;
  cout << "count not event: " << countNotEvent << endl;
  cout << "suma not event: " << sumaNotEvent << endl;
  cout << "count numbers % 3: " << count3 << endl;
}

void drawWithRepetition(void) {
  int result[6];

  for (int i = 0; i < 6; ++i) {
    result[i] = rand() % 49 + 1;
  }

  cout << "6 out of 49 (with repetitions): ";

  for (int i = 0; i < 6; ++i) {
    cout << result[i] << " ";
  }

  cout << endl;
}
void drawWithRepetitionNoAdjacent(void) {
  int result[6];
  result[0] = rand() % 49 + 1;

  for (int i = 1; i < 6; ++i) {
    int newNum;

    do {
      newNum = rand() % 49 + 1;
    } while (newNum == result[i - 1]);

    result[i] = newNum;
  }

  cout << "6 out of 49 (with repetitions but not adjacent): ";

  for (int i = 0; i < 6; ++i) {
    cout << result[i] << " ";
  }

  cout << endl;
}
void drawWithoutRepetition(void) {
  int numbers[49];

  for (int i = 0; i < 49; ++i) {
    numbers[i] = i + 1;
  }

  for (int i = 48; i > 0; --i) {
    int random = rand() % (i + 1);
    int temp = numbers[i];
    numbers[i] = numbers[random];
    numbers[random] = temp;
  }

  cout << "6 out of 49 (without repetitions): ";

  for (int i = 0; i < 6; ++i) {
    cout << numbers[i] << " ";
  }

  cout << endl;
}
void task8(void) {
  drawWithRepetition();
  drawWithRepetitionNoAdjacent();
  drawWithoutRepetition();
}

bool XOR(int a, int b) { return (a & ~b) | (~a & b); }
void task9(void) {
  const int length = 100;
  int numbers[length];
  init_array(numbers, length);

  for (int i = 0; i < length; i++) {
    int random1 = rand() % (i + 1);
    int random2 = rand() % (i + 1);

    cout << "XOR for " << numbers[random1] << " and for " << numbers[random2]
         << ": " << XOR(numbers[random1], numbers[random2]) << endl;
  }
}

int main(void) {
  srand(time(NULL));

  cout << "Task4!" << endl;
  task4();

  cout << "Task6!" << endl;
  task6();

  cout << "Task7!" << endl;
  task7();

  cout << "Task8!" << endl;
  task8();

  cout << "Task9!" << endl;
  task9();
}
