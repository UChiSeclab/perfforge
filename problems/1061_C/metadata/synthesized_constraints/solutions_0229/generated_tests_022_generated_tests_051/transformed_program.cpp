#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 10;
int n;
int a[MAX];
int f[MAX];
vector<int> dv[MAX];

int add(int a, int b) { return (a + b) % MOD; }

// High maximum element value invariant
void check_max_element_invariant(int maxa) {
    if (maxa > 1e6) {
        cerr << "Warning: High maximum element value detected!" << endl;
        abort();
    }
}

// Large number of divisors invariant
void check_large_divisor_count_invariant(int element, int divisor_count_threshold) {
    if (dv[element].size() > divisor_count_threshold) {
        cerr << "Warning: Large number of divisors for element detected!" << endl;
        abort();
    }
}

// Value distribution and density invariant
void check_value_density_invariant(const vector<int>& a, int density_threshold) {
    map<int, int> frequency;
    for (int num : a) {
        frequency[num]++;
    }
    for (const auto& pair : frequency) {
        if (pair.second > density_threshold) {
            cerr << "Warning: High density of value detected!" << endl;
            abort();
        }
    }
}

// High frequency of large composite numbers invariant
void check_large_composite_invariant(const vector<int>& a, int composite_threshold) {
    int composite_count = 0;
    for (int num : a) {
        if (dv[num].size() > 2) { // More than two divisors indicates it's composite
            composite_count++;
        }
    }
    if (composite_count > composite_threshold) {
        cerr << "Warning: High frequency of large composite numbers detected!" << endl;
        abort();
    }
}

void process() {
    cin >> n;
    vector<int> input_a(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        input_a[i - 1] = a[i];
    }
    int maxa = *max_element(a + 1, a + n + 1);
    
    // Insert check for high maximum element value
    check_max_element_invariant(maxa);
    
    // Precompute divisor lists
    for (int i = 1; i <= maxa; i++)
        for (int j = 1; j <= maxa / i; j++) dv[i * j].push_back(i);

    // Insert checks related to divisors
    for (int i = 1; i <= maxa; i++) {
        check_large_divisor_count_invariant(i, 1000); // Arbitrary threshold
    }
    
    // Check value density in the input array
    check_value_density_invariant(input_a, 10); // Arbitrary density threshold
    
    // Check for large composite numbers
    check_large_composite_invariant(input_a, 50); // Arbitrary composite threshold

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = int((dv[a[i]]).size()) - 1; j >= 0; j--) {
            f[dv[a[i]][j]] = add(f[dv[a[i]][j]], f[dv[a[i]][j] - 1]);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = add(res, f[i]);
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    process();
}