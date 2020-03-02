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


# :warning: lib/string/RollingHash.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a48db5fb6f746df590a3d4604f6478b">lib/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/string/RollingHash.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-03 04:21:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct RollingHash {
    using T = long long;
    using hash_type = pair<T, T>;
    const T mod1 = 1000000007, mod2 = 1000000009;
    T base1, base2;
    vector<T> hash1, hash2, pow1, pow2;

    RollingHash(const string &s){
        int n = s.size();
        std::random_device rnd;
        std::mt19937 mt(rnd());
        base1 = mt()%(mod1-2)+2;
        base2 = mt()%(mod2-2)+2;

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);
        for(int i=0; i<n; i++){
            hash1[i+1] = (hash1[i]*base1+s[i])%mod1;
            hash2[i+1] = (hash2[i]*base2+s[i])%mod2;
            pow1[i+1]=pow1[i]*base1%mod1;
            pow2[i+1]=pow2[i]*base2%mod2;
        }
    }

    // [l, r)
    hash_type get(int l,int r){
        T res1 = ((hash1[r] - hash1[l]*pow1[r-l]) % mod1 + mod1) % mod1;
        T res2 = ((hash2[r] - hash2[l]*pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(res1, res2);
    }

    hash_type concat(hash_type h1, hash_type h2, int h2len) {
        T res1 = (h1.first*pow1[h2len] + h2.first) % mod1;
        T res2 = (h1.second*pow2[h2len] + h2.second) % mod2;
        return make_pair(res1, res2);
    }
    // LCPは長さで二分探索する
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/string/RollingHash.cpp"
struct RollingHash {
    using T = long long;
    using hash_type = pair<T, T>;
    const T mod1 = 1000000007, mod2 = 1000000009;
    T base1, base2;
    vector<T> hash1, hash2, pow1, pow2;

    RollingHash(const string &s){
        int n = s.size();
        std::random_device rnd;
        std::mt19937 mt(rnd());
        base1 = mt()%(mod1-2)+2;
        base2 = mt()%(mod2-2)+2;

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);
        for(int i=0; i<n; i++){
            hash1[i+1] = (hash1[i]*base1+s[i])%mod1;
            hash2[i+1] = (hash2[i]*base2+s[i])%mod2;
            pow1[i+1]=pow1[i]*base1%mod1;
            pow2[i+1]=pow2[i]*base2%mod2;
        }
    }

    // [l, r)
    hash_type get(int l,int r){
        T res1 = ((hash1[r] - hash1[l]*pow1[r-l]) % mod1 + mod1) % mod1;
        T res2 = ((hash2[r] - hash2[l]*pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(res1, res2);
    }

    hash_type concat(hash_type h1, hash_type h2, int h2len) {
        T res1 = (h1.first*pow1[h2len] + h2.first) % mod1;
        T res2 = (h1.second*pow2[h2len] + h2.second) % mod2;
        return make_pair(res1, res2);
    }
    // LCPは長さで二分探索する
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

