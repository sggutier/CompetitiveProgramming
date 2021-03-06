#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> par;
#define f first
#define s second
const int limN = 2e5 + 5;

int ans[limN];

struct item {
    int key, prior;
    int crgK, crgC;
    int id;
    item *l, *r;
    item(int key, int id) : key(key), prior(rand()), crgK(0), crgC(0), id(id), l(NULL), r(NULL) {}
};
typedef item* pitem;

void push(const pitem t) {
    if(!t || !t->crgC)
        return;
    ans[t->id] += t->crgC;
    t->key -= t->crgK;
    if(t->l) {
        t->l->crgK += t->crgK;
        t->l->crgC += t->crgC;
    }
    if(t->r) {
        t->r->crgK += t->crgK;
        t->r->crgC += t->crgC;
    }
    t->crgK = t->crgC = 0;
}

void cga(const pitem t, const int k) {
    if(t)
        t->crgK += k, t->crgC ++;
}

void split(const pitem t, const int k, pitem &l, pitem &r) {
    push(t);
    if(!t)
        l = r = NULL;
    else if(k < t->key)
        split(t->l, k, l, t->l), r = t;
    else
        split(t->r, k, t->r, r), l = t;
}

void merge(pitem &t, const pitem l, const pitem r) {
    push(l), push(r);
    if(!l || !r)
        t = l? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
}

void insert(pitem &t, const pitem it) {
    push(t);
    if(!t)
        t = it;
    else if(it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key? t->l : t->r, it);
}

void unite (pitem &l, const pitem r) {
    if(!r)
        return;
    push(r);
    unite(l, r->l);
    unite(l, r->r);
    r->l = r->r = NULL;
    insert(l, r);
}

void printa(pitem t) {
    if(!t) return;
    push(t);
    printa(t->l);
    // printf("%d ", t->key);
    printa(t->r);
}

void compra(int c, pitem &t) {
    pitem x, y, z;
    split(t, c-1, x, y);
    cga(y, c);
    split(y, c-1, y, z);
    unite(x, y);
    merge(t, x, z);
}

int main() {
    srand(time(NULL));
    
    int N, K ;
    pair<int,int> cams[limN], ctes[limN];
    pitem t = NULL;

    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int a, b ;
        scanf("%d%d", &a, &b);
        cams[i] = par(-b, a);
    }
    scanf("%d", &K);
    for(int i=0; i<K; i++) {
        scanf("%d", &ctes[i].f);
        ctes[i].s = i;
    }

    sort(cams, cams+N);
    sort(ctes, ctes+K);
    for(int i=0; i<K; i++)
        merge(t, t, new item(ctes[i].f, ctes[i].s));
    for(int i=0; i<N; i++)
        compra(cams[i].s, t);
    printa(t);

    for(int i=0; i<K; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
