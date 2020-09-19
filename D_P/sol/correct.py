import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

N, P = map(int, readline().split())
A = list(map(int, readline().split()))
B = [0] * (N)

def construction(num):
	C = [0] * (N)
	sum = 0
	
	for i in range(N):
		B[i] = (A[i] * num + P - 1) // P
		sum = sum + B[i]
		C[i] = ((A[i] + 1) * num + P - 1) // P - 1
	
	for i in range(N)[::-1]:
		if num == sum:
			break
			
		if C[i] - B[i] >= num - sum:
			B[i] = B[i] + num - sum
			sum = num
			break
		else:
			sum = sum + C[i] - B[i]
			B[i] = C[i]


def check(ef, es, num):
	res = True
	sum = 0
	sum2 = 0
	
	for i in range(len(ef)):
		
		c = (es[i] * num + P - 1) // P
		
		if c * P // num != es[i]:
			res = False;
		
		sum = sum + c * ef[i]
		
		d = ((es[i] + 1) * num + P - 1) // P - 1
		
		sum2 = sum2 + (d - c) * ef[i]
		
	
	if(sum > num):
		res = False
	
	if(sum2 < num - sum):
		res = False
	
	return res;

def solve():
	count = [0] * (P+1)
	ef = []
	es = []
	
	for i in range(N):
		count[A[i]] += 1
		
	for i in range(P+1):
		if count[i] >= 1:
			ef.append(count[i])
			es.append(i)
	
	num = 1
	
	while check(ef, es, num) == False:
		num += 1
	
	construction(num)
	
	return num



sum = 0;

for i in range(N):
	sum += A[i];

if (sum < P - N + 1) or (sum > P):
	print(-1)
else :
	solve()

	for i in range(N):
		if i != 0:
			print(' ', end='')
		print(B[i], end='')
		
	print('')
