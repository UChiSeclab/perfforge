#include <bits/stdc++.h>
using namespace std;

// Phase 3 checkers integrated here
void check_substring_invariant(int title_length) {
    if (title_length > 15) { // Threshold: 15 as a proxy for potentially costly checks
        cerr << "Warning: Performance bottleneck - potential exponential growth in substrings." << endl;
        abort();
    }
}

void check_set_size_invariant(int set_size) {
    if (set_size > 1000) { // Threshold: 1000 to indicate large set size
        cerr << "Warning: Performance bottleneck - large set of substrings causing slow membership checks." << endl;
        abort();
    }
}

void check_queue_size_invariant(int queue_size) {
    if (queue_size > 1000) { // Threshold: 1000 to signal large queue size
        cerr << "Warning: Performance bottleneck - large BFS queue causing slow processing." << endl;
        abort();
    }
}

template <class F, class T>
T convert(F a, int p = -1) {
    stringstream ss;
    if (p >= 0) ss << fixed << setprecision(p);
    ss << a;
    T r;
    ss >> r;
    return r;
}

const int oo = int(1e9) + 7;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const int N = int(2e5) + 10;
int n, t;
bool ok;
set<string> f;
string s, res, cur;
queue<string> q;

int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        t = s.length();
        check_substring_invariant(t); // Check length of each title for potential exponential substring growth
        for (int i = 0; i < t; ++i) {
            for (int j = i; j < t; ++j) {
                res = "";
                for (int k = i; k <= j; ++k) {
                    res = res + s[k];
                }
                f.insert(res);
            }
        }
    }
    
    check_set_size_invariant(f.size()); // Check size of the set for large number of substrings

    q.push("");
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        check_queue_size_invariant(q.size()); // Check size of the queue for potential large BFS expansion
        for (int ch = 'a'; ch <= 'z'; ++ch) {
            res = cur + char(ch);
            if (!f.count(res)) {
                cout << res;
                return 0;
            }
            q.push(res);
        }
    }
    return 0;
}