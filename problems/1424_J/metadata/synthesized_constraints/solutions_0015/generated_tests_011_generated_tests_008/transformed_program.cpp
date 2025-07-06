#include <bits/stdc++.h>
using namespace std;

int a[1000005], b[1000005];
bool check[1000005];

void check_tmp_size_invariant(int tmp) {
    if (tmp >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - large value of tmp!" << endl;
        abort();
    }
}

void check_sieve_invariant(int tmp) {
    if (tmp >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive sieve operations!" << endl;
        abort();
    }
}

void check_prime_count_invariant(int tmp) {
    if (tmp >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - costly prime accumulation!" << endl;
        abort();
    }
}

int main() {
    int n, tmp = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tmp = max(tmp, a[i]);
    }

    // Check the invariants after determining 'tmp'
    check_tmp_size_invariant(tmp);

    for (int i = 2; i <= tmp; i++) check[i] = true;
    for (int i = 2; i * i <= tmp; i++) {
        if (check[i] == true)
            for (int j = i * i; j <= tmp; j += i) check[j] = false;
    }
    
    // Check sieve invariant after initialization
    check_sieve_invariant(tmp);
    
    for (int i = 2; i <= tmp; i++) {
        b[i] = (check[i] == true) + b[i - 1];
    }

    // Check prime count accumulation invariant
    check_prime_count_invariant(tmp);

    for (int i = 0; i < n; i++) {
        int cnt = sqrt(a[i]);
        cout << b[a[i]] - b[cnt] + 1 << " ";
    }
    return 0;
}