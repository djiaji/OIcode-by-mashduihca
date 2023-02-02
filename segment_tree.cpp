#include <iostream>
template<typename T> struct Segment_PLR_T { T& p; T& l; T& r; Segment_PLR_T(T& _p,T& _l,T& _r) : p(_p) , l(_l) , r(_r) {} };
template<typename T> struct Segment_P_CLR_T { T& p; const T& l; const T& r; Segment_P_CLR_T(T& _p,const T& _l,const T& _r) : p(_p) , l(_l) , r(_r) {} };
template<typename T,typename Lazy = decltype(nullptr),typename Update = T,typename Query = T>
class Segment_Tree {
public:
	int n;
	T* tree;
	Lazy* tag;
	Query _accu;
private:
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) static inline void assert(bool x,const char* detail = "") { if(!x) { exit(-printf("Segment Tree Runtime Error : \n%s\n",detail)); } }
	void _build(int p,int l,int r) {
		if(l == r) return init(tree[p],tag[p],l);
		int mid = (l + r) >> 1;
		_build(l,mid,p<<1);
		_build(mid+1,r,p<<1|1);
		push_up({tree[p],tree[p<<1],tree[p<<1|1]},{tag[p],tag[p<<1],tag[p<<1|1]});
	}
	Query _query(int L,int R,int l,int r,int p) {
		if(L <= l && r <= R) return tree[p];
		push_down({tree[p],tree[p<<1],tree[p<<1|1]},{tag[p],tag[p<<1],tag[p<<1|1]},l,r);
		int mid = (l + r) >> 1;
		Query ans = _accu;
		if(L <= mid) ans = accumulate(ans,_query(L,R,l,mid,p<<1));
		if(R > mid) ans = accumulate(ans,_query(L,R,mid+1,r,p<<1|1));
		return ans;
	}
	void _update(int L,int R,const Update& u,int l,int r,int p) {
		if(L <= l && r <= R) return modify(tree[p],tag[p],l,r);
		push_down({tree[p],tree[p<<1],tree[p<<1|1]},{tag[p],tag[p<<1],tag[p<<1|1]},l,r);
		int mid = (l + r) >> 1;
		if(L <= mid) _update(L,R,u,l,mid,p<<1);
		if(R > mid) _update(L,R,u,mid+1,r,p<<1|1);
		push_up({tree[p],tree[p<<1],tree[p<<1|1]},{tag[p],tag[p<<1],tag[p<<1|1]});
	}
public:
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) virtual inline void init(T& p,Lazy& t,__attribute__((unused)) int index) { tree[p] = 0; tag[p] = 0; }
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) virtual inline void push_up(const Segment_P_CLR_T<T>& p,__attribute__((unused)) const Segment_P_CLR_T<Lazy>& t) { p.p = p.l + p.r; }
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) virtual inline T accumulate(const Query& ql,const Query& qr,const Query& initval = 0) { return ql + qr; _accu = initval;}
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) virtual inline void modify(T& p,Lazy& t,int l,int r) = 0;
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) virtual inline void push_down(const Segment_PLR_T<T>& p,const Segment_PLR_T<Lazy>& t,int l,int r) = 0;
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) inline void update(int L,int R,const Update& u) { _update(L,R,u,1,n,1); }
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) inline Query query(int L,int R) { return _query(L,R,1,n,1); }
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) inline void build() { assert(n>0,"EmptySizeException"); _build(1,1,n); }
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) inline void build(int _n) { if(tree == nullptr) tree = new T[(n+1)<<2]; if(tag == nullptr) tag = new Lazy[(n+1)<<2]; _build(1,1,n); }
	__attribute__((__gnu_inline__,__always_inline__,__artificial__)) inline void resize(int _n) { n = _n; if(tree != nullptr) delete[] tree , delete[] tag; tree = new T[(n+1)<<2]; tag = new Lazy[(n+1)<<2]; }
	Segment_Tree() { n = 0; tree = tag = nullptr; }
	Segment_Tree(int _n) { n = _n; tree = new T[(n+1)<<2]; tag = new Lazy[(n+1)<<2]; }
	~Segment_Tree() { if(tree != nullptr) delete[] tree; if(tag != nullptr) delete[] tag; }
};
int main() {
	
	return 0;
}
