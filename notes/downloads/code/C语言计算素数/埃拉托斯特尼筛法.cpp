#include <iostream>
using namespace std;

int main() {
	bool a[101];
	fill_n(a, 101, true);
	for(int i = 2; i < 101; i++) {
		if(a[i] == false) continue;
		for(int j = 2 * i; j < 101; j += i)
			a[j] = false;
	}
	for(int i = 2; i < 101; i++) {
		if(a[i])
			printf("%d ", i);
	}
}
