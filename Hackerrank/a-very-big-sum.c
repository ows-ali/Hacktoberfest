long aVeryBigSum(int ar_count, long* ar) {
    int count = 0;
    long long int sum = 0;
    
    for(; count < ar_count; ++count) {
        sum += ar[count];
    }

    return sum;
}
