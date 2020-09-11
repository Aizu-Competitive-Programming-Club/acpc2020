#include<bits/stdc++.h>


using namespace std;


#define rep(i,n) for (int i=0; i < (int)(n); i++)
typedef long double D;      // 座標値の型。Dかlong Dを想定
typedef complex<D> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;
typedef vector<VP> Vcon;
const D EPS = 1e-17;    // 許容誤差。問題によって変える
#define X real()
#define Y imag()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)
 
// 内積　dot(a,b) = |a||b|cosθ
D dot(P a, P b) {return (conj(a)*b).X; }
 
// 外積　cross(a,b) = |a||b|sinθ
D cross(P a, P b) {  return (conj(a)*b).Y;}
 
// 点の進行方向
int ccw(P a, P b, P c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

bool isparallel(L a,L b){
  return cross(a.first-a.second,b.first-b.second) == 0.0 ;
}
 
/* 交差判定　直線・線分は縮退してはならない。接する場合は交差するとみなす。isecはintersectの略 */
 
// 直線と点
bool isecLP(P a1, P a2, P b) {
  return abs(ccw(a1, a2, b)) != 1;  // return EQ(cross(a2-a1, b-a1), 0); と等価
}
 
// 直線と直線
bool isecLL(P a1, P a2, P b1, P b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}
 
// 直線と線分
bool isecLS(P a1, P a2, P b1, P b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}
 
// 線分と線分
bool isecSS(P a1, P a2, P b1, P b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
         ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}
 
// 線分と点
bool isecSP(P a1, P a2, P b) {
  return !ccw(a1, a2, b);
  // return abs(a1 - b) + abs(a2 - b) - abs(a2 - a1) < EPS;  //Perfective
}
 
 
/* 距離　各直線・線分は縮退してはならない */
 
// 点pの直線aへの射影点を返す
P proj(P a1, P a2, P p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}
 
// 点pの直線aへの反射点を返す
P reflection(P a1, P a2, P p) {
  return (D)2.0*proj(a1, a2, p) - p;
}
 

// 2直線の交点
P crosspointLL(P a1, P a2, P b1, P b2) {
  D d1 = cross(b2-b1, b1-a1);
  D d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  if (EQ(d2, 0)) throw "kouten ga nai";   // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

 
// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const P a, const P b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}
 
// 凸包
VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}
 
// 凸判定。縮退を認めないならccwの判定部分を != 1 とする
bool isCcwConvex(const VP& ps) {
  int n = ps.size();
  rep (i, n) if (ccw(ps[i], ps[(i+1) % n], ps[(i+2) % n]) == -1) return false;
  return true;
}
 
// 凸多角形の内部判定　O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(P p, const VP& ps) {
  int n = ps.size();
  int dir = ccw(ps[0], ps[1], p);
  rep (i, n) {
    int ccwc = ccw(ps[i], ps[(i + 1) % n], p);
    if (!ccwc) return 2;  // 線分上に存在
    if (ccwc != dir) return 0;
  }
  return 1;
}
 

