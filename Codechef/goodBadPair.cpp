#include <cstdio>

int no_of_bits(int n)
{
    int answer = 0;

    while(n)
    {
        n >>= 1;
        answer++;
    }

    return answer;
}

int population_count(int n)
{
    int answer = 0;

    while(n)
    {
        if(n&1 != 0)
            answer++;

        n >>= 1;
    }

    return answer;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf(no_of_bits(a) == no_of_bits(b) && population_count(a) == population_count(b) ? "good" : "bad");

    return 0;
}
