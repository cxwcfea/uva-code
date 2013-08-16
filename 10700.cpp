#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>

using namespace std;

#define MAXN 40

char buffer[MAXN];

int main() {
#ifdef Debug
	freopen("10700.in", "r", stdin);
#endif
	int n, i, j;
	long long value, max_v, min_v;
	stack<long long> min_stack;
	stack<long long> max_stack;
	vector<int> min_vector;
	vector<int> max_vector;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; ++i) {
		fgets(buffer, MAXN, stdin);
		int len = strlen(buffer);
		value = 0;
		min_vector.clear();
		max_vector.clear();
		for (j = 0; j < len; ++j) {
			if (buffer[j] == '*') {
				min_vector.push_back(value);
				max_vector.push_back(value);
				value = 0;
				for (vector<int>::iterator iter = max_vector.begin(); iter != max_vector.end(); ++iter) {
					value += *iter;
				}
				max_vector.clear();
				max_stack.push(value);
				value = 0;
			} else if (buffer[j] == '+') {
				max_vector.push_back(value);
				min_vector.push_back(value);
				value = 1;
				for (vector<int>::iterator iter = min_vector.begin(); iter != min_vector.end(); ++iter) {
					value *= *iter;
				}
				min_vector.clear();
				min_stack.push(value);
				value = 0;
			} else {
				if (buffer[j] != EOF && buffer[j] != '\n')
					value = value*10 + (buffer[j]-'0');
			}	
		}
		min_vector.push_back(value);
		max_vector.push_back(value);
		value = 0;
		for (vector<int>::iterator iter = max_vector.begin(); iter != max_vector.end(); ++iter) {
			value += *iter;
		}
		max_stack.push(value);
		value = 1;
		for (vector<int>::iterator iter = min_vector.begin(); iter != min_vector.end(); ++iter) {
			value *= *iter;
		}
		min_stack.push(value);
		max_v = 1;
		while (!max_stack.empty()) {
			value = max_stack.top();
			max_stack.pop();
			max_v *= value;
		}
		min_v = 0;
		while (!min_stack.empty()) {
			value = min_stack.top();
			min_stack.pop();
			min_v += value;
		}
		printf("The maximum and minimum are %lld and %lld.\n", max_v, min_v);
	}
	return 0;
}
