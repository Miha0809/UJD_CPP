#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void task1(char *argv[]) {
  ifstream file(argv[1]);

  if (!file) {
    cerr << "Error opening file: " << argv[1] << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }

  file.close();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }

  cout << endl << "Task1" << endl;
  task1(argv);

  return 0;
}
