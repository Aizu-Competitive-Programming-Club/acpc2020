#ifndef ENC_HPP
#define ENC_HPP

#include "../../common/testlib.h"

using P=pair<int,int>;

int uft[(HW_MAX+2)*(HW_MAX+2)];

int parent(int a){return uft[a]==a?a:uft[a]=parent(uft[a]);}

int merge(int a,int b){
  if(parent(a)==parent(b)){return 0;}
  uft[parent(b)]=parent(a);
  return 1;
}

void init(int MAX=HW_MAX*HW_MAX){for(int i=0;i<MAX;i++){uft[i]=i;}}

bool good(int x,int y,int H,int W){return 0<=x && x<H && 0<=y && y<W;}

vector<P> enc(int H,int W,int Q,const vector<vector<int>> &C,const vector<P> &query){
  //0::sea 1::island
  vector<int> dif(Q);
  for(auto &I:query){assert(I.F<H && I.S<W);}
  {
    auto Good=[&](int x,int y){return good(x,y,H,W);};
    const int dx[4]={1,0,-1,0};
    const int dy[4]={0,1,0,-1};
    init(H*W);
    auto idx=[&](int a,int b){return a*W+b;};
    vector<vector<int>> A=C;
    for(int i=0;i<Q;i++){auto I=query[i]; A[I.F][I.S]=0;}
    int ans=0;
    auto add=
      [&](int i,int j){
        A[i][j]=1;
        ans++;
        for(int k=0;k<4;k++){
          int x=i+dx[k];
          int y=j+dy[k];
          if(Good(x,y) && A[x][y]){ans-=merge(idx(x,y),idx(i,j));}
        }
      };
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(A[i][j]){add(i,j);}
      }
    }
    for(int i=Q-1;i>=0;i--){
      dif[i]=ans%mod;
      auto I=query[i];
      add(I.F,I.S);
    }
  }
  vector<P> ret=query;
  int s=0;
  for(int i=0;i<Q;i++){
    ret[i].F^=s;
    ret[i].S^=s;
    s=roll*s+cst*dif[i];
    s%=mod;
  }
  return ret;
}

void inv(int H,int W,int Q,const vector<vector<int>> &C,const vector<pair<int,int>> &query){

  const int dx[8]={0,1,0,-1,1,-1,1,-1};
  const int dy[8]={1,0,-1,0,1,1,-1,-1};

  const int sqx[4]={0,1,0,1};
  const int sqy[4]={0,0,1,1};
  
  H+=2; W+=2;
  init(H*W);
  auto idx=[&](int x,int y){return x*W+y;};
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
      ensuref(1<=a && a<=H && 1<=b && b<=W,"hani\n");
      ensuref(A[a][b]=='#',"A[a][b] must be island\n");
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
        if(A[x][y]=='.'){
          con-=merge(idx(x,y),idx(a,b));
        }
      }
      ans=pts-edge+con+none-1;
    };

  for(int i=1;i+1<H;i++){
    for(int j=1;j+1<W;j++){
      if(C[i-1][j-1]==0){erase(i,j);}
    }
  }
  ll s=0;
  for(int q=0;q<Q;q++){
    ll x=query[q].F,y=query[q].S;
    x=s^x; x++;
    y=s^y; y++;
    erase(x,y);
    s=roll*s+cst*ans;
    s%=mod;
  }
}

