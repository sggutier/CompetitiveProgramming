#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 100005 ;

int N ;
int arr[lim] ;

int mcd( int a, int b ) {
	int c ;
	while( b ) {
		c = a%b ;
		a = b ;
		b = c ;
	}
	return a ;
}

int main() {
	int W, res=-1 ; 

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
	W = arr[0] ;

	for( int i=1; i<N; i++ ) 
		W = mcd( W, arr[i] ) ;

	for( int i=0; i<N; i++ ) 
		res = max( res, arr[i]/W ) ;
	
	if( (N-res)%2 )
		printf("Alice\n" ) ;
	else
		printf("Bob\n") ;

	return 0 ;
}


