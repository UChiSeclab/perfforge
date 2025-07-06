#include <bits/stdc++.h>
using namespace std;

vector<string> v;
int n;
string s;
map<string, bool> m;

bool comp(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

string sig(string mini) {
    string r = "";
    if (mini[mini.length() - 1] == 'z') {
        bool ok = 0;
        for (int i = mini.length() - 1; i >= 0; i--) {
            if (mini[i] != 'z') {
                mini[i]++;
                ok = 1;
                mini[mini.length() - 1] = 'a';
                return mini;
            }
        }
        if (!ok) {
            for (int i = 0; i <= mini.length(); i++) {
                r += "a";
            }
        }
        return r;
    } else {
        mini[mini.length() - 1]++;
        return mini;
    }
}

// Checker functions
void check_substring_explosion(int titleLength) {
    if (titleLength > 15) {  // Threshold based on complexity
        cerr << "Warning: Performance bottleneck condition triggered - too many substrings!" << endl;
        abort();
    }
}

void check_sorting_overhead(int substringCount) {
    if (substringCount > 200) {  // Threshold for sorting overhead
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting!" << endl;
        abort();
    }
}

void check_lexical_comparisons(int numComparisons) {
    if (numComparisons > 10000) {  // Threshold for lexical comparisons
        cerr << "Warning: Performance bottleneck condition triggered - excessive lexical comparisons!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    string mini = "a";
    int totalComparisons = 0; // New variable to count comparisons

    for (int i = 0; i < n; i++) {
        cin >> s;
        check_substring_explosion(s.length()); // Check for too many substrings

        for (int j = 0; j < s.length(); j++) {
            for (int r = 0; r <= s.length(); r++) {
                if (j + r > s.length()) continue;
                string aux = s.substr(j, r);
                if (!m[aux] && aux.length() > 0) v.push_back(aux);
                m[aux] = 1;
            }
        }
    }

    check_sorting_overhead(v.size()); // Check for sorting overhead
    sort(v.begin(), v.end(), [&](string a, string b) {
        totalComparisons++; // Increment for each comparison
        return comp(a, b);
    });

    check_lexical_comparisons(totalComparisons); // Check for excessive comparisons

    string res = "";
    if (v[0] != "a") {
        cout << "a" << endl;
        return 0;
    }
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i + 1] != sig(v[i]) && v[i + 1] != v[i]) {
            res = v[i];
            break;
        }
    }
    if (res != "") {
        cout << sig(res) << endl;
    } else {
        cout << sig(v[v.size() - 1]) << endl;
    }
}