/*
void inv(int H,int W,int Q,const vector<vector<int>> &C,const vector<pair<int,int>> &query){
  H+=2; W+=2;
  vector<vector<char>> A(H,vector<char>(W,'#'));
  vector<vector<char>> B(H,vector<char>(W,'.'));
  vector<int> uft(H*W);
  for(int i=0;i<H*W;i++){uft[i]=i;}
  for(int i=1;i+1<H;i++){for(int j=1;j+1<W;j++){B[i][j]=C[i-1][j-1]==1?'#':'.';}}
  auto idx=[&](int i,int j){return i*W+j;};
  auto parent=[&](int i){
                stack<int> S;
                while(uft[i]!=i){S.push(i); i=uft[i];}
                while(!S.empty()){uft[S.top()]=i; S.pop();}
                return i;
              };
  vector<int> dx={1,-1,0,0};
  vector<int> dy={0,0,1,-1};

  int edge=0,con=0,face=0,p=0;
  auto add_point=[&](int i,int j){
    A[i][j]='.';
    p++;
    con++;
    for(int d=0;d<4;d++){
      int x=i+dx[d];
      int y=j+dy[d];
      if(x<0 || y<0 || x>=H || y>=W){continue;}
      if(A[x][y]=='#'){continue;}
      edge++;
      if(parent(idx(x,y))!=parent(idx(i,j))){
        con--;
        uft[parent(idx(x,y))]=parent(idx(i,j));
      }
    }
    for(auto d1:{0,1}){
      for(auto d2:{2,3}){
        int x=i+dx[d1];
        int y=j+dy[d2];
        if(x<0 || y<0 || x>=H || y>=W){continue;}
        if(A[i][y]=='.' && A[x][j]=='.' && A[x][y]=='#'){edge--;}
        if(A[x][y]=='#'){continue;}
        edge++;
        if(parent(idx(x,y))!=parent(idx(i,j))){
          con--;
          uft[parent(idx(x,y))]=parent(idx(i,j));
        }
        if(A[i][y]=='.' || A[x][j]=='.'){edge--;}
        if(A[i][y]=='.' && A[x][j]=='.'){face++;}
      }
    }
  };
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(B[i][j]=='.'){
        add_point(i,j);
      }
    }
  }
  
  int s=0;
  
  for(int t=0;t<Q;t++){
    int x,y;
    x=query[t].F,y=query[t].S;
    x^=s; y^=s;
    x++; y++;
    ensuref(A[x][y]=='#',"it must be sharp\n");
    add_point(x,y);
    int ans=-p+edge+con-face;
    s=roll*s%mod+cst*(ans%mod)%mod;
    s%=mod;
  }
}
*/
/*
vector<pair<int,int>> enc(int H,int W,int Q,const vector<vector<int>> &C,const vector<pair<int,int>> &query){
  H+=2; W+=2;
  vector<vector<char>> A(H,vector<char>(W,'#'));
  vector<vector<char>> B(H,vector<char>(W,'.'));
  vector<int> uft(H*W);
  for(int i=0;i<H*W;i++){uft[i]=i;}
  for(int i=1;i+1<H;i++){for(int j=1;j+1<W;j++){B[i][j]=C[i-1][j-1]==1?'#':'.';}}
  auto idx=[&](int i,int j){return i*W+j;};
  auto parent=[&](int i){
                stack<int> S;
                while(uft[i]!=i){S.push(i); i=uft[i];}
                while(!S.empty()){uft[S.top()]=i; S.pop();}
                return i;
              };
  vector<int> dx={1,-1,0,0};
  vector<int> dy={0,0,1,-1};

  int edge=0,con=0,face=0,p=0;
  auto add_point=[&](int i,int j){
    A[i][j]='.';
    p++;
    con++;
    for(int d=0;d<4;d++){
      int x=i+dx[d];
      int y=j+dy[d];
      if(x<0 || y<0 || x>=H || y>=W){continue;}
      if(A[x][y]=='#'){continue;}
      edge++;
      if(parent(idx(x,y))!=parent(idx(i,j))){
        con--;
        uft[parent(idx(x,y))]=parent(idx(i,j));
      }
    }
    for(auto d1:{0,1}){
      for(auto d2:{2,3}){
        int x=i+dx[d1];
        int y=j+dy[d2];
        if(x<0 || y<0 || x>=H || y>=W){continue;}
        if(A[i][y]=='.' && A[x][j]=='.' && A[x][y]=='#'){edge--;}
        if(A[x][y]=='#'){continue;}
        edge++;
        if(parent(idx(x,y))!=parent(idx(i,j))){
          con--;
          uft[parent(idx(x,y))]=parent(idx(i,j));
        }
        if(A[i][y]=='.' || A[x][j]=='.'){edge--;}
        if(A[i][y]=='.' && A[x][j]=='.'){face++;}
      }
    }
  };
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(B[i][j]=='.'){
        add_point(i,j);
      }
    }
  }
  vector<pair<int,int>> ret(Q);
  int s=0;
  
  for(int t=0;t<Q;t++){
    int x,y;
    x=query[t].F,y=query[t].S;
    ret[t]={x^s,y^s};
    x++; y++;
    ensuref(0<x && x+1<H && 0<y && y+1<W,"x,y nohani\n");
    add_point(x,y);
    int ans=-p+edge+con-face;
    s=roll*s+cst*(ans%mod)%mod;
    s%=mod;
  }
  return ret;
}
*/

#endif
