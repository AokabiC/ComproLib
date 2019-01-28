void warshall_floyd(vector<vector<int>> &G){
    int V = G.size();
    rep(k, V)rep(i, V)rep(j, V){
        if(G[i][k] == INF || G[k][j] == INF) continue;
        G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
    }
    // G[i][i] < 0が存在 <=> 負閉路が存在
}