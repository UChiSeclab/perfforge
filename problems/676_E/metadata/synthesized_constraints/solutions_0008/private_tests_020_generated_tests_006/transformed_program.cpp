#include <bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
long long n, k;
long long a[123456];
const long long inf = (int)(1e9);
int cnt = 0;
long long mas[123456];

// Function to check prime number search inefficiency
void check_prime_search_invariant(int startValue) {
    if (startValue >= 1e9) {
        cerr << "Warning: Performance bottleneck condition triggered - large prime search space!" << endl;
        abort();
    }
}

// Function to check handling of large sparse polynomials
void check_sparse_polynomial_invariant(int n, int undefinedCount) {
    if (n >= 100 && undefinedCount > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - large sparse polynomial handling!" << endl;
        abort();
    }
}

long long solve() {
    long long md;
    int startValue = mt() % 123456 + (int)(1e9);
    check_prime_search_invariant(startValue); // Check for inefficient prime search
    for (int i = startValue;; i++) {
        bool ok = false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            md = i;
            break;
        }
    }
    long long tmp = 1;
    for (int i = 0; i <= n; i++) {
        mas[i] = tmp;
        tmp *= k;
        tmp %= md;
    }
    long long sum = 0;
    for (int i = 0; i <= n; i++) {
        long long t = (a[i] * mas[i]) % md;
        sum += t;
        sum %= md;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    int undefinedCount = 0;
    for (int i = 0; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "?") {
            a[i] = inf;
            undefinedCount++;
        } else {
            istringstream iss(s);
            iss >> a[i];
            cnt++;
        }
    }
    
    check_sparse_polynomial_invariant(n, undefinedCount); // Check for large sparse polynomial

    if (cnt < n + 1) {
        if (k == 0 && a[0] != 0 && a[0] != inf) {
            cout << "No" << endl;
            exit(0);
        }
        if (n % 2 == 1) {
            if (k == 0 && a[0] == inf && cnt % 2 == 0)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        } else {
            if ((k == 0 && a[0] == 0) || (k == 0 && a[0] == inf && cnt % 2 == 1))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        exit(0);
    }
    long long attempt1 = solve();
    long long attempt2 = solve();
    long long attempt3 = solve();
    if (attempt1 == 0 && attempt2 == 0 && attempt3 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}