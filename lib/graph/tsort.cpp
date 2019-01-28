struct edge
{
  int src, to, cost;
};
using Edges = vector<edge>;
using WeightedGraph = vector<Edges>;

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