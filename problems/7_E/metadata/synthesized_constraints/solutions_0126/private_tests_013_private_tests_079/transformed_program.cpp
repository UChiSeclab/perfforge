#include <bits/stdc++.h>
using namespace std;

// Checker function implementations
void check_macro_expansion_invariant(int expansionDepth, int threshold) {
    if (expansionDepth > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive macro expansions!" << endl;
        abort();
    }
}

void check_operator_precedence_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to operator precedence conflict!" << endl;
        abort();
    }
}

void check_nested_macro_invariant(int nestingLevel, int threshold) {
    if (nestingLevel > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to deeply nested macro definitions!" << endl;
        abort();
    }
}

int parse(vector<string>& tokens, vector<int>& master, vector<int>& prec, int& cpos, int minPrecedence) {
    int curMaster = cpos;
    while (cpos < (int)tokens.size()) {
        string cur = tokens[cpos];
        if (cur == "+" || cur == "-") {
            if (minPrecedence > 0) return curMaster;
            prec[cpos] = 0;
            master[curMaster] = cpos;
            curMaster = cpos;
            master[parse(tokens, master, prec, ++cpos, 1)] = curMaster;
        } else if (cur == "*" || cur == "/") {
            if (minPrecedence > 1) return curMaster;
            prec[cpos] = 1;
            master[curMaster] = cpos;
            curMaster = cpos;
            master[parse(tokens, master, prec, ++cpos, 2)] = curMaster;
        } else if (cur == "(") {
            prec[cpos] = 2;
            curMaster = cpos;
            master[parse(tokens, master, prec, ++cpos, 0)] = curMaster;
            master[cpos] = curMaster;
            prec[cpos++] = 2;
        } else if (cur == ")")
            return curMaster;
        else {
            curMaster = cpos;
            prec[cpos++] = 3;
        }
    }
    return curMaster;
}

vector<string> tokenize(string in) {
    vector<string> ret;
    in.resize(remove(in.begin(), in.end(), ' ') - in.begin());
    for (int i = 0; i < (int)in.size();) {
        int j = i;
        while (j < (int)in.size() && (('a' <= in[j] && in[j] <= 'z') || ('A' <= in[j] && in[j] <= 'Z')))
            j++;
        if (j == i)
            ret.push_back(string(1, in[j++]));
        else
            ret.push_back(in.substr(i, j - i));
        i = j;
    }
    return ret;
}

map<string, int> expr;
vector<vector<string> > tokens;
vector<vector<int> > masters, precs;
vector<int> root;
vector<bool> tested;

void test(vector<string>& token, vector<int>& master, vector<int>& prec) {
    int expansionDepth = 0;
    int nestingLevel = 0;

    for (int i = 0; i < (int)token.size(); i++) {
        string cur = token[i];
        if (('a' <= cur[0] && cur[0] <= 'z') || ('A' <= cur[0] && cur[0] <= 'Z'))
            if (expr.count(cur) != 0) {
                int ind = expr[cur];
                
                // Check for nested macro definitions
                check_nested_macro_invariant(++nestingLevel, 10);

                if (!tested[ind]) {
                    test(tokens[ind], masters[ind], precs[ind]);
                    tested[ind] = true;
                }

                // Check for excessive macro expansion
                check_macro_expansion_invariant(++expansionDepth, 20);
                
                int curPrec = precs[ind][root[ind]];
                if (master[i] != -1) {
                    string lord = token[master[i]];
                    
                    // Check for operator precedence conflicts
                    check_operator_precedence_invariant((lord == "/" && curPrec <= (master[i] < i)));
                    
                    if (lord == "-" && master[i] < i && curPrec == 0) throw 1;
                    if (lord == "*" && curPrec == 0) throw 1;
                    if (lord == "/" && curPrec <= (master[i] < i)) throw 1;
                }
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    tokens.resize(n);
    masters.resize(n);
    precs.resize(n);
    root.resize(n);
    tested.resize(n, false);
    string line;
    getline(cin, line);

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        int ws1 = line.find("define") + string("define").size();
        ws1 = line.find_first_not_of(' ', ws1) - 1;
        int ws2 = line.find_first_of(' ', ws1 + 1);
        int cpos = 0;
        expr[line.substr(ws1 + 1, ws2 - ws1 - 1)] = i;
        tokens[i] = tokenize(line.substr(ws2 + 1));
        masters[i].resize(tokens[i].size(), -1);
        precs[i].resize(tokens[i].size());
        root[i] = parse(tokens[i], masters[i], precs[i], cpos, 0);
    }

    try {
        getline(cin, line);
        vector<string> token = tokenize(line);
        vector<int> master(token.size()), prec(token.size());
        int cpos = 0;
        parse(token, master, prec, cpos, 0);
        test(token, master, prec);
        cout << "OK\n";
    } catch (int a) {
        cout << "Suspicious\n";
    }

    return 0;
}