#include <bits/stdc++.h>
using namespace std;

struct operation {
    string l, r;
    char op;
};

vector<operation> operations;
set<string> toCheck;
map<string, string> m;
set<string> checked;

// Function to check complex macro expressions
void check_complex_macro_expression(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex macro expressions!" << endl;
        abort();
    }
}

// Function to check recursion depth
void check_recursion_depth(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth!" << endl;
        abort();
    }
}

// Function to check operator handling
void check_operator_handling(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex operator handling!" << endl;
        abort();
    }
}

void f1(const vector<string>& v, const vector<char>& op) {
    int n = static_cast<int>((v).size());
    for (int i = 0; i < n - 1; ++i) {
        operations.push_back({v[0], v[i + 1], op[i]});
    }
}

void f3(const string& s);

void f2(const vector<string>& v, const vector<char>& op) {
    vector<string> newV;
    vector<char> newOp;
    vector<string> currV;
    vector<char> currOp;
    string curr = v[0];
    currV.push_back(v[0]);
    int n = static_cast<int>((v).size());
    for (int i = 0; i < n - 1; ++i) {
        if (op[i] == '*' || op[i] == '/') {
            curr += op[i];
            curr += v[i + 1];
            currV.push_back(v[i + 1]);
            currOp.push_back(op[i]);
        } else {
            newV.push_back(curr);
            curr = v[i + 1];
            newOp.push_back(op[i]);
            if (!currOp.empty()) {
                f1(currV, currOp);
            }
            currV = {v[i + 1]};
            currOp.clear();
        }
    }
    newV.push_back(curr);
    if (!currOp.empty()) {
        f1(currV, currOp);
    }
    for (int i = 0; i < static_cast<int>((newV).size()) - 1; ++i) {
        operations.push_back({newV[0], newV[i + 1], newOp[i]});
    }
}

void f3(const string& s) {
    checked.insert(s);
    int n = static_cast<int>((s).size());

    // Check recursion depth and complexity
    check_recursion_depth(n > 50);  // Example arbitrary threshold for recursion depth

    if (m.count(s)) {
        toCheck.insert(m[s]);
        return;
    }
    int balance = 0;
    bool inPar = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++balance;
        }
        if (s[i] == ')') {
            --balance;
        }
        if ((i != n - 1 && !balance) || static_cast<int>((s).size()) == 1) {
            inPar = false;
            break;
        }
    }
    if (inPar) {
        string t = "";
        for (int i = 1; i < n - 1; ++i) {
            t += s[i];
        }
        f3(t);
        return;
    }
    bool ops = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
            ops = true;
            break;
        }
    }
    if (!ops) {
        return;
    }
    vector<string> v;
    v.push_back("");
    vector<char> op;
    balance = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++balance;
        }
        if (s[i] == ')') {
            --balance;
        }
        if (balance || s[i] == ')') {
            v.back() += s[i];
            continue;
        }
        if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/') {
            op.push_back(s[i]);
            v.push_back("");
            continue;
        } else {
            v.back() += s[i];
        }
    }

    // Check operator handling complexity
    check_operator_handling(op.size() > 10);  // Example arbitrary threshold for operator complexity

    f2(v, op);
}

string deleteSpaces(const string& s) {
    string ans = "";
    int n = static_cast<int>((s).size());
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            ans += s[i];
        }
    }
    return ans;
}

set<char> freeOp(const string& s) {
    string t = m[s];
    set<char> ans;
    int balance = 0;
    int n = static_cast<int>((t).size());
    for (int i = 0; i < n; ++i) {
        if (t[i] == '(') {
            ++balance;
            continue;
        }
        if (t[i] == ')') {
            --balance;
            continue;
        }
        if (!balance &&
            (t[i] == '-' || t[i] == '+' || t[i] == '*' || t[i] == '/')) {
            ans.insert(t[i]);
        }
    }
    return ans;
}

bool check(const operation& o) {
    if (m.count(o.l)) {
        toCheck.insert(m[o.l]);
    } else {
        toCheck.insert(o.l);
    }
    if (m.count(o.r)) {
        toCheck.insert(m[o.r]);
    } else {
        toCheck.insert(o.r);
    }
    if (o.op == '+') {
        return true;
    }
    if (o.op == '-') {
        if (!m.count(o.r)) {
            return true;
        }
        set<char> sr = freeOp(o.r);
        if (sr.count('+') || sr.count('-')) {
            return false;
        }
        return true;
    }
    if (o.op == '*') {
        if (m.count(o.r)) {
            set<char> sr = freeOp(o.r);
            if (sr.count('+') || sr.count('-')) {
                return false;
            }
        }
        if (m.count(o.l)) {
            set<char> sl = freeOp(o.l);
            if (sl.count('+') || sl.count('-')) {
                return false;
            }
        }
        return true;
    }
    if (o.op == '/') {
        if (m.count(o.r)) {
            set<char> sr = freeOp(o.r);
            if (!sr.empty()) {
                return false;
            }
        }
        if (m.count(o.l)) {
            set<char> sl = freeOp(o.l);
            if (sl.count('+') || sl.count('-')) {
                return false;
            }
        }
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    if (!n) {
        cout << "OK\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        string def;
        cin >> def;
        if (def != "#define") {
            cin >> def;
        }
        string name;
        cin >> name;
        string val;
        getline(cin, val);
        m[name] = deleteSpaces(val);

        // Check complex macro expressions
        check_complex_macro_expression(m[name].size() > 30);  // Example arbitrary threshold for macro complexity
    }
    string s;
    getline(cin, s);
    s = deleteSpaces(s);
    toCheck.insert(s);
    while (!toCheck.empty()) {
        operations.clear();
        string tmp = *toCheck.begin();
        if (checked.count(tmp)) {
            toCheck.erase(tmp);
            continue;
        }
        f3(tmp);
        for (int i = 0; i < static_cast<int>((operations).size()); ++i) {
            if (!check(operations[i])) {
                cout << "Suspicious\n";
                return 0;
            }
        }
        toCheck.erase(tmp);
    }
    cout << "OK\n";
}