# -*- coding: utf-8 -*-
"""
Created on Fri Jul 19 20:14:02 2019

@author: yxy
"""

import numpy as np
import time

class Solution:
    def primePalindrome(self, N: int) -> int:
        print(N)
        num = N
        while True:
            # find the prime number
            while True:
                find_prime = True
                
                # Special input
                if num <= 1:
                    return 2
                
                for i in range(2,int(np.sqrt(num))+1):
                    if (num%i == 0):
                        find_prime = False
                        num += 1
                        break
                    
                    if (i==int(np.sqrt(num))):
                        find_prime = True
                        break
                    
                if find_prime:
                    break
            
            # whether is palindrome
            reverse = 0
            cur = int(num)
            while True:
                reverse = 10*reverse + cur%10
                
                if (cur//10 == 0):
                    break
                
                cur //= 10
            
            if reverse == num:            
                break
            else:
                num += 1
            
        return num

if __name__ == "__main__":
    S = Solution()
    # now = time.time()
    print(S.primePalindrome(3503054))
    # print(time.time() - now)