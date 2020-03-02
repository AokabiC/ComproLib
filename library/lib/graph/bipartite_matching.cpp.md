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


# :warning: lib/graph/bipartite_matching.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/bipartite_matching.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-12 01:49:23+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// from うしさんのライブラリ
struct BipartiteMatching {
    using Graph = vector<vector<int>>;
    Graph G;
    vector<int> match, alive, used;
    int timestamp;

    BipartiteMatching(int n) : G(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int dfs(int idx) {
        used[idx] = timestamp;
        for(auto &&to : G[idx]) {
            int w = match[to];
            if(alive[to] == 0) continue;
            if(w < 0 || (used[w] != timestamp && dfs(w))) {
                match[idx] = to;
                match[to] = idx;
                return 1;
            }
        }
        return 0;
    }

    int bipartite_matching() {
        int res = 0;
        for(int i = 0; i < G.size(); i++) {
            if(alive[i] == 0) continue;
            if(match[i] == -1) {
                ++timestamp;
                res += dfs(i);
            }
        }
        return res;
    }

     void output() {
        for(int i = 0; i < G.size(); i++) {
            if(i < match[i]) {
                cout << i << "-" << match[i] << endl;
            }
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/bipartite_matching.cpp"
// from うしさんのライブラリ
struct BipartiteMatching {
    using Graph = vector<vector<int>>;
    Graph G;
    vector<int> match, alive, used;
    int timestamp;

    BipartiteMatching(int n) : G(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int dfs(int idx) {
        used[idx] = timestamp;
        for(auto &&to : G[idx]) {
            int w = match[to];
            if(alive[to] == 0) continue;
            if(w < 0 || (used[w] != timestamp && dfs(w))) {
                match[idx] = to;
                match[to] = idx;
                return 1;
            }
        }
        return 0;
    }

    int bipartite_matching() {
        int res = 0;
        for(int i = 0; i < G.size(); i++) {
            if(alive[i] == 0) continue;
            if(match[i] == -1) {
                ++timestamp;
                res += dfs(i);
            }
        }
        return res;
    }

     void output() {
        for(int i = 0; i < G.size(); i++) {
            if(i < match[i]) {
                cout << i << "-" << match[i] << endl;
            }
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

