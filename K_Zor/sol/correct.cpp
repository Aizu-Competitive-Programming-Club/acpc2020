#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
//const ll MOD=1000000007;
const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin>>N;
  vector<int> P(64);
  vector<string> Mt(N);
  cin>>P>>Mt;
  vector<vector<int>> c;
  vector<int> used(64,0);
  for(int i=0;i<64;i++){
    if(used[i]){continue;}
    c.push_back({});
    int idx=i;
    do{c.back().push_back(idx); idx=P[idx]; used[idx]=1;}while(idx!=i);
  }
  sort(c.begin(),c.end(),[](const vector<int> &a,const vector<int> &b){return a.size()<b.size() || (a.size()==b.size() && a<b);});
  vector<int> cic;
  for(auto &I:c){cic.push_back(I.size());}
  int jb=cic.size();
  for(int i=1;i<jb;i++){cic[i]+=cic[i-1];}
  vector<ull> A(N);
  for(int i=0;i<N;i++){
    reverse(Mt[i].begin(),Mt[i].end());
    ull k=0;
    int cnt=0;
    for(auto &C:c){
      for(auto &idx:C){
        if(Mt[i][idx]=='1'){k^=1ull<<cnt;}
        cnt++;
      }
    }
    A[i]=k;
  }

  auto MSK=
    [](int lf,int rg){
      ull ret=0;
      for(int i=lf;i<rg;i++){ret^=1ull<<i;}
      return ret;
    };
  
  auto perm=
    [&](ull k,int a){
      ull ret=0;
      for(int i=0;i<jb;i++){
        int rg=cic[i],lf=i==0?0:cic[i-1];
        ull msk=MSK(lf,rg);
        ull x=k&msk;
        int A=a%(rg-lf);
        assert(((x<<A)&(x>>(rg-lf-A)))==0);
        x=(x<<A)|(x>>(rg-lf-A));
        x&=msk;
        ret^=x;
      }
      return ret;
    };
  ll ans=1;
  for(int i=0;i<jb;i++){
    int rg=cic[i],lf=i==0?0:cic[i-1];
    ull msk=MSK(lf,rg);
    N=A.size();
    for(int idx=1;idx<N;idx++){
      while((A[0]&msk)!=0 && (A[idx]&msk)!=0){
        ull a=A[0]&msk,b=A[idx]&msk;
        if(a<b){swap(a,b); swap(A[0],A[idx]);}
        int x=rg-1,y=rg-1;
        while(!(a>>x&1)){x--;}
        while(!(b>>y&1)){y--;}
        A[0]^=perm(A[idx],x-y);
        assert((perm(A[idx],x-y)&msk)==((b<<(x-y))&msk));
      }
      if((A[0]&msk)==0){swap(A[0],A[idx]);}
    }
    for(int j=1;j<=rg-lf;j++){
      A.push_back(perm(A[0],j));
    }
    for(int idx=N;idx<N+rg-lf;idx++){
      while((A[0]&msk)!=0 && (A[idx]&msk)!=0){
        ull a=A[0]&msk,b=A[idx]&msk;
        if(a<b){swap(a,b); swap(A[0],A[idx]);}
        int x=rg-1,y=rg-1;
        while(!(a>>x&1)){x--;}
        while(!(b>>y&1)){y--;}
        A[0]^=perm(A[idx],x-y);
      }
      if((A[0]&msk)==0){swap(A[0],A[idx]);}
    }
    ull a=A[0]&msk;
    ll db=1,k=rg-1;
    if(a!=0){do{db*=2; db%=MOD;}while(!(a>>(k--)&1));}
    ans*=db; ans%=MOD;
    swap(A[0],A[N+rg-lf-1]);
    A.pop_back();
  }
  cout<<ans<<endl;
  
  return 0;
}
