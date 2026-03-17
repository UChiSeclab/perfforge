#include <bits/stdc++.h>
using namespace std;
int main() {
  int boysize, girlsize, boycounter, girlcounter, index = 0;
  bool boy[101] = {false}, girl[101] = {false};
  cin >> boysize >> girlsize;
  cin >> boycounter;
  for (int i = 0; i < boycounter; i++) {
    cin >> index;
    boy[index] = true;
  }
  cin >> girlcounter;
  for (int i = 0; i < girlcounter; i++) {
    cin >> index;
    girl[index] = true;
  }
  for (int i = 0; i <= 10000000; i++) {
    if (boy[i % boysize] && !girl[i % girlsize]) {
      girl[i % girlsize] = true;
      girlcounter++;
    } else if (girl[i % girlsize] && !boy[i % boysize]) {
      boy[i % boysize] = true;
      boycounter++;
    }
    if (boycounter + girlcounter == boysize + girlsize) break;
  }
  if (boycounter + girlcounter == boysize + girlsize)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
