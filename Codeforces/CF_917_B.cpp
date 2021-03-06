#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
#define f first
#define s second
const int limN = 101;
const int limC = 27;

vector <par> adj[limN];
bool usd[limN][limN][limC];
bool ganaMemo[limN][limN][limC];

bool gana(int a, int b, int t) {
    if(usd[a][b][t])
        return ganaMemo[a][b][t];
    usd[a][b][t] = true;
    bool &ans = ganaMemo[a][b][t];
    for(const par &edg:adj[a]) {
        if(edg.f >= t && !gana(b, edg.s, edg.f))
            return ans = true;
    }
    return ans;
}

int main() {
    int N, E;
    char tmp[10];
    scanf("%d%d", &N, &E);
    for(int i=0; i<E; i++) {
        int a, b;
        scanf("%d%d%s", &a, &b, tmp);
        adj[a-1].push_back({tmp[0]-'a'+1, b-1});
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%c", gana(i,j,0)? 'A':'B');
        }
        printf("\n");
    }
}
