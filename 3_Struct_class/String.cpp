struct String {

	/* Реализуйте этот конструктор */
	String(const char* str = "")
	{
		this->size = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			this->size++;
			i++;
		}
		i = 0;
		this->str = new char[size+1];
		while (str[i] != '\0')
		{
			this->str[i] = str[i];
			i++;
		}
		this->str[i] = '\0';
	}

	size_t size;
	char* str;
};