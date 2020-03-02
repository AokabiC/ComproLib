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


# :warning: lib/graph/bellman_ford.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/bellman_ford.cpp">View this file on GitHub</a>
    - Last commit date: 2019-01-28 13:50:48+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct edge{
    int src, to, cost;
};
using Edges = vector<edge>;

vector<int> bellman_ford(Edges &E, int V, int st){
    vector<int> dist(V, INF);
    dist[st] = 0;
    rep(i, V-1){
        for(auto &e: E){
            if(dist[e.src] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.src]+e.cost);
        }
    }
    for(auto &e: E){
        if(dist[e.src] == INF) continue;
        if(dist[e.to] > dist[e.src]+e.cost){
            // 負閉路が存在
            return vector<int>();
        }
    }
    return dist;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/bellman_ford.cpp"
struct edge{
    int src, to, cost;
};
using Edges = vector<edge>;

vector<int> bellman_ford(Edges &E, int V, int st){
    vector<int> dist(V, INF);
    dist[st] = 0;
    rep(i, V-1){
        for(auto &e: E){
            if(dist[e.src] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.src]+e.cost);
        }
    }
    for(auto &e: E){
        if(dist[e.src] == INF) continue;
        if(dist[e.to] > dist[e.src]+e.cost){
            // 負閉路が存在
            return vector<int>();
        }
    }
    return dist;
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

