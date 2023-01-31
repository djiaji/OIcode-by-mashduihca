#include <iostream>
using namespace std;
const int N = 114514;
int n,m,t,fa[N],rk[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x,int y) {
	int fx = find(x) , fy = find(y);
	if(rk[fx] < rk[fy]) fa[fx] = fy;
	else fa[fy] = fx;
	if(rk[fx] == rk[fy]) ++rk[fx];
}
void mian() {
	for(int i=1;i<=n;++i)
		fa[i] = i , rk[i] = 1;
	int cnt = n;
	for(int i=1;i<=m;++i) {
		int x,y;
		cin >> x >> y;
		if(find(x) != find(y)) {
			--cnt;
			merge(x,y);
		}
	}
	printf("Case %d: %d\n",t,cnt);
}
int main() {
	while(cin >> n >> m) {
		++t;
		if(n == 0 && m == 0) break;
		mian();
	}
	return 0;
}
