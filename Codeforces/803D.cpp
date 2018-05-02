#include <bits/stdc++.h>
using namespace std;
const int limN = 1e6 + 5;

char str[limN];
vector <int> poss;
int tlen ;

bool funca(int K, int maxL) {
    int N = poss.size();
    for(int i=0, u=-1; i<N; i++) {
        if(poss[i]-u > maxL) {
            K --;
            if(K==0) {
                return false;
            }
            u = poss[i-1];
        }
    }
    return true;
}

int main() {
    int K ;
    fgets(str, sizeof(str), stdin);
    K = atoi(str);
    fgets(str, sizeof(str), stdin);
    tlen = strlen(str);
    str[--tlen] = 0;
    for(int i=0; i<tlen; i++)
        if(str[i]==' ' || str[i]=='-')
            poss.push_back(i);
    poss.push_back(tlen-1);
    int ini=poss[0]+1, fin = tlen;
    for(int i=poss.size()-1; i>0; i--)
        ini = max(ini, poss[i] - poss[i-1]);
    while(ini < fin) {
        int piv = (ini+fin)/2 ;
        if(funca(K, piv))
            fin = piv;
        else
            ini = piv+1;
    }
    printf("%d\n", ini);
}
