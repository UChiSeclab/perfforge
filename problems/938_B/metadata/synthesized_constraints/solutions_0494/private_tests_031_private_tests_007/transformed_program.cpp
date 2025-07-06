#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_symmetric_distribution_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - symmetric distribution of prizes!" << endl;
        abort();
    }
}

void check_large_search_space_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - large search space between closest prizes!" << endl;
        abort();
    }
}

void check_middle_position_prizes_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck - multiple prizes in middle positions!" << endl;
        abort();
    }
}

int main() {
    int n;
    set<int> s;
    cin >> n;
    long long g;
    long long a, b;
    a = 1;
    b = 1000000;
    vector<int> prizes(n);
    for (int c = 0; c < n; c++) {
        cin >> prizes[c];
        s.insert(prizes[c]);
    }

    // Check for symmetric distribution of prizes
    check_symmetric_distribution_invariant(n >= 2 && (prizes[0] + prizes[n-1]) / 2 == 500000);

    // Check for large search space between the closest prizes to the starting positions
    check_large_search_space_invariant(prizes[0] > 500 && prizes[n-1] < 999500);

    // Check for multiple prizes in the middle positions
    int middleRangeStart = 450000;
    int middleRangeEnd = 550000;
    int middlePrizesCount = count_if(prizes.begin(), prizes.end(), [&](int pos) {
        return pos >= middleRangeStart && pos <= middleRangeEnd;
    });
    check_middle_position_prizes_invariant(middlePrizesCount > n / 2);

    long long p = 0;
    long long c = 0;
    for (c;; c++) {
        if (s.find(a) != s.end()) p++;
        if (s.find(b) != s.end()) p++;
        a++;
        b--;
        if (p == n) break;
    }
    cout << c;
    return 0;
}