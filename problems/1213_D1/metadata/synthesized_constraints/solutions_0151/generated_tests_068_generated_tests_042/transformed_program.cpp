#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long inf64 = 1e18;

// Checkers for performance bottlenecks
void check_diversity_invariant(int n, const vector<int>& a) {
    int unique_values = 0;
    unordered_set<int> value_set;
    for (int num : a) {
        int temp = num;
        while (temp) {
            value_set.insert(temp);
            temp >>= 1;
        }
    }
    unique_values = value_set.size();
    if (unique_values > n * 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to high diversity in divisions!" << endl;
        abort();
    }
}

void check_nested_iterations_invariant(int values_size, int n) {
    if (values_size > n * 20) {
        cerr << "Warning: Performance bottleneck condition triggered due to frequent nested iterations!" << endl;
        abort();
    }
}

void check_sorting_accumulation_invariant(int cnt_size, int k) {
    if (cnt_size > k * 5) {
        cerr << "Warning: Performance bottleneck condition triggered due to sorting and accumulation overhead!" << endl;
        abort();
    }
}

void check_element_complexity_invariant(int n, const vector<int>& a) {
    int high_value_count = 0;
    for (int num : a) {
        if (num > 100000) {
            high_value_count++;
        }
    }
    if (high_value_count > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered due to element complexity!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    // Insert checker for element complexity after input
    check_element_complexity_invariant(n, a);

    vector<int> values;
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        while (temp) {
            values.push_back(temp);
            temp >>= 1;
        }
    }

    // Insert checker for diversity after populating values
    check_diversity_invariant(n, a);

    int ans = inf;
    for (int x : values) {
        vector<int> cnt;
        for (int i = 0; i < n; i++) {
            int cur = 0, temp = a[i];
            while (temp > x) {
                temp >>= 1;
                cur++;
            }
            if (temp == x) cnt.push_back(cur);
        }

        // Insert checker for sorting and accumulation before sorting
        check_sorting_accumulation_invariant(cnt.size(), k);

        if ((int)cnt.size() < k) continue;
        sort((cnt).begin(), (cnt).end());
        ans = min(ans, accumulate(cnt.begin(), cnt.begin() + k, 0));
    }

    // Insert checker for nested iterations after processing values
    check_nested_iterations_invariant(values.size(), n);

    cout << ans;
}