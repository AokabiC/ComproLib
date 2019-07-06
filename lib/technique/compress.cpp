// 座標圧縮
vector<int> unzip = a;
map<int, int> zip;
sort(all(unzip));
unzip.erase(unique(all(unzip)), unzip.end());
for(int i=0; i<unzip.size(); i++) zip[unzip[i]] = i;