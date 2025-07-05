#include <bits/stdc++.h>
using namespace std;

int a[200000];

// Checker functions
void check_high_perfect_square_count(int count, int n) {
    if (count > n / 2) {
        cerr << "Warning: High perfect square count causing imbalance!" << endl;
        abort();
    }
}

void check_repeated_sorting_and_summing(int vectorSize, int threshold) {
    if (vectorSize > threshold) {
        cerr << "Warning: Repeated sorting and summing with large vector size!" << endl;
        abort();
    }
}

void check_initial_imbalance(int c0, int c1, int n) {
    if (abs(c0 - c1) > n / 4) {
        cerr << "Warning: Initial imbalance in square and non-square piles!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    int c[2];
    memset(c, 0, sizeof c);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[(int)sqrt(a[i]) * (int)sqrt(a[i]) == a[i]]++;
    }

    // Check for initial imbalance
    check_initial_imbalance(c[0], c[1], n);

    if (c[0] == c[1]) {
        cout << 0 << endl;
        return 0;
    }

    long long val = 0;
    vector<int> v;
    v.clear();

    if (c[1] > c[0]) {
        for (int i = 0; i < n; i++) {
            if (!((int)sqrt(a[i]) * (int)sqrt(a[i]) - a[i]))
                a[i] ? v.push_back(1) : v.push_back(2);
        }
        
        // Check for high perfect square count
        check_high_perfect_square_count(c[1], n);

        sort(v.begin(), v.end());
        
        // Check for repeated sorting and summing
        check_repeated_sorting_and_summing(v.size(), n / 4);

        for (int i = 0; i < c[1] - (n >> 1); i++) {
            val += v[i];
        }
        
        cout << val << endl;
        return 0;
    }

    val = 0;
    v.clear();
    if (c[0] > c[1]) {
        for (int i = 0; i < n; i++) {
            if ((int)sqrt(a[i]) * (int)sqrt(a[i]) - a[i]) {
                v.push_back(
                    min(abs((int)sqrt(a[i]) * (int)sqrt(a[i]) - a[i]),
                        abs(((int)sqrt(a[i]) + 1) * ((int)sqrt(a[i]) + 1) - a[i])));
            }
        }
        
        sort(v.begin(), v.end());

        // Check for repeated sorting and summing
        check_repeated_sorting_and_summing(v.size(), n / 4);

        for (int i = 0; i < c[0] - (n >> 1); i++) {
            val += v[i];
        }
        
        cout << val << endl;
        return 0;
    }
    return 0;
}