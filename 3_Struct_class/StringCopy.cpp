#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


    /* Реализуйте конструктор копирования */
	String(const String &other) : size(other.size), str(new char[other.size+1])
    {
        for (int i = 0; i<size + 1; i++)
        {
            str[i] = other.str[i];
        }
    }


	void append(const String &other);

	size_t size;
	char *str;
};