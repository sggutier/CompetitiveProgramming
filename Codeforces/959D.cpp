#include <bits/stdc++.h>
using namespace std;
const int limP = 2e6;
const int limN = 2e5 + 5;

bitset<limP> isComp;
int P = 0;
int primos[limN];
bitset <limP> usd;
vector <int> facs[limN];

void criba(int n = limP) {
    for(int i=2; i*i<n; i++)
        if(!isComp[i])
            for(int j=i*i; j<n; j+=i)
                isComp[j] = true;
    for(int i=2; i<n; i++)
        if(!isComp[i])
            primos[P++] = i;
}

void marca(int n = limN) {
    for(int i=0; i<P; i++) {
        int p = primos[i];
        if(p >= n) break;
        for(int j=p; j<n; j+=p)
            facs[j].push_back(p);
    }
}

bool prueba(int w) {
    for(const int f : facs[w]) {
        if(usd[f])
            return false;
    }
    for(const int f : facs[w]) {
        // printf("usando %d\n", f);
        usd[f] = true;
    }
    return true;
}

int main() {
    criba();
    marca();
    int N ;
    int nums[limN];

    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &nums[i]);

    for(int i=0; i<N; i++) {
        int w = nums[i];
        if(prueba(w))
            continue;
        for(w++; !prueba(w); w++) ;
        // printf("reemplazando %d con %d\n", nums[i], w);
        nums[i] = w;
        int j = 0;
        for(i++; i<N; i++) {
            for(; usd[primos[j]]; j++);
            nums[i] = primos[j];
            usd[primos[j]] = true;
        }
        break;
    }

    for(int i=0; i<N; i++)
        printf("%d ", nums[i]);
    printf("\n");
}
