// task 4.4.1.
bool check_equals(Expression const *left, Expression const *right)
{
    return ((void(*(*(&)[2]))(const Expression&))left)[0][0] == ((void(*(*(&)[2]))(const Expression&))right)[0][0];
}