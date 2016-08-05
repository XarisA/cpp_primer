int fact(int a) {
    int result = 1;
    while (a > 1) {
        result *= a--;
    }
    return result;
}