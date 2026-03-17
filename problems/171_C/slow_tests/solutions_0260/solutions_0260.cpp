#include <bits/stdc++.h>
using namespace std;
int main() {
  int carrots = 2;
  int calories = 0;
  int chocolate_spread = 100;
  int pack_of_flour = 1;
  int egg = 1;
  stack<int> mixing_bowl;
  mixing_bowl.push(calories);
  cin >> carrots;
  for (int i = 1; i <= carrots; ++i) {
    cin >> chocolate_spread;
    mixing_bowl.push(chocolate_spread);
    mixing_bowl.top() *= pack_of_flour;
    chocolate_spread = mixing_bowl.top();
    mixing_bowl.pop();
    mixing_bowl.top() += chocolate_spread;
    mixing_bowl.push(pack_of_flour);
    mixing_bowl.top() += egg;
    pack_of_flour = mixing_bowl.top();
    mixing_bowl.pop();
  }
  while (!mixing_bowl.empty()) {
    cout << mixing_bowl.top() << '\n';
    mixing_bowl.pop();
  }
  return 0;
}
