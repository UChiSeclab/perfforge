#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")

using namespace std;

int n;
vector<string> tok[105];
string name[105];
bool term2[105], sum2[105], safe[105];
bool used[105];
map<string, int> id;
string expr;
int p;

// Checker functions
void check_complex_expression_invariant(int expressionLength) {
    if (expressionLength > 50) { // Threshold for complexity
        cerr << "Warning: Performance bottleneck condition triggered - complex expression!" << endl;
        abort();
    }
}

void check_nested_macro_invariant(int macroDepth) {
    if (macroDepth > 10) { // Threshold for nested depth
        cerr << "Warning: Performance bottleneck condition triggered - nested macro evaluations!" << endl;
        abort();
    }
}

void check_operator_density_invariant(int operatorCount, int expressionLength) {
    if (operatorCount > expressionLength / 2) { // More than 50% of the expression is operators
        cerr << "Warning: Performance bottleneck condition triggered - high operator density!" << endl;
        abort();
    }
}

void check_bracketing_invariant(bool hasBrackets) {
    if (!hasBrackets) {
        cerr << "Warning: Performance bottleneck condition triggered - missing brackets in macro!" << endl;
        abort();
    }
}

bool operation(string s) {
    return s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")";
}

string add();
string un() {
    // Check expression complexity and operator density
    int expressionLength = expr.size();
    int operatorCount = count_if(expr.begin(), expr.end(), [](char c) { return c == '+' || c == '-' || c == '*' || c == '/'; });
    check_complex_expression_invariant(expressionLength);
    check_operator_density_invariant(operatorCount, expressionLength);

    if (expr[p] == '?') {
        p++;
        return "?";
    }
    p++;
    add();
    p++;
    return "?";
}

string mult() {
    string c = un();
    while (p < (int)expr.size() && (expr[p] == '*' || expr[p] == '/')) {
        p++;
        un();
        c = "?*?";
    }
    return c;
}

string add() {
    string c = mult();
    while (p < (int)expr.size() && (expr[p] == '+' || expr[p] == '-')) {
        p++;
        mult();
        c = "?+?";
    }
    return c;
}

void simplify(string& tmp) {
    expr = tmp;
    p = 0;
    tmp = add();
}

void calc(int i) {
    if (used[i]) return;
    used[i] = true;
    string expr;
    vector<string> sign;
    for (int j = 0; j < int(tok[i].size()); j++) {
        if (operation(tok[i][j])) {
            sign.push_back(tok[i][j]);
        }
    }
    int cur = 0;
    safe[i] = true;
    bool hasBrackets = false;
    for (int j = 0; j < int(tok[i].size()); j++) {
        if (operation(tok[i][j])) {
            expr += tok[i][j];
            cur++;
            if (tok[i][j] == "(") hasBrackets = true; // Check for brackets
            continue;
        }
        if (id.count(tok[i][j])) {
            int k = id[tok[i][j]];
            calc(k);
            if (!safe[k]) {
                safe[i] = false;
                return;
            }
            if (sum2[k]) {
                if (cur > 0 && (sign[cur - 1] == "*" || sign[cur - 1] == "/" || sign[cur - 1] == "-")) {
                    safe[i] = false;
                    return;
                }
                if (cur < (int)sign.size() && (sign[cur] == "*" || sign[cur] == "/")) {
                    safe[i] = false;
                    return;
                }
                expr += "?+?";
            } else if (term2[k]) {
                if (cur > 0 && sign[cur - 1] == "/") {
                    safe[i] = false;
                    return;
                }
                expr += "?*?";
            } else {
                expr += "?";
            }
        } else {
            expr += "?";
        }
    }
    simplify(expr);
    if (expr == "?+?") {
        sum2[i] = true;
    }
    if (expr == "?*?") {
        term2[i] = true;
    }
    // Check bracketing
    check_bracketing_invariant(hasBrackets);
}

int main() {
    scanf("%d\n", &n);

    // Check for nested macro evaluations
    check_nested_macro_invariant(n);

    for (int i = 0; i < int(n + 1); i++) {
        string s;
        getline(cin, s);
        string t = "";
        for (int j = 0; j < int(s.size()); j++) {
            if (operation(s.substr(j, 1))) {
                t += ' ';
                t += s[j];
                t += ' ';
            } else {
                t += s[j];
            }
        }
        istringstream sin(t);
        if (i < n) {
            string def;
            sin >> def;
            if (def == "#") sin >> def;
            sin >> name[i];
            id[name[i]] = i;
        }
        string tmp;
        while (sin >> tmp) {
            tok[i].push_back(tmp);
        }
    }
    calc(n);
    if (safe[n]) {
        printf("OK\n");
    } else {
        printf("Suspicious\n");
    }
    return 0;
}