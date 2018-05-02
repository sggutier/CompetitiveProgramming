#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;
const int inf = 1e9;

map <string, int> dico;
int csts[limN], gpo[limN];
vector <int> gpos[limN];
int minC[limN];

int main() {
    int N, K, M;
    long long ans = 0;

    scanf("%d%d%d", &N, &K, &M);
    for(int i=0; i<N; i++) {
        char tmp[30];
        scanf("%s", tmp);
        dico[tmp] = i;
    }
    for(int i=0; i<N; i++)
        scanf("%d", &csts[i]);
    for(int i=0; i<K; i++) {
        int X ;
        scanf("%d", &X);
        gpos[i].resize(X);
        minC[i] = inf;
        for(int j=0; j<X; j++) {
            scanf("%d", &gpos[i][j]);
            gpos[i][j]--;
            gpo[ gpos[i][j] ] = i;
            minC[i] = min(minC[i], csts[ gpos[i][j] ]);
        }
    }

    for(int i=0; i<M; i++) {
        char tmp[50];
        scanf("%s", tmp);
        ans += minC[ gpo[dico[tmp]] ];
    }

    printf("%lld\n", ans);
}
