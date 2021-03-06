struct RollingHash {
    using T = long long;
    using hash_type = pair<T, T>;
    const T mod1 = 1000000007, mod2 = 1000000009;
    T base1, base2;
    vector<T> hash1, hash2, pow1, pow2;

    RollingHash(const string &s){
        int n = s.size();
        std::random_device rnd;
        std::mt19937 mt(rnd());
        base1 = mt()%(mod1-2)+2;
        base2 = mt()%(mod2-2)+2;

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);
        for(int i=0; i<n; i++){
            hash1[i+1] = (hash1[i]*base1+s[i])%mod1;
            hash2[i+1] = (hash2[i]*base2+s[i])%mod2;
            pow1[i+1]=pow1[i]*base1%mod1;
            pow2[i+1]=pow2[i]*base2%mod2;
        }
    }

    // [l, r)
    hash_type get(int l,int r){
        T res1 = ((hash1[r] - hash1[l]*pow1[r-l]) % mod1 + mod1) % mod1;
        T res2 = ((hash2[r] - hash2[l]*pow2[r-l]) % mod2 + mod2) % mod2;
        return make_pair(res1, res2);
    }

    hash_type concat(hash_type h1, hash_type h2, int h2len) {
        T res1 = (h1.first*pow1[h2len] + h2.first) % mod1;
        T res2 = (h1.second*pow2[h2len] + h2.second) % mod2;
        return make_pair(res1, res2);
    }
    // LCPは長さで二分探索する
};