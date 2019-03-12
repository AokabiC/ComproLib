/*
!) 0-indexed
!) [a, b)に対する演算
!) m0に単位元, func(a, b)に区間をマージするときに行う二項演算を書く
*/
template<typename Monoid>
struct Segtree{
    int n;
    vector<Monoid> dat;
    Monoid m0;
    Segtree(int sz, Monoid m0) : m0(m0){
        n = 1;
        while(n < sz) n *= 2;
        dat.assign(2*n-1, m0);
    }

    Monoid func(Monoid a, Monoid b){
        // ##### WRITE HERE #####
        return
    }

    void set(int k, Monoid a){
        k += n-1;
        dat[k] = a;
    }
    void build() {
        for(int i = n-2; i >= 0; i--){
            dat[i] = func(dat[2*i+1], dat[2*i+2]);
        }
    }
    void update(int k, Monoid a){
        k += n-1;
        dat[k] = a;
        while(k > 0) {
            k = (k-1)/2;
            dat[k] = func(dat[k*2+1], dat[k*2+2]);
        }
    }
    Monoid query(int a, int b){
        Monoid L = m0, R = m0;
        int A = a+n-1;
        int B = b+n-1;
        while(A < B) {
            if((A&1) == 0) L = func(L, dat[A++]);
            if((B&1) == 0) R = func(dat[--B], R);
            A >>= 1;
            B >>= 1;
        }
        return func(L, R);
    }
    Monoid operator[](const int &k) const { return dat[k+n-1]; }
};
