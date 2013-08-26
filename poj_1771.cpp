#include<cstdio>

#define MAXN 35

int floor[MAXN];
int stop[MAXN];
int result[MAXN];

int n, stop_index, ans;

bool possible(int time) {
	int last_stop = 1, time_to_last_stop = 0, time_to_i, x;
	stop_index = 0;
	for (int i = 0; i < n; ++i) {
		if (floor[i] <= last_stop) continue;
		time_to_i = time_to_last_stop + (floor[i]-last_stop)*20;
		if (time_to_i < time) continue;
		// need another stop, and with this extra stop the time to floor[i] need <= time
		// formular: assume should stop at x, greedy algorithm to select a x which x >= floor[i],
		// so other unchecked floor will closer to x 
		// 20*(x-floor[i]) + time_to_last_stop + 10 + 4*(x-last_stop) <= time (if at least stop 1 before)
		// 20*(x-floor[i]) + 4*(x-last_stop) <= time
		int temp = time_to_last_stop ? time_to_last_stop + 10 : 0; 
		x = (time - temp + 20*floor[i] + 4*last_stop)/24;
		if (x < floor[i]) return false;
		time_to_last_stop = temp + (x-last_stop)*4;
		last_stop = x;
		stop[stop_index++] = last_stop;
	}
	return true;
}

void solve() {
	int max = floor[n-1]*4 + 20*(floor[n-1]-floor[0])-1;
	int i, mid, min = 0;
	result[0] = 1;
	result[1] = floor[n-1];
	while (min < max) {
		mid = (max+min)/2;
		if (possible(mid)) {
			ans = mid;
			result[0] = stop_index;
			for (i = 0; i < stop_index; ++i) {
				result[i+1] = stop[i];
			}
			max = mid;
		} else {
			min = mid+1;
		}
	}
	printf("%d\n", ans);
	printf("%d", result[0]);
	for (int i = 1; i <= result[0]; ++i) {
		printf(" %d", result[i]);
	}
	printf("\n");
}

int main() {
#ifdef Debug
	freopen("poj_1771.in", "r", stdin);
#endif
	int i; 
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		for (i = 0; i < n; ++i) {
			scanf("%d", &floor[i]);
		}
		solve();
	}

	return 0;
}
