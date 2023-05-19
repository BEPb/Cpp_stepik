unsigned strlen(const char *str)
{
    unsigned len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}