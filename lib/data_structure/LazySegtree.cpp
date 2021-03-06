/*
!) 0-indexed 遅延伝搬セグメント木
!) [a, b)に対する演算
!) M0, L0, merge, updateNode, propagateを書く
*/
template <typename Monoid>
struct LazySegtree {
    int n;
    vector<Monoid> dat, lazy;

    Monoid M0, L0 // データと遅延配列の初期化値 queryに合わせて選択する

    LazySegtree(int sz, Monoid dat_init){
        n = 1;
        while (n < sz) n *= 2;
        dat.assign(2*n-1, dat_init);
        lazy.assign(2*n-1, L0);
    }

    Monoid merge(Monoid a, Monoid b) // 区間をマージする二項演算
    void updateNode(int k, Monoid x) // 区間を操作する二項演算
    void propagate(int k, int l, int r) // 遅延配列の伝搬のさせ方

    void eval(int k, int l, int r) {
        if(lazy[k] == L0) return;
        propagate(k, l, r);
        if(r-l > 1) {
            updateNode(2*k+1, lazy[k]);
            updateNode(2*k+2, lazy[k]);
        }
        lazy[k] = L0;
    }

    void update(int a, int b, Monoid x, int k, int l, int r) {
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            updateNode(k, x);
            eval(k, l, r);
        }else{
            update(a, b, x, k*2+1, l, (l+r)/2);
            update(a, b, x, k*2+2, (l+r)/2, r);
            dat[k] = merge(dat[2*k+1], dat[2*k+2]);
        }
    }

    void update(int a, int b, Monoid x) {
        update(a, b, x, 0, 0, n);
    }

    Monoid query(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        if (r <= a || b <= l) return M0;
        if (a <= l && r <= b) return dat[k];
        Monoid L = query(a, b, k*2+1, l, (l+r)/2);
        Monoid R = query(a, b, k*2+2, (l+r)/2, r);
        return merge(L, R);
    }

    Monoid query(int a, int b){
        return query(a, b, 0, 0, n);
    }
};

//########## 例 ##########
// Range update - min (AOJ DSL_2_F)
Monoid M0 = LLINF, L0 = LLINF;
Monoid merge(Monoid a, Monoid b){ return min(a, b); }
void updateNode(int k, Monoid x){ lazy[k] = x; }
void propagate(int k, int l, int r){ dat[k] = lazy[k]; }
LazySegtree<LL> seg(n+1, (1LL<<31)-1);

// Range update - sum (AOJ DSL_2_I)
Monoid M0 = 0, L0 = LLINF;
Monoid merge(Monoid a, Monoid b){ return a + b; }
void updateNode(int k, Monoid x){ lazy[k] = x; }
void propagate(int k, int l, int r){ dat[k] = lazy[k]*(r-l); }
LazySegtree<LL> seg(n+1, 0);

// Range add - min (AOJ DSL_2_H)
Monoid M0 = LLINF, L0 = 0;
Monoid merge(Monoid a, Monoid b){ return min(a, b); }
void updateNode(int k, Monoid x){ lazy[k] += x; }
void propagate(int k, int l, int r){ dat[k] += lazy[k]; }
LazySegtree<LL> seg(n+1, 0);

// Range add - sum (AOJ DSL_2_G)
Monoid M0 = 0, L0 = 0;
Monoid merge(Monoid a, Monoid b){ return a + b; }
void updateNode(int k, Monoid x){ lazy[k] += x; }
void propagate(int k, int l, int r){ dat[k] += lazy[k]*(r-l); }
LazySegtree<LL> seg(n+1, 0);
