#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
const int INF = 1e9;
const LL LLINF = 1e16;

template<int mod>
struct ModInt {
    int x;

    ModInt() : x(0) {}

    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        return ModInt(u);
    }

    friend ostream &operator<<(ostream &os, const ModInt<mod> &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt<mod> &a) {
        long long x;
        is >> x;
        a = ModInt<mod>(x);
        return (is);
    }
};
const int mod = 1e9 + 7;
using modint = ModInt< mod >;

int main(){

    cin >> n;
<<<<<<< HEAD
    vector<int> a = {3, 1, 4, 1, 5};
    rep(i, n) cout << a[i] << endl;

    sort(a.begin(), a.end());

    rep(i, n) cout << a[i] << endl;
}
=======
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n+1, 0), zero(n+1, 0);
    rep(i, n) b[i+1] = b[i] ^ a[i];
    vector<vector<int>> cmp_b(1<<20, vector<int>(1,1));

    rep1(i, n+1){
        zero[i] += zero[i-1];
        if(b[i] == 0) zero[i]++;
        else cmp_b[b[i]].push_back(i);
    }

    modint ans = 0;
    vector<vector<modint>> dp(1<<20, vector<modint>(2, 0));
    rep(i, 1<<20){
        if(cmp_b[i].size() == 1) continue;
        dp[i][0] = 1; dp[i][1] = 0;
        rep1(j, cmp_b[i].size() - 1){
            int z = zero[cmp_b[i][j]] - zero[cmp_b[i][j-1]];
            dp[i][0] += dp[i][1] * z;
            else dp[i][1] += dp[i][0];
            // cout << z << " " << dp[i][0] << " " << dp[i][1] << endl;
        }
        if(b[n] == 0){
            
    }

    if(b[n] == 0){
        ans = 1;
        rep(i, zero[n]-1) ans *= 2;
        rep1(i, 1<<20) ans += dp[i][0];
    }else{
        // n-1マス目で 0 -> n マス目でb[n] … dp[b[n]][0]と同じ
        ans += dp[b[n]][1];
    }
    cout << ans << endl;

}
>>>>>>> a3d935f7e1674ccf91338d9065c811f3ae07c57d
