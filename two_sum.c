#include <iostream>

void printnum(int nums[])
{
    for( int i = 0; i < 2; i++) 
    {
	printf("%d\n", nums[i]);
    }
}


int* twoSum(int* nums, int target, int size)
{
    int res[2], elem1;
    int i1 = 0;
    int i2 = 0;
    int test = 0;
    
    while (test == 0)
    {
        res[0] = i1;
        elem1 = nums[i1];
        i2 = 0;

        while (i2 != size)
        {
            if (i1 != i2)
            {
                if (elem1 + nums[i2] == target)
                {
                    res[1] = i2;
                    test = 1;
                }
            }
            i2++;
        }
        i1++;
    }
    printnum(res);
    return res
}


int main()
	{
	    int nums[] = {3,2,4};
        int size = sizeof(nums)/4;
	    int target = 9;
	    twoSum(nums, target, size);
	}
