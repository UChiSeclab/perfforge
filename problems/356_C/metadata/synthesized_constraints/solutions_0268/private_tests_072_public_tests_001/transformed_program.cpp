#include <bits/stdc++.h>
using namespace std;

// Check for a high number of singleton compartments
void check_singleton_compartments(const map<int, int>& c) {
    if (c.at(1) > 100) { // Arbitrary threshold for "high frequency"
        cerr << "Warning: Performance bottleneck condition triggered - High frequency of singleton compartments!" << endl;
        abort();
    }
}

// Check for uneven distribution leading to complex redistributions
void check_uneven_distribution(const map<int, int>& c, int n) {
    if ((c.at(1) + c.at(2)) > n / 2) { // If more than half of the compartments are problematic
        cerr << "Warning: Performance bottleneck condition triggered - Uneven distribution of students!" << endl;
        abort();
    }
}

// Check for a high initial count of two-student compartments
void check_two_student_compartments(const map<int, int>& c) {
    if (c.at(2) > 80) { // Arbitrary threshold for excess two-student compartments
        cerr << "Warning: Performance bottleneck condition triggered - Excess two-student compartments!" << endl;
        abort();
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> c, cc;
    map<int, set<int> > q;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        ++c[v[i]];
        q[v[i]].insert(i);
    }

    // Insert checks after data is collected
    check_singleton_compartments(c);
    check_uneven_distribution(c, n);
    check_two_student_compartments(c);

    int t;
    t = min(c[1], c[2]);
    c[1] -= t, c[2] -= t;
    c[3] += t;
    ans += t;
    if (c[2] == 0 && c[1] == 0) {
        cout << ans;
        return 0;
    }
    if (c[2] == 0) {
        t = c[1] / 3;
        c[3] += t;
        c[1] %= 3;
        ans += 2 * t;
        if (c[1] != 0) {
            t = min(c[1] / 2, c[4]);
            c[3] += t;
            c[4] -= t;
            c[1] -= t * 2;
            ans += t * 2;
            t = min(c[1], c[3]);
            c[1] -= t;
            c[3] += t;
            ans += t;
        }
        if (c[1] != 0) {
            t = min(c[4] / 2, c[1]);
            c[1] -= t;
            c[4] -= 2 * t;
            c[3] += t;
            ans += t * 2;
        }
    } else {
        t = c[2] / 3;
        c[3] += 2 * t;
        c[2] %= 3;
        ans += 2 * t;
        if (c[2] != 0) {
            t = c[2] / 2;
            c[4] += t;
            c[2] -= t * 2;
            ans += t * 2;
            t = min(c[2], c[4]);
            ans += t;
            c[4] -= t, c[2] -= t;
            c[3] += t;
            t = min(c[2], c[3] / 2);
            ans += 2 * t;
            c[4] += 2 * t;
            c[3] -= 2 * t;
            c[2] -= t;
        }
    }
    if (c[1] != 0 || c[2] != 0) {
        ans = -1;
    }
    cout << ans;
}