#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
const ll MOD=1000000007;
//const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}

const int SZ=2100;
const int MAX=SZ*SZ;
int uft[MAX];

int parent(int a){return uft[a]==a?a:uft[a]=parent(uft[a]);}

void merge(int a,int b){uft[parent(b)]=parent(a);}

int idx(int a,int b){return a*SZ+b;}

int dx[8]={0,1,0,-1,1,-1,1,-1};
int dy[8]={1,0,-1,0,1,1,-1,-1};

int sqx[4]={0,1,0,1};
int sqy[4]={0,0,1,1};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  for(int i=0;i<MAX;i++){uft[i]=i;}
  int H,W,Q;
  cin>>H>>W>>Q;
  H+=2; W+=2;
  vector<vector<char>> A(H,vector<char>(W,'.'));
  int pts=0,edge=0,none=0,con=0,ans=0;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(i==0 || j==0 || i+1==H || j+1==W){merge(idx(0,0),idx(i,j));}
      else{A[i][j]='#';}
    }
  }
  pts=(H-2)*(W-2);
  edge=(H-3)*(W-2)+(H-2)*(W-3);
  none=(H-3)*(W-3);
  con=1;
  ans=1;
  
  auto erase=
    [&](int a,int b){
      assert(A[a][b]=='#');
      pts--;
      for(int k=0;k<4;k++){
        int x=a+dx[k];
        int y=b+dy[k];
        if(A[x][y]=='#'){edge--;}
      }
      for(int k=0;k<4;k++){
        bool jd=true;
        int x=a-sqx[k];
        int y=b-sqy[k];
        for(int l=0;l<4 && jd;l++){
          int r=x+sqx[l];
          int c=y+sqy[l];
          jd&=A[r][c]=='#';
        }
        if(jd){none--;}
      }
      A[a][b]='.';
      con++;
      for(int k=0;k<8;k++){
        int x=a+dx[k];
        int y=b+dy[k];
        if(A[x][y]=='.' && parent(idx(x,y))!=parent(idx(a,b))){
          merge(idx(x,y),idx(a,b));
          con--;
        }
      }
      ans=pts-edge+con+none-1;
    };

  for(int i=1;i+1<H;i++){
    for(int j=1;j+1<W;j++){
      char c;
      cin>>c;
      if(c=='.'){erase(i,j);}
    }
  }
  ll s=0,roll=427,cst=1821,mod=2048;
  while(Q--){
    ll x,y;
    cin>>x>>y;
    x=s^x; x++;
    y=s^y; y++;
    cout<<x<<" "<<y<<endl;
    assert(A[x][y]=='#');
    erase(x,y);
    //cout<<ans<<endl;
    s=roll*s+cst*ans;
    s%=mod;
  }

  return 0;
}
