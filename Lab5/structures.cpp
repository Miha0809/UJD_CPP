#include <iostream>

using namespace std;

// Task1

struct Point {
public:
  int x;
  int y;
};

struct Square {
public:
  int x1, x2;
  int y1, y2;
};

bool pointInSquare(Point p, Square s) {
  return (p.x >= s.x1 && p.x <= s.x2 && p.y >= s.y1 && p.y <= s.y2);
}

Square normalizeSquare(Square s) {
  Square normalizedSquare;

  normalizedSquare.x1 = min(s.x1, s.x2);
  normalizedSquare.y1 = min(s.y1, s.y2);
  normalizedSquare.x2 = max(s.x1, s.x2);
  normalizedSquare.y2 = max(s.y1, s.y2);

  return normalizedSquare;
}

void task1(void) {
  Point p = {3, 4};
  Square s = {1, 1, 5, 5};

  if (pointInSquare(p, s)) {
    cout << "The point is inside the square." << endl;
  } else {
    cout << "The point is not inside the square." << endl;
  }

  Square normalized = normalizeSquare(s);
  cout << "After normalization, the coordinates of the square are ("
       << normalized.x1 << ", " << normalized.y1 << ") and (" << normalized.x2
       << ", " << normalized.y2 << ")" << endl;
}

// Task2

struct Triangle {
public:
  double side1;
  double side2;
  double side3;
};

double calculatePerimeter(Triangle t) { return t.side1 + t.side2 + t.side3; }

void task2(void) {
  Triangle triangle;

  cout << "Enter the length of the 1 side of the triangle: ";
  cin >> triangle.side1;

  cout << "Enter the length of the 2 side of the triangle: ";
  cin >> triangle.side2;

  cout << "Enter the length of the 3 side of the triangle: ";
  cin >> triangle.side3;

  double perimeter = calculatePerimeter(triangle);
  cout << "The perimeter of the triangle is: " << perimeter << endl;
}

int main(void) {
  cout << "Task1!" << endl;
  task1();

  cout << "Task2!" << endl;
  task2();

  return 0;
}
