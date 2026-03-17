#include <bits/stdc++.h>
using namespace std;
void initCanMake(vector<vector<bool> > &can_make, vector<int> &coins);
int main() {
  int num_coins, price;
  cin >> num_coins >> price;
  vector<int> coins(num_coins);
  for (int i = 0; i < coins.size(); i++) cin >> coins[i];
  coins.push_back(0);
  sort(coins.begin(), coins.end());
  vector<vector<bool> > can_make(price + 1, vector<bool>(price + 1, false));
  can_make[0][0] = true;
  initCanMake(can_make, coins);
  vector<int> answers;
  for (int i = 0; i < can_make.back().size(); i++)
    if (can_make.back()[i]) answers.push_back(i);
  cout << answers.size() << endl;
  for (int i = 0; i < answers.size(); i++)
    cout << answers[i] << ((i < answers.size() - 1) ? ' ' : '\n');
  return 0;
}
void initCanMake(vector<vector<bool> > &can_make, vector<int> &coins) {
  for (int ci = 0; ci < coins.size(); ci++)
    for (int pi = can_make.size() - 1; pi >= coins[ci]; pi--)
      for (int si = 0; si < can_make[pi].size(); si++) {
        can_make[pi][si] = can_make[pi][si] || can_make[pi - coins[ci]][si];
        if (si >= coins[ci])
          can_make[pi][si] =
              can_make[pi][si] || can_make[pi - coins[ci]][si - coins[ci]];
      }
}
