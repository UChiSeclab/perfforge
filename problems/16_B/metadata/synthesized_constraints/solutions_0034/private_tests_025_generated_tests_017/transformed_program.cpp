#include <bits/stdc++.h>
using namespace std;

// Function to check the invariant where n is much larger than available matchboxes
void check_large_n_invariant(int n, int m, const vector<pair<int, int>>& v) {
    long long totalBoxes = 0;
    for (const auto& container : v) {
        totalBoxes += container.first;
    }
    if (n > 10 * totalBoxes) {
        cerr << "Warning: Performance bottleneck condition triggered - n is much larger than available matchboxes!" << endl;
        abort();
    }
}

// Function to check the invariant where there are insufficient matchboxes compared to n
void check_small_total_boxes_invariant(int n, int m, const vector<pair<int, int>>& v) {
    long long totalBoxes = 0;
    for (const auto& container : v) {
        totalBoxes += container.first;
    }
    if (totalBoxes < n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient matchboxes compared to n!" << endl;
        abort();
    }
}

int main() {
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        pair<int, int> p(x, y);
        v.push_back(p);
    }
    
    // Insert checks after reading inputs
    check_large_n_invariant(n, m, v);
    check_small_total_boxes_invariant(n, m, v);

    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j].second > v[i].second) {
                pair<int, int> p = v[i];
                v[i] = v[j];
                v[j] = p;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int counter = 0;
        if (sum == n) {
            break;
        }
        int t = n - sum;
        while (counter < v[i].first && t--) {
            counter++;
            sum++;
            ans += v[i].second;
        }
    }
    cout << ans << endl;
}