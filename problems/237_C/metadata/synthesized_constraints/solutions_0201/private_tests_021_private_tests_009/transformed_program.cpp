#include <bits/stdc++.h>
using namespace std;

// Function to check for prime range invariant
void check_prime_range_invariant(int b, int a) {
    if (b - a + 1 > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - large range for prime checking!" << endl;
        abort();
    }
}

// Function to check for large input range overhead
void check_large_input_range(int b, int a) {
    if (b - a + 1 > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered - processing over large input range!" << endl;
        abort();
    }
}

// Function to check for high primality verification load
void check_high_primality_load(int k, int numPrimesInRange) {
    if (k > numPrimesInRange * 0.8) {
        cerr << "Warning: Performance bottleneck condition triggered - high demand for primes relative to range!" << endl;
        abort();
    }
}

int a[1000] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
               103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
               173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
               241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
               317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
               401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
               479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,
               571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
               647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
               739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,
               827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
               919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

bool jie(int t) {
  if (t == 1) return 0;
  for (int i = 0; i < 168; i++)
    if (t == a[i])
      return 1;
    else if (t % a[i] == 0)
      return 0;
  return 1;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  // Check for large input range before processing
  check_large_input_range(m, n);
  
  // Estimate the number of primes in the range for the primality load check
  int approxNumPrimesInRange = (m - n + 1) / log(m);
  check_high_primality_load(k, approxNumPrimesInRange);

  // Check for prime range invariant
  check_prime_range_invariant(m, n);

  int u = -1;
  int l = 0;
  int y = 0;
  int h = 0;
  bool pan = 0;
  int b[100000];
  
  for (int i = n; i <= m; i++) {
    if (jie(i)) {
      b[h] = i;
      h++;
      if (h - l == k) {
        y = b[h - 1] - b[l] + 1;
        pan = 1;
        u = max(b[h - 1] - b[l] + 1, u);
        l++;
      }
    } else {
      y++;
      u = max(y, u);
    }
  }

  l = 0;
  y = 0;
  h = 0;
  for (int i = m; i >= n; i--) {
    if (jie(i)) {
      b[h] = i;
      h++;
      if (h - l == k) {
        y = b[l] - b[h - 1] + 1;
        pan = 1;
        u = max(b[l] - b[h - 1] + 1, u);
        l++;
      }
    } else {
      y++;
      u = max(y, u);
    }
  }
  if (pan)
    cout << u << endl;
  else
    cout << -1 << endl;
  
  return 0;
}