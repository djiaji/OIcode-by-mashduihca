#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 1919810;
long long ans;
struct edge {
	int to,from,col;
	bool operator<(const edge& e) const {
		return col < e.col;
	}
}a[N];
stack<pair<int&,int>> s;
vector<pair<int,int>> g[N];
int n,c,b[N],fa[N],sz[N],rk[N];
int find(int x) {
	while(x != fa[x]) x = fa[x];
	return x;
}
bool merge(int x,int y) {
	int fx = find(x) , fy = find(y);
	if(fx != fy) {
		if(rk[fx] < rk[fy]) swap(fx,fy);
		s.emplace(fa[fy],fa[fy]);
		s.emplace(sz[fx],sz[fx]);
		s.emplace(rk[fx],rk[fx]);
		fa[fy] = fx;
		sz[fx] += sz[fy];
		if(rk[fx] == rk[fy]) rk[fx]++;
		return true;
	}
	return false;
}
void cancel() {
	for(int i=1;i<=3;++i) {
		s.top().first = s.top().second;
		s.pop();
	}
}
void solve(int l,int r) {
	if(l == r) {
		for(const pair<int,int>& p : g[l])
			ans += 1LL*sz[find(p.first)]*sz[find(p.second)];
		return ;
	}
	int mid = (l+r) >> 1 , succss = 0;
	for(int i=l;i<=mid;++i)
		for(const pair<int,int>& p : g[i])
			succss += merge(p.first,p.second);
	solve(mid+1,r);
	while(succss--)
		cancel();
	++succss;
	for(int i=mid+1;i<=r;++i)
		for(const pair<int,int>& p : g[i])
			succss += merge(p.first,p.second);
	solve(l,mid);
	while(succss--)
		cancel();
}
int main() {
	cin >> n;
	for(int i=1;i!=n;++i)
		cin >> a[i].from >> a[i].to >> a[i].col , b[i] = a[i].col;
	sort(b+1,b+n);
	int t = unique(b+1,b+n) - b - 1;
	for(int i=1;i!=n;++i) {
		a[i].col = lower_bound(b+1,b+t+1,a[i].col) - b;
		g[a[i].col].emplace_back(a[i].from,a[i].to);
	}
	for(int i=1;i<=n;++i) fa[i] = i , rk[i] = sz[i] = 1;
	solve(1,t);
	cout << ans;
	return 0;
}
