map<LL, int> prime_factor(LL n) {
    map< LL, int > ret;
    for(LL i=2; i*i<=n; i++){
        while(n%i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return res;
}