N = int( raw_input() )
DP = [ [ 0, 0 ] for i in range(N) ]

A = [ int(a) for a in raw_input().split() ]
B = [ int(a) for a in raw_input().split() ]
C = [ int(a) for a in raw_input().split() ]

DP[N-1][0] = A[N-1]
DP[N-1][1] = B[N-1]

for L in range(N-2,-1,-1) :
	DP[L][0] = max( DP[L+1][1] + A[L],  DP[L+1][0] + B[L] )
	DP[L][1] = max( DP[L+1][1] + B[L],  DP[L+1][0] + C[L] ) 

print DP[0][0]
