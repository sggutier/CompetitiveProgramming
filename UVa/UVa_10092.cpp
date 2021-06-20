#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

void testCase(int N, int E) {
	const int ini = 0;
	const int fin = 1;
	PushRelabel pr(2 + N + E);
	int tot = 0 ;
	for(int i=0, a; i < N; i++) {
		scanf("%d", &a);
		pr.add_edge(ini, i + 2, a);
		tot += a;
	}
	for(int i=0; i < E; i++) {
		int k ;
		scanf("%d", &k);
		pr.add_edge(N + 2 + i, fin, 1);
		for(int j=0, a; j < k; j++)  {
			scanf("%d", &a);
			pr.add_edge(a + 1, N + 2 + i, 1);
		}
	}
	if(pr.maxflow(ini, fin) != tot) {
		printf("0\n");
		return ;
	}
	printf("1\n");
	for(int i=0; i < N; i++) {
		bool fst = true;
		for(const auto &e : pr.g[i + 2]) {
			if(e.f <= 0) continue;
			if(!fst)
				printf(" ");
			fst = false;
			printf("%d", e.dest - (N + 1));
		}
		printf("\n");
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N, E ;
	while(scanf("%d%d", &N, &E) != EOF && (N || E))
		testCase(N, E);
}