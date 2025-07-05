#include <bits/stdc++.h>
using namespace std;

string word, in;
int ndigits[10];

// Checker functions
void check_exhaustive_search_invariant(int wordSize, int iteration) {
    if (iteration > 10000 && wordSize > 100) {  // Assuming wordSize > 100 is considered large
        cerr << "Warning: Performance bottleneck condition triggered - exhaustive search on large input!" << endl;
        abort();
    }
}

void check_string_conversion_invariant(int iteration) {
    if (iteration > 10000) {  // Assuming string conversions become expensive after 10,000 iterations
        cerr << "Warning: Performance bottleneck condition triggered - excessive string conversions!" << endl;
        abort();
    }
}

void check_digit_availability_invariant(int wordSize, int digitsChecked) {
    if (digitsChecked > wordSize * 10) {  // Arbitrary factor to illustrate excessive checks
        cerr << "Warning: Performance bottleneck condition triggered - repeated digit checks!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> word >> in;
    if (word == "0") return cout << "0", 0;

    for (int i = 0; i < word.size(); i++) ndigits[word[i] - '0']++;
    for (int i = 0; i < in.size(); i++) ndigits[in[i] - '0']--;

    int digitsChecked = 0;  // Counter for digit availability checks

    for (int i = 1; i <= 1000000; i++) {
        check_exhaustive_search_invariant(word.size(), i);
        check_string_conversion_invariant(i);

        string digits;
        stringstream ss;
        ss << i;
        ss >> digits;

        bool flag = 1;
        for (int j = 0; j < digits.size(); j++) {
            digitsChecked++;
            if (!ndigits[digits[j] - '0']) {
                flag = 0;
                break;
            }
        }

        check_digit_availability_invariant(word.size(), digitsChecked);

        if (flag && word.size() - digits.size() == i) {
            for (int i = 0; i < digits.size(); i++) {
                ndigits[digits[i] - '0']--;
            }
            bool t = 1;
            bool flag3 = 0;
            for (int i = 1; i <= 9; i++) {
                if (ndigits[i]) {
                    flag3 = 1;
                    if (in[0] == '0' || i < in[0] - '0') {
                        cout << i;
                        ndigits[i]--;
                    } else if (i == in[0] - '0') {
                        bool flag2 = 1;
                        int z = ndigits[0];
                        for (int j = 1; j < in.size(); j++) {
                            if (in[j] - '0' > i || (in[j] - '0' > 0 && z > 0)) {
                                flag2 = 0;
                                break;
                            }
                            z--;
                        }
                        if (flag2) {
                            cout << in;
                            t = 0;
                        } else {
                            cout << i;
                            ndigits[i]--;
                        }
                    } else if (i > in[0] - '0') {
                        cout << in;
                        t = 0;
                    }
                    break;
                }
            }
            if (!flag3) {
                cout << in;
                t = 0;
            }
            for (int i = 0; i <= 9; i++) {
                while (ndigits[i]) {
                    if (!t) {
                        cout << i;
                        ndigits[i]--;
                    } else {
                        if (i >= in[0] - '0') {
                            bool flag2 = 1;
                            for (int j = 0; j < in.size(); j++) {
                                if (in[j] - '0' < i) break;
                                if (in[j] - '0' > i) {
                                    flag2 = 0;
                                    break;
                                }
                            }
                            if (flag2) {
                                cout << in;
                                t = 0;
                            } else {
                                cout << i;
                                ndigits[i]--;
                            }
                        } else {
                            cout << i;
                            ndigits[i]--;
                        }
                    }
                }
            }
            if (t) cout << in;
            return 0;
        }
    }
    return 0;
}