#include <bits/stdc++.h>
using namespace std;

struct Dinic {
  // Dinic's algorithm code omitted for brevity, as it wasn't relevant to the current problem
};

const int M = 1e6 + 7;
const int HashCode = 123;

inline int getHash(string str) {
  int len = str.length();
  int ret = 0;
  for (int i = 0; i < len; i++) {
    ret = (ret * HashCode + str[i]) % M;
  }
  return ret;
}

map<int, int> HashExp;
int n;
string mDefine, mName, mExp[105], finalExp;
int mSafe[105];

inline string getNextState(int& pos, string str) {
  string ret = "";
  int len = str.length();
  for (int& i = pos; i < len; i++)
    if (str[i] != ' ') break;
  if (!(('A' <= str[pos] && str[pos] <= 'Z') ||
        ('a' <= str[pos] && str[pos] <= 'z') ||
        ('0' <= str[pos] && str[pos] <= '9'))) {
    ret += str[pos];
    pos++;
    return ret;
  }
  for (int& i = pos; i < len; i++) {
    if ((('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z') || 
         ('0' <= str[i] && str[i] <= '9'))) {
      ret += str[i];
    } else {
      break;
    }
  }
  return ret;
}

int stackOp[1005], stackNum[1005];
int opCnt, numCnt;

inline int getPri(int str) {
  if (str == 1 || str == 2) return 1;
  if (str == 4 || str == 3) return 2;
  if (str == 5) return 3;
  return 0;
}

inline bool isOP(string str) {
  if (str == "+" || str == "-") return true;
  if (str == "*" || str == "/") return true;
  if (str == "(" || str == ")") return true;
  return false;
}

inline int getOP(string str) {
  if (str == "+") return 1;
  if (str == "-") return 2;
  if (str == "*") return 3;
  if (str == "/") return 4;
  if (str == ")") return 5;
  if (str == "(") return 0;
}

inline bool isOP(char str) {
  if (str == '+' || str == '-') return true;
  if (str == '*' || str == '/') return true;
  if (str == '(' || str == ')') return true;
  return false;
}

int getState(string str);

int getSafe(string str) {
  int id = HashExp[getHash(str)];
  if (id == 0) return 1;
  return getState(str);
}

void Calc(int op, int s1, int s2) {
  if (s1 == 2 || s2 == 2) {
    stackNum[++numCnt] = 2;
    return;
  }
  switch (op) {
    case 1:
      stackNum[++numCnt] = 3;
      break;
    case 2:
      if (s2 == 3)
        stackNum[++numCnt] = 2;
      else
        stackNum[++numCnt] = 3;
      break;
    case 3:
      if (s1 == 3 || s2 == 3)
        stackNum[++numCnt] = 2;
      else
        stackNum[++numCnt] = 4;
      break;
    case 4:
      if (s1 == 3 || s2 == 3)
        stackNum[++numCnt] = 2;
      else if (s2 == 4)
        stackNum[++numCnt] = 2;
      else
        stackNum[++numCnt] = 4;
      break;
  }
}

int getState(string str) {
  int id = HashExp[getHash(str)];
  if (id != 0 && mSafe[id] != 0) return mSafe[id];
  if (id != 0) str = mExp[id];
  int pos = 0, len = str.length();
  int stOP = opCnt;
  while (pos < len) {
    string tmp = getNextState(pos, str);
    if (isOP(tmp)) {
      if ((opCnt == stOP || stackOp[opCnt] == 0 || 
           getPri(getOP(tmp)) > getPri(stackOp[opCnt]) || getOP(tmp) == 0) &&
          getOP(tmp) != 5) {
        stackOp[++opCnt] = getOP(tmp);
      } else {
        int pri = getOP(tmp);
        if (pri == 5) {
          while (stackOp[opCnt] != 0) {
            Calc(stackOp[opCnt--], stackNum[numCnt--], stackNum[numCnt--]);
          }
          opCnt--;
          if (stackNum[numCnt--] != 2)
            stackNum[++numCnt] = 1;
          else
            stackNum[++numCnt] = 2;
        } else {
          while (!(opCnt == stOP || getPri(pri) > getPri(stackOp[opCnt]))) {
            Calc(stackOp[opCnt--], stackNum[numCnt--], stackNum[numCnt--]);
          }
          stackOp[++opCnt] = pri;
        }
      }
    } else {
      int nm = getSafe(tmp);
      stackNum[++numCnt] = nm;
    }
  }
  while (opCnt > stOP)
    Calc(stackOp[opCnt--], stackNum[numCnt--], stackNum[numCnt--]);
  return mSafe[id] = stackNum[numCnt--];
}

inline string TrimStr(string str) {
  int len = str.length();
  string ret = "";
  bool flag = false;
  for (int i = len - 1; i >= 0; i--) {
    if (('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z') || 
        isOP(str[i]) || ('0' <= str[i] && str[i] < '9'))
      flag = true;
    if (flag) {
      ret = str[i] + ret;
    }
  }
  return ret;
}

inline void solve(int T) {
  scanf("%d", &n);

  // Check macro complexity
  check_macro_complexity(n);

  for (int i = 1; i <= n; i++) {
    cin >> mDefine;
    while (mDefine != "define" && mDefine != "#define") cin >> mDefine;
    cin >> mName;
    HashExp[getHash(mName)] = i;
    getline(cin, mExp[i]);
    // Check expression complexity
    check_expression_complexity(mExp[i].length());
    mExp[i] = TrimStr(mExp[i]);
  }
  getline(cin, finalExp);
  // Check expression complexity
  check_expression_complexity(finalExp.length());

  // Count number of hash calls (just a mockup)
  int hashCallCount = 0;
  for (auto it : HashExp) {
    hashCallCount++;
  }
  check_hashing_operations(hashCallCount);

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