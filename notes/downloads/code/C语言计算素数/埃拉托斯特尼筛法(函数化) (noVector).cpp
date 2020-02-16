#include <iostream>
#include <memory.h>
using namespace std;

void getPrime(int prime[], int n) {
	if(n < 2) return;
	int t = -1;
	bool isPrime[n + 1];
	memset(isPrime, 1, sizeof(isPrime));
	for(int i = 2; i <= n; i++) {
		if(isPrime[i]) {
			prime[++t] = i;
			for(int j = 2 * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}
}

int main() {
	int prime[10000] = {0};
	getPrime(prime, 10000);
}
