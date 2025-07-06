#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_high_sum_max_length(int m, int s) {
    if (m == 100 && s > 800) {
        cerr << "Warning: Performance bottleneck condition triggered - high sum with maximum length!" << endl;
        abort();
    }
}

void check_large_dp_table(int m, int s) {
    if (s > 800) {
        cerr << "Warning: Performance bottleneck condition triggered - large DP table dimensions!" << endl;
        abort();
    }
}

void check_exhaustive_digit_search(int s) {
    if (s > 800) {
        cerr << "Warning: Performance bottleneck condition triggered - exhaustive digit search!" << endl;
        abort();
    }
}

string dp(int i, int j, int m, int s, vector<vector<string>> &table, const string &digits) {
    if (i < 0 || j < 0) {
        return "-1";
    }
    if (i == 0) {
        if (j == 0) {
            return "";
        } else {
            return "-1";
        }
    }
    if (table[i][j] == "") {
        table[i][j] = "-1";
        for (auto digit : digits) {
            auto result = dp(i - 1, j - digit + '0', m, s, table, digits);
            if (result != "-1") {
                table[i][j] = (digit + result);
                break;
            }
        }
    }
    return table[i][j];
}

int main() {
    int m, s;
    scanf("%d %d", &m, &s);

    // Runtime checks for performance bottlenecks
    check_high_sum_max_length(m, s);
    check_large_dp_table(m, s);
    check_exhaustive_digit_search(s);

    if (m == 1 && s == 0) {
        printf("0 0 \n");
        return 0;
    }
    string digits = "0123456789";
    vector<vector<string>> min_dp(m, vector<string>(s, ""));
    string min_answer = "-1";
    for (int i = 1; i < digits.size(); i++) {
        string result = dp(m - 1, s - digits[i] + '0', m, s, min_dp, digits);
        if (result != "-1") {
            min_answer = digits[i] + result;
            break;
        }
    }
    reverse(digits.begin(), digits.end());
    string max_answer = "-1";
    for (int i = 0; i < digits.size() - 1; i++) {
        string result = dp(m - 1, s - digits[i] + '0', m, s, min_dp, digits);
        if (result != "-1") {
            max_answer = digits[i] + result;
            break;
        }
    }
    printf("%s %s\n", min_answer.c_str(), max_answer.c_str());
    return 0;
}