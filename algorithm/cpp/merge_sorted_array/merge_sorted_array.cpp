// Source : 
// Author : Edgar Wu
// Date   : 18/04/2021
// Rewrite by myself, but refer from https://github.com/haoel/leetcode

/********************************************************************************** 
* 
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal to m + n such that it has enough space to hold additional elements from nums2.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]

 

Constraints:

    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[i] <= 109



*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx_1 = m-1 ;
        int idx_2 = n-1 ;
        int i;
        for (i = m + n - 1; i >= 0; i--){

            // special case, nums1 is sorted and all of nums2 has been already merged into nums1 (append in this case)
            // so can exit loop now
            if (idx_1 >= 0 && idx_2 < 0)
                break;

            // cause idx_1 is negative, mean that all of nums1 has been move to the tail of the array
            // so do not need to compare, just move nums2 to nums1
            if (idx_1 < 0 && idx_2 >= 0){
                nums1[i] = nums2[idx_2];
                idx_2--;
                continue;
            }

            if (idx_1 >= 0 && idx_2 >= 0){
                if (nums1[idx_1] > nums2[idx_2]){
                    nums1[i] = nums1[idx_1];
                    idx_1--;
                }else{
                    nums1[i] = nums2[idx_2];
                    idx_2--;
                }
            }

        }
    }
    
};

void printArray(int A[], int n) {
    printf("{");
    for(int i=0; i<n; i++) {
        printf("%d, ", A[i]);
    }
    printf("}\n");
}

int main()
{
    int a[]={2,4,6,8,10,0,0,0};
    int b[]={1,3,5};
    merge(a, 5, b, 3 );
    printArray(a,  sizeof(a)/sizeof(int));

    int a1[]={2,4,0,0,0};
    int b1[]={3,5,7};
    merge(a1, 2, b1, 3 );
    printArray(a1, sizeof(a1)/sizeof(int));

    int a2[]={12,14,16,18,20,0,0,0};
    int b2[]={1,3,5};
    merge(a2, 5, b2, 3 );
    printArray(a2,  sizeof(a2)/sizeof(int));

    int a3[]={2,0};
    int b3[]={3,};
    merge(a3, 1, b3, 1 );
    printArray(a3, sizeof(a3)/sizeof(int));

    int a4[]={0,0,0};
    int b4[]={1,3,5};
    merge(a4, 0, b4, 3 );
    printArray(a4, sizeof(a4)/sizeof(int));

    int a5[]={2,4,6,8,10,0,0,0};
    int b5[]={11,13,15};
    merge(a5, 5, b5, 3 );
    printArray(a5,  sizeof(a5)/sizeof(int));

    int a6[]={2,4,0,0,0,0,0,0};
    int b6[]={1,3,5,7,9,11};
    merge(a6, 2, b6, 6 );
    printArray(a6, sizeof(a6)/sizeof(int));

    return 0;


}




