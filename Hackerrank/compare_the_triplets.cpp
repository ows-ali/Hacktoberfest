#include <stdio.h>
int main()
{
    int alice[3], k, s_alice = 0, s_bob = 0;
    for(int i = 0; i < 3; ++i)
        scanf("%d", &alice[i]);
    for(int i = 0; i < 3; ++i)
    {
        scanf("%d", &k);
        if(k > alice[i])
            s_bob++;
        else if(alice[i] > k)
            s_alice++;
    }
    printf("%d %d", s_alice, s_bob);
    return 0;
}