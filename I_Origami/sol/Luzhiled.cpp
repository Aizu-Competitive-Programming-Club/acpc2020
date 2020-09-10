#include <bits/stdc++.h>

// basis
namespace geometry {
    using real_number = long double;

    constexpr real_number eps = 1e-8;
    constexpr real_number pi = acos(-1);

    real_number radian_to_degree(real_number r);
    real_number degree_to_radian(real_number d);

    inline int sign(real_number x) {
        if (x < -eps) return -1;
        if (x > +eps) return +1;
        return 0;
    }

    inline bool is_equal(real_number r1, real_number r2) {
        return sign(r1 - r2) == 0;
    }
}

// point
namespace geometry {
    using point = std::complex< real_number >;
    using points = std::vector< point >;

    point operator*(const point &p, const real_number &k) {
        return point(p.real() * k, p.imag() * k);
    }

    std::istream &operator>>(std::istream &is, point &p) {
        real_number x, y;
        is >> x >> y;
        p = point(x, y);
        return is;
    }

    std::ostream &operator<<(std::ostream &os, point &p) {
        return os << p.real() << " " << p.imag(); 
    }

    point rotate(real_number theta, const point &p);
}

namespace std {
    bool operator<(const geometry::point &a, const geometry::point &b) {
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    }
}

// polygon
namespace geometry {
    using polygon = std::vector< point >;
    using polygons = std::vector< polygon >;
}

// line 
namespace geometry {
    struct line {
        point a, b;

        line() = default;
        line(point a, point b) : a(a), b(b) {}
    };

    using lines = std::vector< line >;
}

// segment
namespace geometry {
    struct segment : line {
        segment() = default;
        using line::line;
    };

    using segments = std::vector< segment >;
}

// circle
namespace geometry {
    struct circle {
        point p;
        real_number r;
        circle(point p, real_number r) : p(p), r(r) {}
    };

    using circles = std::vector< circle >;
}

namespace geometry {
    real_number get_angle(const point &a, const point &b, const point &c);

    real_number cross(const point &a, const point &b) {
        return a.real() * b.imag() - a.imag() * b.real();
    }

    real_number dot(const point &a, const point &b) {
        return a.real() * b.real() + a.imag() * b.imag();
    }
}

// ccw
namespace geometry {
    constexpr int COUNTER_CLOCKWISE = +1;
    constexpr int CLOCKWISE         = -1;
    constexpr int ONLINE_BACK       = +2; // c-a-b
    constexpr int ONLINE_FRONT      = -2; // a-b-c
    constexpr int ON_SEGMENT        =  0; // a-c-b
    int ccw(const point &a, point b, point c) {
        b = b - a, c = c - a;
        if (sign(cross(b, c)) == +1) return COUNTER_CLOCKWISE;
        // if (cross(b, c) >  eps) return COUNTER_CLOCKWISE;
        if (sign(cross(b, c)) == -1) return CLOCKWISE;
        // if (cross(b, c) < -eps) return CLOCKWISE;
        if (dot(b, c) < 0) return ONLINE_BACK;
        if (norm(b) < norm(c)) return ONLINE_FRONT;
        return ON_SEGMENT;
    }

}

// projection and reflection
namespace geometry {
    point projection(const line &l, const point &p) {
        real_number t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
        return l.a + (l.a - l.b) * t;
    }

    point reflection(const line &l, const point &p) {
        return p + (projection(l, p) - p) * 2;
    }
}

// parallel and orthogonal
namespace geometry {
    // is???
    bool is_parallel(const line &l1, const line &l2) {
        return is_equal(cross(l1.b - l1.a, l2.b - l2.a), 0);
    }

    // is???
    bool is_orthogonal(const line &l1, const line &l2) {
        return is_equal(dot(l1.a - l1.b, l2.a - l2.b), 0);
    }
}

// intersect
namespace geometry {
    bool is_intersect(const segment &s1, const segment &s2) {
        return ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 &&
               ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0;
    }
}

// cross point
namespace geometry {
    point cross_point(const segment &s1, const segment &s2) {
        // if (!is_intersect(s1, s2)) ! panic
        real_number a = cross(s1.b - s1.a, s2.b - s2.a);
        real_number b = cross(s1.b - s1.a, s1.b - s2.a);
        if (is_equal(a, 0) && is_equal(b, 0)) return s2.a;
        return s2.a + (s2.b - s2.a) * b / a;
    }
}

// distance
namespace geometry {
    real_number distance(const segment &s, const point &p) {
        point pr = projection(s, p);
        if (ccw(s.a, s.b, pr) == 0) return abs(pr - p);
        return std::min(abs(s.a - p), abs(s.b - p));
    }

