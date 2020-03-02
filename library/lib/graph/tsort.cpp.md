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


# :warning: lib/graph/tsort.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/tsort.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-12 00:34:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct edge{
    int to, cost;
};
using WeightedGraph = vector<vector<edge>>;

vector<int> tsort(WeightedGraph &G){
    vector<int> tsorted;
    vector<int> used(G.size(), 0);
    bool f = false;
    function<void(int)> dfs = [&](int u){
        if(used[u] > 0){
            if(used[u] == 1) f = true;
            return;
        }
        used[u] = 1;
        for(auto &e : G[u]) dfs(e.to);
        used[u] = 2;
        tsorted.pb(u);
    };
    rep(i, G.size()) dfs(i);
    if(f){
        // 閉路が存在
        return vector<int>();
    }
    reverse(all(tsorted));
    return tsorted;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/tsort.cpp"
struct edge{
    int to, cost;
};
using WeightedGraph = vector<vector<edge>>;

vector<int> tsort(WeightedGraph &G){
    vector<int> tsorted;
    vector<int> used(G.size(), 0);
    bool f = false;
    function<void(int)> dfs = [&](int u){
        if(used[u] > 0){
            if(used[u] == 1) f = true;
            return;
        }
        used[u] = 1;
        for(auto &e : G[u]) dfs(e.to);
        used[u] = 2;
        tsorted.pb(u);
    };
    rep(i, G.size()) dfs(i);
    if(f){
        // 閉路が存在
        return vector<int>();
    }
    reverse(all(tsorted));
    return tsorted;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

