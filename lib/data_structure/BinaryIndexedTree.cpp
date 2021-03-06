template< class T >
struct BinaryIndexedTree {
    vector< T > dat;

    BinaryIndexedTree(int sz) {
        dat.assign(++sz, 0);
    }

    T sum(int k){
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return ret;
    }

    void add(int k, T x){
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};