    real_number distance(const segment &s1, const segment &s2) {
        if (is_intersect(s1, s2)) return 0;
        return std::min({distance(s1, s2.a), distance(s1, s2.b), distance(s2, s1.a), distance(s2, s1.b)});
    }
}

// area
namespace geometry {
    real_number area(const polygon &p) {
        real_number res = 0;
        for (int i = 0; i < (int)p.size(); ++i) {
            res += cross(p[i], p[(i + 1) % p.size()]);
        }
        return res / 2;
    }
}

// convex
namespace geometry {
    bool is_convex(const polygon &p) { // p は反時計回りに与えられる
        int n = p.size();
        for (int i = 0; i < n; ++i) {
            if (ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return false;
        }
        return true;
    }

    polygon convex_hull(polygon p) {
        int n = p.size(), k = 0;
        if (n <= 2) return p;
        std::sort(p.begin(), p.end());

        polygon res(2 * n);
        for (int i = 0; i < n; res[k++] = p[i++]) {
            while (k >= 2 && sign(cross(res[k - 1] - res[k - 2], p[i] - res[k - 1])) != +1) {
                --k;
            }
        }

        for (int i = n - 2, t = k + 1; i >= 0; res[k++] = p[i--]) {
            while (k >= t && sign(cross(res[k - 1] - res[k - 2], p[i] - res[k - 1])) != +1) {
                --k;
            }
        }

        res.resize(k - 1);
        return res;
    }

    polygon convex_cut(polygon p, line l) {
        polygon res;
        int n = p.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + 1 == n ? 0 : i + 1);

            real_number ci = cross(l.a - p[i], l.b - p[i]);
            real_number cj = cross(l.a - p[j], l.b - p[j]);

            if (sign(ci) >= 0) res.emplace_back(p[i]);
            if (sign(ci) * sign(cj) < 0) {
                real_number s = cross(p[j] - p[i], l.b - l.a);
                real_number t = cross(l.a - p[i], l.b - l.a);
                res.emplace_back(p[i] + t / s * (p[j] - p[i]));
            }
        }

        return res;
    }

    // 0 : poing out the polygon
    // 1 : point on the polygon edge
    // 2 : poing in the polygon
    int contains(const polygon &poly, const point &p) {
        bool in = false;
        int n = poly.size();
        for (int i = 0; i < n; ++i) {
            int j = (i + 1 == n ? 0 : i + 1);
            point a = poly[i] - p, b = poly[j] - p;
            if (a.imag() > b.imag()) std::swap(a, b);
            if (a.imag() <= 0 && 0 < b.imag() && cross(a, b) < 0) in = !in;
            if (sign(cross(a, b)) == 0 && sign(dot(a, b)) <= 0) {
                return 1;
            }
        }

        return in ? 2 : 0;
    }
}

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

        for (auto poly: polys) {
            poly = convex_hull(poly);
            
            { // left side
                polygon l = convex_cut(poly, line(p, q));

                for (point &v: l) {
                    v = reflection(line(p, q), v);
                }

                l = convex_hull(l);

                if (l.size() > 2) {
                    new_polys.emplace_back(l);
                }
            }

            { // right side
                polygon r = convex_cut(poly, line(q, p));

                r = convex_hull(r);
                if (r.size() > 2) {
                    new_polys.emplace_back(r);
                }
            }
        }

        polys = new_polys;
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
                    if ( is_parallel(s1, s2) ) continue;

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

    sort(xs.begin(), xs.end());

    vector< real_number > ans((1 << m) + 1);
    for (int i = 1; i < (int)xs.size(); ++i) {
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

        for (int j = 1; j < (int)ls.size(); ++j) {
            real_number gy = (ls[j - 1] + ls[j] + rs[j - 1] + rs[j]) / 4.0;
            real_number gx = (l + r) / 2.0;
            point g(gx, gy);

            real_number S = (ls[j] - ls[j - 1] + rs[j] - rs[j - 1]) * (r - l) / 2.0;
            int cnt = 0;
            for (const auto &poly: polys) {
                if (contains(poly, g) == 2) {
                    cnt++;
                }
            }

            ans[cnt] += S;
        }
    }

    cout << fixed << setprecision(15);
    for (int i = 1; i <= (1 << m); ++i) {
        cout << ans[i] << endl;
    }

    { // debug
        real_number S = 0;
        for (int i = 1; i < (int)ans.size(); ++i) {
            S += i * ans[i];
        }

        assert(fabs(area(ps) - S) < 1e-6);
    }
}


