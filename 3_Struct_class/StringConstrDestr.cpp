#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {

	String(size_t n, char c) : size(n)
	{
		str = new char[n + 1];
		for (int i = 0; i < n; i++)
		{
			str[i] = c;
		}
		str[n] = '\0';
	}

	~String()
	{
		delete[] str;
	}

	size_t size;
	char* str;
};