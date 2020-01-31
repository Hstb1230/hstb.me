#include <stdio.h>
int main() {
	char s[20] = {0};
	int i = 0;
	while((s[i++] = getchar()) != '\n');
	printf("%s", s);
}
