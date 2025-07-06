#include <bits/stdc++.h>
using namespace std;

// Include performance checks definitions here
// ...

string pl(string s) {
    int p = (int)s.size() - 1;
    string res;
    while (p >= 0 and s[p] == 'z') p--;
    check_trailing_z(s);  // Check for trailing 'z' characters
    if (p == -1) {
        res.push_back('a');
        for (int i = 0; i < s.size(); i++) res.push_back('a');
        return res;
    } else {
        res = s;
        res[p]++;
        return res;
    }
}

string min_str(string a, string b) {
    if (a.size() != b.size()) return (a.size() < b.size()) ? a : b;
    return min(a, b);
}

int main() {
    int n;
    cin >> n;
    set<string> q;
    q.insert("");
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int substr_count = 0;
        for (int j = 0; j < s.size(); j++) {
            for (int k = 1; j + k <= s.size(); k++) {
                q.insert(s.substr(j, k));
                substr_count++;
            }
        }
        check_substring_generation(substr_count);  // Check excessive substring generation
    }
    
    check_set_size(q);  // Check if the set grows too large

    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    int min_calls = 0;
    for (set<string>::iterator it = q.begin(); it != q.end(); ++it) {
        string s = pl(*it);
        if (q.find(s) == q.end()) {
            ans = min_str(ans, s);
            min_calls++;
        }
    }
    
    check_min_comparisons(min_calls);  // Check for excessive min comparisons

    cout << ans << endl;
    return 0;
}