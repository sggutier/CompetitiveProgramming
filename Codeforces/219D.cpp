#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;
typedef pair<int,int> pii;
#define f first
#define s second

int ans[limN];
vector <pii> adj[limN];

int cuenta(const int pos, const int pv = -1) {
    int ans = 0;
    for(const auto sig : adj[pos]) if(pv != sig.f) {
            ans += cuenta(sig.f, pos) - min(0, sig.s);
    }
    return ans;
}

void dfs(const int pos, const int pv = -1) {
    for(const auto sig : adj[pos]) if(pv != sig.f) {
            ans[sig.f] = ans[pos] + sig.s;
            dfs(sig.f, pos);
    }
}

int main() {
    int N ;
    scanf("%d", &N);
    for(int i=1, a, b; i<N; i++) {
        scanf("%d%d", &a, &b);
        adj[a].push_back({b, 1});
        adj[b].push_back({a, -1});
    }

    ans[1] = cuenta(1);
    dfs(1);

    int mv = (1<<30);
    for(int i=1; i<=N; i++)
        mv = min(mv, ans[i]);
    printf("%d", mv);
    int w = 0;
    for(int i=1; i<=N; i++) {
        if(ans[i] == mv)
            printf("%c%d", (w++)==0? '\n' : ' ', i);
    }
    printf("\n");
}
