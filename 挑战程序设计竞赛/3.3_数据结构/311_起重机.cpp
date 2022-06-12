#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e4 + 5;
const double PI = acos(-1.0);
struct Node {
	double x, y, add;//add懒标记 
} tr[N << 2];
int n, m, len[N], s, a;//pre代表与i关节上一次的度数  题目求的是旋转使i与i+1的度数之差为a 并不是旋转a度 
double pre[N], si, co;
void pushup(int id) { //合并2个区间的向量 
	tr[id].x = tr[id << 1].x + tr[id << 1 | 1].x;
	tr[id].y = tr[id << 1].y + tr[id << 1 | 1].y;
}
void pushdown(int id) {
	if (tr[id].add == 0) return;
	//计算出旋转后的向量坐标 
	Node &l = tr[id << 1], &r = tr[id << 1 | 1]; 
	double x, y;
	double a = tr[id].add, co = cos(a), si = sin(a);
	x = co * l.x - si * l.y;
	y = si * l.x + co * l.y;
	l.x = x, l.y = y;
	x = co * r.x - si * r.y;
	y = si * r.x + co * r.y;
	r.x = x, r.y = y;
	l.add += tr[id].add; r.add += tr[id].add;
	tr[id].add = 0;
}
void build(int id, int l, int r) {
	tr[id].add = tr[id].x = 0; 
	if (l == r) {
		tr[id].y = len[l];
		return; 
	}
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	pushup(id); 
}
void update(int id, int l, int r, int x, int y, double a) {
	double xx, yy;
	if (x <= l && r <= y) {
		//旋转a度后这个向量的x,y坐标的变化
		xx = cos(a) * tr[id].x - sin(a) * tr[id].y;
		yy = sin(a) * tr[id].x + cos(a) * tr[id].y;
		tr[id].x = xx, tr[id].y = yy; 
		tr[id].add += a;
		return;
	}
	pushdown(id);
	int mid = (l + r) >> 1;
	if (x <= mid) update(id << 1, l, mid, x, y, a);
	if (y > mid) update(id << 1 | 1, mid + 1, r, x, y, a);
	pushup(id); 
}
int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) scanf("%d", &len[i]), pre[i] = PI; //初始i与i+1这2个向量角度之差默认为180度
		build(1, 1, n); 
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &s, &a);
			double rad = a / 360.0 * 2 * PI; 
			update(1, 1, n, s + 1, n, rad - pre[s]);
			pre[s] = rad; //更新s与s+1之间的角度差 
			printf("%.2f %.2f\n", tr[1].x, tr[1].y); 
		}
		printf("\n");
	}
	return 0;
}
