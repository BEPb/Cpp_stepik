// task 2.4.2.
unsigned strlen(const char *str) // Функция strlen возвращает длину строки
{
	unsigned counter = 0;
	while (*str != '\0')
	{
		str++;
		counter++;
	}
	return counter;
}

void strcat(char *to, const char *from)  // Функция strcat объединяет две строки
{
	unsigned len = strlen(to);
	unsigned len2 = strlen(from);
	for (int i = len; i < len + len2; i++)
	{
		to[i] = from[i - len];
	}
    to[len + len2] = '\0';
}
/*
Функция strlen возвращает длину строки, переданной в качестве аргумента. Она работает путем итерации по символам
строки, пока не будет встречен символ конца строки ('\0'), и считает количество символов до этого момента.

Функция strcat объединяет две строки, добавляя содержимое второй строки (from) в конец первой строки (to). Она сначала
находит длину первой строки (to), затем добавляет содержимое второй строки в конец первой строки, начиная со следующего
символа после последнего символа первой строки. В конце она добавляет символ конца строки ('\0') в новую
конкатенированную строку.
*/