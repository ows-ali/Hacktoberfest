int count_ones(int val)
{
	// Using Brian Kernighan’s Algorithm.
	// We are using Bitwise And operator to find no of set bits in a number
 
	int ret=0;
	while(val>0)
	{
		ret++;
		val=val&(val-1);
	}
	return ret;
}
