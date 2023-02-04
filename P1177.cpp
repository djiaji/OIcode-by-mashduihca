#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
using namespace std;
const int N = 1919810;
int n,a[N],b[N],c[N];
int main() {
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> a[i];
	int mask = (1 << 8) - 1;
	for(int i=0;i<32;i+=8) {
		for(int j=0;j<=mask;++j) c[j] = 0;
		for(int j=1;j<=n;++j) ++c[a[j]>>i&mask];
		partial_sum(c,c+mask+1,c);
		for(int j=n;j>=1;--j) b[c[a[j]>>i&mask]--]=a[j];
		copy_n(b+1,n,a+1);
	}
	for(int i=1;i<=n;++i) cout << a[i] << ' ';
	return 0;
}
