#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();


	void append(String& other)
	{
		char* tmp = new char[this->size + other.size + 1];
		for (int i = 0; i < this->size; i++)
		{
			tmp[i] = this->str[i];
		}
		for (int i = this->size; i < this->size + other.size; i++)
		{
			tmp[i] = other.str[i - this->size];
		}
		tmp[this->size + other.size] = '\0';
		delete[] this->str;
		this->str = new char[this->size + other.size + 1];
		for (int i = 0; i < this->size + other.size + 1; i++)
		{
			this->str[i] = tmp[i];
		}
		delete[] tmp;
		this->size += other.size;
	}

	size_t size;
	char *str;
};