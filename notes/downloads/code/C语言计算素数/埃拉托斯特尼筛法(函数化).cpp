#include <iostream>
#include <vector>
using namespace std;

void getPrime(vector<int> & prime, int n) {
	if(n < 2) return;
	prime.clear();
	vector<bool> isPrime(n + 1, true);
	for(int i = 2; i <= n; i++) {
		if(isPrime[i]) {
			prime.push_back(i);
			for(int j = 2 * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}
}

int main() {
	vector<int> prime;
	getPrime(prime, 10000);
	printf("%d\n", prime.size());
	for(vector<int>::iterator it = prime.begin(); it != prime.end(); it++) {
		printf("%d ", *it);
	}
}
