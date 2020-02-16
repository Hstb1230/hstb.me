#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(const int n) {
	int end = sqrt(n) + 1;
	for(int i = 2; i < end; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
	for(int i = 2; i < 10001; i++) {
		if(is_prime(i))
			printf("%d ", i);
	}
}
