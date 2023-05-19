char *resize(const char *str, unsigned size, unsigned new_size)
{
    char* newStr = new char[new_size];
    for (int i=0; i<size && i<new_size; i++)
    {
        newStr[i] = str[i];
    }
    delete [] str;
    
    return newStr;
}