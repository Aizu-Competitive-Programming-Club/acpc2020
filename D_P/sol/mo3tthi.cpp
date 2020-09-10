#include<iostream>

using namespace std;

int main(){
  int n,p;
  cin>>n>>p;
  int a[n];
  int b[n]={};
  int sum=0;
  for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
  if(sum<p && p-n>=sum){cout<<-1<<endl;return 0;}
  for(int k=1;k<(n*p);k++){
    bool flag=true;
    int nowsum=0;
    for(int i=0;i<n;i++){
      b[i]=((k*a[i])+(p-1))/p;
      if((b[i]*p)/k != a[i]){
	flag=false;
	break;
      }
      nowsum+=b[i];
    }
    if(!flag || k<nowsum){continue;}
    for(int i=n-1;i>=0;i--){
      while(nowsum<k && ((b[i]+1)*p)/k == a[i]){
	nowsum++;b[i]++;
      }
    }
    if(nowsum!=k){continue;}
    else{
      for(int i=0;i<n;i++){
	if(i!=0) cout<<" ";
	cout<<b[i];
      }
      cout<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
    
}
