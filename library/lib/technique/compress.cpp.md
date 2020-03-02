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


# :warning: lib/technique/compress.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#c28ebdb8b02bd1fb16be7a48d63d1e9e">lib/technique</a>
* <a href="{{ site.github.repository_url }}/blob/master/lib/technique/compress.cpp">View this file on GitHub</a>
    - Last commit date: 2019-07-07 05:12:51+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 座標圧縮
vector<int> unzip = a;
map<int, int> zip;
sort(all(unzip));
unzip.erase(unique(all(unzip)), unzip.end());
for(int i=0; i<unzip.size(); i++) zip[unzip[i]] = i;
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "lib/technique/compress.cpp"
// 座標圧縮
vector<int> unzip = a;
map<int, int> zip;
sort(all(unzip));
unzip.erase(unique(all(unzip)), unzip.end());
for(int i=0; i<unzip.size(); i++) zip[unzip[i]] = i;

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

