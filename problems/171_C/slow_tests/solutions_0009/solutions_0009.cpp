#include <bits/stdc++.h>
using namespace std;
int rev(int n) {
  int res = 0;
  while (n) {
    res *= 10;
    res += n % 10;
    n /= 10;
  }
  return res;
}
bool prime(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  stack<int> st;
  st.push(0);
  int carrots;
  cin >> carrots;
  int spread;
  int flour = 1;
  int egg = 1;
  while (carrots) {
    cin >> spread;
    st.push(spread);
    int t = st.top();
    st.pop();
    t *= flour;
    st.push(t);
    spread = st.top();
    st.pop();
    t = st.top();
    st.pop();
    t += spread;
    st.push(t);
    st.push(flour);
    t = st.top();
    ++t;
    st.pop();
    st.push(t);
    flour = st.top();
    st.pop();
    --carrots;
  }
  cout << st.top();
  return 0;
}
