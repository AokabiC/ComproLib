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


# :warning: lib/data_structure/UnionFind.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cf1c0d6ca83608d6888653791580480b">lib/data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/data_structure/UnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-02 21:40:30+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
  private:
    vector<int> data;
  public:
    UnionFind(int size) : data(size, -1) {}

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }

    int size(int x) { return -data[root(x)]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/data_structure/UnionFind.cpp"
struct UnionFind {
  private:
    vector<int> data;
  public:
    UnionFind(int size) : data(size, -1) {}

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }

    int size(int x) { return -data[root(x)]; }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

