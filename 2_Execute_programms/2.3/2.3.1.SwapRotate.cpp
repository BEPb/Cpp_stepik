// task 2.3.1.

// функция замены двух элементов, решается путем подмены адресов ячеек массива
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// функция которая получает на вход массив, его размер и величину сдвига и реализует саму замену элементов
void rotate(int a[], unsigned size, int shift)
{
	for (int j = 0; j < shift; j++)
	{
		for (int i = 0; i < size; i++)
		{
			swap(a[(i - 1 + size) % size], a[i]);
		}
		swap(a[size - 1], a[size - 2]);
	}
}