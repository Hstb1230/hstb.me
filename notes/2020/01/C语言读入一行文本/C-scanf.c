#include <stdio.h>
int main() {
	char s[20];
	while(scanf("%[^\n\r]", &s))
		printf("%s", s);
}
