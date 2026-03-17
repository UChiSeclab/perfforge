#include <bits/stdc++.h>
using namespace std;
struct Dinic {
  const static int Maxn = 200;
  const static int Maxm = 200;
  const static int Inf = 2100000000;
  int head[Maxn + 5];
  int cur[Maxn + 5];
  struct Edge {
    int v, nxt, f;
    Edge() {}
    Edge(int v0, int n0, int f0) {
      v = v0;
      nxt = n0;
      f = f0;
    }
  };
  Edge e[Maxm * 2 + 5];
  int nume = 1;
  inline void init() {
    nume = 1;
    memset(head, 0, sizeof(head));
  }
  inline void insertEdge(int u, int v, int f) {
    e[++nume] = Edge(v, head[u], f);
    head[u] = nume;
  }
  inline void addEdge(int u, int v, int f) {
    insertEdge(u, v, f);
    insertEdge(v, u, 0);
  }
  int dist[Maxn + 5];
  queue<int> que;
  int src, sink;
  inline bool bfs() {
    while (!que.empty()) que.pop();
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    que.push(src);
    while (!que.empty()) {
      int now = que.front();
      que.pop();
      for (int i = head[now]; i; i = e[i].nxt) {
        if (e[i].f > 0 && dist[e[i].v] == -1) {
          dist[e[i].v] = dist[now] + 1;
          que.push(e[i].v);
        }
      }
    }
    return dist[sink] != -1;
  }
  int dfs(int x, int delta) {
    if (x == sink) {
      return delta;
    } else {
      int ret = 0;
      for (int& i = cur[x]; i; i = e[i].nxt) {
        if (e[i].f > 0 && dist[e[i].v] == dist[x] + 1) {
          int ddelta = dfs(e[i].v, min(e[i].f, delta));
          e[i].f -= ddelta;
          e[i ^ 1].f += ddelta;
          delta -= ddelta;
          ret += ddelta;
        }
      }
      return ret;
    }
  }
  inline int Max_Flow(int src0, int sink0) {
    src = src0;
    sink = sink0;
    int ret = 0;
    while (bfs()) {
      memcpy(cur, head, sizeof(head));
      ret += dfs(src, Inf);
    }
    return ret;
  }
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
inline int getState(string str);
inline int getSafe(string str) {
  int id = HashExp[getHash(str)];
  if (id == 0) return 1;
  return getState(str);
}
inline void Calc(int op, int s1, int s2) {
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
inline int getState(string str) {
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
      getSafe(tmp);
      stackNum[++numCnt] = getSafe(tmp);
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
  for (int i = 1; i <= n; i++) {
    cin >> mDefine;
    while (mDefine != "define" && mDefine != "#define") cin >> mDefine;
    cin >> mName;
    HashExp[getHash(mName)] = i;
    getline(cin, mExp[i]);
    mExp[i] = TrimStr(mExp[i]);
  }
  getline(cin, finalExp);
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
