#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_factorization_invariant(long long b, long long threshold) {
    long long count = 0;
    for (long long i = 2; i <= sqrt(b); ++i) {
        while (b % i == 0) {
            count++;
            b /= i;
        }
    }
    if (b > 1) count++; // Count the last prime factor if b is still greater than 1
    
    if (count > threshold) {
        cerr << "Warning: factorization_invariant triggered - excessive factorization divisions" << endl;
        abort();
    }
}

void check_division_invariant(const map<long long, long long>& pr, long long threshold) {
    if (pr.size() > threshold) {
        cerr << "Warning: division_invariant triggered - many divisions required for factorization" << endl;
        abort();
    }
}

void check_iteration_invariant(long long b, long long threshold) {
    if (sqrt(b) > threshold) {
        cerr << "Warning: iteration_invariant triggered - excessive loop iterations for factorization" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10);

    long long n, b;
    cin >> n >> b;
    
    // Insert invariant checks
    long long factorization_threshold = 1000; // Sample threshold
    long long iteration_threshold = 1000000; // Sample threshold
    check_iteration_invariant(b, iteration_threshold);
    
    map<long long, long long> pr;
    long long b_copy = b;
    
    for (long long i = 2; i <= sqrt(b_copy); ++i) {
        while (b_copy % i == 0) {
            pr[i]++;
            b_copy /= i;
        }
    }
    if (b_copy > 1) pr[b_copy]++;
    
    // Check factorization complexity
    check_factorization_invariant(b, factorization_threshold);
    check_division_invariant(pr, factorization_threshold);

    long long mi = -1;
    for (auto el : pr) {
        if (el.second == 0) continue;
        long long first = el.first;
        long long c = 0;
        while (first <= n) {
            c += n / first;
            if (first > n / el.first) break;
            first *= el.first;
        }
        c /= el.second;
        if (mi == -1) mi = c;
        mi = min(mi, c);
    }
    cout << mi << '\n';
    return 0;
}