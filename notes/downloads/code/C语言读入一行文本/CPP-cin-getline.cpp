#include <iostream>
using namespace std;

int main() {
	char s[1024];
	cin.getline(s, 1024);
	cout << s << endl;
	cin.getline(s, 1024, '\n');
	cout << s << endl;
}
