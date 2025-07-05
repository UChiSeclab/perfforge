#include <bits/stdc++.h>
#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;

const int N = 1100;
const int MAXN = int(1e6) + 100;
const int Mmask = (1 << 20);
const int mod = int(1e9) + 7;
const long long MOD = (long long)(1e18) + 7ll;

bool debug = false;
int n;
string ans = "";
vector<string> strings;

void check_nested_loop_invariant(size_t size) {
    if (size > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive string comparisons in nested loops!" << endl;
        abort();
    }
}

void check_prefix_join_invariant(const vector<string>& strings) {
    for (const auto& str : strings) {
        if (str.length() > 50) {  // Assuming a threshold for complexity
            cerr << "Warning: Performance bottleneck condition triggered - excessive prefix and join operations!" << endl;
            abort();
        }
    }
}

void check_string_start_invariant(const vector<string>& strings) {
    unordered_set<char> starting_chars;
    for (const auto& str : strings) {
        starting_chars.insert(str[0]);
        if (starting_chars.size() > 26) {  // More unique initial characters than possible
            cerr << "Warning: Performance bottleneck condition triggered - too many distinct starting characters!" << endl;
            abort();
        }
    }
}

void print() {
    if (!debug) return;
    cout << "Debug:\n";
    for (string s : strings) cout << s << ' ';
    cout << "\n\n";
}

bool str_cmp(string f, string s) {
    return (s[0] == f[0] && f.size() < s.size()) || (f[0] < s[0]);
}

bool checkBad(string x) {
    if (x.size() > 26) return true;
    vector<bool> u(26, 0);
    for (int i = 0; i < x.size(); i++) {
        if (u[x[i] - 'a']) return true;
        u[x[i] - 'a'] = true;
    }
    return false;
}

void get() {
    cin >> n;
    strings.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        if (checkBad(strings[i])) {
            cout << "NO";
            exit(0);
        }
    }
}

bool preff(string f, string s) {
    for (int i = 0; i < f.size(); i++)
        if (f[i] != s[i]) return false;
    return true;
}

void remove_preffixes() {
    for (int i = 0; i < strings.size() - 1;) {
        if (strings[i][0] == strings[i + 1][0]) {
            if (preff(strings[i], strings[i + 1])) {
                strings.erase(begin(strings) + i);
            } else {
                cout << "NO";
                exit(0);
            }
        } else {
            i++;
        }
    }
}

bool can_join(string base, string add) {
    for (int i = 0; i < base.size(); i++) {
        if (base[i] == add[0]) {
            for (int j = 1; j < add.size() && i + j < base.size(); j++) {
                if (add[j] != base[i + j]) {
                    cout << "NO";
                    exit(0);
                }
            }
            return true;
        }
    }
    return false;
}

void join(string& base, string add) {
    for (int i = 0; i < base.size(); i++) {
        if (base[i] == add[0]) {
            for (int j = base.size() - i; j < add.size(); j++) base.push_back(add[j]);
            return;
        }
    }
}

void join_joinable() {
    bool founded = true;
    while (founded) {
        founded = false;
        for (int i = 0; i < strings.size() && !founded; i++) {
            for (int j = 0; j < strings.size() && !founded; j++) {
                if (i == j) {
                    continue;
                }
                if (can_join(strings[i], strings[j])) {
                    join(strings[i], strings[j]);
                    strings.erase(begin(strings) + j);
                    founded = true;
                }
            }
        }
    }
}

void append_strings() {
    for (int i = 0; i < strings.size(); i++) {
        ans += strings[i];
    }
    if (debug) cout << "pre ans: " << ans << '\n';
    if (checkBad(ans)) {
        cout << "NO";
        exit(0);
    }
}

void print_ans() { cout << ans; }

int solution() {
    get();
    print();
    check_nested_loop_invariant(strings.size()); // Check for too many comparisons
    check_prefix_join_invariant(strings); // Check for excessive prefix/join operations
    check_string_start_invariant(strings); // Check for too many distinct starting characters
    stable_sort(begin(strings), end(strings), str_cmp);
    if (debug) cout << "sorted:\n";
    print();
    remove_preffixes();
    if (debug) cout << "rem performed:\n";
    print();
    join_joinable();
    if (debug) cout << "crafted:\n";
    print();
    append_strings();
    if (debug) cout << "strings appended:\n";
    print();
    print_ans();
    return 0;
}

int main(int argc, char* const argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return solution();
}