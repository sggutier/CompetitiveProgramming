#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
typedef long long ll ;

int main() {
	ll h, w ;
	ll p, a, b ;
	ll rh=1LL, rw=1LL ;
	
	cin >> h >> w ;
	
	if( h>=2LL && w>=2LL ) 
		rh = 2LL, rw = 2LL ;
	
	for( p=4LL; p<=h && p<=w; p*=2LL ) ;
	p /= 2LL ;
	if(  p>=4LL && p<=h && p<=w   )   {
		rh = p ;
		rw = min( w, (p/4LL)*5LL  )  ;
		b = p ;
		a = min( h, (p/4LL)*5LL  )  ;
		if( a*b >= rh*rw ) {
			rh = a ;
			rw = b ;
		}
	}
	
	cout << rh << " " << rw << endl ;
	
	return 0 ;
}
