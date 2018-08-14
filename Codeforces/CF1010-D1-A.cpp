#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int N ;
    int ow ;
    int as[limN], bs[limN];

    scanf("%d%d", &N, &ow);
    for(int i=0; i<N; i++) {
        scanf("%d", &as[i]);
        if(--as[i] == 0) {
            printf("-1\n");
            return 0;
        }
    }
    for(int i=0; i<N; i++) {
        scanf("%d", &bs[i]);
        if(--bs[i] == 0) {
            printf("-1\n");
            return 0;
        }
    }

    double w = ow;
    for(int i=N-1; i>=0; i--) {
        w += w / bs[(i+1)%N];
        w += w/ as[i];
    }

    printf("%.9lf\n", w - ow);
}
