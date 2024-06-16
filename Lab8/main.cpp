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
    cerr << "Error opening file: " << argv[1] << endl;
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

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }

  cout << endl << "Task1" << endl;
  task1(argv);

  cout << endl << "Task2!" << endl;
  task2(argv);

  return 0;
}
