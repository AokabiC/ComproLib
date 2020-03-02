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


# :warning: lib/graph/grid_bfs.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6e267a37887a7dcb68cbf7008d6c7e48">lib/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/graph/grid_bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-05 15:08:10+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int W, H;
vector<vector<char>> s;
vector<vector<int>> cost;
int bfs(){
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    cost[0][0] = 0;

    while(!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        if(p == make_pair(H-1, W-1)){
            // ゴールに到達
            return cost[p.first][p.second];
        }
        for(int i = 0; i < 4; i++) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if(s[ny][nx] == '#') continue;
            if(cost[ny][nx] != -1) continue;

            cost[ny][nx] = cost[p.first][p.second] + 1;
            que.push(make_pair(ny, nx));
        }
    }
    return -1;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/graph/grid_bfs.cpp"
int W, H;
vector<vector<char>> s;
vector<vector<int>> cost;
int bfs(){
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    cost[0][0] = 0;

    while(!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        if(p == make_pair(H-1, W-1)){
            // ゴールに到達
            return cost[p.first][p.second];
        }
        for(int i = 0; i < 4; i++) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if(s[ny][nx] == '#') continue;
            if(cost[ny][nx] != -1) continue;

            cost[ny][nx] = cost[p.first][p.second] + 1;
            que.push(make_pair(ny, nx));
        }
    }
    return -1;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

