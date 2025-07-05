#include <bits/stdc++.h>
using namespace std;

// Checker for sort invariant
void check_sort_invariant(int n, const vector<long long>& a) {
    unordered_map<long long, int> frequency;
    for (auto durability : a) {
        frequency[durability]++;
    }
    for (const auto& pair : frequency) {
        if (pair.second > 0.9 * n) { // If more than 90% of doors have the same durability
            cerr << "Warning: sort_invariant triggered - many doors have similar durability." << endl;
            abort();
        }
    }
}

// Checker for repair invariant
void check_repair_invariant(int x, int y, int n, const vector<long long>& a) {
    if (x <= y) {
        int nearZeroCount = 0;
        for (auto durability : a) {
            if (durability <= x) {
                nearZeroCount++;
            }
        }
        if (nearZeroCount > 0.8 * n) {  // If more than 80% of doors have low durability
            cerr << "Warning: repair_invariant triggered - many doors are at low durability with x <= y." << endl;
            abort();
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, x, y;
    cin >> n >> x >> y;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insert checks before entering the main logic loop, leveraging the input constraints:
    check_sort_invariant(n, a);
    check_repair_invariant(x, y, n, a);
    
    long long k, z;
    if (x > y) {
        cout << n << endl;
        return 0;
    } else {
        while (1) {
            sort(a.begin(), a.end());
            for (long long j = 0; j < n; j++) {
                if (a[j] != 0) {
                    z = a[j];
                    k = j;
                    break;
                }
            }
            if (z > x) {
                cout << k << endl;
                return 0;
            } else {
                a[k] = 0;
                if ((k + 1) == n) {
                    cout << k + 1 << endl;
                    return 0;
                }
            }
            if (a[k] == 0) {
                a[k + 1] = a[k + 1] + y;
            } else {
                a[k] = a[k] + y;
            }
        }
    }
}