// 凸多角形クリッピング
VP convexCut(const VP& ps, P a1, P a2) {
  int n = ps.size();
  VP ret;
  rep(i,n) {
    int ccwc = ccw(a1, a2, ps[i]);
    if (ccwc != -1) ret.push_back(ps[i]);
    int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
    if (ccwc * ccwn < 0) ret.push_back(crosspointLL(a1, a2, ps[i], ps[(i + 1) % n]));
  }
  //cerr<<' '<<n<<' '<<ret.size()<<endl;
  return ret;
}
D area(const VP&);

 
// 多角形の符号付面積
D area(const VP& ps) {
  D a = 0;
  rep (i, (int)ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2.0;
}



D ans[1<<11];

int main(){
  int n,m;
  VP VEX;
  vector<VP>v;
  cin>>n>>m;
  rep(i,n){
    D a,b;
    cin>>a>>b;;
    VEX.emplace_back(P(a,b));
  }
  VEX=convexHull(VEX);
  v.emplace_back(convexHull(VEX));
  rep(i,m){
    D a,b,c,d;
    cin>>a>>b>>c>>d;
    P pa=P(a,b),pb=P(c,d);
    vector<VP>tmp;
    rep(j,(int)v.size()){
      v[j]=convexHull(v[j]);
      VP A=convexCut(v[j],pa,pb);
      rep(k,(int)A.size()){
        A[k] = reflection(pa,pb,A[k]);
      }
      VP B=convexCut(v[j],pb,pa);
      if((int)A.size()){
        A=convexHull(A);
        if(A.size()>=3)tmp.emplace_back(A);
      }
      if((int)B.size()){
        B=convexHull(B);
        if(B.size()>=3)tmp.emplace_back(B);
      }
    }
    v=tmp;
  }



  VP point;
  rep(i,(int)v.size()){
    rep(j,(int)v[i].size()){
      point.emplace_back(v[i][j]);
    }
  }
  rep(a,(int)v.size()){
    rep(b,(int)v[a].size()){
      P A1=v[a][b];
      P A2=v[a][(b+1)%(int)v[a].size()];
      rep(c,(int)v.size()){
        if(c<=a)continue;
        rep(d,(int)v[c].size()){
          P B1=v[c][d];
          P B2=v[c][(d+1)%(int)v[c].size()];
          if(!isecSS(A1,A2,B1,B2))continue;
          if(isparallel(L(A1,A2),L(B1,B2)))continue;
          point.emplace_back(crosspointLL(A1,A2,B1,B2));
        }
      }
    }
  }
  //cout<<point.size()<<endl;
  sort(point.begin(),point.end());
  VP tm;
  tm.emplace_back(point[0]);
  rep(i,(int)point.size()){
    if(!i) continue;
    int fl=0;
    if(!fl)tm.emplace_back(point[i]);
  }

  sort(tm.begin(),tm.end());

  rep(i,(int)tm.size()-1){
    P A=tm[i];
    P B=tm[i+1];
    D sax=abs(A.X-B.X);
    if(sax<EPS) continue;
    P A1=P(A.X,-1e9) , A2=P(A.X,1e9);
    P B1=P(B.X,-1e9) , B2=P(B.X,1e9);
    vector<D> left,right;
    rep(j,(int)v.size()){
      rep(k,(int)v[j].size()){
        P C1=P(v[j][k]);
        P C2=P(v[j][(k+1)%(int)v[j].size()]);
        if(!isecSS(A1,A2,C1,C2) || !isecSS(B1,B2,C1,C2)) continue;
        if(isparallel(L(A1,A2),L(C1,C2)) || isparallel(L(B1,B2),L(C1,C2))) continue;
        left.emplace_back(crosspointLL(A1,A2,C1,C2).Y);
        right.emplace_back(crosspointLL(B1,B2,C1,C2).Y);
      }
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    if((int)left.size()==1)exit(1);
    rep(j,(int)left.size()-1){
      D say=abs(left[j]-left[j+1]) + abs(right[j]-right[j+1]);
      D ar = say * sax / 2;
      D y = ( left[j] + left[j+1] + right[j] + right[j+1] ) / 4;
      D x = ( A.X + B.X )/2;
      int cnt = 0;
      rep(k,v.size()){
        if(isCcwConvex(v[k])==0)exit(1);
        if(inConvex(P(x,y),v[k])==1)cnt++;
        //if(inConvex(P(x,y),v[k])==2)cnt--;
      }
      ans[cnt] += ar;
    }
    //cerr<<endl<<endl<<endl;
  }

  rep(i,(1<<m)) printf("%.9Lf\n",ans[i+1]);

  /*
  printf("%.9Lf\n",area(VEX));
  D sa=0;
  rep(i,(1<<m))sa+=ans[i+1]*(i+1);
  printf("%.9Lf\n",sa);
  D sa2=0;
  rep(i,(int)v.size())sa2+=area(v[i]);
  printf("%.9Lf\n",sa2);
  */

}



