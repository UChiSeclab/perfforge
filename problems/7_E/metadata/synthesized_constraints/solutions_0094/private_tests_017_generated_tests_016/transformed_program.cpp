#include <bits/stdc++.h>
using namespace std;

void check_macro_complexity(const std::string& expression) {
    int macroCount = std::count(expression.begin(), expression.end(), '+') +
                     std::count(expression.begin(), expression.end(), '-') +
                     std::count(expression.begin(), expression.end(), '*') +
                     std::count(expression.begin(), expression.end(), '/');
    if (macroCount > 10) {
        cerr << "Warning: Performance bottleneck due to complex macro expression!" << endl;
        abort();
    }
}

void check_expression_nesting(const std::string& expression) {
    int nestingLevel = 0, maxNesting = 0;
    for (char c : expression) {
        if (c == '(') {
            nestingLevel++;
            maxNesting = std::max(maxNesting, nestingLevel);
        } else if (c == ')') {
            nestingLevel--;
        }
    }
    if (maxNesting > 5) {
        cerr << "Warning: Performance bottleneck due to excessive nesting!" << endl;
        abort();
    }
}

void check_string_operations(int hashCalls, int lengthOps) {
    if (hashCalls > 100 || lengthOps > 100) {
        cerr << "Warning: Performance bottleneck due to frequent string operations!" << endl;
        abort();
    }
}

struct Dinic {
    // ... (other parts of the Dinic structure remain unchanged)
};

const int M = 1e6 + 7;
const int HashCode = 123;
int hashCallCount = 0, lengthOpCount = 0;

inline int getHash(string str) {
    hashCallCount++;
    int len = str.length();
    lengthOpCount++;
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret = (ret * HashCode + str[i]) % M;
    }
    return ret;
}

// ... (rest of the code remains unchanged)

inline void solve(int T) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> mDefine;
        while (mDefine != "define" && mDefine != "#define") cin >> mDefine;
        cin >> mName;
        HashExp[getHash(mName)] = i;
        getline(cin, mExp[i]);
        mExp[i] = TrimStr(mExp[i]);
        // Check complexity of each macro definition
        check_macro_complexity(mExp[i]);
    }
    getline(cin, finalExp);
    // Check nested level of the final expression
    check_expression_nesting(finalExp);
    // Check overall string operation counts
    check_string_operations(hashCallCount, lengthOpCount);
    int State = getState(TrimStr(finalExp));
    if (State != 2) {
        printf("OK\n");
    } else {
        printf("Suspicious\n");
    }
    return;
}

inline void init() {}

int main() {
    int T = 1;
    for (int i = 1; i <= T; i++) {
        init();
        solve(i);
    }
    return 0;
}