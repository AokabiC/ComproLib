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


# :warning: lib/data_structure/BinaryIndexedTree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cf1c0d6ca83608d6888653791580480b">lib/data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/data_structure/BinaryIndexedTree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-07 05:12:51+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template< class T >
struct BinaryIndexedTree {
    vector< T > dat;

    BinaryIndexedTree(int sz) {
        dat.assign(++sz, 0);
    }

    T sum(int k){
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return ret;
    }

    void add(int k, T x){
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};



```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/data_structure/BinaryIndexedTree.cpp"
template< class T >
struct BinaryIndexedTree {
    vector< T > dat;

    BinaryIndexedTree(int sz) {
        dat.assign(++sz, 0);
    }

    T sum(int k){
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return ret;
    }

    void add(int k, T x){
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};



```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

