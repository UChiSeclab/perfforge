#include <bits/stdc++.h>
using namespace std;

// Checker for Prime Checking Overhead
void check_prime_checking_invariant(int y, int p) {
    if (y - p < 1000 && p > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive prime checking!" << endl;
        abort();
    }
}

// Checker for Decremental Search Loop
void check_decremental_search_invariant(int y, int p) {
    if (y - p < 1000 && y > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient decremental search!" << endl;
        abort();
    }
}

// Checker for Divisor Collection Overhead
void check_divisor_collection_invariant(int p) {
    if (p > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive divisor collection overhead!" << endl;
        abort();
    }
}

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int p, y;
    cin >> p >> y;

    // Insert checkers at strategic points
    check_prime_checking_invariant(y, p);
    check_decremental_search_invariant(y, p);
    check_divisor_collection_invariant(p);

    int t = y;
    while (t > p && !is_prime(t)) --t;
    if (t == p) ++t;

    std::vector<int> div;
    for (int i = 2; i <= p && i * i <= y; ++i)
        if (is_prime(i)) div.push_back(i);

    int res = -1;
    for (int i = t; i <= y; ++i) {
        bool free = true;
        for (size_t j = 0; j < div.size(); ++j) {
            if (div[j] * div[j] > i) break;
            if (i % div[j] == 0) {
                free = false;
                break;
            }
        }
        if (free) res = i;
    }
    cout << res;
    return 0;
}