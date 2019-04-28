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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    string ans = "";
    int l=0, r=n-1, now = 0;
    while(now < a[l] || now < a[r]){
        if(a[l] == a[r]){
            int tmpl = 0, tmpr = 0;
            while(a[l+tmpl] < a[l+tmpl+1]) tmpl++;
            while(a[r-tmpr] < a[r-tmpr-1]) tmpr++;
            if(tmpl > tmpr){
                rep(j, tmpl+1) ans += "L";
            }else{
                rep(j, tmpr+1) ans += "R";
            }
            break;
        }else{
            if(a[l] < a[r] && now < a[l]){
                ans += "L";
                now = a[l];
                l++;
            }else if(now < a[r]){
                ans += "R";
                now = a[r];
                r--;
            }else{
                ans += "L";
                now = a[l];
                l++;
            }
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
}