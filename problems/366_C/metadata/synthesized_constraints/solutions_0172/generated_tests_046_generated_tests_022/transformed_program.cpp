#include <bits/stdc++.h>
using namespace std;
const int N = 110;
set<int> sve;
map<int, int> dp;
int a[N], b[N], n, k;
vector<pair<int, int>> v;

// Checker functions
void check_set_size_invariant(int setSize, int threshold) {
    if (setSize > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large set size!" << endl;
        abort();
    }
}

void check_input_size_invariant(int n, int threshold) {
    if (n >= threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large input size!" << endl;
        abort();
    }
}

void check_variation_invariant(const vector<int>& a, const vector<int>& b, int variation_threshold) {
    int taste_range = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    int calorie_range = *max_element(b.begin(), b.end()) - *min_element(b.begin(), b.end());

    if (taste_range > variation_threshold || calorie_range > variation_threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to high variation in tastes or calories!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> k;

    // Check input size invariant
    check_input_size_invariant(n, 90);  // Set threshold to 90 as a safe boundary given n <= 100

    vector<int> a_vector(n+1), b_vector(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i], a_vector[i] = a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b_vector[i] = b[i];
        b[i] *= k;
    }

    // Check variation invariant before further processing
    check_variation_invariant(a_vector, b_vector, 80);  // Arbitrary variation threshold

    for (int i = 1; i <= n; i++) {
        v.clear();
        for (auto it : sve) {
            int sum = it;
            v.push_back(make_pair(sum + a[i] - b[i], dp[sum] + a[i]));
        }
        for (int j = 0; j < v.size(); j++) {
            int best = dp[v[j].first];
            best = max(best, v[j].second);
            dp[v[j].first] = best;
            sve.insert(v[j].first);
        }
        if (sve.find(a[i] - b[i]) == sve.end()) {
            sve.insert(a[i] - b[i]);
            dp[a[i] - b[i]] = a[i];
        } else {
            int best = dp[a[i] - b[i]];
            best = max(best, a[i]);
            dp[a[i] - b[i]] = best;
        }

        // Check set size invariant after processing each fruit
        check_set_size_invariant(sve.size(), 5000);  // Set threshold to an empirical value
    }

    if (dp.count(0) == 0)
        cout << "-1";
    else
        cout << dp[0];
    return 0;
}