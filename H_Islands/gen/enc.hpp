#ifndef ENC_HPP
#define ENC_HPP

#include "../../common/testlib.h"

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
    s=roll*s+cst*ans;
    s%=mod;
  }
  return ret;
}

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
    s=roll*s+cst*ans;
    s%=mod;
  }
}


#endif
