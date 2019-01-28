struct UnionFind{
    vector<int> data;

    UnionFind(int sz){
        data.assign(sz, -1);
    }

    bool unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return(false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return(true);
    }

    int find(int k){
        if(data[k] < 0) return(k);
        return(data[k] = find(data[k]));
    }

    int size(int k){
        return(-data[find(k)]);
    }
};

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