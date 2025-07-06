#include <bits/stdc++.h>
using namespace std;

namespace round170 {
namespace B {

inline string next(string a) {
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (a[i] == 'z') {
            a[i] = 'a';
            if (i == 0) a = "a" + a;
        } else {
            ++a[i];
            return a;
        }
    }
    return a;
}

inline bool cmp(const string& a, const string& b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void check_next_function_usage(int usageCount) {
    // This check detects excessive usage of the `next` function, indicating
    // potential performance slowdown due to repeated generation of substrings.
    if (usageCount > 100) {  // Arbitrary threshold, considering constraints
        cerr << "Warning: Performance bottleneck condition triggered - excessive calls to `next` function!" << endl;
        abort();
    }
}

void check_substring_set_size(int setSize) {
    // This check monitors the size of the substring set `q`, which can grow large
    // and cause sorting/comparison overhead.
    if (setSize > 1000) {  // Arbitrary threshold, considering constraints
        cerr << "Warning: Performance bottleneck condition triggered - substring set too large!" << endl;
        abort();
    }
}

int solve(istream& in) {
    int n;
    in >> n;
    set<string> q;
    string s;
    string ans;

    // Track usage count for the `next` function
    int nextFunctionUsageCount = 0;

    for (int i = 0; i < n; ++i) {
        in >> s;
        for (int j = 0; j < (int)s.size(); ++j)
            for (int k = j + 1; k <= (int)s.size(); ++k) {
                string t;
                for (int z = j; z < k; ++z) t += s[z];
                q.insert(t);
            }
    }

    // Check the size of the substring set `q`
    check_substring_set_size(q.size());

    vector<string> v(q.begin(), q.end());
    sort(v.begin(), v.end(), cmp);
    int i = 0;
    s = v[i];
    if (s != "a")
        ans = "a";
    else {
        for (++i; i < (int)v.size(); ++i) {
            s = next(s);
            nextFunctionUsageCount++;  // Increment usage count for `next` function
            if (v[i] != s) {
                ans = s;
                break;
            }
        }
        if (ans.empty()) {
            ans = next(v.back());
            nextFunctionUsageCount++;  // Increment usage count for `next` function
        }
    }

    // Check the `next` function usage
    check_next_function_usage(nextFunctionUsageCount);

    cout << ans << endl;
    return 999;
}

}  // namespace B
}  // namespace round170

int main() {
    ios_base::sync_with_stdio(false);
    int status = 0;
    do {
        status = round170::B::solve(cin);
    } while (0);
    return 0;
}