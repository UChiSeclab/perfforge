#include <bits/stdc++.h>
using namespace std;

// Performance checks based on derived invariants
void check_average_position_invariant(const vector<int>& prizes) {
    int n = prizes.size();
    int sum_positions = accumulate(prizes.begin(), prizes.end(), 0);
    int avg_position = sum_positions / n;
    if (avg_position > 500000) {
        cerr << "Warning: average_position_invariant triggered - prizes are far from starting points" << endl;
        abort();
    }
}

void check_skew_invariant(const vector<int>& prizes) {
    int n = prizes.size();
    if (prizes.front() > 500000 || prizes.back() < 500001) {
        cerr << "Warning: skew_invariant triggered - prizes skewed towards one end" << endl;
        abort();
    }
}

void check_large_gap_invariant(const vector<int>& prizes) {
    for (size_t i = 1; i < prizes.size(); ++i) {
        if (prizes[i] - prizes[i-1] > 100000) {
            cerr << "Warning: large_gap_invariant triggered - large gap between prizes" << endl;
            abort();
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Check performance-characterizing invariants
    check_average_position_invariant(a);
    check_skew_invariant(a);
    check_large_gap_invariant(a);

    int x = 1, y = 1000000, t = 0;
    int i = 0, j = n - 1, b = n;
    while (b >= 1) {
        if (x == a[i]) {
            a[i] = 0;
            i++;
            b--;
        }
        if (y == a[j]) {
            a[j] = 0;
            j--;
            b--;
        }
        x = x + 1;
        y = y - 1;
        t++;
    }
    printf("%d", t - 1);
    return 0;
}