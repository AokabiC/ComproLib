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
