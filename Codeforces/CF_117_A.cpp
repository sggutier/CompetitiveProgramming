#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N, m ;
	
	cin >> N >> m ;
	for( int i=0; i<N; i++ ) {
		int ini, fin, t ;
		int cicl ;
		cin >> ini >> fin >> t ;
		if( ini==fin ) {
			cout << t << endl ;
			continue ;
		}
		cicl = t/( 2*(m-1) ) ;
		if( ini<fin  )  {
			if( t%( 2*(m-1) ) > ini-1  )
				cicl ++ ;
			t = ( 2*(m-1) )*cicl + fin-1 ;
		}
		else {
			if( t%( 2*(m-1) ) > (m-1)+(m-ini)  ) 
				cicl ++ ;
			t = ( 2*(m-1) )*cicl + (m-fin) + (m-1) ;
		}
		cout <<  t  << endl ;
	}
	
	return 0 ;
}
