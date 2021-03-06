#include <bits/stdc++.h>
using namespace std;
const int limN = 2e5 + 5;

vector <int> poss[limN];

int maxS(vector <int> &v, const int k) {
    int ans = 0;
    int N = v.size();
    for(int i=0, j=0, s=0; j<N; j++) {
        if(j)
            s += v[j]-v[j-1]-1; 
        while(i < j && k < s) {
            s -= v[i+1]-v[i]-1;
            i++;
        }
        ans = max(ans, j-i+1);
    }
    return ans;
}

int main() {
    int N, M, k;

    scanf("%d%d%d", &N, &M, &k);
    for(int i=0, a; i<N; i++) {
        scanf("%d", &a);
        poss[a].push_back(i);
    }

    int ans = 0;
    for(int i=1; i<=M; i++)
        ans = max(ans, maxS(poss[i], k));

    printf("%d\n", ans);
}
