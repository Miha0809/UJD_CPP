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

void displayNonWhitespaceChars(const string &filepath) {
  ifstream file(filepath);

  if (!file.is_open()) {
    cout << "Error opening file: " << filepath << endl;
    return;
  }

  char ch;
  while (file.get(ch)) {
    if (!isspace(ch)) {
      cout << ch;
    }
  }

  file.close();
}
int compareFiles(const string &filepath1, const string &filepath2) {
  ifstream file1(filepath1);
  ifstream file2(filepath2);

  if (!file1.is_open() || !file2.is_open()) {
    cout << "Error opening files." << endl;
    return -1;
  }

  char ch1, ch2;
  while (file1.get(ch1) && file2.get(ch2)) {
    if (ch1 != ch2) {
      file1.close();
      file2.close();
      return 0;
    }
  }

  if (!file1.eof() || !file2.eof()) {
    file1.close();
    file2.close();
    return 0;
  }

  file1.close();
  file2.close();
  return 1;
}
int appendToEnd(const string &filepath) {
  ofstream file(filepath, ios::app);

  if (!file.is_open()) {
    cout << "Error opening file: " << filepath << endl;
    return -1;
  }

  file << "Hello, world!" << endl;

  file.close();
  return 0;
}
int replaceBegin(const string &filepath) {
  fstream file(filepath, ios::out | ios::in);

  if (!file.is_open()) {
    cout << "Error opening file: " << filepath << endl;
    return -1;
  }

  file.seekp(0);
  file << "Goodbye, world!" << endl;

  file.close();
  return 0;
}
int writeNLinesToFile(int fd, int n) {
  ofstream file;
  file.open(to_string(fd) + ".txt", ios::out);

  if (!file.is_open()) {
    cout << "Error opening file." << endl;
    return -1;
  }

  cout << "Enter " << n << " lines:" << endl;
  string line;
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    file << line << endl;
  }

  file.close();
  return 0;
}
void task7() {
  displayNonWhitespaceChars("test.txt");
  cout << endl;

  int result = compareFiles("file1.txt", "file2.txt");
  if (result == 1) {
    cout << "Files are identical." << endl;
  } else if (result == 0) {
    cout << "Files are different." << endl;
  } else {
    cout << "Error comparing files." << endl;
  }

  int fd = appendToEnd("append.txt");
  if (fd == 0) {
    cout << "Data appended successfully." << endl;
  } else {
    cout << "Error appending data." << endl;
  }

  fd = replaceBegin("replace.txt");
  if (fd == 0) {
    cout << "Data replaced successfully." << endl;
  } else {
    cout << "Error replacing data." << endl;
  }

  int fd_result = writeNLinesToFile(1234, 3);
  if (fd_result == 0) {
    cout << "Lines written successfully." << endl;
  } else {
    cout << "Error writing lines to file." << endl;
  }
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

  cout << endl << "Task7!" << endl;
  task7();

  return 0;
}
