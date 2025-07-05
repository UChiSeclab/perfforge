#include <bits/stdc++.h>
using namespace std;

int f(string s) {
    int res = 0;
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N')
            cur++;
        else {
            res = max(res, cur);
            cur = 0;
        }
    }
    return max(res, cur);
}

void check_question_mark_invariant(const string& s, int k) {
    int questionMarkCount = count(s.begin(), s.end(), '?');
    int consecutiveN = 0;
    for (char c : s) {
        if (c == 'N') {
            consecutiveN++;
        } else {
            if (consecutiveN >= k) break;
            consecutiveN = 0;
        }
    }
    if (questionMarkCount > 20 && k < consecutiveN) { // Example threshold for '?'
        cerr << "Warning: Performance bottleneck condition triggered by '?' marks!" << endl;
        abort();
    }
}

void check_concentration_invariant(const string& s) {
    int questionMarkSegments = 0;
    bool inSegment = false;
    for (char c : s) {
        if (c == '?') {
            if (!inSegment) {
                questionMarkSegments++;
                inSegment = true;
            }
        } else {
            inSegment = false;
        }
    }
    if (questionMarkSegments > 10) { // Example threshold for '?' segments
        cerr << "Warning: High concentration of '?', leading to potential slowdown!" << endl;
        abort();
    }
}

void check_function_call_invariant(int calls, int n) {
    if (calls > 50 && n > 50) { // Example threshold for function calls
        cerr << "Warning: Excessive calls to dissatisfaction check function!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    // Place checks to detect potential bottlenecks
    check_question_mark_invariant(s, k);
    check_concentration_invariant(s);

    int functionCalls = 0;
    for (int i = 0; i < n; i++) {
        string b = s;
        for (int j = 0; j < i; j++)
            if (b[j] == '?') b[j] = 'Y';
        for (int j = i; j < i + k; j++)
            if (b[j] == '?') b[j] = 'N';
        for (int j = i + k; j < n; j++)
            if (b[j] == '?') b[j] = 'Y';

        functionCalls++;
        check_function_call_invariant(functionCalls, n);

        if (f(b) == k) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}