#include "pa03.h"
#include <string.h>

void sortStringCharacters(char *str){
	qsort(str, strlen(str), sizeof(char), charcompare);
	return;
}

int charcompare(const void *a, const void *b){
	const char x = *(const char *)a;
	const char y = *(const char *)b;

	return (int)x - (int)y;
}

void sortStringArray(char * *arrString, int len){
	qsort(arrString, len, sizeof(char*), strcompare);
	return;
}

int strcompare(const void *a, const void *b){
	const char **x = (const char * *)a;
	const char **y = (const char * *)b;
	return strcmp(*x, *y);
}

char *strcat_ex(char * *dest, int *n, const char *src){
	size_t src_len = strlen(src);
	size_t dest_len = *dest == NULL? 0:strlen(*dest);
	if (*dest == NULL || (src_len + dest_len + 1 >= *n)) //NULL
	{	*n = 1 + 2*(src_len + dest_len);
		char *buffer = malloc(*n * sizeof(char));
		*buffer = '\0';
		if (*dest != NULL) {
			strcpy(buffer, *dest);
		}
		free(*dest);
		*dest = buffer;
	}	
	strcat(*dest, src);

	return *dest;
}

char * *emplode(const char *str, const char *delims, int *arrLen){
	//Calculate the number of strings we need
	*arrLen = 1;
	const char *pos = str;
	while (*pos != '\0'){
		if (strchr(delims, *pos)){
			(*arrLen)++;
			pos++;
		}
	}

	//Create the array of strings
	char * *string_list = malloc(*arrLen * sizeof(char*));

	//Split the string into substrings
	int i = 0;
	const char *start = str;
	pos = str;
	while(*pos != '\0')	{
		if(strchr(delims, *pos)){
			int len = pos - start;
			string_list[i] = malloc((len+1) * sizeof(char));
			memcpy (string_list[i], start, len * sizeof(char));
			string_list[i][len] = '\0';
			i++;
			start = pos + 1;
		}
		pos++;
	}

	//Copy the last string
	int len = pos - start;
	string_list[i] = malloc((len + 1) * sizeof(char));
	memcpy(string_list[i], start, len * sizeof(char));
	string_list[i][len] = '\0';
	return string_list;
}

char * implode(char * *strArr, int len, const char *glue){
	int i;
	char *newarray = NULL;
	int Len = len;
	for (i = 0; i < Len - 1; i++){
		strcat_ex(&newarray, &len, strArr[i]);
		strcat_ex(&newarray, &len, glue);
	}
	strcat_ex(&newarray, &len, strArr[i]);
	return newarray;
}

void destroyStringArray(char * *strArr, int len){
	int i = 0;
	if(strArr == NULL) {return;}
	for(i = 0; i < len; i++){
		free(strArr[i]);
	}
	free(strArr);
	return;
}
