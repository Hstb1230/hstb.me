#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>
using namespace std;

int main() {
	int n = 20 + 1;
	int a[n][n];
	memset(a, 0, sizeof(a));
	freopen("demo.csv", "w", stdout);
//	ofstream o("demo.csv");
	vector<int> prime;
	vector<bool> isPrime(n, true);
	for(int i = 2; i < n; i++) {
		int t = 0;
		if(isPrime[i])
			prime.push_back(i);
		for(int j = 0; j < prime.size() && i * prime[j] < n; j++)
//		for(int j = 0; j < prime.size(); j++)
		{
			isPrime[ i * prime[j] ] = false;
//			printf("a[%d][%d]\n", i, t);
			a[t++][i] = i * prime[j];
			if(i % prime[j] == 0) break;
		}
	}
	for(int i = 2; i < n; i++)
		printf("%5d,", i);
	printf("\n");
	for(int i = 0; i < n; i++) {
		for(int j = 2; j < n; j++) {
			if(a[i][j] != 0)
				printf("%5d,", a[i][j]);
			else
				printf("%5c,", ' ');
		}
		printf("\n");
	}
}
