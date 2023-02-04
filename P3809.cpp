#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1919810;
char s[N];
int n,ans[N];
ll a[N];
pair<ll,int> v[N];
int main() {
	//	freopen("P3809_11.in","r",stdin);
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i=1;i<=n;++i)
		v[i] = {s[i],i};
	sort(v+1,v+n+1);
	for(int i=1,cnt=0;i<=n;++i) {
		if(v[i].first != v[i-1].first) ++cnt;// cout <<(char)v[i].first<<' '<< i << "<-\n";
		a[v[i].second] = cnt;
		//		cout << cnt << ' ';
	}
	for(int j=1;j<=__lg(n)+1;++j) {
		for(int i=1;i<=n;++i) {
			if(i + (1 << (j-1)) <= n)
				v[i] = {a[i]<<24|a[i+(1<<(j-1))],i};
			else v[i] = {a[i]<<24,i};
		}
		sort(v+1,v+n+1);
		for(int i=1,cnt=0;i<=n;++i) {
			if(v[i].first != v[i-1].first) ++cnt;
			a[v[i].second] = cnt;
		}
	}
	for(int i=1;i<=n;++i)
		ans[a[i]] = i;
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}
