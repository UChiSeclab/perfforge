#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;

int n;
vector<string> s;

// Checker functions
void check_frequent_character_set_invariant(const vector<string>& strings) {
    int totalUniqueChars = 0;
    vector<bool> charPresence(26, false);
    
    for (const string& str : strings) {
        for (char c : str) {
            if (!charPresence[c - 'a']) {
                charPresence[c - 'a'] = true;
                totalUniqueChars++;
            }
        }
    }
    
    if (totalUniqueChars > 20) {
        cerr << "Warning: Frequent character set invariant triggered - excessive character diversity" << endl;
        abort();
    }
}

void check_inefficient_vector_manipulation_invariant(const vector<string>& strings) {
    for (const string& str : strings) {
        if (str.size() > 50) {
            cerr << "Warning: Inefficient vector manipulation invariant triggered - large string size" << endl;
            abort();
        }
    }
}

void check_alphabet_coverage_invariant(const vector<string>& strings) {
    vector<bool> alphabetCoverage(26, false);
    int distinctCharCount = 0;

    for (const string& str : strings) {
        for (char c : str) {
            if (!alphabetCoverage[c - 'a']) {
                alphabetCoverage[c - 'a'] = true;
                distinctCharCount++;
            }
        }
    }
    
    if (distinctCharCount > 23) {
        cerr << "Warning: Alphabet coverage invariant triggered - near full alphabet usage" << endl;
        abort();
    }
}

string combine(vector<string> s, int t) {
    if (s.empty()) return "";
    vector<char> res(100, ' ');

    for (int i = 0; i < s.size(); i++) {
        int pos = 0;
        for (int j = 0; j < s[i].size(); j++)
            if (s[i][j] - 'a' == t) pos = j;

        for (int j = 0; j < s[i].size(); j++) {
            if (res[50 + j - pos] != ' ' && res[50 + j - pos] != s[i][j]) return "NO";
            res[50 + j - pos] = s[i][j];
        }
    }

    string w;
    for (int i = 0; i < 100; i++)
        if (res[i] != ' ') w.push_back(res[i]);

    int mask = 0;
    for (int i = 0; i < w.size(); i++) {
        if (mask & (1 << (w[i] - 'a'))) return "NO";
        mask |= 1 << (w[i] - 'a');
    }

    return w;
}

int main() {
    cin >> n;
    string t;
    getline(cin, t);

    for (int i = 0; i < n; i++) {
        getline(cin, t);
        int mask = 0;
        for (int j = 0; j < t.size(); j++) {
            if (mask & (1 << (t[j] - 'a'))) {
                puts("NO");
                return 0;
            }
            mask |= 1 << (t[j] - 'a');
        }
        s.push_back(t);
    }

    // Insert invariant checks after all input is read
    check_frequent_character_set_invariant(s);
    check_inefficient_vector_manipulation_invariant(s);
    check_alphabet_coverage_invariant(s);

    for (int i = 0; i < 26; i++) {
        vector<string> ns, tmp;
        for (int j = 0; j < s.size(); j++) {
            bool has = 0;
            for (int k = 0; k < s[j].size(); k++)
                if (s[j][k] - 'a' == i) has = 1;
            if (has)
                tmp.push_back(s[j]);
            else
                ns.push_back(s[j]);
        }
        string t = combine(tmp, i);
        if (t == "NO") {
            puts("NO");
            return 0;
        }
        if (!t.empty()) ns.push_back(t);
        s = ns;
    }

    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) cout << s[i];
    puts("");
    return 0;
}