import static java.lang.System.in;

class Prime
{
    void checkPrime(int... num)
    {
        int len = num.length;
        Boolean flag = false;
        for(int i = 0; i < len; i += 1)
        {
            if (num[i] == 2 || num[i] == 3)
            {
                System.out.print(num[i]+" ");
            }
            else if (num[i] % 2 != 0 && num[i] > 2)
            {
                for(int j = 3; j <= num[i]/2; j += 1)
                {
                    if (num[i] % j == 0)
                    {
                        flag = true;
                    }
                }
                if (flag == false)
                {
                    System.out.print(num[i]+" ");
                }
                flag = false;
            }
        }
        if(flag == false)
        {
            System.out.println();   
        }
    }
}
