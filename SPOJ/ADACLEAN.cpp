#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int limN = 3e5 + 5;

typedef pair<ll, int> pli;
void count_sort(vector<pli> &b, int bits) { // (optional)
	//this is just 3 times faster than stl sort for N=10^6
	int mask = (1 << bits) - 1;
	rep(it,0,2) {
		int move = it * bits;
		vi q(1 << bits), w(sz(q) + 1);
		rep(i,0,sz(b))
			q[(b[i].first >> move) & mask]++;
		partial_sum(q.begin(), q.end(), w.begin() + 1);
		vector<pli> res(b.size());
		rep(i,0,sz(b))
			res[w[(b[i].first >> move) & mask]++] = b[i];
		swap(b, res);
	}
}
struct SuffixArray {
	vi a;
	string s;
	SuffixArray(const string _s) : s(_s + '\0') {
		int N = sz(s);
		vector<pli> b(N);
		a.resize(N);
		rep(i,0,N) {
			b[i].first = s[i];
			b[i].second = i;
		}

		int q = 8;
		while ((1 << q) < N) q++;
		for (int moc = 0;; moc++) {
			count_sort(b, q); // sort(all(b)) can be used as well
			a[b[0].second] = 0;
			rep(i,1,N)
				a[b[i].second] = a[b[i - 1].second] +
					(b[i - 1].first != b[i].first);

			if ((1 << moc) >= N) break;
			rep(i,0,N) {
				b[i].first = (ll)a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		rep(i,0,sz(a)) a[i] = b[i].second;
	}
	vi lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i-1])
		int n = sz(a), h = 0;
		vi inv(n), res(n);
		rep(i,0,n) inv[a[i]] = i;
		rep(i,0,n) if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};


char str[limN];

void testCase() {
    int N, K;
    fgets(str, limN, stdin);
    sscanf(str, "%d%d", &N, &K);
    fgets(str, limN, stdin);
    str[N] = 0;
    SuffixArray sa(str);
    vi rcp = sa.lcp();
    int ans = 0;
    for(int i=1; i<=N; i++) {
        // printf("%d %d %s\n", sa.a[i], rcp[i], str + sa.a[i] );
        if(rcp[i] >= K)
            continue ;
        if(N - sa.a[i] >= K)
            ans++;//, printf("\thiri\n");
    }
    printf("%d\n", ans);
}

int main() {
	int tc ;
    fgets(str, limN, stdin);
    for(tc = atoi(str); tc; tc--)
        testCase();
}
