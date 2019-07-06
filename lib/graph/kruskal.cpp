// UnionFindが必要

struct edge{
    int src, to, cost;
};
using Edges = vector<edge>;

int kruskal(Edges &E, int V)
{
    sort(all(E), [](const edge &a, const edge &b)
    {
        return (a.cost < b.cost);
    });
    UnionFind tree(V);
    int res = 0;
    for(auto &e : E) {
        if(tree.unite(e.src, e.to)) res += e.cost;
    }
    return (res);
}