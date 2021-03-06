#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll depo(int n, int k) {
    if(k==0)
        return 0;
    ll arr[n+1];

    arr[0] = 1LL;
    for(int i=1; i<=n; i++) {
        arr[i] = 0;
        for(int j=1; j<=k && i-j >=0; j++) {
            arr[i] = (arr[i-j] + arr[i])%mod;
        }
    }

    return arr[n];
}

int main() {
    ll n, k, d;
    cin >> n >> k >> d;
    cout << (mod + depo(n, k) - depo(n, d-1)) % mod << endl;
}
