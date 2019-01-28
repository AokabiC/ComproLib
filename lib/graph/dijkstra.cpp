struct edge{
    int src, to, cost;
};
using Edges = vector<edge>;
using WeightedGraph = vector<Edges>;

vector<int> dijkstra(WeightedGraph &G, int st){
    vector<int> dist(G.size(), INF);
    using pi = pair<int, int>;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    dist[st] = 0;
    q.push(mp(dist[st], st));
    while(!q.empty()){
        int cost, idx;
        tie(cost, idx) = q.top(); q.pop();
        if(dist[idx] < cost) continue;
        for(auto &e: G[idx]){
            if(dist[e.to] <= cost+e.cost) continue;
            dist[e.to] = cost+e.cost;
            q.push(mp(dist[e.to], e.to));
        }
    }
    return dist;
}