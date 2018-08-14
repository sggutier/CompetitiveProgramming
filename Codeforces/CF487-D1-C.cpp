#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

ll mod ; // change to something else
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

int main() {
    int n ;

    scanf("%d", &n);


    if(n==4) {
        printf("YES\n1\n3\n2\n4\n");
        return 0;
    }

    for(int i=2; i*i<=n; i++) {
        if(n % i == 0) {
            printf("NO\n");
            return 0;
        }
    }

    mod = n;
    printf("YES\n1\n");
    for(int i=2, a; i<=n; i++) {
        a = (Mod(i) / Mod(i-1)).x;
        printf("%d\n", a? a : n );
    }
}
