#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void task1(char *argv[]) {
  ifstream file(argv[1]);

  if (!file) {
    cout << "Error opening file: " << argv[1] << endl;
    return;
  }

  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }

  file.close();
}

bool isWord(const string &word, bool min2) {
  if (min2) {
    return word.size() >= 2;
  } else {
    return !word.empty();
  }
}
void task2(char *argv[]) {
  ifstream file(argv[1]);

  if (!file) {
    cout << "Error opening file: " << argv[1] << endl;
    return;
  }

  char ch;
  int charCount = 0;
  int uppercaseCount = 0;
  int lowercaseCount = 0;
  int wordCount = 0;
  bool min2 = false;

  if (string(argv[2]) == "min2") {
    min2 = true;
  }

  string word;
  while (file.get(ch)) {
    ++charCount;
    if (isalpha(ch)) {
      if (isupper(ch)) {
        ++uppercaseCount;
      } else if (islower(ch)) {
        ++lowercaseCount;
      }
      word += ch;
    } else if (isspace(ch)) {
      if (isWord(word, min2)) {
        ++wordCount;
      }
      word.clear();
    }
  }

  if (!word.empty() && isWord(word, min2)) {
    ++wordCount;
  }

  file.close();

  cout << "Number of characters: " << charCount << endl;
  cout << "Number of uppercase letters: " << uppercaseCount << endl;
  cout << "Number of lowercase letters: " << lowercaseCount << endl;
  cout << "Number of words: " << wordCount << endl;
}

void task4(char *argv[]) {
  ifstream file(argv[1]);

  if (!file.is_open()) {
    cout << "Error opening file: " << argv[1] << endl;
    return;
  }

  int lineCount = 0;
  int maxLength = 0;
  string line;

  while (getline(file, line)) {
    ++lineCount;
    if (line.length() > maxLength) {
      maxLength = line.length();
    }
  }

  file.close();

  cout << "Number of lines: " << lineCount << endl;
  cout << "Maximum length of lines: " << maxLength << endl;
}

void task5(char *argv[]) {
  ifstream file(argv[1]);

  if (!file.is_open()) {
    cout << "Error opening file: " << argv[1] << endl;
    return;
  }

  string line;
  string *lines = nullptr;
  int lineCount = 0;

  while (getline(file, line)) {
    string *temp = new string[lineCount + 1];
    for (int i = 0; i < lineCount; ++i) {
      temp[i] = lines[i];
    }
    temp[lineCount] = line;
    delete[] lines;
    lines = temp;
    ++lineCount;
  }

  file.close();

  cout << "Lines read from file:" << endl;
  for (int i = 0; i < lineCount; ++i) {
    cout << lines[i] << endl;
  }

  delete[] lines;
}

void writeSquaresToFile(const string &filename) {
  ofstream file(filename);

  if (!file.is_open()) {
    cout << "Error opening file: " << filename << endl;
    return;
  }

  for (int i = 1; i <= 10; ++i) {
    file << i * i << endl;
  }

  file.close();
}
void readAndDisplayFile(const string &filename) {
  ifstream file(filename);

  if (!file.is_open()) {
    cout << "Error opening file: " << filename << endl;
    return;
  }

  int number;
  while (file >> number) {
    cout << number << endl;
  }

  file.close();
}
void task6() {
  const string filename = "squares.txt";

  writeSquaresToFile(filename);
  readAndDisplayFile(filename);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }

  cout << endl << "Task1" << endl;
  task1(argv);

  cout << endl << "Task2!" << endl;
  task2(argv);

  cout << endl << "Task4!" << endl;
  task4(argv);

  cout << endl << "Task5!" << endl;
  task5(argv);

  cout << endl << "Task6!" << endl;
  task6();

  return 0;
}
