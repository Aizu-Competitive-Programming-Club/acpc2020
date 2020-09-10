#include "/Users/admin/Programming/CompProg/Library/cpp-library/geometry.hpp"
using namespace geometry;
using namespace std;

int main() {
    constexpr real_number xy_inf = 1000001.0;

    int n, m;
    cin >> n >> m;

    polygon ps(n);
    for (auto &p: ps) cin >> p;

    {
        assert(is_convex(ps));
    }

    // origami part
    polygons polys({ps});
    for (int i = 0; i < m; ++i) {
        polygons new_polys;
        
        point p, q;
        cin >> p >> q;

        for (auto &poly: polys) {
            
            { // left side
                polygon l = convex_cut(poly, line(p, q));

                if (l.size() > 2) {
                    for (point &v: l) {
                        v = reflection(line(p, q), v);
                    }
                    new_polys.emplace_back(l);
                }
            }

            { // right side
                polygon r = convex_cut(poly, line(q, p));

                if (r.size() > 2) {
                    new_polys.emplace_back(r);
                }
            }

            polys = new_polys;
        }
    } // origami end

    // cross point
    // V = N + 2^M, O(V^2 * log V) ? 
    vector< real_number > xs;
    for (int idx2 = 0; idx2 < (int)polys.size(); ++idx2) {
        const polygon &p2 = polys[idx2];
        int n2 = p2.size();

        for (int idx1 = 0; idx1 < idx2; ++idx1) {
            const polygon &p1 = polys[idx1];
            int n1 = p1.size();

            for (int i = 0; i < n1; ++i) { // poly[idx1]'s segment
                int ni = (i + 1) % n1;
                segment s1(p1[i], p1[ni]);

                for (int j = 0; j < n2; ++j) { // poly[idx2]'s segment
                    int nj = (j + 1) % n2;
                    segment s2(p2[j], p2[nj]);

                    if ( !is_intersect(s1, s2) ) continue;

                    xs.emplace_back(cross_point(s1, s2).real());
                }
            }
        }
    }

    for (const auto &poly: polys) {
        for (const auto &p: poly) {
            xs.emplace_back(p.real());
        }
    }

    { // compless xs
        sort(xs.begin(), xs.end());
        vector< real_number > old_xs = xs;
        int idx = 1;
        for (int i = 1; i < (int)old_xs.size(); ++i) {
            if (is_equal(xs[i - 1], xs[i])) continue;
            xs[idx++] = old_xs[i];
        }

        xs.resize(idx);
    }

    vector< real_number > anss(1 << m);
    for (int i = 1; i < xs.size(); ++i) {
        real_number l = xs[i - 1], r = xs[i];

        point ld(l, -xy_inf), lu(l, xy_inf);
        point rd(r, -xy_inf), ru(r, xy_inf);

        segment sl(ld, lu);
        segment sr(rd, ru);

        vector< real_number > ls, rs;

        ls.emplace_back(-xy_inf);
        rs.emplace_back(-xy_inf);

        for (const auto &poly: polys) {
            for (int j = 0; j < (int)poly.size(); ++j) {
                segment s(poly[j], poly[(j + 1) % poly.size()]);
                if ( !is_intersect(s, sl) ) continue;
                if ( !is_intersect(s, sr) ) continue;

                ls.emplace_back(cross_point(s, sl).imag());
                rs.emplace_back(cross_point(s, sr).imag());
            }
        }

        ls.emplace_back(xy_inf);
        rs.emplace_back(xy_inf);

        sort(ls.begin(), ls.end());
        sort(rs.begin(), rs.end());

        for (int j = 1; j < ls.size(); ++j) {
            point p1(l, ls[j]);
            point p2(r, rs[j]);
            point p3;

            if ( !is_equal(ls[j - 1], ls[j]) ) {
                p3 = point(l, ls[j - 1]);
            } else {
                p3 = point(r, rs[j - 1]);
            }

            real_number k = 1.0 / 3.0;
            point g = k * (p1 + p2 + p3);

            real_number S = (ls[j] - ls[j - 1] + rs[j] - rs[j - 1]) * (xs[i] - xs[i - 1]) / 2.0;
            int cnt = 0;
            for (const auto &poly: polys) {
                if (contains(poly, g) == 2) {
                    cnt++;
                }
            }

            if (cnt == 0) continue;
            anss[cnt - 1] += S;
        }
    }

    cout << fixed << setprecision(15);
    for (auto &ans: anss) {
        cout << ans << endl;
    }

    { // debug

        real_number S = 0;
        for (int i = 0; i < (int)anss.size(); ++i) {
            S += (i + 1) * anss[i];
        }
        real_number sample = 24.545862697754065 + 2 * 10.102028899903089;

        cerr << "area ps  : " << area(ps) << endl;
        cerr << "area ans : " << S << endl;
        cerr << "sample4  : " << sample << endl;
    }
}


