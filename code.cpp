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

int main(){

    cin >> n;
    vector<int> a = {3, 1, 4, 1, 5};
    rep(i, n) cout << a[i] << endl;

    sort(a.begin(), a.end());

    rep(i, n) cout << a[i] << endl;
}