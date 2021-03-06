#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef int ll;
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
					H[u] = 1e8;
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

int TC = 0;

int anum(int N, int p) {
    if(p==N)
        return -100;
    if(p==N+1)
        return -200;
    return p>=N? p-N-1 : p+1;
}

void testCase(int N, int E) {
    TC ++;
    vector <vector<bool> > usd(N, vector<bool>(N));
    int ini = N, fin = N+1;
    PushRelabel pr = fin+1;
    // printf("TC %d =>\n", TC);
    // printf("%d %d\n", N, E);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        // printf("%d ", a);
        if(a)
            pr.add_edge(i, fin, 1);
        else
            pr.add_edge(ini, i, 1);
    }
    // printf("\n");
    for(int i=0, a, b; i<E; i++) {
        scanf("%d%d", &a, &b);
        // printf("%d %d\n", a, b);
        a--, b--;
        if(a==b || usd[a][b]) {
            // printf("pishi problemsetter %d %d\n", a, b);
            // while(true) {}
            continue;
        }
        usd[a][b] = usd[b][a] = true;
        pr.add_edge(a, b, 1, 1);
    }
    // printf(">>>\n");
    printf("%d\n", pr.maxflow(ini, fin));
    // for(int i=0; i<=fin; i++) {
    //     for(auto &e : pr.g[i]) {
    //         if(e.f > 0)
    //             printf("%d %d > %lld\n", anum(N, i), anum(N, e.dest), e.f);
    //     }
    // }
}

int main() {
	int a, b ;
    while(scanf("%d%d", &a, &b)!=EOF && (a || b))
        testCase(a, b);
}
