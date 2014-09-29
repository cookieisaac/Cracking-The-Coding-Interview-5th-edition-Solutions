#include "Solution.h"

void reverse(char* str)
{
	int end_pos = 0;
	for (; str[end_pos] != '\0'; end_pos++);

	for (int i = 0, j = end_pos - 1; i < j; i++, j--)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}