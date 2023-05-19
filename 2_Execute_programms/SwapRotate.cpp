void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

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