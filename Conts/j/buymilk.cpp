#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("buymilk.inp","r",stdin);
	freopen("buymilk.out","w",stdout);
	long long a , b , c , d;
	cin >> a >> b >> c >> d;
	if( b <= c-d || a < c )
		cout << a/b << endl;
	else
		cout << (a-d)/(c-d)+(a-(a-d)/(c-d)*(c-d))/b << endl;
	return 0;
}