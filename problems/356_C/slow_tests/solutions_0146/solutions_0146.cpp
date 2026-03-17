#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
int Frequencies[5], Answer;
void Solve() {
  bool bigMove = true;
  while (bigMove) {
    bigMove = false;
    while (Frequencies[1] > 0 && Frequencies[2] > 0) {
      --Frequencies[1];
      --Frequencies[2];
      ++Frequencies[3];
      ++Answer;
      bigMove = true;
    }
    while (Frequencies[2] >= 3) {
      Frequencies[2] -= 3;
      Frequencies[3] += 2;
      Answer += 2;
      bigMove = true;
    }
    while (Frequencies[2] >= 2) {
      Frequencies[2] -= 2;
      ++Frequencies[4];
      Answer += 2;
      bigMove = true;
    }
    bool move = true;
    while (move) {
      move = false;
      while (Frequencies[2] > 0 && Frequencies[4] > 0) {
        --Frequencies[2];
        --Frequencies[4];
        Frequencies[3] += 2;
        ++Answer;
        move = true;
        bigMove = true;
      }
      while (Frequencies[2] > 0 && Frequencies[3] >= 2) {
        --Frequencies[2];
        Frequencies[3] -= 2;
        Frequencies[4] += 2;
        Answer += 2;
        move = true;
        bigMove = true;
      }
      while (Frequencies[2] > 0 && Frequencies[4] > 0) {
        --Frequencies[2];
        --Frequencies[4];
        Frequencies[3] += 2;
        ++Answer;
        move = true;
        bigMove = true;
      }
    }
    while (Frequencies[1] >= 3) {
      Frequencies[1] -= 3;
      ++Frequencies[3];
      Answer += 2;
      bigMove = true;
    }
    move = true;
    while (move) {
      move = false;
      while (Frequencies[1] > 1 && Frequencies[4] > 0) {
        Frequencies[1] -= 2;
        --Frequencies[4];
        Frequencies[3] += 2;
        Answer += 2;
        move = true;
        bigMove = true;
      }
      while (Frequencies[1] > 0 && Frequencies[3] > 0) {
        --Frequencies[1];
        --Frequencies[3];
        ++Frequencies[4];
        ++Answer;
        move = true;
        bigMove = true;
      }
      while (Frequencies[1] > 0 && Frequencies[4] > 1) {
        --Frequencies[1];
        Frequencies[4] -= 2;
        Frequencies[3] += 3;
        Answer += 2;
        move = true;
        bigMove = true;
      }
    }
    while (Frequencies[1] >= 2) {
      Frequencies[1] -= 2;
      ++Frequencies[2];
      ++Answer;
      bigMove = true;
    }
  }
  if (Frequencies[1] > 0 || Frequencies[2] > 0) Answer = -1;
}
void Read() {
  int n;
  cin >> n;
  for (; n > 0; --n) {
    int value;
    cin >> value;
    ++Frequencies[value];
  }
}
void Print() { cout << Answer << "\n"; }
int main() {
  Read();
  Solve();
  Print();
  return 0;
}
