#include <iostream>

using namespace std;

void task3(void) {
  char tab[10] = "Cisco";

  cout << *&tab << endl;
}

int main(void) {
  cout << "Task3!" << endl;
  task3();

  return 0;
}
