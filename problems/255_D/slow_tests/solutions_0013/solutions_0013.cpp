#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, x, y, c;
  std::cin >> n >> x >> y >> c;
  ++n;
  bool topLeft = true, topRight = true, bottomLeft = true, bottomRight = true;
  int counter = 1, timer = 0, arm = 1, up = 0, left = 0, down = 0, right = 0;
  int xiterator, yiterator;
  while (counter < c) {
    if (topLeft) {
      xiterator = x - up;
      yiterator = y + arm;
      if (yiterator >= n) {
        yiterator = n - 1;
        ++up;
        --xiterator;
      }
      while (xiterator > 0 && yiterator > y) {
        if (xiterator == 1 && yiterator == n - 1) topLeft = false;
        ++counter;
        --xiterator;
        --yiterator;
      }
    }
    if (bottomLeft) {
      xiterator = x - arm;
      yiterator = y - left;
      if (xiterator <= 0) {
        xiterator = 1;
        ++left;
        --yiterator;
      }
      while (xiterator < x && yiterator > 0) {
        if (xiterator == 1 && yiterator == 1) bottomLeft = false;
        ++counter;
        ++xiterator;
        --yiterator;
      }
    }
    if (bottomRight) {
      xiterator = x + down;
      yiterator = y - arm;
      if (yiterator <= 0) {
        yiterator = 1;
        ++down;
        ++xiterator;
      }
      while (xiterator < n && yiterator < y) {
        if (xiterator == n - 1 && yiterator == 1) bottomRight = false;
        ++counter;
        ++xiterator;
        ++yiterator;
      }
    }
    if (topRight) {
      xiterator = x + arm;
      yiterator = y + right;
      if (xiterator >= n) {
        xiterator = n - 1;
        ++right;
        ++yiterator;
      }
      while (xiterator > x && yiterator < n) {
        if (xiterator == n - 1 && yiterator == n - 1) topRight = false;
        ++counter;
        --xiterator;
        ++yiterator;
      }
    }
    ++arm;
    ++timer;
  }
  std::cout << timer << endl;
  return 0;
}
