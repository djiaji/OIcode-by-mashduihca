#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1919810;
int x,y,ans,fa[N],rk[N],sz[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x,int y) {
	int fx = find(x) , fy = find(y);
	if(fx != fy) {
		if(rk[fx] < rk[fy]) swap(fx,fy);
		fa[fy] = fx;
		sz[fx] += sz[fy];
		if(rk[fx] == rk[fy]) ++rk[fx];
	}
}
int main() {
	while(cin >> x) {
		for(int i=1;i<N;++i)
			fa[i] = i , rk[i] = sz[i] = 1;
		ans = 0;
		while(x != -1) {
			cin >> y;
			if(find(x) == find(y)) ++ans;
			else merge(x,y);
			cin >> x;
		}
		cout << ans << '\n';
	}
	return 0;
}
