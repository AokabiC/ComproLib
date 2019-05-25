// [i-k, i]の最小値を格納したvectorを返す
vector<int> slide_min(vector<int> &a, int k){
    deque<int> deq;
    vector<int> b;
    rep(i, a.size()){
        // maxはここの不等号の向きを変える
        while(!deq.empty() && a[deq.back()] >= a[i]) deq.pop_back();
        deq.push_back(i);
        b.push_back(a[deq.front()]);
        if(i-k+1 >= 0 && deq.front() == i-k+1) deq.pop_front();
    }
    return b;
}

