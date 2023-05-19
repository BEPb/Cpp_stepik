unsigned strlen(const char *str)
{
	unsigned counter = 0;
	while (*str != '\0')
	{
		str++;
		counter++;
	}
	return counter;
}

void strcat(char *to, const char *from)
{
	unsigned len = strlen(to);
	unsigned len2 = strlen(from);
	for (int i = len; i < len + len2; i++)
	{
		to[i] = from[i - len];
	}
    to[len + len2] = '\0';
}
