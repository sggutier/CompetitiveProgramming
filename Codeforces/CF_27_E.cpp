#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limP = 1005;
const ll inf = 2e18;

bitset<limP> isComp;
vector <int> primos;

void criba(int N = limP) {
    isComp[0] = isComp[1] = true;
    for(int i=2; i*i<N; i++)
        if(!isComp[i])
            for(int j=i*i; j<N; j+=i)
                isComp[j] = true;
    for(int i=2; i<N; i++)
        if(!isComp[i])
            primos.push_back(i);
}

// bool usd[limP][limP];
// ll dp[limP][limP];

ll calcaMin(int pos, int N, int u=limP) {
    if(N==1)
        return 1;
    // if(usd[pos][N])
    //     return dp[pos][N];
    // usd[pos][N] = true;
    // ll &ans = dp[pos][N];
    ll ans = inf;
    ll p = 1;
    for(int i=2; i<=N && i<=u && p<ans; i++) {
        p *= primos[pos];
        if(N%i)
            continue;
        ll w = calcaMin(pos+1, N/i, i);
        // ll w = 1;
        // cout << "cala >> " << pos << " " << N << " " << u << " => " << w << " " << p << endl;
        if(ans/p >= w && w<ans)
            ans = min(ans, p*w);
    }
    // cout << pos << " " << N << " " << u << " => " << ans << endl;
    return ans;
}

int main() {
    criba();
    int N ;
    cin >> N ;
    cout << calcaMin(0, N) << endl;
}
