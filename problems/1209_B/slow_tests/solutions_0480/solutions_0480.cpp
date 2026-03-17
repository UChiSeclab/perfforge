#include <bits/stdc++.h>
using namespace std;
int LIGHT_SIZE;
bool light[101];
int start[101];
int cycle[101];
int ini_Lights(const string& s) {
  LIGHT_SIZE = s.size();
  int on = 0;
  for (int i = 0; i < s.size(); i++) {
    light[i] = s[i] == '1';
    if (light[i]) {
      on++;
    }
  }
  return on;
}
int simRound(int round, int lastOn) {
  int on = lastOn;
  for (int i = 0; i < LIGHT_SIZE; i++) {
    int begin = round - start[i];
    if (begin >= 0 && begin % cycle[i] == 0) {
      light[i] = !light[i];
      if (light[i]) {
        on++;
      } else {
        on--;
      }
    }
  }
  return on;
}
void coutSim() {
  for (int i = 0; i < LIGHT_SIZE; i++) {
    cout << (light[i]) ? '1' : '0';
  }
  cout << endl;
}
int main() {
  cin >> LIGHT_SIZE;
  string s;
  cin >> s;
  int max_on = ini_Lights(s);
  int last_on = max_on;
  for (int i = 0; i < LIGHT_SIZE; i++) {
    cin >> cycle[i] >> start[i];
  }
  for (int i = 1; i <= 100000; i++) {
    last_on = simRound(i, last_on);
    max_on = max(max_on, last_on);
    if (max_on == LIGHT_SIZE) {
      break;
    }
  }
  cout << max_on << endl;
}
