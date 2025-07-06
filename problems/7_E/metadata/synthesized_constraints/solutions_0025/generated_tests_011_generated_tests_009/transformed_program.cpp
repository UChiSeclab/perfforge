#include <bits/stdc++.h>
using namespace std;

map<string, string> mp;
map<string, int> mp2;

string str_cut(string str1, int index1, int index2) {
    string str2 = "";
    str2 = str1.substr(index1, index2 - index1);
    return str2;
}

int check(string str, int currentDepth) {
    // Check recursion depth invariant
    check_recursive_depth_invariant(currentDepth, 10); // Arbitrary max depth for demonstration

    if (mp2[str] != 0) return (mp2[str] - 1);
    if (mp[str] != "") str = mp[str];
    int len = str.length();
    int in = 0;
    int index1 = -1, index2 = -1;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') in++;
        if (str[i] == ')') in--;
        if ((str[i] == '+' || str[i] == '-') && in == 0) index1 = i;
        if ((str[i] == '*' || str[i] == '/') && in == 0) index2 = i;
    }
    int index = 0;
    if (str[0] == '(' && str[len - 1] == ')' && index1 == -1 && index2 == -1) {
        if (check(str_cut(str, 1, len - 1), currentDepth + 1) == 3)
            return 3;
        else
            return 0;
    }
    if (index1 == -1 && index2 == -1) return 0;
    if (index1 == -1)
        index = index2;
    else
        index = index1;
    int num1 = check(str_cut(str, 0, index), currentDepth + 1),
        num2 = check(str_cut(str, index + 1, len), currentDepth + 1);

    // Check for potential precedence conflicts
    check_operator_precedence((num1 == 3 || num2 == 3) && (str[index] == '+' || str[index] == '-'));
    check_operator_precedence((num1 == 2 || num2 == 2) && (str[index] == '*' || str[index] == '/'));

    if (str[index] == '+') {
        if (num1 == 3 || num2 == 3) {
            mp2[str] = 4;
            return 3;
        } else {
            mp2[str] = 3;
            return 2;
        }
    } else if (str[index] == '-') {
        if (num1 == 3 || num2 == 2 || num2 == 3) {
            mp2[str] = 4;
            return 3;
        } else {
            mp2[str] = 3;
            return 2;
        }
    } else if (str[index] == '*') {
        if (num1 == 2 || num1 == 3 || num2 == 2 || num2 == 3) {
            mp2[str] = 4;
            return 3;
        } else {
            mp2[str] = 2;
            return 1;
        }
    } else {
        if (num1 == 2 || num1 == 3 || num2 == 1 || num2 == 2 || num2 == 3) {
            mp2[str] = 4;
            return 3;
        } else {
            mp2[str] = 2;
            return 1;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        string str1 = "", str2 = "", str3 = "";
        getline(cin, s);
        bool b = 0, b2 = 1;
        for (int i = 0; i < s.length(); i++) {
            if (str1 != "#define" && s[i] != ' ') {
                str1 += s[i];
                continue;
            }
            if (!b && s[i] != ' ' && b2) {
                b = 1;
            }
            if (b && s[i] == ' ') {
                b = 0;
                b2 = 0;
            }
            if (b) {
                str2 += s[i];
                continue;
            }
            if (s[i] != ' ') str3 += s[i];
        }
        mp[str2] = str3;
    }
    string check_str = "";
    getline(cin, check_str);
    string check_str2 = "";
    for (int i = 0; i < check_str.length(); i++)
        if (check_str[i] != ' ') check_str2 += check_str[i];
    int ans = check(check_str2, 0);
    if (ans == 3)
        cout << "Suspicious";
    else
        cout << "OK";
    return 0;
}