#include <bits/stdc++.h>
const long long INFLL = 1e18;
using namespace std;

// Checker functions
void check_hyphen_heavy_words(const vector<string>& words) {
    int hyphen_count = 0;
    for (const string& word : words) {
        hyphen_count += count(word.begin(), word.end(), '-');
        if (hyphen_count > 10) { // Arbitrary threshold for demonstration
            cerr << "Warning: Performance bottleneck condition triggered due to hyphen-heavy words!" << endl;
            abort();
        }
    }
}

void check_long_words_without_spaces(const vector<string>& words) {
    for (const string& word : words) {
        if (word.size() > 20) { // Arbitrary threshold for demonstration
            cerr << "Warning: Performance bottleneck condition triggered due to long words without spaces!" << endl;
            abort();
        }
    }
}

void check_frequent_wrapping_decisions(int wrap_decision_count) {
    if (wrap_decision_count > 15) { // Arbitrary threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered due to frequent wrapping decisions!" << endl;
        abort();
    }
}

void check_close_to_max_line_constraint(int res, int k) {
    if (res >= k - 1) { // Close to the maximum line constraint
        cerr << "Warning: Performance bottleneck condition triggered due to being close to max line constraint!" << endl;
        abort();
    }
}

int k;

void sep(vector<string> &vec, string &s) {
    string cur = "";
    for (auto ch : s) {
        cur += ch;
        if (ch == '-') {
            vec.push_back(cur);
            cur = "";
        }
    }
    if (!cur.empty()) vec.push_back(cur);
}

bool check(int w, string &s) {
    int n = (int)s.size();
    vector<string> words;
    string cur = "";

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            if (!cur.empty()) sep(words, cur);
            cur = "";
        } else {
            cur += s[i];
        }
    }
    if (!cur.empty()) sep(words, cur);

    // Invariant checks before processing
    check_hyphen_heavy_words(words);
    check_long_words_without_spaces(words);

    int lost = w;
    int res = 1;
    int wrap_decision_count = 0;

    for (int i = 0; i < (int)words.size(); i++) {
        string word = words[i];
        int last = (i + 1 == (int)words.size() ? 0 : 1);
        if (word.back() == '-') last = 0;
        int need = (int)word.size() + last;

        if (lost >= need) {
            lost -= need;
        } else {
            bool ok = false;
            for (int j = (int)word.size() - 1, k = 0; j >= 0; j--, k++) {
                if (word[j] == '-') {
                    if (lost >= j + 1) {
                        lost = w - (need - j);
                        if (lost < 0) {
                            return false;
                        }
                        res++;
                        ok = true;
                        wrap_decision_count++;
                    }
                }
            }
            if (!ok) {
                if (w >= need) {
                    lost = w;
                    lost -= need;
                    res++;
                    wrap_decision_count++;
                } else {
                    return false;
                }
            }
        }
    }

    // Check after processing with collected data
    check_frequent_wrapping_decisions(wrap_decision_count);
    check_close_to_max_line_constraint(res, k);

    return res <= k;
}

int main() {
    cin >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    check(10, s);
    int l = 0, r = 1e6 + 10, m;

    while (r > l + 1) {
        m = (l + r) / 2;
        if (check(m, s))
            r = m;
        else
            l = m;
    }

    cout << r << endl;
    return 0;
}