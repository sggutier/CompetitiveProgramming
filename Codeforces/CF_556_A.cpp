#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

int main() {
    int ans = 0;
    int N ;
    char str[limN];

    scanf("%d%s", &N, str);

    for(int i=0, u=0, c=0; i<=N; i++) {
        if(i && str[i]!=str[i-1]) {
            // printf("%d %d\n", u, c);
            ans += min(u, c);
            if(c <= u) {
                c = u-c;
                u = 0;
            }
            else {
                u = c-u;
                c = 0;
            }
        }
        c++;
    }

    printf("%d\n", N-2*ans);
}
