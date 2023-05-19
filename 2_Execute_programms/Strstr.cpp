int strstr(const char *text, const char *pattern)
{
   int cnt = 0;
    bool is_ok = false;
    if(*pattern)
        do {
            while(text[cnt] && text[cnt] != *pattern) ++cnt;
            if(text[cnt]) {
                int i = 1;
                is_ok = true;
                while(is_ok && pattern[i]) {
                    if(text[cnt + i] && text[cnt + i] == pattern[i])
                        ++i;
                    else
                        is_ok = false;
                }
            }
        } while(!is_ok && text[++cnt]);
    else
        is_ok = true;
 
    return is_ok ? cnt : -1;
}