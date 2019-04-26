# include <stdio.h>
# include <stdlib.h>
# include <string>
# include <string.h>

int s[33];

int out(int m, int k) {
	int point = -1;
	int t = m;
	int tmp = k;
	while (k --) {
		m = t;
		while(m --) {
			while (!s[(++ point) % (s[30])]);
		}
		point = point % (s[30]);
		//if (s[point] <= tmp) return 0;
		printf ("%d ", s[point]);
		s[point] = 0;
	}
	return 1;
}

int pre (int k) {
	for (int i = 0; i < k * 2; ++ i) {
		s[i] = i + 1;
	}
}

int go (int n, int &point, int k) {
	while (n --) {
		while (!s[(++ point) % (k * 2)]);
	}
	if(point >= 2 * k)point -= 2 * k;
	int t = s[point];
	s[point] = 0;
	return  t;
}

int check(int m, int k) {
	int tmp = 0;
	for (int i = k * 2; i > k; -- i) {
		tmp = (tmp + m - 1) % i;
		if (tmp < k) return 0;
	}
	return 1;
}

int main () {
	int k;
	memset(s, 0, sizeof(int) * 30);
	for(;;) {
		scanf ("%d", &k);
		if (!k) return 0;
		//s[30] = k * 2;
		int flag = 0;
		int i;
		for (int x = 1; ; x++) {
			if (check(x * (k + 1),k)) {printf("%d\n", x * (k + 1)); break;};
			if (check(x*(k+1) + 1,k)) {printf("%d\n", x* (k + 1) + 1); break;}
			/*
			flag = 0;
			i = x * (k + 1);
here:
			//int point = -1;
			int j;
			int tmp = 0;
			//if (tmp <= k && tmp > 0) continue;
			//pre(k);
			//tmp = 0;
			for (j = 0; j < k; ++ j) {
				tmp = (i + tmp - 1) % (k * 2 - j);
				//if (tmp == 0) tmp = 2 * k - j;
				if (tmp < k)break;
				//if (go(tmp, point, k) <= k) break;
			}
			if (j == k) {
				printf ("%d ", i);
				//pre(k);
				//out(i, k);
				break;
			}
			if (!flag) {i = x * (k + 1) + 1; flag = 1;goto here; }
			*/
			/*
			int t = i % (k * 2);
			if (t <= k && t > 0) continue;
			//printf ("%d        ", i);
			go (k);
			if ( out(i, k) ) {
				printf ("%d\n", i);
				break;
			}
			*/
		}
	}
	return 0;
}