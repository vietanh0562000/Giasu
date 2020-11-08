#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("makestr.inp","r",stdin);
	freopen("makestr.out","w",stdout);
	long long int i,j=0,k,l,n,m,a[100];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=n-2;i>=0;i--)
		while(a[i]>=a[i+1] && a[i]>0)
			a[i]--;
	for(i=0;i<n;i++)
		j+=a[i];
	cout<<j<<endl;
	return 0;
}