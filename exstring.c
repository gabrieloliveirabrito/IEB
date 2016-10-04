#include "includes.h"

int indexOf(char* str, char wrd)
{
	int i;
	for(i = 0; i < strlen(str); i++)
	{
		if(str[i] == wrd)
			return i;
	}
	return -1;
}

int lastIndexOf(char* str, char wrd)
{
	int i, ind = -1;
	for(i = 0; i < strlen(str); i++)
	{
		if(str[i] == wrd)
			ind = i;
	}
	return ind;
}

char* removeStr(char* str, int start, int end)
{
	if(start >= 0 && end < strlen(str))
	{
		int cnt = end - start;
		int i, j = 0;
		
		char nstr[strlen(str)];
		
		for(i = 0; i < strlen(str); i++)
		{
			if(i < start || i >= end)
			{
				nstr[j++] = str[i];
			}
		}
		nstr[j++] = '\0';
		
		return strdup(nstr);
	}
	return (char*)0xBAADF00D;
}

char* substr(char* str, int start, int end)
{
	if(start >= 0 && end < strlen(str))
	{
		int cnt = end - start;
		int i, j = 0;
		
		char nstr[strlen(str)];
		
		for(i = 0; i < strlen(str); i++)
		{
			if(i > start && i < end)
			{
				nstr[j++] = str[i];
			}
		}
		nstr[j++] = '\0';
		
		return strdup(nstr);
	}
	return (char*)0xBAADF00D;
}

char* insertStr(char *str, int position, char* value)
{
	if(position >= 0 && position < strlen(str))
	{
		char nstr[strlen(str) + strlen(value)];
		int i, j = 0;
		
		for(i = 0; i < strlen(nstr); i++)
		{
			if(i < position)
				nstr[i] = str[i];
			else if(i > position && j < strlen(value))
				nstr[i] = value[j++];
			else
				nstr[i] = str[i - strlen(value)];
		}
		nstr[i++] = '\0';
		
		return strdup(nstr);
	}
	return (char*)0xBAADF00D;
}
