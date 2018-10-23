#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 3e5 + 5;

int cntBts(ll k) {
    int ans = 0;
    while(k) {
        ans += k&1;
        k /= 2;
    }
    return ans;
}

int arb[limN];

void mete(int pos, const int nov) {
    for(; pos; pos -= (pos & -pos))
        arb[pos] = max(arb[pos], nov);    
}

int saca(int pos) {
    int ans = 0;
    for(; pos < limN; pos += (pos & -pos))
        ans = max(ans, arb[pos]);
    return ans;
}

vector <int> poss[2];
int sumos[limN];
int bts[limN];

int quer(int pos, int nov) {
    mete(pos, nov);
    vector <int> &ps = poss[sumos[pos]%2];
    int k = ps.size()-1;
    ps.push_back(pos);
    int ans = 0;
    // printf("quer @ %d %d\n", pos, nov);
    for(; k>=0; k--) {
        int p = ps[k];
        int s = sumos[pos] - sumos[p];
        if(s >= 120) {
            ans += k+1;
            break;
        }
        int mx = saca(p+1);
        // printf("\t %d %d %d\n", p, s, mx);
        if(s >= mx*2)
            ans ++;        
    }
    return ans;
}

int main() {
    int N ;

    scanf("%d", &N);
    ll a ;
    for(int i=1; i<=N; i++) {
        scanf("%lld", &a);
        a = cntBts(a);
        bts[i] = a;
        sumos[i] = sumos[i-1] + a;
    }
    poss[0].push_back(0);

    ll ans = 0;
    for(int i=1; i<=N; i++)
        ans += quer(i, bts[i]);

    printf("%lld\n", ans);
}
