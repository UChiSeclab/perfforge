#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_iteration_count(int k) {
    if (k > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count!" << endl;
        abort();
    }
}

void check_repeated_updates(int k) {
    if (k > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated frequency array updates!" << endl;
        abort();
    }
}

void check_alternating_updates(int k, int n) {
    if (k > 1000 && n > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - alternating updates overhead!" << endl;
        abort();
    }
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    
    // Insert checks based on the invariants
    check_high_iteration_count(k);
    check_repeated_updates(k);
    check_alternating_updates(k, n);

    int a[n];
    int freq[2001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    int l = 0;
    int tmp[2001];
    for (int i = 0; i < k; i++) {
        l = 0;
        for (int i = 0; i < 2001; i++) tmp[i] = freq[i];
        for (int j = 0; j < 2001; j++) {
            if (l % 2 == 0 && freq[j] % 2 == 1) {
                tmp[j ^ x] += ceil(freq[j] / 2.0);
                tmp[j] -= ceil(freq[j] / 2.0);
                l++;
            } else if (l % 2 == 1 && freq[j] % 2 == 1) {
                tmp[j ^ x] += floor(freq[j] / 2.0);
                tmp[j] -= floor(freq[j] / 2.0);
                l++;
            } else {
                tmp[j ^ x] += freq[j] / 2;
                tmp[j] -= freq[j] / 2;
            }
        }
        for (int i = 0; i < 2001; i++) freq[i] = tmp[i];
    }
    
    int pq = 0;
    for (int i = 0; i < 2001; i++) {
        if (freq[i] != 0) {
            pq = i;
        }
    }
    cout << pq << " ";
    for (int i = 0; i < 2001; i++) {
        if (freq[i] != 0) {
            cout << i;
            break;
        }
    }
    return 0;
}