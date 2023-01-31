#include <algorithm>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int N = 10005;
int c,r,fa[N],sz[N];
map<string,int> m;
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x,int y) {
	int fx = find(x) , fy = find(y);
	fa[fx] = fy;
	sz[fy] += sz[fx];
}
void mian() {
	for(int i=1;i<=c;++i)
		fa[i] = i , sz[i] = 1;
	for(int i=1;i<=c;++i) {
		string s;
		cin >> s;
		m[s] = i;
	}
	for(int i=1;i<=r;++i) {
		string x,y;
		cin >> x >> y;
		int v = m[x] , w = m[y];
		if(find(v) != find(w))
			merge(v,w);
	}
	cout << *max_element(sz+1,sz+c+1) << '\n';
}
int main() {
	while(cin >> c >> r) {
		if(c + r == 0) break;
		mian();
	}
	return 0;
}
