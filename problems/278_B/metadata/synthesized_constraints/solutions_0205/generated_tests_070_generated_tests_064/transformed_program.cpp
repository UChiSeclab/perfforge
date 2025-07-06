#include <bits/stdc++.h>
using namespace std;

// Checker function to monitor excessive substring generation
void check_substring_invariant(int titleLength, int uniqueChars) {
    if (titleLength > 15 && uniqueChars > 10) {
        cerr << "Warning: Performance bottleneck - excessive substring generation!" << endl;
        abort();
    }
}

// Checker function to monitor wide character coverage in titles
void check_title_generation_invariant(set<char> uniqueChars) {
    if (uniqueChars.size() > 20) {
        cerr << "Warning: Performance bottleneck - wide character coverage in titles!" << endl;
        abort();
    }
}

// Checker function to monitor input complexity
void check_input_complexity_invariant(int totalTitles, int maxTitleLength) {
    if (totalTitles > 25 && maxTitleLength > 15) {
        cerr << "Warning: Performance bottleneck - complex input configuration!" << endl;
        abort();
    }
}

int main() {
    int n;
    map<string, int> m;
    scanf("%d", &n);
    string s, l;
    int maxTitleLength = 0;
    set<char> allUniqueChars;

    // Check input complexity invariant
    check_input_complexity_invariant(n, 20);

    for (int i = 0; i < n; ++i) {
        cin >> s;
        maxTitleLength = max(maxTitleLength, (int)s.size());
        set<char> titleUniqueChars(s.begin(), s.end());
        allUniqueChars.insert(s.begin(), s.end());

        // Check substring generation invariant
        check_substring_invariant(s.size(), titleUniqueChars.size());

        for (int j = 0; j < int(s.size()); ++j) {
            for (int k = j; k < int(s.size()); ++k) {
                l = s.substr(j, k - j + 1);
                m[l]++;
            }
        }
    }

    // Check title generation invariant
    check_title_generation_invariant(allUniqueChars);

    char ch, c;
    for (int i = 1; i <= 2; i++) {
        s = "";
        for (int j = 0; j < i; ++j) s += 'a';
        for (c = 'a'; c <= 'z'; c++) {
            for (ch = 'a'; ch <= 'z'; ch++) {
                s[i - 1] = ch;
                if (i > 1) s[i - 2] = c;
                if (!m[s]) {
                    cout << s << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}