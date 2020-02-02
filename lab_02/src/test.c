#include <stdio.h>
#include <stddef.h>
#include "test_str.h"

int main() {
	test_strcpy();
	test_strcat();
	test_strcmp();
	test_strlen();
	printf("%s\n", "OK!");
	return 0;
}