#include <bits/stdc++.h>
using namespace std;
const int limN = 1e5 + 5;

int main() {
    int A, B;
    int p, q;
    int X[limN], Y[limN];

    cin >> A >> B ;
    cin >> p >> q;
    for(int i=0; i<A; i++)
        cin >> X[i] ;
    for(int i=0; i<B; i++)
        cin >> Y[i] ;

    printf("%s\n", X[p-1] < Y[B-q]? "YES" : "NO" );
}
