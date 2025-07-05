#include <bits/stdc++.h>
using namespace std;

const char *ops = "+-*/";
map<string, int> env;
map<string, bool> ok;

// Checker Functions
void check_complex_division_invariant(const string& expr) {
    int division_count = std::count(expr.begin(), expr.end(), '/');
    if (division_count > 1) {
        cerr << "Warning: complex_division_invariant triggered - multiple divisions detected in expression" << endl;
        abort();
    }
}

void check_complex_arithmetic_invariant(const string& expr) {
    int add_sub_count = std::count(expr.begin(), expr.end(), '+') + std::count(expr.begin(), expr.end(), '-');
    int mul_div_count = std::count(expr.begin(), expr.end(), '*') + std::count(expr.begin(), expr.end(), '/');
    if (add_sub_count > 1 && mul_div_count > 1) {
        cerr << "Warning: complex_arithmetic_invariant triggered - complex nested operations in expression" << endl;
        abort();
    }
}

void check_recursive_macro_invariant(const map<string, string>& env, const string& expr) {
    int recursion_depth = 0;
    string current_expr = expr;
    while (recursion_depth <= 10) {
        size_t pos = current_expr.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
        if (pos == string::npos) break;
        
        string macro = current_expr.substr(pos, current_expr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", pos) - pos);
        if (env.count(macro)) {
            current_expr.replace(pos, macro.length(), env.at(macro));
            recursion_depth++;
        } else {
            break;
        }
    }
    
    if (recursion_depth > 10) {
        cerr << "Warning: recursive_macro_invariant triggered - excessive recursive macro expansion detected" << endl;
        abort();
    }
}

int parse(const string &s) {
    int l = s.length();
    int lev = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == '(')
            lev++;
        else if (s[i] == ')')
            lev--;
        else if (lev == 0 && !isalnum(s[i])) {
            int t = strchr(ops, s[i]) - ops;
            return (1 << t) | parse(s.substr(0, i)) | parse(s.substr(i + 1));
        }
    }
    if (s[0] == '(')
        return 0;
    else {
        if (env.count(s))
            return env[s];
        else
            return 0;
    }
}

void check(const string &s) {
    int l = s.length();
    int lev = 0;
    vector<string> terms;
    int prv = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == '(')
            lev++;
        else if (s[i] == ')')
            lev--;
        else if (lev == 0 && (s[i] == '+' || s[i] == '-')) {
            terms.push_back(s.substr(prv, i - prv));
            terms.push_back(s.substr(i, 1));
            prv = i + 1;
        }
    }
    terms.push_back(s.substr(prv));
    if (terms.size() > 1) {
        for (int i = 0; i < (int)terms.size(); i += 2) {
            check(terms[i]);
            if (i > 0 && terms[i - 1][0] == '-' && (parse(terms[i]) & 3)) throw 0;
        }
        return;
    }
    terms.clear();
    prv = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == '(')
            lev++;
        else if (s[i] == ')')
            lev--;
        else if (lev == 0 && (s[i] == '*' || s[i] == '/')) {
            terms.push_back(s.substr(prv, i - prv));
            terms.push_back(s.substr(i, 1));
            prv = i + 1;
        }
    }
    terms.push_back(s.substr(prv));
    if (terms.size() > 1) {
        for (int i = 0; i < (int)terms.size(); i += 2) {
            check(terms[i]);
            int p = parse(terms[i]);
            if (p & 3) throw 0;
            if (i > 0 && terms[i - 1][0] == '/' && p != 0) throw 0;
        }
        return;
    }
    if (s[0] == '(') {
        check(s.substr(1, l - 2));
    } else {
        if (ok.count(s) && !ok[s]) throw 0;
    }
}

string read(stringstream &ss) {
    string expr = "", tmp;
    while (ss >> tmp) expr += tmp;
    return expr;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int N = atoi(line.c_str());
        env.clear();
        ok.clear();
        map<string, string> macro_expressions; // Store macro expressions for recursive check

        for (int i = 0; i < N; i++) {
            getline(cin, line);
            stringstream ss(line);
            string tmp, name;
            int le = 0;
            while (le < 7) {
                ss >> tmp;
                le += tmp.length();
            }
            ss >> name;
            string expr = read(ss);

            // Store the expression for recursive checks
            macro_expressions[name] = expr;

            env[name] = parse(expr);
            bool c = true;
            try {
                check(expr);
            } catch (...) {
                c = false;
            }
            ok[name] = c;

            // Check for complex operations
            check_complex_division_invariant(expr);
            check_complex_arithmetic_invariant(expr);
        }

        getline(cin, line);
        stringstream ss(line);
        string expr = read(ss);

        // Check for recursive macro expansion
        check_recursive_macro_invariant(macro_expressions, expr);

        try {
            check(expr);
        } catch (...) {
            puts("Suspicious");
            continue;
        }
        puts("OK");
    }
}