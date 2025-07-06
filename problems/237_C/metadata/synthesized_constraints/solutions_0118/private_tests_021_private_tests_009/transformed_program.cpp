#include <bits/stdc++.h>
using namespace std;

vector<bool> primes;
vector<int> primesCnt;

void check_sieve_invariant(int a, int b, int threshold) {
    if (b - a > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large range for sieve!" << endl;
        abort();
    }
}

void check_prime_count_invariant(int a, int b, int threshold) {
    if (b - a > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive prime count calculation!" << endl;
        abort();
    }
}

void check_input_size_invariant(int a, int b, int maxLimit) {
    if (b - a + 1 > maxLimit) {
        cerr << "Warning: Performance bottleneck condition triggered - input size too large!" << endl;
        abort();
    }
}

void seive(int a, int b) {
    primes = vector<bool>(b + 1, true);
    primesCnt = vector<int>(b, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= b; i++) {
        for (int j = i; j * i <= b; j++) {
            primes[i * j] = false;
        }
    }
    primesCnt[0] = 0;
    for (decltype(b + 1)(i) = (1); (i) < (b + 1); (i)++) {
        primesCnt[i] = primesCnt[i - 1] + primes[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, k, ans = -1;
    cin >> a >> b >> k;

    // Checker invocations
    check_sieve_invariant(a, b, 500000); // Checking sieve complexity
    check_prime_count_invariant(a, b, 500000); // Checking prime count calculation complexity
    check_input_size_invariant(a, b, 1000000); // Checking overall input size

    seive(a, b);
    if (primesCnt[b] - primesCnt[a - 1] < k) {
        cout << ans;
        return 0;
    }

    int left = 0, right = b - a + 1, med;
    while (right > left + 1) {
        med = (right + left) / 2;
        bool can = true;
        int j = a + med - 1;
        while (j <= b) {
            if (primesCnt[j] - primesCnt[j - med] < k) {
                can = false;
                break;
            }
            j++;
        }
        if (can)
            right = med;
        else
            left = med;
    }
    cout << right;
    return 0;
}