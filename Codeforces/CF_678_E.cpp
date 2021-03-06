#include <bits/stdc++.h>
using namespace std;
const int limN = 18;
const int limB = 1<<limN;

int N ;
double mat[limN][limN];

bool usd[limN][limB];
double probWMemo[limN][limB];

double probW(int pos, int msk=(1<<N)-1) {
    if(msk == 1)
        return 1.0;
    if((msk & 1) == 0)
        return 0.0;
    if(usd[pos][msk])
        return probWMemo[pos][msk];
    usd[pos][msk] = true;
    double &ans = probWMemo[pos][msk];
    // printf("%d %d => %.9lf\n", pos, msk , ans);
    // for(int b=0; b<N; b++) {
    //     if( b!=pos && ((1<<b) & msk)) {
    //         printf("\tLleva a %d %d\n", pos, msk - (1<<b));
    //         printf("\tTambien a %d %d\n", pos, msk - (1<<pos));
    //     }
    // }
    for(int b=0; b<N; b++) {
        if( b!=pos && ((1<<b) & msk))
            ans = max(ans, mat[pos][b]*probW(pos, msk - (1<<b))
                      +  mat[b][pos]*probW(b, msk - (1<<pos)));
    }    
    return ans;
}

int main() {
    double ans = 0.0;
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%lf", &mat[i][j]);

    for(int i=0; i<N; i++)
        ans = max(ans, probW(i));

    printf("%.12lf\n", ans);
}
