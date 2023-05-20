void swap_min(int* m[], unsigned rows, unsigned cols)
{
	int min = m[0][0];
	int minRow = 0;
	for (int k = 0; k < rows; k++)
	{
		for (int l = 0; l < cols; l++)
		{
			if (min > m[k][l])
			{
				min = m[k][l];
				minRow = k;
			}
		}
	}
	int* tmp;
	if (minRow != 0)
	{
		tmp = m[0];
		m[0] = m[minRow];
		m[minRow] = tmp;
	}
}