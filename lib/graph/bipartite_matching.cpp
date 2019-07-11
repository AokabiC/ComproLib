// from うしさんのライブラリ
struct BipartiteMatching {
    using Graph = vector<vector<int>>;
    Graph G;
    vector<int> match, alive, used;
    int timestamp;

    BipartiteMatching(int n) : G(n), alive(n, 1), used(n, 0), match(n, -1), timestamp(0) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int dfs(int idx) {
        used[idx] = timestamp;
        for(auto &&to : G[idx]) {
            int w = match[to];
            if(alive[to] == 0) continue;
            if(w < 0 || (used[w] != timestamp && dfs(w))) {
                match[idx] = to;
                match[to] = idx;
                return 1;
            }
        }
        return 0;
    }

    int bipartite_matching() {
        int res = 0;
        for(int i = 0; i < G.size(); i++) {
            if(alive[i] == 0) continue;
            if(match[i] == -1) {
                ++timestamp;
                res += dfs(i);
            }
        }
        return res;
    }

     void output() {
        for(int i = 0; i < G.size(); i++) {
            if(i < match[i]) {
                cout << i << "-" << match[i] << endl;
            }
        }
    }
};