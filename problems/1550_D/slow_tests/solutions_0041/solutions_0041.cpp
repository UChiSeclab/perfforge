#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

const ll mod = 1e9 + 7;

ll ipow(ll a, ll p) {
	if (p == 0)
		return 1;

	ll ret = ipow(a, p / 2);
	ret = ret * ret % mod;
	if (p & 1)
		ret = ret * a % mod;

	return ret;
}

ll fac[200005];

ll comb(ll n, ll r) {
	return fac[n] * ipow(fac[r], mod - 2) % mod * ipow(fac[n - r], mod - 2) % mod;
}

int main() {
	fac[0] = 1;
	for (int i = 1; i < 200005; ++i)
		fac[i] = fac[i - 1] * i % mod;

	int T;
	scanf("%d", &T);
	while (T--) {
		ll n, l, r;
		scanf("%lld %lld %lld", &n, &l, &r);

		ll mn = min(-l + 1, r - n);

		ll ans = mn % mod * comb(n, n / 2) * (n % 2 + 1) % mod;
		
		mn++;
		int s = 1, e = n;
		while (true) {
			if (r - 1 < mn || l - n > -mn)
				break;

			while (l - s > -mn)
				s++;
			while (r - e < mn)
				e--;

			int x = n - e, y = s - 1;

			if (x > (n + 1) / 2 || y > (n + 1) / 2)
				break;
			
			if (n % 2 == 0) {
				if (e - s + 1 <= 0)
					ans = (ans + 1) % mod;
				else
					ans = (ans + comb(e - s + 1, n / 2 - x)) % mod;
			}
			else {
				if (e - s + 1 > 0 && x < (n + 1) / 2 && y < (n + 1) / 2) {
					ans = (ans + comb(e - s + 1, n / 2 - x + 1)) % mod;
					ans = (ans + comb(e - s + 1, n / 2 - x)) % mod;
				}
				else if (x < (n + 1) / 2 || y < (n + 1) / 2)
					ans = (ans + 1) % mod;
			}

			mn++;
		}

		printf("%lld\n", ans);
	}

	return 0;
}