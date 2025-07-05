#include <bits/stdc++.h>
using namespace std;

// Checker functions based on performance-characterizing invariants
void check_nested_macro_definitions(const map<string, string>& defs) {
    for (const auto& [name, expr] : defs) {
        size_t nested_count = count(expr.begin(), expr.end(), '(');
        if (nested_count > 10) {  // Arbitrary threshold
            cerr << "Warning: Performance bottleneck due to nested macro definitions!" << endl;
            abort();
        }
    }
}

void check_complex_expression(const string& expression) {
    int depth = 0;
    int max_depth = 0;
    for (char ch : expression) {
        if (ch == '(') {
            depth++;
            max_depth = max(max_depth, depth);
        } else if (ch == ')') {
            depth--;
        }
    }
    if (max_depth > 10) {  // Arbitrary threshold
        cerr << "Warning: Performance bottleneck due to complex arithmetic expressions!" << endl;
        abort();
    }
}

void check_operator_usage(const string& expression) {
    int operator_count = 0;
    for (char ch : expression) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operator_count++;
        }
    }
    if (operator_count > 20) {  // Arbitrary threshold
        cerr << "Warning: Performance bottleneck due to excessive operator usage!" << endl;
        abort();
    }
}

// Original code with integrated checks
int main() {
    int N;
    map<string, string> defs;
    map<string, bool> dp;
    
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
        string sss;
        getline(cin, sss);
        
        istringstream iss(sss);
        string s;
        string t;
        string name;
        while (iss >> t) {
            s += t;
            if (s == "#define") {
                iss >> name;
                s = "";
            }
        }
        defs[name] = s;
    }

    // Check for nested macro definitions
    check_nested_macro_definitions(defs);
    
    string sss;
    getline(cin, sss);
    
    istringstream iss(sss);
    string s;
    string t;
    while (iss >> t) {
        s += t;
    }
    
    // Check for complex expressions
    check_complex_expression(s);
    
    defs["beteradfjoiasfgnvushngsdflhgkjdsfuidfbviudfbv"] = s;

    // Check for excessive operator usage
    check_operator_usage(s);

    bool res = isok("beteradfjoiasfgnvushngsdflhgkjdsfuidfbviudfbv");
    if (res)
        printf("OK\n");
    else
        printf("Suspicious\n");
    
    return 0;
}