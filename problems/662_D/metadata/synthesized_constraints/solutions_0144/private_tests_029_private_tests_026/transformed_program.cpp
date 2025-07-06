#include <bits/stdc++.h>
using namespace std;

void check_leading_zeros_invariant(const string& abbr) {
    if (!abbr.empty() && abbr[0] == '0') {
        cerr << "Warning: Performance bottleneck condition triggered due to leading zeros!" << endl;
        abort();
    }
}

void check_year_generation_invariant(int suffix_length) {
    if (suffix_length < 4) {
        cerr << "Warning: Performance bottleneck condition triggered due to year generation!" << endl;
        abort();
    }
}

void check_long_abbreviation_invariant(int abbr_length) {
    if (abbr_length > 4) {
        cerr << "Warning: Performance bottleneck condition triggered due to long abbreviation!" << endl;
        abort();
    }
}

int findYear(string abbr) {
    int result;
    unordered_set<int> yearFound;
    int year = 0;

    // Check for long abbreviation invariant
    check_long_abbreviation_invariant(abbr.length());

    for (int i = 1; i <= abbr.length(); ++i) {
        string abr = abbr.substr(abbr.length() - i);
        string nabr;

        // Check for leading zeros invariant
        check_leading_zeros_invariant(abr);

        if (abr.length() < 4) {
            // Check for year generation invariant
            check_year_generation_invariant(abr.length());

            for (int n = 1989; 1; ++n) {
                string ns = to_string(n);
                nabr = ns.substr(0, 4 - abr.length()) + abr;
                year = atoi(nabr.c_str());
                if (year >= 1989 && yearFound.count(year) == 0) {
                    goto next;
                }
            }
        }
        year = atoi(abr.c_str());
        if (yearFound.count(year) == 0 && year >= 1989) {
            goto next;
        }
        for (int x = 1; 1; ++x) {
            abr = to_string(x) + abr;
            year = atoi(abr.c_str());
            if (yearFound.count(year) == 0 && year >= 1989) {
                goto next;
            }
        }
    next:
        yearFound.insert(year);
        continue;
    }
    result = year;
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string abbr;
        cin >> abbr;
        int year = findYear(abbr.substr(4));
        cout << year << endl;
    }
    return 0;
}