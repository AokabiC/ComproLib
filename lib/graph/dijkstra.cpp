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