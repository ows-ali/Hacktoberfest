#include <cstdio>
#include <map>

#define max(a, b) (a > b ? a : b)
#define max_3(a, b, c) max(a, max(b, c))

using namespace std;

const int MAX_N = 10005;
int answer[MAX_N][MAX_N];

map <int, int> previous_occurence;

int main()
{
    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int number_i;
        scanf("%d", &number_i);

        for(int d = 1; d*d <= number_i; d++)
        {
            if(number_i%d == 0)
            {
                int divisor_1 = d, divisor_2 = number_i/d;

                if(previous_occurence[divisor_1] != 0)
                {
                    int left = previous_occurence[divisor_1], right = i;

                    answer[left][right] = max(answer[left][right], divisor_1);
                }

                previous_occurence[divisor_1] = i;

                if(divisor_1 == divisor_2)
                {
                    continue;
                }

                if(previous_occurence[divisor_2] != 0)
                {
                    int left = previous_occurence[divisor_2], right = i;

                    answer[left][right] = max(answer[left][right], divisor_2);
                }

                previous_occurence[divisor_2] = i;
            }
        }
    }

    for(int interval_size = 2; interval_size <= no_of_elements; interval_size++)
    {
        for(int left = 1, right = left + interval_size - 1; right <= no_of_elements; left++, right++)
        {
            answer[left][right] = max_3(answer[left][right], answer[left + 1][right], answer[left][right - 1]);
        }
    }

    while(no_of_queries--)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", answer[left][right]);
    }

    return 0;
}
