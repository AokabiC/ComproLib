struct UnionFind{
    vector<int> dat;

    UnionFind(int sz){
        dat.assign(sz, -1);
    }

    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return(false);
        if(dat[x] > dat[y]) swap(x, y);
        dat[x] += dat[y];
        dat[y] = x;
        return(true);
    }

    int root(int k){
        if(dat[k] < 0) return(k);
        return(dat[k] = root(dat[k]));
    }

    int size(int k){
        return(-dat[root(k)]);
    }
};