#include <bits/stdc++.h>
using namespace std;

void check_frequent_value_invariant(const map<int, int>& frequency) {
    for (const auto& entry : frequency) {
        if (entry.second > 50) { // Arbitrary threshold based on n <= 100
            cerr << "Warning: Performance bottleneck condition triggered - frequent coin value repetition!" << endl;
            abort();
        }
    }
}

void check_high_value_frequency_invariant(const map<int, int>& frequency, int n) {
    int maxFrequency = 0;
    for (const auto& entry : frequency) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
        }
    }
    if (maxFrequency > n / 2) { // More than half the coins are of the same value
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of a single coin value!" << endl;
        abort();
    }
}

void check_unique_pockets_invariant(const vector<set<int>>& pockets) {
    if (pockets.size() > 50) { // Arbitrary threshold to catch potential slowdowns
        cerr << "Warning: Performance bottleneck condition triggered - high number of unique pockets!" << endl;
        abort();
    }
}

void solve() {
    int n;
    vector<set<int>> pockets;
    cin >> n;
    
    map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        frequency[a]++;
    }

    // Insert checks after reading inputs for initial conditions
    check_frequent_value_invariant(frequency);
    check_high_value_frequency_invariant(frequency, n);

    for (int i = 0; i < n; i++) {
        int a;
        bool done = false;
        for (int j = 0; j < pockets.size(); j++) {
            int sb = pockets[j].size();
            pockets[j].insert(a);
            if (sb != pockets[j].size()) {
                done = true;
                break;
            }
        }
        if (!done) {
            set<int> temp;
            temp.insert(a);
            pockets.push_back(temp);
        }
    }

    // Check potential issues after pockets have been populated
    check_unique_pockets_invariant(pockets);

    cout << pockets.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}