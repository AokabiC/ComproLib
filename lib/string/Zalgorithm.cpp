vector<int> A(s.size());
A[0] = s.size();
int i = 1, j = 0;
while (i < s.size()) {
    while (i+j < s.size() && s[j] == s[i+j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < s.size() && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
}
