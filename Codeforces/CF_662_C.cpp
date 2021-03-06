#include <bits/stdc++.h>
using namespace std;
const int limN = 20;
const int limB = 1<<limN;
const int limM = 1e5 + 5;

int N, T ;
char matr[limN][limM];

int getNum(int N, int col) {
    int ans = 0;
    for(int i=0; i<N; i++)
        ans += matr[i][col]=='1'? (1<<i) : 0;
    return ans;
}

struct Nodo {
    int D;
    Nodo *l, *r;
    int cnt = 0;
    Nodo(int D) : D(D), l(NULL), r(NULL), cnt(0) {}
    void mete(const int n) {
        cnt ++;
        if(D==-1) return;
        if((1<<D) & n) {
            if(r==NULL) r = new Nodo(D-1);
            r->mete(n);
        }
        else {
            if(l==NULL) l = new Nodo(D-1);
            l->mete(n);
        }
    }
    vector<vector <int>>* calcBts() {
        vector<vector <int>> *nums;
        if(D==-1) {
            nums = new vector<vector <int>>(N+1);            
            for(int prevo=0; prevo<=N; prevo++) {
                (*nums)[prevo].resize(1);
                (*nums)[prevo][0] = min(N-prevo, prevo)*cnt ;
            }
            return nums;
        }
        vector<vector <int>> *LV, *RV;
        if(l) LV = l->calcBts();
        if(r) RV = r->calcBts();
        nums = new vector<vector <int>>(N-D);
        // printf("Calculando a prof %d con %d filas y %d cols\n", D, N-D, 1<<(D+1));
        for(int i=N-D-1; i>=0; i--) {
            (*nums)[i].resize(1<<(D+1));
            for(int j=(1<<(D+1))-1; j>=0; j--) {
                if((1<<D) & j) {
                    // printf("A punto de meter en %d %d %d\n", D, i, j);
                    (*nums)[i][j] = (l? (*LV)[i+1][j-(1<<D)] : 0)
                        + (r? (*RV)[i][j-(1<<D)] : 0);
                }
                else {
                    // printf("B punto de meter en %d %d %d\n", D, i, j);
                    (*nums)[i][j] = (l? (*LV)[i][j] : 0)
                        + (r? (*RV)[i+1][j] : 0);
                }
            }
        }
        if(l) delete LV ;
        if(r) delete RV ;
        return nums;
    }
};

Nodo *t ;

int main() {
    scanf("%d%d", &N, &T);
    for(int i=0; i<N; i++)
        scanf("%s", matr[i]);
    t = new Nodo(N-1);
    for(int j=0; j<T; j++) {
        int s = 0;
        for(int i=0; i<N; i++)
            if(matr[i][j]=='1')
                s += (1<<i);
        t->mete(s);
    }
    vector <vector<int>> *vac = t->calcBts();
    int ans = (1<<30);
    for(int i=(1<<N)-1; i>=0; i--)
        ans = min(ans, (*vac)[0][i]);
    printf("%d\n", ans);
}
