#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std ;

int main() {
	set <char> rep ;
	string S ;

	cin >> S ;

	for( int i=0; i<S.size(); i++ )
		rep.insert(S[i]) ;

	if( rep.size()%2 )
		cout << "IGNORE HIM!" << endl ; 
	else 
		cout << "CHAT WITH HER!" << endl ; 		

	return 0 ;
}
