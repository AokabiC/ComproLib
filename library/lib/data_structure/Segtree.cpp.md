---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: lib/data_structure/Segtree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cf1c0d6ca83608d6888653791580480b">lib/data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/data_structure/Segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-02 21:40:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
!) 0-indexed
!) [a, b)に対する演算
!) merge, updateNodeを書く
*/
template<typename Monoid>
struct Segtree{
  private:
    int n;
    vector<Monoid> dat;
    Monoid m0; // データの初期化値

    Monoid merge(Monoid a, Monoid b){ return ; }    // 区間をマージする二項演算
    void updateNode(int k, Monoid x){ dat[k] = ; }  // 区間を操作する二項演算

  public:
    Segtree(int sz, Monoid m0) : m0(m0){
        n = 1;
        while(n < sz) n *= 2;
        dat.assign(2*n-1, m0);
    }

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/data_structure/Segtree.cpp"
/*
!) 0-indexed
!) [a, b)に対する演算
!) merge, updateNodeを書く
*/
template<typename Monoid>
struct Segtree{
  private:
    int n;
    vector<Monoid> dat;
    Monoid m0; // データの初期化値

    Monoid merge(Monoid a, Monoid b){ return ; }    // 区間をマージする二項演算
    void updateNode(int k, Monoid x){ dat[k] = ; }  // 区間を操作する二項演算

  public:
    Segtree(int sz, Monoid m0) : m0(m0){
        n = 1;
        while(n < sz) n *= 2;
        dat.assign(2*n-1, m0);
    }

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

