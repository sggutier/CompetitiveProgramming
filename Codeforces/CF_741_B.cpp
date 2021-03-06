#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 1e5 + 5;

vector <int> adj[limN];
int beau[limN], weit[limN];
int sumB[limN], sumW[limN];
bool usd[limN];
vector <int> hs[limN];
int ans[limN];

void dfs(const int ini, int pos) {
    if(usd[pos]) return;
    usd[pos] = true;
    sumB[ini] += beau[pos];
    sumW[ini] += weit[pos];
    hs[ini].push_back(pos);
    for(const int &sig:adj[pos])
        dfs(ini, sig);
}

int main() {
    int N, E, W;

    scanf("%d%d%d", &N, &E, &W);
    for(int i=0; i<N; i++)
        scanf("%d", &weit[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &beau[i]);
    for(int i=0; i<E; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0; i<N; i++) {
        if(usd[i]) continue;
        dfs(i, i);
        vector <int> &hl = hs[i];
        int b = sumB[i], w = sumW[i];
        for(int p=W; p>=0; p--) {
            if(p >= w)
                ans[p] = max(ans[p], ans[p-w]+b);
            for(const int &h:hl)
                if(p >= weit[h])
                    ans[p] = max(ans[p], ans[p-weit[h]] + beau[h]);
        }
    }

    printf("%d\n", ans[W]);
}
