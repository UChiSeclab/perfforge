#include <bits/stdc++.h>
using namespace std;

// Checker function for high '?' count with low k
void check_question_marks_low_k(int questionMarkCount, long long k) {
    if (questionMarkCount > 10 && k <= 1) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - high '?' count with low k!" << endl;
        abort();
    }
}

// Checker function for interspersed '?' and 'N's
void check_interspersed_question_marks(string &s, long long k) {
    int questionMarkStreak = 0;
    bool interspersedFlag = false;
    for (char c : s) {
        if (c == '?') {
            questionMarkStreak++;
        } else if (c == 'N' && questionMarkStreak > 0) {
            interspersedFlag = true;
            break;
        } else {
            questionMarkStreak = 0;
        }
    }
    if (interspersedFlag && k <= 1) {
        cerr << "Warning: Performance bottleneck condition triggered - '?' interspersed with 'N'!" << endl;
        abort();
    }
}

// Checker function for redundant copy operations
void check_redundant_copy_operations(string &s) {
    int questionMarkCount = count(s.begin(), s.end(), '?');
    if (questionMarkCount > 20) { // Example threshold
        cerr << "Warning: Performance bottleneck condition triggered - potential redundant string copies!" << endl;
        abort();
    }
}

int main() {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Place checkers after input to catch slow scenarios early
    int questionMarkCount = count(s.begin(), s.end(), '?');
    check_question_marks_low_k(questionMarkCount, k); // Check for high '?' with low k
    check_interspersed_question_marks(s, k);          // Check for '?' interspersed within 'N'
    check_redundant_copy_operations(s);               // Check for potential redundant copies

    for (long long i = 0; i < s.length(); i++) {
        string t = s;
        for (long long j = 0; j < s.length(); j++) {
            if (j >= i && j < i + k && s[j] == '?') {
                t[j] = 'N';
            }
        }
        long long ans = 0, cnt = 0;
        for (long long j = 0; j < s.length(); j++) {
            if (t[j] == 'N') {
                cnt++;
            } else {
                cnt = 0;
            }
            ans = max(ans, cnt);
        }
        if (ans == k) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}