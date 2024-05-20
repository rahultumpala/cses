/*
Use Binary Lifting to precalculate the children of each node, upto 2^31 children
Then again use binary lifting to query the child

modified to C code because same code in C++ was timing out.
*/

#include<stdio.h>
#include<math.h>

const int MAX_CHILDREN = 31;
int children[200002][MAX_CHILDREN];

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	for (int cur = 1; cur <= n; cur++) {
		scanf("%d", &children[cur][0]);
	}

	for (int j = 1; j < MAX_CHILDREN; j++) {
		for (int cur = 1; cur <= n; cur++) {
			int lift = children[cur][j - 1];
			children[cur][j] = children[lift][j - 1];
		}
	}

	while (m--) {
		int cur, k;
		scanf("%d", &cur);
		scanf("%d", &k);
		int lift = 0;
		while (k > 0) {
			lift = log2(k);
			cur = children[cur][lift];
			k -= 1 << lift;
		}
		printf("%d\n", cur);
	}

	return 0;
}