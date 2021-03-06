#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map <ll, ll> memo;

ll calca(ll n) {
    if(memo.count(n))
        return memo[n];
    ll p = 1;
    for(; p <n; p<<=1);
    p >>= 1;
    return memo[n] = calca(p) + calca(n - p) + ((p<<1)==n? p : 0);
}

int main() {
    ll n ;
    scanf("%lld", &n);
    memo[0] = 0;
    memo[1] = 1;
    printf("%lld\n", calca(n-1));
}
