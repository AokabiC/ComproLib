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


# :warning: lib/graph/dinic.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-12 00:34:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 最大流
template<typename flow_t>
struct Dinic{
    const flow_t INF_flow_t = INF;   // WRITE HERE

    struct edge{
        int to;
        flow_t cap;
        int rev;
    };
    using WeightedGraph = vector<vector<edge>>;
    int V;
    WeightedGraph G;
    vector<int> itr, level;

    Dinic(int V) : V(V) { G.assign(V, vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge){from, 0, (int)G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for(auto &&e: G[v]){
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    flow_t dfs(int v, int t, flow_t f) {
        if(v == t) return f;
        for(int &i = itr[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                flow_t d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t res = 0, f;
        while(bfs(s), level[t] >= 0) {
            itr.assign(V, 0);
            while((f = dfs(s, t, INF_flow_t)) > 0) res += f;
        }
        return res;
    }
};

// 最小流量制限付き最大流
// 各辺に[lb, ub]の容量の辺を張る
template<typename flow_t>
struct DinicWithLowerBound{
    Dinic<flow_t> flow;
    int S, T;
    flow_t sum_lb;

    DinicWithLowerBound(int V) : flow(V+2), S(V), T(V+1), sum_lb(0) {}

    void add_edge(int from, int to, flow_t lb, flow_t ub) {
        flow.add_edge(from, to, ub-lb);
        flow.add_edge(S, to, lb);
        flow.add_edge(from, T, lb);
        sum_lb += lb;
    }

    flow_t max_flow(int s, int t) {
        auto a = flow.max_flow(S, T);
        auto b = flow.max_flow(s, T);
        auto c = flow.max_flow(S, t);
        auto d = flow.max_flow(s, t);
        return (b == c && a + b == sum_lb) ? b+d : -1;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/dinic.cpp"
// 最大流
template<typename flow_t>
struct Dinic{
    const flow_t INF_flow_t = INF;   // WRITE HERE

    struct edge{
        int to;
        flow_t cap;
        int rev;
    };
    using WeightedGraph = vector<vector<edge>>;
    int V;
    WeightedGraph G;
    vector<int> itr, level;

    Dinic(int V) : V(V) { G.assign(V, vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge){from, 0, (int)G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for(auto &&e: G[v]){
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    flow_t dfs(int v, int t, flow_t f) {
        if(v == t) return f;
        for(int &i = itr[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                flow_t d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t res = 0, f;
        while(bfs(s), level[t] >= 0) {
            itr.assign(V, 0);
            while((f = dfs(s, t, INF_flow_t)) > 0) res += f;
        }
        return res;
    }
};

// 最小流量制限付き最大流
// 各辺に[lb, ub]の容量の辺を張る
template<typename flow_t>
struct DinicWithLowerBound{
    Dinic<flow_t> flow;
    int S, T;
    flow_t sum_lb;

    DinicWithLowerBound(int V) : flow(V+2), S(V), T(V+1), sum_lb(0) {}

    void add_edge(int from, int to, flow_t lb, flow_t ub) {
        flow.add_edge(from, to, ub-lb);
        flow.add_edge(S, to, lb);
        flow.add_edge(from, T, lb);
        sum_lb += lb;
    }

    flow_t max_flow(int s, int t) {
        auto a = flow.max_flow(S, T);
        auto b = flow.max_flow(s, T);
        auto c = flow.max_flow(S, t);
        auto d = flow.max_flow(s, t);
        return (b == c && a + b == sum_lb) ? b+d : -1;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

