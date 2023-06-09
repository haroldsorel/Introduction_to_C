#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int one, int two, int three, int sum, int *nums)
{
    if (one != two && two != three && one != three)
    {
        sum = 0;
        sum += nums[one] + nums[two] + nums[three];
    }
    return sum;
}



int threeSumClosest(int* nums, int numsSize, int target)
{
    int sum = nums[0] + nums[1] + nums[2], candidat;
    for (int i = 0; i < numsSize/sizeof(nums[0]); i++)
    {
        for (int j = 0; j < numsSize/sizeof(nums[0]); j++ )
        {
            for (int k = 0; k < numsSize/sizeof(nums[0]); k++ )
            {
                candidat = foo(i, j, k, sum, nums);
                if (abs(candidat - target) < abs(sum - target))
                {
                    sum = candidat;
                }

            }
        }
    }
    return sum;
}

int main()
{
    int nums[4] = {1, 1, -1, - 1};
    int target = -3;
    int numsSize = sizeof(nums);
    printf("%d", threeSumClosest(nums, numsSize, target));
    return 0;
}
