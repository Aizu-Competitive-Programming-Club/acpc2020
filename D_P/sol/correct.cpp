#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

bool check(vector<long long> &b, vector<long long> &c, long long N, long long P, long long num) {
	long long tsum = 0, tsum2 = 0;
	vector<long long> d(N);

	c.resize(N);
	
	for(int i = 0; i < N; i++){ 
		c[i] = (b[i] * num + P - 1) / P;
		
		if(c[i] * P / num != b[i]) return false;
		tsum += c[i];
		d[i] = ((b[i] + 1)* num + P - 1) / P;
		d[i]--;
		
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

bool check2(vector<pair<long long, long long>> &e, long long P, long long num) {
	long long tsum = 0, tsum3 = 0;
	
	for(int i = 0; i < (long long)e.size(); i++){
		long long c = 0, d = 0;
		
		c = (e[i].second * num + P - 1) / P;
		
		if(c * P / num != e[i].second) return false;
		
		tsum += c * e[i].first;
		
		d = ((e[i].second + 1) * num + P - 1) / P;
		
		d--;
		
		assert(c * P / num == d * P / num);
		
		tsum3 += (d - c) * e[i].first;
	}
	
	if(tsum > num) return false;
	
	
	if(tsum3 < num - tsum) return false;
	
	
	return true;
}

long long solve2(vector<long long> &b, vector<long long> &c, long long N, long long P) {
	long long res = 1;
	vector<pair<long long,long long>> con(P+1);
	vector<pair<long long,long long>> e;
	
	for(int i = 0; i <= P; i++){
		con[i].second = i;
	}
	
	for(int i = 0; i < N; i++){
		con[b[i]].first++;
	}
	
	for(int i = 0; i <= P; i++){
		if(con[i].first >= 1) {
			e.push_back(con[i]);
		}
	}
	
	for(;; res++){
		if(check2(e, P, res)) break;
	}
	
	assert(check(b, c, N, P, res) == true);
	
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
	long long sum = 0;
	cin>>N>>P;
	
	B.resize(N);
	
	for(int i = 0; i < N; i++){
		cin>>B[i];
		sum += B[i];
	}
	
	if(sum < P - N + 1 || sum > P) {
		cout<<-1<<endl;
		return 0;
	}
	
	solve2(B, C, N, P);
	
	for(int i = 0; i < N; i++){
		if(i) cout<<" ";
		cout<<C[i];
	}
	
	cout<<endl;
	
	
	return 0;
}