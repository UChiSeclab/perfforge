#include <bits/stdc++.h>
using namespace std;

int a[100], b[100], c[1000]; // Adjusted sizes to fit problem constraints
char s[1000];

// Frequent Toggles Check
void check_frequent_toggles(const vector<int>& a) {
    int frequentToggleCount = 0;
    for (int ai : a) {
        if (ai == 1) {
            frequentToggleCount++;
        }
    }
    if (frequentToggleCount > a.size() / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent toggles!" << endl;
        abort();
    }
}

// High Synchronization Check
void check_high_synchronization(const vector<int>& a, const vector<int>& b) {
    map<int, int> syncMap;
    for (size_t i = 0; i < a.size(); ++i) {
        int timeStep = a[i];
        for (int t = b[i]; t < 10000; t += timeStep) {
            syncMap[t]++;
        }
    }
    for (const auto& pair : syncMap) {
        if (pair.second > a.size() / 2) {
            cerr << "Warning: Performance bottleneck condition triggered - high synchronization!" << endl;
            abort();
        }
    }
}

// High Iteration Count Check
void check_high_iteration_count(int iterationLimit) {
    if (iterationLimit >= 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    vector<int> a(n), b(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    
    // Insert checks after reading input
    check_frequent_toggles(a);
    check_high_synchronization(a, b);
    
    for (int i = 0; i < n; i++) {
        c[i] = s[i] - '0';
        if (c[i]) cnt++;
    }

    int ans = cnt;
    if (cnt == n) {
        printf("%d\n", n);
    } else {
        check_high_iteration_count(10000);
        for (int i = 1; i < 10000; i++) {
            for (int j = 0; j < n; j++) {
                if (i < b[j]) continue;
                if (i == b[j] || (i - b[j]) % a[j] == 0) {
                    if (c[j]) {
                        cnt--;
                        c[j] = 0;
                    } else {
                        cnt++;
                        c[j] = 1;
                    }
                }
            }
            ans = max(ans, cnt);
            if (ans >= n) {
                ans = n;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}