#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>
#include <unordered_set>

void check_cycle_invariant(const queue<int>& r1, const queue<int>& r2, unordered_set<string>& seenConfigurations) {
    string config;
    auto copy1 = r1, copy2 = r2;
    while (!copy1.empty()) {
        config += to_string(copy1.front()) + ",";
        copy1.pop();
    }
    config += "|";
    while (!copy2.empty()) {
        config += to_string(copy2.front()) + ",";
        copy2.pop();
    }
    
    if (seenConfigurations.find(config) != seenConfigurations.end()) {
        cerr << "Warning: Cycle detected - potential infinite loop!" << endl;
        abort();
    }
    seenConfigurations.insert(config);
}

// Check if neither player can win quickly due to balanced card strength
void check_balance_invariant(const queue<int>& r1, const queue<int>& r2) {
    int max1 = *max_element(r1.front(), r1.back());
    int max2 = *max_element(r2.front(), r2.back());
    if (abs(max1 - max2) <= 1) { // Arbitrarily chosen threshold for similar max strength
        cerr << "Warning: Balanced card strength - prolonged game possible!" << endl;
        abort();
    }
}

// Check for excessive number of rounds
void check_excessive_rounds(int TLE) {
    if (TLE > 1000) { // Example threshold, can be adjusted for practical purposes
        cerr << "Warning: Excessive number of game rounds!" << endl;
        abort();
    }
}

queue<int> r1, r2;
int n, x, TLE, asd;
bool flag;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= x; i++) cin >> asd, r1.push(asd);
    cin >> x;
    for (int i = 1; i <= x; i++) cin >> asd, r2.push(asd);
    
    unordered_set<string> seenConfigurations; // Set to track seen configurations

    // Check for potential bottlenecks before starting the loop
    check_balance_invariant(r1, r2);
    
    while (TLE < 10000000) {
        check_excessive_rounds(TLE);
        check_cycle_invariant(r1, r2, seenConfigurations);

        if (r1.size() == 0 || r2.size() == 0) {
            flag = 1;
            break;
        }
        TLE++;
        int u = r1.front(), v = r2.front();
        r1.pop(), r2.pop();
        if (u > v)
            r1.push(v), r1.push(u);
        else
            r2.push(u), r2.push(v);
    }
    
    if (flag)
        if (r1.size() == 0)
            cout << TLE << " " << 2 << endl;
        else
            cout << TLE << " " << 1 << endl;
    else
        puts("-1");
    return 0;
}