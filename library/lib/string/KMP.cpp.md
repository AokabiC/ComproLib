---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: lib/string/KMP.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#9a48db5fb6f746df590a3d4604f6478b">lib/string</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/string/KMP.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-12 00:34:46+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/string/KMP.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

