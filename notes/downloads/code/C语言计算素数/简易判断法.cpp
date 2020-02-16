#include <iostream>
using namespace std;

bool is_prime(int & n) {
	if(n < 2) return true;
	static int prime[10000] = {2};
	static int t = 1;
	int k = 0;
	int end = n / 2;
	for(int i = prime[t - 1] + 1; i <= end; i++) {
		for(int j = k; j < t; j++) {
			if(n % prime[j] == 0) return false;
			if(j + 1 == t && i % prime[j] != 0) {
				k = t;
				prime[t++] = i;
			}
		}
	}
	return true;
}

int main() {
	for(int i = 2; i < 10001; i++) {
		if(is_prime(i))
			printf("%d ", i);
	}
}
