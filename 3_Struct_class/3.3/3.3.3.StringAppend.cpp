// task 3.3.3.
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

// создаем структуру
struct String {
	String(const char *str = "");  // по умолчанию указатель на пустую строку
	String(size_t n, char c);  // размер строки и символ
	~String();  // деструктор строки


	void append(String& other)  // неопределенная функция добавления на входе две строки
	{
		char* tmp = new char[this->size + other.size + 1];  // указатель на временный массив размером в две строки + 1 символ

		for (int i = 0; i < this->size; i++)  // проходим по всем элементам первой строки
		{
			tmp[i] = this->str[i];  // записываем в результир. массив первую строку
		}

		for (int i = this->size; i < this->size + other.size; i++) // дописываем вторую строку в результ. массив
		{
			tmp[i] = other.str[i - this->size];
		}
		tmp[this->size + other.size] = '\0';  // в конце дописываем символ окончания '\0'
		delete[] this->str;  // удаляем исходную строку
		this->str = new char[this->size + other.size + 1];  // создаем по старому указателю строки новый массив
		for (int i = 0; i < this->size + other.size + 1; i++)  // переносим все значения полного массива в старую строку
		{
			this->str[i] = tmp[i];
		}
		delete[] tmp;  // удаляем временный массив
		this->size += other.size;  // определяем размер итогового массива
	}

	size_t size;  // переменная размер
	char *str;  // переменная указатель строки
};