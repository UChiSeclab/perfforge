#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_operations_invariant(long long k) {
    if (k > 50000) {
        cerr << "Warning: Performance bottleneck due to high number of operations!" << endl;
        abort();
    }
}

void check_iterative_load_invariant(long long k, int arraySize) {
    if (k * arraySize > 50000000) {
        cerr << "Warning: Performance bottleneck due to high iterative load!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k, x, *a;
    cin >> n >> k >> x;
    a = new long long[n];
    long long val[1024] = {0};
    int temp[1024] = {0};
    
    // Insert checker calls before the main processing loop
    check_operations_invariant(k);
    check_iterative_load_invariant(k, 1024);
    
    for (long long i = 0; i < (n); i++) {
        cin >> a[i];
        val[a[i]]++;
    }
    for (long long i = 1; i <= k; i++) {
        int cnt = 0;
        for (long long j = 0; j <= 1023; j++) {
            if (cnt % 2 == 0) {
                temp[j ^ x] += ceil(val[j] / 2.0);
                temp[j] += (val[j] / 2);
            } else {
                temp[j] += ceil(val[j] / 2.0);
                temp[j ^ x] += (val[j] / 2);
            }
            cnt += val[j];
        }
        for (long long j = 0; j <= 1023; j++) {
            val[j] = temp[j];
            temp[j] = 0;
        }
    }
    long long minimum, maximum;
    for (long long i = 0; i <= 1023; i++)
        if (val[i] > 0) {
            minimum = i;
            break;
        }
    for (long long i = 1023; i >= 0; i--)
        if (val[i] > 0) {
            maximum = i;
            break;
        }
    cout << maximum << " " << minimum;
    return 0;
}