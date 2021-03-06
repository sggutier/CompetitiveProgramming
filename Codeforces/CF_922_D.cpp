#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int limN = 1e5 + 5;
typedef pair<ll,ll> pii;
#define f first
#define s second

ll calca(char *s, pii &cnt)  {
    int N = strlen(s);
    ll ans = 0;
    cnt = {0, 0};
    for(int i=0, c=0; i<N; i++) {
        if(s[i]=='s') {
            c++;
            cnt.f ++;
        }
        else {
            cnt.s ++;
            ans += c;
        }
    }
    return ans;
}

int main() {
    int N ;
    ll ans = 0;
    pii cmbs[limN];
    char tmp[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%s", tmp);
        ans += calca(tmp, cmbs[i]);
        // printf("%lld\n", calca(tmp, cmbs[i]));
    }

    sort(cmbs, cmbs+N,
         [] (const pii a, const pii b) {
             return a.f * b.s > b.f * a.s;
         });
    for(int i=0, c=0; i<N; i++) {
        // printf("%lld %lld\n", cmbs[i].f, cmbs[i].s);
        ans += c*cmbs[i].s;
        c += cmbs[i].f;
    }

    printf("%lld\n", ans);
}
