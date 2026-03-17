#include <bits/stdc++.h>
using namespace std;
struct ExCont {};
struct ExBrk {};
int d[11][11] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
inline int max(int a) { return a; }
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
int thrExBrk() {
  throw ExBrk();
  return 0;
}
int thrExCont() {
  throw ExCont();
  return 0;
}
int main(void) {
  int N;
  cin >> N;
  int i, j, k;
  try {
    i = 0;
  loadOuter:
    try {
      throw(i < N ? thrExCont() : thrExBrk());
    } catch (ExCont) {
      try {
        j = 0;
      loadInner:
        try {
          throw(j < N ? thrExCont() : thrExBrk());
        } catch (ExCont) {
          cin >> d[i][j];
          ++j;
        }
        goto loadInner;
      } catch (ExBrk) {
      }
      ++i;
    }
    goto loadOuter;
  } catch (ExBrk) {
  }
  try {
    i = 0;
  loadOuter2:
    try {
      throw(i < N ? thrExCont() : thrExBrk());
    } catch (ExCont) {
      try {
        j = 0;
      loadInner2:
        try {
          throw(j < N ? thrExCont() : thrExBrk());
        } catch (ExCont) {
          try {
            k = 0;
          loadInnerInner:
            try {
              throw(k < N ? thrExCont() : thrExBrk());
            } catch (ExCont) {
              d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
              ++k;
            }
            goto loadInnerInner;
          } catch (ExBrk) {
          }
          ++j;
        }
        goto loadInner2;
      } catch (ExBrk) {
      }
      ++i;
    }
    goto loadOuter2;
  } catch (ExBrk) {
  }
  int m = 0;
  m = max(m,
          max(d[0][0],
              max(d[0][1],
                  max(d[0][2],
                      max(d[0][3],
                          max(d[0][4],
                              max(d[0][5],
                                  max(d[0][6],
                                      max(d[0][7],
                                          max(d[0][8],
                                              max(d[0][9], d[0][10])))))))))));
  m = max(m,
          max(d[1][0],
              max(d[1][1],
                  max(d[1][2],
                      max(d[1][3],
                          max(d[1][4],
                              max(d[1][5],
                                  max(d[1][6],
                                      max(d[1][7],
                                          max(d[1][8],
                                              max(d[1][9], d[1][10])))))))))));
  m = max(m,
          max(d[2][0],
              max(d[2][1],
                  max(d[2][2],
                      max(d[2][3],
                          max(d[2][4],
                              max(d[2][5],
                                  max(d[2][6],
                                      max(d[2][7],
                                          max(d[2][8],
                                              max(d[2][9], d[2][10])))))))))));
  m = max(m,
          max(d[3][0],
              max(d[3][1],
                  max(d[3][2],
                      max(d[3][3],
                          max(d[3][4],
                              max(d[3][5],
                                  max(d[3][6],
                                      max(d[3][7],
                                          max(d[3][8],
                                              max(d[3][9], d[3][10])))))))))));
  m = max(m,
          max(d[4][0],
              max(d[4][1],
                  max(d[4][2],
                      max(d[4][3],
                          max(d[4][4],
                              max(d[4][5],
                                  max(d[4][6],
                                      max(d[4][7],
                                          max(d[4][8],
                                              max(d[4][9], d[4][10])))))))))));
  m = max(m,
          max(d[5][0],
              max(d[5][1],
                  max(d[5][2],
                      max(d[5][3],
                          max(d[5][4],
                              max(d[5][5],
                                  max(d[5][6],
                                      max(d[5][7],
                                          max(d[5][8],
                                              max(d[5][9], d[5][10])))))))))));
  m = max(m,
          max(d[6][0],
              max(d[6][1],
                  max(d[6][2],
                      max(d[6][3],
                          max(d[6][4],
                              max(d[6][5],
                                  max(d[6][6],
                                      max(d[6][7],
                                          max(d[6][8],
                                              max(d[6][9], d[6][10])))))))))));
  m = max(m,
          max(d[7][0],
              max(d[7][1],
                  max(d[7][2],
                      max(d[7][3],
                          max(d[7][4],
                              max(d[7][5],
                                  max(d[7][6],
                                      max(d[7][7],
                                          max(d[7][8],
                                              max(d[7][9], d[7][10])))))))))));
  m = max(m,
          max(d[8][0],
              max(d[8][1],
                  max(d[8][2],
                      max(d[8][3],
                          max(d[8][4],
                              max(d[8][5],
                                  max(d[8][6],
                                      max(d[8][7],
                                          max(d[8][8],
                                              max(d[8][9], d[8][10])))))))))));
  m = max(m,
          max(d[9][0],
              max(d[9][1],
                  max(d[9][2],
                      max(d[9][3],
                          max(d[9][4],
                              max(d[9][5],
                                  max(d[9][6],
                                      max(d[9][7],
                                          max(d[9][8],
                                              max(d[9][9], d[9][10])))))))))));
  m = max(
      m, max(d[10][0],
             max(d[10][1],
                 max(d[10][2],
                     max(d[10][3],
                         max(d[10][4],
                             max(d[10][5],
                                 max(d[10][6],
                                     max(d[10][7],
                                         max(d[10][8],
                                             max(d[10][9], d[10][10])))))))))));
  cout << m << endl;
  return 0;
}
