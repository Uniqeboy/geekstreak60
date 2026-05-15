/*
Given a special keyboard that contains only four keys:

Key 1: Prints a single character 'A' on the screen.
Key 2 (Ctrl + A): Selects all the characters currently present on the screen.
Key 3 (Ctrl + C): Copies the selected characters to a buffer.
Key 4 (Ctrl + V): Pastes the content of the buffer onto the screen, appending it to the existing text.
Initially, the screen is empty and the buffer is also empty.

Determine the maximum number of 'A' characters that can be displayed on the screen after performing
exactly n key presses
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    int optimalKeys(int n) {
        if (n <= 6)
            return n;
    
        int screen[n];

        for (int i = 1; i <= 6; i++)
            screen[i - 1] = i;
    
        for (int i = 7; i <= n; i++)
            screen[i - 1] = max(2 * screen[i - 4], max(3 * screen[i - 5], 4 * screen[i - 6]));
    
        return screen[n - 1];
    }
};