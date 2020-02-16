#include <iostream>
#include <vector>
using namespace std;

void get_prime(vector<int> & prime, int n) {
	if(n < 2) return;
	prime.clear();
	vector<bool> is_prime(n + 1, true);
	for(int i = 2; i <= n; i++) {
		if(is_prime[i]) {
			prime.push_back(i);
		}
		for(int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
			is_prime[ i * prime[j] ] = false;
			if(i % prime[j] == 0) break;
		}
	}
}

int main() {
	vector<int> prime;
	get_prime(prime, 100);
	for(vector<int>::iterator it = prime.begin(); it != prime.end(); it++) {
		printf("%d ", *it);
	}
}
