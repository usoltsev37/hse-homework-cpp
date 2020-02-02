#include "str.h"
#include "test_str.h"
#include <assert.h>
#include <string.h>
#include <stddef.h>

void test_strcpy(void) {
	char s1[30] = "";
	const char s2[20] = "abc";
	const char *c = my_strcpy(s1,s2);
	assert(!my_strcmp(s2,c));//
	char s3[40] = "qwert";
	const char s4[20] = "fgdhsjaghshd";
	const char *c1 = my_strcpy(s3,s4);
	assert(!my_strcmp(c1,s4));//
}

void test_strcat(void) {
	char s1[23] = "asdf";
	char s2[23] = "bc";
	char s3[34] = "asdfbc";
	const char *c = my_strcat(s1,s2);
	assert(!my_strcmp(s3,c));//
	char s4[23] = "sqw";
	char s5[23] = "cf";
	char s6[34] = "sqwcf";
	const char *c1 = my_strcat(s4,s5);
	assert(!my_strcmp(s6,c1));//
}

void test_strcmp(void) { 
	char s1[] = "asd";
	char s2[] = "awe";
	//int std = strcmp(s1,s2);
	int c = my_strcmp(s1,s2);
	assert(c < 0);
	char q1[] = "asdf";
	char q2[] = "asdf";
	//int w = strcmp(q1,q2);
	int e = my_strcmp(q1,q2);
	assert(e == 0);
	char z1[] = "axyguyguyg";
	char z2[] = "aahushdfuihssnidnf";
	//int tes = strcmp(z1,z2);
	int bes = my_strcmp(z1,z2);
	assert(bes > 0);
    
}

void test_strlen(void) {
	char s1[5] = "asdf";
	size_t std = (size_t)4;
	size_t c = my_strlen(s1);
	assert(c == std);
	char s2[6] = "as";
	size_t std1 = (size_t)2;
	size_t c1 = my_strlen(s2);
	assert(c1 == std1);
}
