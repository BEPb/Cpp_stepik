// task 1.8.1.
// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//
int power(int x, unsigned p) {
    int answer = 1;
    for (int i=0; i<p; i++)
    {
        answer *= x;
    }
    return answer;
}