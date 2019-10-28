#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd __gcd

ll mcm(const ll a, const ll b) {
    const ll g = gcd(a, b);
    return (a/g) * b;
}

int main() {
    int N ;
    ll k, c = 1;
    scanf("%d%lld", &N, &k);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        c = mcm(c, gcd((ll) a, k));
    }
    printf("%s\n", c==k? "Yes" : "No");
}

