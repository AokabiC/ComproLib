struct edge{
    int src, to, cost;
};
using Edges = vector<edge>;
using WeightedGraph = vector<Edges>;
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