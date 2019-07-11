// 最大流
template<typename flow_t>
struct Dinic{
    const flow_t INF_flow_t = INF;   // WRITE HERE

    struct edge{
        int to;
        flow_t cap;
        int rev;
    };
    using WeightedGraph = vector<vector<edge>>;
    int V;
    WeightedGraph G;
    vector<int> itr, level;

    Dinic(int V) : V(V) { G.assign(V, vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge){to, cap, (int)G[to].size()});
        G[to].push_back((edge){from, 0, (int)G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for(auto &&e: G[v]){
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    flow_t dfs(int v, int t, flow_t f) {
        if(v == t) return f;
        for(int &i = itr[v]; i < (int)G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                flow_t d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t res = 0, f;
        while(bfs(s), level[t] >= 0) {
            itr.assign(V, 0);
            while((f = dfs(s, t, INF_flow_t)) > 0) res += f;
        }
        return res;
    }
};

// 最小流量制限付き最大流
// 各辺に[lb, ub]の容量の辺を張る
template<typename flow_t>
struct DinicWithLowerBound{
    Dinic<flow_t> flow;
    int S, T;
    flow_t sum_lb;

    DinicWithLowerBound(int V) : flow(V+2), S(V), T(V+1), sum_lb(0) {}

    void add_edge(int from, int to, flow_t lb, flow_t ub) {
        flow.add_edge(from, to, ub-lb);
        flow.add_edge(S, to, lb);
        flow.add_edge(from, T, lb);
        sum_lb += lb;
    }

    flow_t max_flow(int s, int t) {
        auto a = flow.max_flow(S, T);
        auto b = flow.max_flow(s, T);
        auto c = flow.max_flow(S, t);
        auto d = flow.max_flow(s, t);
        return (b == c && a + b == sum_lb) ? b+d : -1;
    }
};