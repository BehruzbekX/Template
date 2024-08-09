//Fenwick<T> a(vector<T> arr);
//Fenwick<T> a(n);

template<typename T> struct Fenwick {
    vector<T> bit;
    int n;
    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    Fenwick(vector<T> const &a) : Fenwick(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
    T sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};