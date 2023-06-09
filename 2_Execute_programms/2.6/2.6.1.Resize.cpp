// task 2.6.1.
char *resize(const char *str, unsigned size, unsigned new_size)  // создаем функцию resize с тремя аргументами на входе
// три аргумента:
// указатель на область памяти, выделенную с помощью оператора new[]  - (*str)
// размер области - (size)
// новый размер - (new_size)

{
    char* newStr = new char[new_size];  // выделяем память для массива указанного нового размера new_size (указатель
                                        // символьной переменной
    for (int i=0; i<size && i<new_size; i++)  // цикл в котором переменная i от 0 до до окончания размера области
    {
        newStr[i] = str[i];  // каждая ячейка нового массива принимает соответсвующую ячейку старого
    }
    delete [] str; // удаляем старый массив
    
    return newStr; // по окончании работы функции возвращаем результат - новый массив (с новым размером)
}