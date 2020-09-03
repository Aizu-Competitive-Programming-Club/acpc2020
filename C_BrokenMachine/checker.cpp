#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <numeric>
#include "testlib.h"
#include "params.h"

#include <iostream>

using ll = int64_t;
using namespace std;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();

    int m = ouf.readInt(M_MIN, M_MAX);
    
    vector<bool> has_in(n, false);
    vector<vector<int>> edges(n, vector<int>{});
    for (int i = 0; i < m; i++){
        int v = ouf.readInt(1, n) - 1;
        int w = ouf.readInt(1, n) - 1;
        if (v >= w) quitf(_wa, "edge should v < w");
        edges[v].push_back(w);
        has_in[w] = true;
    }
    if (!ouf.seekEof())
        quitf(_wa, "Participant output contains extra tokens");

    vector<ll> init_values(n);
    for (int i = 0; i < n; i++){
        init_values[i] = has_in[i] ? 0 : 1;
    }

    set<int> cands{};
    for (int broken = 0; broken < n; broken++){
        vector<ll> values = init_values;
        for (int node = 0; node < n; node++){
            ll nextValue = broken == node ? values[node] * 2 : values[node];
            for (auto adj : edges[node]){
                values[adj] = (values[adj] + nextValue) % (ll(1) << 32);
            }
        }
        cands.insert(values[n - 1]);
    }

    if (((int)cands.size()) < n) quitf(_wa, "there is same possible outcome");

   quitf(_ok, "OK");
}
