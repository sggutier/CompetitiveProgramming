N = int( raw_input() ) 
A = "<3"

for i in range(N) :
	tmp = raw_input()
	A = A + tmp + "<3"

B = raw_input()

x = 0
y = 0

while x<len(A) and y<len(B) :
	if A[x]==B[y]:
		x += 1
	y += 1

print "yes" if x==len(A) else "no"
