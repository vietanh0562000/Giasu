#include <bits/stdc++.h>
using namespace std;
#define fi cin
#define fo cout
#define x first
#define y second
#define ll long long
#define db long double
#define IOS ios_base :: sync_with_stdio(0)

int n, bfrom, bto;
ll a[1<<20], b[1<<20];
ll sum[1 << 20];

ll cost(int from, int to){
    return a[from]*(to-from-1) - (sum[from+1]-sum[to]);
}

ll bsearch(){
    ll ans = 0;
    ll total = 0;
    for (int i = n;i;--i) sum[i] = sum[i+1] + a[i];
    for (int i = 1;i <= n;++i) total += 1ll * i * a[i];

    for (int i = 1;i <= n;++i){
        int lo = 1, hi = n + 1;
        while (lo < hi){
            int m = (lo + hi) / 2;
            if (cost(i, m) >= cost(i, m+1)) hi = m;
            else lo = m + 1;
        }
        ans = max(ans, cost(i, lo));
    }
    return total+ans;
}

ll brute(){
    ll t, ans=0;
    for(int i=1; i<=n; ++i) ans += i*a[i];
    for(int i=1; i<=n; ++i){
        b[1] = a[i];
        memcpy(b+2, a+1, (i-1)*sizeof(a[1]));
        memcpy(b+i+1, a+i+1, (n-i)*sizeof(a[1]));
        t = 0;
        for(int j=1; j<=n; ++j) t += j*b[j];
        if(ans < t) ans = t;

        memcpy(b+1, a+1, (i-1)*sizeof(a[1]));
        memcpy(b+i, a+i+1, (n-i)*sizeof(a[1]));
        b[n] = a[i];
        t = 0;
        for(int j=1; j<=n; ++j) t += j*b[j];
        if(ans < t) ans = t;
    }
    return ans;
}

void gen(int _n, int range){
    n = _n;
    for(int i=1; i<=n; ++i) a[i] = 1+rand()%(range);
}

int main(void){
	freopen("prodsum.inp","r",stdin);
	freopen("prodsum.out","w",stdout);
    IOS; fi>>n; for (int i = 1;i <= n;++i) fi>>a[i];
    //return cout << bsearch() << endl, 0;
    return cout << brute() << endl, 0;
}
