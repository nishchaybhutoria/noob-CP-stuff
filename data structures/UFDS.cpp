struct UFDS {
    // Uses path compression
    // UFDS U(n);
    
    std::vector <int> sz, par;

    UFDS (int N) {
        sz.assign(N, 1);
        par.resize(N);
        iota(par.begin(), par.end(), 0);
    }

    int get(int x) {
        return x == par[x] ? x : par[x] = get(par[x]);
    }

    bool same_set(int x, int y) {
        return (get(x) == get(y));
    }

    void unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return;
        if (sz[x] > sz[y]) std::swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
    }

    int get_size(int x) {
        return sz[get(x)];
    }
};
