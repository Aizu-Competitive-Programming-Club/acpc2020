#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

bool check(vector<long long> &b, vector<long long> &c, long long N, long long P, long long num) {
	long long tsum = 0, tsum2 = 0;
	vector<long long> d(N);
	
	c.clear();
	c.resize(N, 0);
	
	for(int i = 0; i < N; i++){ 
		
		{
			long long l = -1, h = num + 10, m;
			
			while(l + 1 < h){
				m = (l + h) / 2;
				if(m * P / num < b[i]) {
					l = m;
				} else {
					h = m;
				}
			}
			
			c[i] = h;
		}
		
		if(c[i] * P / num != b[i]) return false;
		tsum += c[i];
		
		{
			long long l = 0, h = num + 10, m;
			
			while(l + 1 < h){
				m = (l + h) / 2;
				
				if(m * P / num < b[i] + 1) {
					l = m;
				} else {
					h = m;
				}
			}
			
			d[i] = l;
		}
		
		assert(c[i] * P / num == d[i] * P / num);
	}
	
	if(tsum > num) return false;
	
	for(int i = N-1; i >= 0; i--){
		if(tsum == num) break;
		
		if(d[i] - c[i] >= num - tsum) {
			c[i] += num - tsum;
			tsum = num;
			break;
		} else {
			tsum += d[i] - c[i];
			c[i] = d[i];
		}
	}
	
	if(tsum != num) return false;
	
	for(int i = 0; i < N; i++){
		tsum2 += c[i];
		assert(c[i] * P / num == b[i]);
	}
	
	assert(tsum2 == num);
	
	return true;
}

long long solve(vector<long long> &b, vector<long long> &c, long long N, long long P) {
	long long res = 1;
	
	for(;; res++){
		if(check(b, c, N, P, res)) break;
	}
	
	long long sum = 0;
	
	assert((long long)b.size() == N);
	assert((long long)c.size() == N);
	
	for(int i = 0; i < N; i++){
		sum += c[i];
	}
	
	assert(sum > 0);
	
	for(int i = 0; i < N; i++){
		assert(b[i] == c[i] * P / sum);
	}
	
	return res;
}

signed main(){
	
	vector<long long> B, C;
	long long N, P;
	
	cin>>N>>P;
	
	B.resize(N);
	
	for(int i = 0; i < N; i++){
		cin>>B[i];
	}
	
	solve(B, C, N, P);
	
	for(int i = 0; i < N; i++){
		if(i) cout<<" ";
		cout<<C[i];
	}
	
	cout<<endl;
	
	
	return 0;
}