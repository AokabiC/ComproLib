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

