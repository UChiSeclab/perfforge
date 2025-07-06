#include <bits/stdc++.h>
using namespace std;

// Function to check the sorting-based invariant
void check_sort_invariant(size_t n) {
    if (n > 50000) { // Example threshold based on potential performance impact of sorting
        cerr << "Warning: Performance bottleneck due to large sorting operations!" << endl;
        abort();
    }
}

// Function to check the loop and condition complexity invariant
void check_loop_invariant(const vector<long long>& v, long long maxi) {
    long long unique_count = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] != v[i-1]) {
            unique_count++;
        }
    }
    if (unique_count > 50 && maxi > 100) {  // Example thresholds
        cerr << "Warning: Performance bottleneck due to high variability and complex loop conditions!" << endl;
        abort();
    }
}

// Function to check the maximum stack height influence invariant
void check_max_height_invariant(long long maxi) {
    if (maxi > 500) { // Example threshold for maximum stack height
        cerr << "Warning: Performance bottleneck due to high maximum stack height adjustments!" << endl;
        abort();
    }
}

int main() {
    long long n, t, b, k, p;
    cin >> n >> k;
    long long ans = 0;
    long long maxi = 0;
    vector<long long> v;

    for (int i = 0; i < n; i++) {
        cin >> b;
        maxi = max(maxi, b);
        v.push_back(b);
    }

    // Insert checks for invariants after input
    check_sort_invariant(n); // Check sorting-based invariant
    check_max_height_invariant(maxi); // Check max height influence invariant

    if (n == 1) {
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());

    // Check loop invariant just after sorting
    check_loop_invariant(v, maxi);

    for (int i = v.size() - 1; i >= 1; i--) {
        if (maxi == 0) {
            ans += (v[i] - 1);
            continue;
        }
        if (v[i - 1] == v[i]) {
            maxi--;
            ans += (v[i] - 1);
        } else {
            if (maxi > v[i - 1]) {
                ans += (v[i] - (maxi - v[i - 1]));
                maxi = v[i - 1];
            } else {
                maxi--;
                ans += (v[i] - 1);
            }
        }
    }

    if (maxi == 0) {
        ans += (v[0] - 1);
    } else {
        ans += (v[0] - maxi);
    }

    cout << ans;
    return 0;
}