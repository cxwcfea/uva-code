#include<cstdio>
#include<cstring>
#include<ctime>

using namespace std;

#define MAXN 200
#define LEN 40000
int a, b, c, d, _d, _amount;
int st[MAXN+1][MAXN+1][MAXN+1];
typedef enum {
	ATOB,
	ATOC,
	BTOA,
	BTOC,
	CTOA,
	CTOB
} OP;

struct State {
	int _a, _b, _c;
	int amount;
	//State(int a1, int b1, int c1, int am):_a(a1),_b(b1),_c(c1),amount(am) {}
	int last_op;
	bool valid(int op) {
		switch (last_op) {
			case ATOB:
				if (op == BTOA) return false;
				break;
			case ATOC:
				if (op == CTOA) return false;
				break;
			case BTOC:
				if (op == CTOB) return false;
				break;
			case BTOA:
				if (op == ATOB) return false;
				break;
			case CTOA:
				if (op == ATOC) return false;
				break;
			case CTOB:
				if (op == BTOC) return false;
				break;
		}
		return true;
	}
	void init(int a1, int b1, int c1, int am) {
		_a = a1;
		_b = b1;
		_c = c1;
		amount = am;
	}
	int get_max() {
		if (_a <= d && _a > _d) {
			_d = _a;
			_amount = amount;
		}
		if (_b <= d && _b > _d) {
			_d = _b;
			_amount = amount;
		}
		if (_c <= d && _c > _d) {
			_d = _c; 
			_amount = amount;
		}
	}
};

State q[LEN];

int resolve() {
	memset(st, 0, sizeof(st));
	int value, i, temp, _a, _b, _c, amount, ok;
	int front = 0, rear = 0;
	_d = 0;
	_amount = 0;
	State &s = q[rear];
	s.init(0, 0, c, 0);
	s.last_op = 6;
	s.get_max();
	st[0][0][c] = 1;
	++rear;
	while (front != rear) {
		State &current = q[front];
		++front;
		current.get_max(); 
		if (_d == d) {
			return current.amount;
		}
		for (i = 0; i < 6; ++i) {
			if (!current.valid(i)) continue;
			ok = 0;
			switch (i) {
				case ATOB:
					temp = b - current._b;	
					if ((current._a > 0) && (temp > 0)) {
						ok = 1;
						amount = current.amount;
						if (temp >= current._a) {
							amount += current._a;
							_a = 0;
							_b = current._a + current._b;
						} else {
							amount += temp; 
							_a = current._a - temp;
							_b = b;
						}
						_c = current._c;
					}
					break;
				case ATOC:
					temp = c - current._c;	
					if ((current._a > 0) && (temp > 0)) {
						ok = 1;
						amount = current.amount;
						if (temp >= current._a) {
							amount += current._a;
							_a = 0;
							_c = current._a + current._c;
						} else {
							amount += temp; 
							_a = current._a - temp;
							_c = c;
						}
						_b = current._b;
					}
					break;
				case BTOA:
					temp = a - current._a;	
					if ((current._b > 0) && (temp > 0)) {
						ok = 1;
						amount = current.amount;
						if (temp >= current._b) {
							amount += current._b;
							_b = 0;
							_a = current._b + current._a;
						} else {
							amount += temp; 
							_b = current._b - temp;
							_a = a;
						}
						_c = current._c;
					}
					break;
				case BTOC:
					temp = c - current._c;	
					if ((current._b > 0) && (temp > 0)) {
						ok = 1;
						amount = current.amount;
						if (temp >= current._b) {
							amount += current._b;
							_b = 0;
							_c = current._b + current._c;
						} else {
							amount += temp; 
							_b = current._b - temp;
							_c = c;
						}
						_a = current._a;
					}
					break;
				case CTOA:
					temp = a - current._a;	
					if ((current._c > 0) && (temp > 0)) {
						ok = 1;
						amount = current.amount;
						if (temp >= current._c) {
							amount += current._c;
							_c = 0;
							_a = current._a + current._c;
						} else {
							amount += temp; 
							_c = current._c - temp;
							_a = a;
						}
						_b = current._b;
					}
					break;
				case CTOB:
					temp = b - current._b;	
					if ((current._c > 0) && (temp > 0)) {
						ok = 1;
						amount = current.amount;
						if (temp >= current._c) {
							amount += current._c;
							_c = 0;
							_b = current._c + current._b;
						} else {
							amount += temp; 
							_c = current._c - temp;
							_b = b;
						}
						_a = current._a;
					}
					break;
			}
			if (ok) {
				if (!st[_a][_b][_c]) {
					q[rear].init(_a, _b, _c, amount);
					q[rear].last_op = i;
					st[_a][_b][_c] = 1;
					++rear;
				}
			}
		}
	}
	return 0;
}

int main() {
#ifdef Debug
	freopen("10603.in", "r", stdin);
#endif
	int n, result;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		result = resolve();
		if (_d != d) {
			result = _amount;
		}
		printf("%d %d\n", result, _d);
	}
#ifdef Debug
	printf("time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
