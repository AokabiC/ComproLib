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


# :warning: lib/graph/dijkstra.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-12 00:34:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct edge{
    int to, cost;
};
using WeightedGraph = vector<vector<edge>>;

vector<int> dijkstra(WeightedGraph &G, int st){
    vector<int> dist(G.size(), INF);
    using pi = pair<int, int>;
    priority_queue<pi, vector<pi>, greater<pi>> que;
    dist[st] = 0;
    que.push(mp(dist[st], st));
    while(!que.empty()){
        int cost, idx;
        tie(cost, idx) = que.top(); que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e: G[idx]){
            if(dist[e.to] <= cost+e.cost) continue;
            dist[e.to] = cost+e.cost;
            que.push(mp(dist[e.to], e.to));
        }
    }
    return dist;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/dijkstra.cpp"
struct edge{
    int to, cost;
};
using WeightedGraph = vector<vector<edge>>;

vector<int> dijkstra(WeightedGraph &G, int st){
    vector<int> dist(G.size(), INF);
    using pi = pair<int, int>;
    priority_queue<pi, vector<pi>, greater<pi>> que;
    dist[st] = 0;
    que.push(mp(dist[st], st));
    while(!que.empty()){
        int cost, idx;
        tie(cost, idx) = que.top(); que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e: G[idx]){
            if(dist[e.to] <= cost+e.cost) continue;
            dist[e.to] = cost+e.cost;
            que.push(mp(dist[e.to], e.to));
        }
    }
    return dist;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

