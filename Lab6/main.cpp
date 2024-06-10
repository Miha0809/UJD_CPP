#include <iostream>

using namespace std;

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
  cout << "Task3!" << endl;
  task3();

  cout << "Task4!" << endl;
  task4();

  return 0;
}
