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


# :warning: lib/tree/tree_diameter.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#208ddb70230bd881aee710e79075dce4">lib/tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/tree/tree_diameter.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-12 00:34:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct edge{
    int to, cost;
};
using WeightedGraph = vector<vector<edge>>;
using pi = pair<int, int>;

pi dfs(WeightedGraph &G, int idx, int src){
    pi res(0, idx);
    for(auto &e : G[idx]) {
        if(e.to == src) continue;
        pi cost = dfs(G, e.to, idx);
        cost.first += e.cost;
        res = max(res, cost);
    }
    return res;
}

int tree_diameter(WeightedGraph &G)
{
    auto far = dfs(G, 0, -1);
    auto res = dfs(G, far.second, -1);
    return (res.first);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/tree/tree_diameter.cpp"
struct edge{
    int to, cost;
};
using WeightedGraph = vector<vector<edge>>;
using pi = pair<int, int>;

pi dfs(WeightedGraph &G, int idx, int src){
    pi res(0, idx);
    for(auto &e : G[idx]) {
        if(e.to == src) continue;
        pi cost = dfs(G, e.to, idx);
        cost.first += e.cost;
        res = max(res, cost);
    }
    return res;
}

int tree_diameter(WeightedGraph &G)
{
    auto far = dfs(G, 0, -1);
    auto res = dfs(G, far.second, -1);
    return (res.first);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

