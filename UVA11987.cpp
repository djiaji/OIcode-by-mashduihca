#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int N = 114514;
int n,m;
bool isroot[N<<1];
int fa[N<<1],sz[N<<1],sum[N<<1];
int find(int x) {
	return isroot[fa[x]] ? fa[x] : (fa[x] = find(fa[x]));
}
inline void merge_set(int x,int y) {
	int fx = find(x) , fy = find(y);
	isroot[fx] = 0;
	sz[fy] += sz[fx];
	sum[fy] += sum[fx];
	fa[fx] = fy;
}
inline void dig(int x,int y) {
	int fx = find(x) , fy = find(y);
	--sz[fx];
	++sz[fy];
	sum[fx] -= x;
	sum[fy] += x;
	fa[x] = fy;
}
inline pair<int,int> query(int x) {
	int fx = find(x);
	return {sz[fx],sum[fx]};
}
inline void mian() {
	for(int i=n+1;i<=2*n;++i)
		isroot[i] = 1;
	for(int i=1;i<=n;++i)
		fa[i] = i+n , sz[i+n] = 1 , sum[i+n] = i;
	for(int i=1;i<=m;++i) {
		int k,p,q;
		cin >> k >> p;
		if(k == 1) {
			cin >> q;
			if(find(p) != find(q))
				merge_set(p,q);
		}
		else if(k == 2) {
			cin >> q;
			if(find(p) != find(q))
				dig(p,q);
		}
		else {
			pair<int,int> q = query(p);
			int x = q.first , y = q.second;
			cout << x << ' ' << y << '\n';
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(cin >> n >> m) {
		mian();
	}
	return 0;
}
