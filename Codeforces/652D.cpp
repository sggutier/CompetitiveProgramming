#include <bits/stdc++.h>
using namespace std;
const int limN = 4e5 + 5;

struct BIT {
    int N ;
    int crg[limN + 5];

    void mete(int pos, int nov = 1) {
        for(; pos<limN; pos += (pos & -pos))
            crg[pos] += nov;
    }

    int saca(int pos) {
        int ans = 0;
        for(; pos; pos -= (pos & -pos))
            ans += crg[pos];
        return ans;
    }
};

map <int, int> ordo;
BIT bt;
int ps[limN];
int ans[limN];
int nms[limN][2];

int main() {
    int N ;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d%d", &nms[i][0], &nms[i][1]);
        ordo[nms[i][0]];
        ordo[nms[i][1]];
        ps[i] = i;
    }

    int W = 1;
    for(auto &p : ordo)
        p.second = W++;
    for(int i=0; i<N; i++) {
        for(int j=0; j<2; j++) {
            nms[i][j] = ordo[nms[i][j]];
            // printf("%d ", nms[i][j]);
        }
        // printf("\n");
    }
    sort(ps, ps+N, [](const int a, const int b) { return nms[a][0] > nms[b][0]; });

    for(int i=0, p; i<N; i++) {
        p = ps[i];
        // printf("%d %d\n", nms[p][0], nms[p][1]);
        ans[p] = bt.saca(nms[p][1]);
        bt.mete(nms[p][1]);
    }
    for(int i=0; i<N; i++)
        printf("%d\n", ans[i]);
}
