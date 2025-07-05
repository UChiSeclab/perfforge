#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

// Checker functions
void check_power_function_invariant(long long exponent) {
    if (exponent > 50000) { // A threshold for large exponents
        cerr << "Warning: Power function bottleneck condition triggered!" << endl;
        abort();
    }
}

void check_nested_loops_invariant(int max1) {
    if (max1 > 90000) { // A threshold indicating large maximum values leading to excessive iterations
        cerr << "Warning: Nested loops bottleneck condition triggered!" << endl;
        abort();
    }
}

void check_divisor_frequency_invariant(long long freq[], int size) {
    for (int i = 1; i <= size; i++) {
        if (freq[i] > 1000) { // A threshold indicating high frequency of a value
            cerr << "Warning: High divisor frequency condition triggered!" << endl;
            abort();
        }
    }
}

// Power function
long long power(long long a, long long b) {
    check_power_function_invariant(b); // Check for large exponents
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    int max1 = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max1 = max(max1, arr[i]);
    }

    // Check for potential nested loop inefficiency
    check_nested_loops_invariant(max1);

    long long freq[max1 + 1], subsequence[max1 + 1];
    for (int i = 0; i <= max1; i++) {
        freq[i] = 0;
        subsequence[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Check for high frequency of divisors
    check_divisor_frequency_invariant(freq, max1);

    for (int i = max1; i > 0; i--) {
        for (int j = i; j <= max1; j += i) {
            subsequence[i] += freq[j];
        }
    }

    long long ans = 0;
    for (int i = max1; i > 0; i--) {
        long long sub = 0;
        for (int j = 2 * i; j <= max1; j += i) {
            sub += subsequence[j];
            sub %= mod;
        }
        subsequence[i] = (power(2, subsequence[i]) - 1 + mod) % mod;
        subsequence[i] -= sub;
        subsequence[i] += mod;
        subsequence[i] %= mod;
    }
    cout << subsequence[1] << "\n";
}