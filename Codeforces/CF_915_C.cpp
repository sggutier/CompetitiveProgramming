#include <bits/stdc++.h>
using namespace std;
const int limB = 25;

int N ;
char A[limB], B[limB];

int main() {
    int M ;
    cin >> A >> B ;
    N = strlen(A), M = strlen(B);
    if(M > N) {
        for(int i=0; i<N; i++)
            B[i] = '9';
    }
    for(int i=0; i<N; i++) {
        sort(A+i, A+N);
        int ip = i;
        for(int j=i; j<N; j++) {
            if(A[j] > B[i])
                break;
            bool fca = true;
            for(int k=i, w=i+1; k<N; k++) {
                if(k==j) {
                    continue;
                }
                if(A[k] < B[w])
                    break;
                if(A[k] > B[w])
                    fca = false;
                w ++;
            }
            fca |= (A[j] < B[i]);
            if(fca)
                ip = j;
            //printf("%d %d => %d [%c %c]\n", i, j, fca, B[i], A[j]);
        }
        swap(A[i], A[ip]);
        if(A[i] < B[i]) {
            sort(A+i+1, A+N);
            reverse(A+i+1, A+N);
            break;
        }
    }
    printf("%s\n", A);
}

