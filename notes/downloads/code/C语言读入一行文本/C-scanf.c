#include <stdio.h>
int main() {
	char s[20];
	scanf("%[^\n\r]", &s);
	printf("%s", s);
}
