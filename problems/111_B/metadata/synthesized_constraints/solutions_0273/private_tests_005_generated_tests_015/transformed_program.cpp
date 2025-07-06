#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<int, int>;

// Check: Large number of divisors
void check_large_divisors(int x, int divisor_count_threshold) {
    int divisorCount = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divisorCount++;
            if (i != x / i) divisorCount++;
        }
    }
    if (divisorCount > divisor_count_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered! Large number of divisors." << endl;
        abort();
    }
}

// Check: Large composite number
void check_large_composite(int x, int composite_threshold) {
    if (x > composite_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered! Large composite number." << endl;
        abort();
    }
}

// Check: Frequent large xi with small yi
void check_frequent_large_x_yi(int x, int yi, int large_x_threshold) {
    if (x > large_x_threshold && yi < 5) {
        cerr << "Warning: Performance bottleneck condition triggered! Frequent large xi with small yi." << endl;
        abort();
    }
}

unordered_set<int> divisors(int x, int p) {
    unordered_set<int> second;
    if (x <= p) {
        second.insert(x);
        second.insert(1);
        return second;
    } else {
        for (int i = p; i * i <= x; i++) {
            if (x % i == 0) {
                auto last_s = divisors(x / i, i);
                for (auto next : last_s) {
                    second.insert(next);
                    second.insert(i * next);
                }
            }
        }
        second.insert(1);
        second.insert(x);
        return second;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vc<int> last(1e5 + 1, -1);
    for (int i = 0; i < n; i++) {
        int x, ind;
        cin >> x >> ind;
        ind = i - ind;

        // Insert checks before computation calls
        check_large_divisors(x, 100); // Assume 100 as a threshold for a large number of divisors
        check_large_composite(x, 50000); // Assume 50000 is a high value for composite numbers
        check_frequent_large_x_yi(x, ind, 75000); // Assume 75000 is a large x threshold

        unordered_set<int> div = divisors(x, 2);
        int anz = 0;
        for (auto d : div) {
            if (last[d] < ind) anz++;
            last[d] = i;
        }
        cout << anz << " ";
    }
    cout << "\n";
}