#include <bits/stdc++.h>
using namespace std;
vector<int> mixingbowl;
vector<int> bakingdish;
int main() {
  int carrots = 2;
  int calories = 0;
  int chocolatespread = 100;
  int packofflour = 1;
  int egg = 1;
  mixingbowl.push_back(calories);
  cin >> carrots;
  while (carrots > 0) {
    cin >> chocolatespread;
    mixingbowl.push_back(chocolatespread);
    mixingbowl[mixingbowl.size() - 1] *= packofflour;
    chocolatespread = mixingbowl[mixingbowl.size() - 1];
    mixingbowl.pop_back();
    mixingbowl[mixingbowl.size() - 1] += chocolatespread;
    mixingbowl.push_back(packofflour);
    mixingbowl[mixingbowl.size() - 1] += egg;
    packofflour = mixingbowl[mixingbowl.size() - 1];
    mixingbowl.pop_back();
    carrots--;
  }
  while (mixingbowl.size() > 0) {
    bakingdish.push_back(mixingbowl[mixingbowl.size() - 1]);
    mixingbowl.pop_back();
  }
  while (bakingdish.size() > 0) {
    cout << bakingdish[bakingdish.size() - 1] << endl;
    bakingdish.pop_back();
  }
  return 0;
}
