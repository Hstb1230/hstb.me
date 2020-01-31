#include <stdio.h>
int main() {
	char s[20] = {0};
	int i = 0;
	while(1) {
		s[i] = getchar();
		if(s[i] == '\n' || s[i] == '\r') break;
		i++;
	}
	printf("%s", s);
}
