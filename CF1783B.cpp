#include <iostream>
#include <cmath>
using namespace std;
const int N = 105;
int a[N][N];
void mian() {
	int n;
	cin >> n;
	int x[] = {1,-n*n};
	int ptr = 1;
	for(int i=1;i<=n;++i) {
		if(i & 1) {
			for(int j=1;j<=n;++j)
				a[i][j] = abs(x[(++ptr)&1]++);
		}
		else {
			for(int j=n;j>=1;--j)
				a[i][j] = abs(x[(++ptr)&1]++);
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}
int main() {
	int t;
	cin >> t;
	while(t--) mian();
	return 0;
}
