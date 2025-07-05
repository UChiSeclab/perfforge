#include <bits/stdc++.h>
using namespace std;

void initCanMake(vector<vector<bool> > &can_make, vector<int> &coins);

// Checker function for high coin value combinations
void check_high_price_invariant(int price, const vector<int>& coins) {
    int highValueCount = 0;
    for (const auto& coin : coins) {
        if (coin > price * 0.8) {
            highValueCount++;
        }
    }
    if (price > 400 && highValueCount > 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to high value coins!" << endl;
        abort();
    }
}

// Checker function for large search space
void check_large_search_space_invariant(int price, int num_coins) {
    if (price > 400 && num_coins < 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to large search space!" << endl;
        abort();
    }
}

// Checker function for complex combinations due to high coin values
void check_complex_combinations_invariant(int price, const vector<int>& coins) {
    int closeCount = 0;
    for (const auto& coin : coins) {
        if (coin >= price * 0.9) {
            closeCount++;
        }
    }
    if (closeCount > 3) {
        cerr << "Warning: Performance bottleneck condition triggered due to complex combinations!" << endl;
        abort();
    }
}

int main() {
    int num_coins, price;
    cin >> num_coins >> price;
    vector<int> coins(num_coins);
    for (int i = 0; i < coins.size(); i++) cin >> coins[i];
    coins.push_back(0);
    sort(coins.begin(), coins.end());
    
    // Inserted performance checkers
    check_high_price_invariant(price, coins);
    check_large_search_space_invariant(price, num_coins);
    check_complex_combinations_invariant(price, coins);
    
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