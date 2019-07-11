// 文字列S[0,i-1]の接頭辞と接尾辞が最大何文字一致しているかを
// 記録した配列を O(|S|)で構築するアルゴリズム
vector<int> A(s.size()+1);
A[0] = -1;
int j = -1;
for (int i = 0; i < s.size(); i++) {
    while (j >= 0 && s[i] != s[j]) j = A[j];
    j++;
    A[i+1] = j;
}
