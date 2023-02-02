#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3005;
int n,m,a[N],w[N][N],f[N][N];
int main() {
	memset(f,0x3f,sizeof(f));
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			w[i][j] = w[i][j-1] + abs(a[i]-a[j]);
	f[0][0] = 0;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=min(m,i);++j) {
			for(int k=0;k!=i;++k) {
				f[i][j] = min(f[i][j],f[k][j-1]+w[(i+k+1)>>1][i]-w[(i+k+1)>>1][k]);
			}
		}
	}
	cout << f[n][m];
	return 0;
}
