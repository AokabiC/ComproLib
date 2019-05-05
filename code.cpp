#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n);i++)
#define rep1(i,n) for(int i=1; i<(n); i++)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
using namespace std;
using LL = long long;
const int INF = 1e9;
const LL LLINF = 1e16;
const int mod = 1e9+7;


int main(){
    int n;
    cin >> n;
    WeightedGraph G(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back((edge){a, b, 1});
        G[b].push_back((edge){b, a, 1});
    }
    int grundy = (tree_diameter(G)+2) % 3;
    cout << (grundy==0 ? "Second" : "First") << endl;

}