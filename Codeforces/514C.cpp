#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
const int limN = 6e5 + 5;
const ll modA = 31443539979727;
const ll modB = 3006703054056749;

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

template<ll mod = 17>
struct Mod {
	ll x;
    Mod() : x(0) {}
	Mod(ll xx) : x(xx) {}
	Mod operator+(const Mod& b) const { return Mod((x + b.x) % mod); }
	Mod operator-(const Mod &b) const { return Mod((x - b.x + mod) % mod); }
	Mod operator*(const Mod &b) const { return Mod((x * b.x) % mod); }
	Mod operator/(const Mod &b) const { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1); return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
    bool operator<(const Mod &otr) const {
		return this->x < otr.x;
	}
};


typedef Mod<modA> ModX;
typedef Mod<modB> ModY;

struct pmm {
    ModX x;
    ModY y;
    pmm() : x(0), y(0) {}
    pmm(const int a) : x(a), y(a) {}
    pmm(ModX x, ModY y) : x(x), y(y) {}
    pmm operator+(const pmm &otr) const {
        ModX w = this->x + otr.x;
        return pmm(w, this->y + otr.y);
    }
    pmm operator-(const pmm &otr) const {
        return pmm(this->x - otr.x, this->y - otr.y);
    }
    pmm operator*(const pmm &otr) const {
        return pmm(this->x * otr.x, this->y * otr.y);
    }
    bool operator<(const pmm &otr) const {
        return this->x < otr.x ;
    }
};

typedef pair<int, pmm> PR;

set <PR> st;

pmm pot3[limN];

void procNum(char *s) {
    pmm hs;
    int len = 0;
    for(char *c=s; *c!='\n'; c++, len++) {
        hs = hs*3 + pmm(*c-'a');
    }
    int w = len-1;
    for(char *c=s; *c!='\n'; c++, w--) {
        pmm v = hs - pot3[w]*pmm(*c-'a');
        for(int i=0; i<3; i++) if(i != *c-'a') {
                st.emplace(len, v + pot3[w]*i);
            }
                                   
    }
}

bool query(char *s) {
    pmm hs;
    int len = 0;
    for(char *c=s; *c!='\n'; c++, len++) {
        hs = hs*3 + pmm(*c-'a');
    }    
    return st.count({len, hs}) > 0;
}

char A[limN];

int main() {
    pot3[0] = 1;
    for(int i=1; i<limN; i++)
        pot3[i] = pot3[i-1]*3;
    
    int N, M ;
    fgets(A, limN, stdin);
    sscanf(A, "%d%d", &N, &M);
    for(int i=0; i<N; i++) {
        fgets(A, limN, stdin);
        procNum(A);
    }
    for(int i=0; i<M; i++) {
        fgets(A, limN, stdin);
        printf("%s\n", query(A)? "YES" : "NO");
    }
}
