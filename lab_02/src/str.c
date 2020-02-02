#include <stdio.h>
#include <stddef.h>
#include "str.h"

char *my_strcpy(char * restrict s1, const char * restrict s2) { //копируем s2 в s1
	char * restrict ss = s1; 
	while(*s2) {
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = 0;
	return ss;
}

char *my_strcat(char * restrict s1, const char * restrict s2) { //конкатенация 
	char * restrict ss = s1;
	while (*s1)
		s1++;
	while(*s2){
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = 0;
	return ss;
}

int my_strcmp(const char *s1, const char *s2) { /////////
	while(*s1 && *s2) {
		if(*s1 != *s2)
			return *s1 - *s2;
		s1++;
		s2++;
	}
	if(*s1 != '\0')
		return 1;
	if(*s2 != '\0')
	    return -1;
	return 0;
}

size_t my_strlen(const char *s) {
	size_t len = 0;
	while(*s) {
		len++;
		s++;
	}
	return len;
}
