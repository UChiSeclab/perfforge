#include <bits/stdc++.h>
using namespace std;

set<string> S;

// Checker functions for performance bottlenecks
void check_excessive_iteration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iteration over years!" << endl;
        abort();
    }
}

void check_repetitive_set_operation(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repetitive set operations!" << endl;
        abort();
    }
}

void check_non_direct_year_match(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - non-direct year match!" << endl;
        abort();
    }
}

string convert(int num) {
    string ret;
    while (num) {
        char c = ((num % 10) + '0');
        ret = c + ret;
        if (S.count(ret) == 0) {
            S.insert(ret);
            return ret;
        }
        num /= 10;
    }
}

int main() {
    int n;
    cin >> n;
    string yr;
    for (int i = 0; i < n; i++) {
        cin >> yr;
        yr = yr.substr(4);
        if (yr.size() >= 4) {
            int year = 0;
            for (int j = 0; j < yr.size(); j++) year = year * 10 + (yr[j] - '0');
            if (yr.size() == 4) {
                if (year <= 3098) yr = "1" + yr;
            } else if (yr.size() == 5) {
                if (year <= 13098) yr = "1" + yr;
            } else if (yr.size() == 6) {
                if (year <= 113098) yr = "1" + yr;
            } else if (yr.size() == 7) {
                if (year <= 1113098) yr = "1" + yr;
            } else if (yr.size() == 8) {
                if (year <= 11113098) yr = "1" + yr;
            } else if (yr.size() == 9) {
                if (year <= 111113098) yr = "1" + yr;
            }
            cout << yr << endl;
        } else {
            S.clear();
            bool non_direct_match_needed = true;
            for (int j = 1989; j <= 3098; j++) {
                string abr = convert(j);
                if (abr == yr) {
                    cout << j << "\n";
                    non_direct_match_needed = false;
                    break;
                }
            }
            // Place checks at appropriate points
            check_excessive_iteration(yr.size() < 4 && non_direct_match_needed);
            check_repetitive_set_operation(S.size() > 1000);  // Arbitrary, yet realistic threshold
            check_non_direct_year_match(non_direct_match_needed);
        }
    }
}