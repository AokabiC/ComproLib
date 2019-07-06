/*
!) 0-indexed
!) [a, b)に対する演算
!) merge, updateNodeを書く
*/
template<typename Monoid>
struct Segtree{
    int n;
    vector<Monoid> dat;
    Monoid m0; // データの初期化値
    Segtree(int sz, Monoid m0) : m0(m0){
        n = 1;
        while(n < sz) n *= 2;
        dat.assign(2*n-1, m0);
    }

    Monoid merge(Monoid a, Monoid b) // 区間をマージする二項演算
    void updateNode(int k, Monoid x) // 区間を操作する二項演算

    void update(int k, Monoid x){
        k += n-1;
        updateNode(k, x);
        while(k > 0) {
            k = (k-1)/2;
            dat[k] = merge(dat[k*2+1], dat[k*2+2]);
        }
    }
    Monoid query(int a, int b){
        Monoid L = m0, R = m0;
        int A = a+n-1;
        int B = b+n-1;
        while(A < B) {
            if((A&1) == 0) L = merge(L, dat[A++]);
            if((B&1) == 0) R = merge(dat[--B], R);
            A >>= 1;
            B >>= 1;
        }
        return merge(L, R);
    }
    Monoid operator[](const int &k) const { return dat[k+n-1]; }
};

//########## 例 ##########
// Range min (AOJ DSL_2_A)
Monoid merge(Monoid a, Monoid b){ return min(a,b); }
void updateNode(int k, Monoid x){ dat[k] = x; }
Segtree<LL> a(n, (1LL<<31)-1);

// Range add (AOJ DSL_2_B)
Monoid merge(Monoid a, Monoid b){ return a + b; }
void updateNode(int k, Monoid x){ dat[k] += x; }
Segtree<LL> a(n, 0);