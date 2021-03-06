#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;

int N ;
bool funcaL[limN][limN];
bool funcaR[limN][limN];
char str[limN];

int main() {
    int ans = 0;
    
    scanf("%s", str);
    N = strlen(str);
    
    for(int i=0; i<N; i++) {
        for(int s=0, j=i; j<N; j++ ){
            s += str[j]!=')'? 1 : -1;
            if(s < 0)
                break;
            funcaL[i][j] = true;
        }
    }
    for(int j=0; j<N; j++) {
        for(int s=0, i=j; i>=0; i--) {
            s += str[i]!='('? 1 : -1;
            if(s < 0)
                break;
            funcaR[i][j] = true;
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j+=2) {
            if(funcaL[i][j] && funcaR[i][j])
                ans ++;
        }
    }

    printf("%d\n", ans);
}
