#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y ;
    cin >> x >> y ;
    for(int b=60; b>=0; b--) {
        if( ((1LL<<b) & x) == ((1LL<<b) & y) )
            continue;
        printf("%lld\n", (1LL<<(b+1)) - 1);
        return 0;
    }
    printf("0\n");
}
