#include<iostream>

using namespace std;

int main(){
  int n,p;
  cin>>n>>p;
  int b[n];
  int c[n]={};
  for(int i=0;i<n;i++) cin>>b[i];
  int now=1;
  while(1){
    bool flag=true;
    int sum=0;
    for(int i=0;i<n;i++){
      c[i]=((now*b[i])+(p-1))/p;
      if((c[i]*p)/now != b[i]){
	flag=false;
	break;
      }
      sum+=c[i];
    }
    if(!flag || now<sum){now++; continue;}
    for(int i=n-1;i>=0;i--){
      while(sum<now && ((c[i]+1)*p)/now == b[i]){
	sum++;c[i]++;
      }
    }
    if(sum!=now){now++;continue;}
    else break;
  }
  for(int i=0;i<n;i++){
    if(i!=0) cout<<" ";
    cout<<c[i];
  }
  cout<<endl;
  return 0;
    
}
