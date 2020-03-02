struct UnionFind {
  private:
    vector<int> data;
  public:
    UnionFind(int size) : data(size, -1) {}

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }

    int size(int x) { return -data[root(x)]; }
};
