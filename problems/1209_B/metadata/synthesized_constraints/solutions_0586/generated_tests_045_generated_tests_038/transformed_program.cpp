#include <bits/stdc++.h>
using namespace std;

const int MAX = 10e4 + 5;

// Checker function for frequent toggle invariant
void check_frequent_toggle_invariant(const vector<pair<int, int>>& v) {
    int small_a_count = 0;
    for (const auto& light : v) {
        if (light.first <= 2) { // Consider a_i values that are small and cause frequent toggling
            small_a_count++;
        }
    }
    if (small_a_count > v.size() / 2) { // If more than half the lights have small a_i
        cerr << "Warning: Performance bottleneck condition triggered - frequent toggling!" << endl;
        abort();
    }
}

// Checker function for late max invariant
void check_late_max_invariant(const string& initialState, const vector<pair<int, int>>& v) {
    bool lateMaxPossible = false;
    for (size_t j = 0; j < v.size(); ++j) {
        if (initialState[j] == '0' && v[j].second > 2) { // Check for lights that start off and toggle late
            lateMaxPossible = true;
            break;
        }
    }
    if (lateMaxPossible) {
        cerr << "Warning: Performance bottleneck condition triggered - potential late maximum!" << endl;
        abort();
    }
}

// Checker function for coincide toggle invariant
void check_coincide_toggle_invariant(const vector<pair<int, int>>& v) {
    map<int, int> toggleFreq;
    for (const auto& light : v) {
        for (int t = light.second; t < 10; t += light.first) { // Check in a small time window
            toggleFreq[t]++;
        }
    }
    for (const auto& [time, freq] : toggleFreq) {
        if (freq > v.size() / 2) { // If more than half the lights toggle at the same time frequently
            cerr << "Warning: Performance bottleneck condition triggered - frequent coinciding toggles!" << endl;
            abort();
        }
    }
}

int main() {
    int n;
    cin >> n;
    string string1 = "";
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (a == '1') maxi++;
        string1 += a;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        v.push_back(p);
    }

    // Place the checks after reading input data
    check_frequent_toggle_invariant(v);
    check_late_max_invariant(string1, v);
    check_coincide_toggle_invariant(v);

    int count = maxi;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= v[j].second and (i - v[j].second) % v[j].first == 0) {
                if (string1[j] == '0') {
                    string1[j] = '1';
                    count++;
                } else {
                    string1[j] = '0';
                    count--;
                }
            }
        }
        maxi = max(maxi, count);
        if (maxi == string1.length()) {
            break;
        }
    }
    cout << maxi;
    return 0;
}