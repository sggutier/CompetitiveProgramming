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

const int LIM_N = 405;
#define r first
#define c second

int dst(pii A, pii B) {
    return (abs(A.r - B.r) + abs(A.c - B.c)) * 200;
}

void testCase() {
    int P, C, S, T;
    scanf("%d%d%d%d", &P, &C, &S, &T);

    PushRelabel pr(P + C + 2);
    int ini = P+C, fin = P+C+1;
    pii ppl[LIM_N];

    for(int i=0; i < P; i++) {
        scanf("%d%d", &ppl[i].first, &ppl[i].second);
        pr.add_edge(ini, i, 1);
    }
    for(int i=0, a, b; i < C; i++) {
        scanf("%d%d", &a, &b);
        pr.add_edge(i + P, fin, 1);
        for(int j=0; j < P; j++) {
            if(T * S >= dst(ppl[j], {a, b}))
                pr.add_edge(j, i + P, 1);
        }
    }

    printf("%lld\n", pr.maxflow(ini, fin));
}

int main() {
    int tc ;
    scanf("%d", &tc);
    for(int i=0; i < tc; i++)
        testCase();
}
