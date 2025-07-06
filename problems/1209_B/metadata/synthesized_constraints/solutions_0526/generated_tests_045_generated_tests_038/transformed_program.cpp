#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Checker functions based on performance-characterizing invariants
void check_iteration_limit(int i, int limit) {
    if (i >= limit) {
        cerr << "Warning: Performance bottleneck condition triggered - maximum iteration limit reached!" << endl;
        abort();
    }
}

void check_frequent_toggling(int toggles, int threshold) {
    if (toggles >= threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent toggling detected!" << endl;
        abort();
    }
}

void check_prolonged_execution(int ans, int n) {
    if (ans < n) {
        cerr << "Warning: Performance bottleneck condition triggered - prolonged execution without convergence!" << endl;
        abort();
    }
}

void check_synchronized_toggles(int simultaneousToggles, int threshold) {
    if (simultaneousToggles > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - numerous toggles per second!" << endl;
        abort();
    }
}

inline void inp(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i] >> b[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n), b(n);
    inp(a, b);
    int ans = 0;
    const int iterationLimit = 500000; // Defined iteration limit
    const int toggleThreshold = 100; // Arbitrary threshold for frequent toggling
    const int syncToggleThreshold = 10; // Arbitrary threshold for synchronized toggles

    for (int i = 0; i < iterationLimit; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                temp++;
            }
        }
        ans = max(temp, ans);
        if (ans == n) break;

        int simultaneousToggles = 0;
        for (int j = 0; j < n; j++) {
            if (i - b[j] >= 0 && (i - b[j]) % a[j] == 0) {
                if (s[j] == '1')
                    s[j] = '0';
                else if (s[j] == '0')
                    s[j] = '1';
                simultaneousToggles++;
            }
        }

        // Check for frequent toggling
        check_frequent_toggling(simultaneousToggles, toggleThreshold);

        // Check for synchronized toggles
        check_synchronized_toggles(simultaneousToggles, syncToggleThreshold);
    }

    // Check for prolonged execution without convergence
    check_prolonged_execution(ans, n);

    cout << ans << "\n";
    return 0;
}