#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_initial_durability(int n, int x, const vector<int>& a) {
    int low_durability_count = count_if(a.begin(), a.end(), [x](int durability) {
        return durability <= x;
    });
    if (low_durability_count > n / 2) {
        cerr << "Warning: High initial low durability values condition triggered!" << endl;
        abort();
    }
}

void check_small_x_relative_to_y(int x, int y, const vector<int>& a) {
    int critical_durability_count = count_if(a.begin(), a.end(), [y](int durability) {
        return durability <= y && durability > 0;
    });
    if (x < y && critical_durability_count > a.size() / 3) {
        cerr << "Warning: Small x relative to y condition triggered!" << endl;
        abort();
    }
}

void check_highly_clustered_values(const vector<int>& a) {
    map<int, int> durability_count;
    for (int durability : a) {
        durability_count[durability]++;
    }
    for (const auto& pair : durability_count) {
        if (pair.second > a.size() / 4) {
            cerr << "Warning: Highly clustered durability values condition triggered!" << endl;
            abort();
        }
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Insert checker functions
    check_high_initial_durability(n, x, a);
    check_small_x_relative_to_y(x, y, a);
    check_highly_clustered_values(a);

    if (x > y)
        cout << n;
    else {
        int c = 0;
        map<int, int> m;
        for (int i = 0; i < n; ++i) m[a[i]]++;
        for (int i = 1; i <= x; ++i) {
            if (m[i] > 0) c += m[i];
        }
        if (c % 2 == 0)
            cout << c / 2;
        else
            cout << c / 2 + 1;
    }
    return 0;
}