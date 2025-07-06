#include <bits/stdc++.h>
using namespace std;

// Function to check factorization overhead
void check_factorization_invariant(int num) {
    int factor_count = 0;
    for (int j = 2; j <= num; ++j) {
        if (num % j == 0) {
            factor_count++;
            while (num % j == 0) {
                num /= j;
            }
        }
    }
    if (factor_count <= 2) { // Few factors, especially when num is large
        cerr << "Warning: Performance bottleneck condition triggered due to high factorization overhead!" << endl;
        abort();
    }
}

// Function to check high exponent impact
void check_high_exponent_invariant(int k) {
    if (k > 50) { // Arbitrary threshold to detect high k values
        cerr << "Warning: Performance bottleneck condition triggered due to high exponent k!" << endl;
        abort();
    }
}

// Function to check input data complexity
void check_complexity_invariant(const vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > 90000) { // Large values close to upper constraint
            cerr << "Warning: Performance bottleneck condition triggered due to large integers with complex factorization!" << endl;
            abort();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    // Check high exponent invariant
    check_high_exponent_invariant(k);

    vector<int> a(n, 0);
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        // Check factorization overhead invariant for each integer
        check_factorization_invariant(a[i]);
    }

    // Check complexity of input data structure invariant
    check_complexity_invariant(a);

    map<vector<pair<int, int>>, long long> m;
    for (int i = 0; i < n; ++i) {
        vector<pair<int, int>> prime;
        int tmp = 0;
        int counter = 1;
        if (a[i] == 1) {
            prime.push_back({});
        }
        while (a[i] > 1) {
            for (int j = 2; j <= a[i]; ++j) {
                if (a[i] % j == 0) {
                    a[i] /= j;
                    if (j != tmp) {
                        if (tmp != 0 && counter % k > 0) {
                            prime.push_back({tmp, counter % k});
                        }
                        counter = 1;
                    } else
                        ++counter;
                    tmp = j;
                    break;
                }
            }
        }
        if (tmp != 0 && counter % k > 0) {
            prime.push_back({tmp, counter % k});
        }
        if (prime.size() == 0) {
            prime.push_back({});
        }
        if (!m.count(prime)) {
            m[prime] = 1;
        } else {
            ++m[prime];
        }
    }

    for (pair<vector<pair<int, int>>, long long> t : m) {
        vector<pair<int, int>> s;
        if (t.first[0].first == 0 && t.first[0].second == 0) {
            ans += t.second * (t.second - 1) / 2;
        } else if (t.second > 0) {
            for (int i = 0; i < t.first.size(); ++i) {
                s.push_back({t.first[i].first, k - t.first[i].second});
            }
        }
        if (m.count(s) && t.first == s) {
            ans += m[t.first] * (m[t.first] - 1) / 2;
        } else if (m.count(s)) {
            ans += m[t.first] * m[s];
            m[s] = 0;
        }
    }

    cout << ans << endl;
}