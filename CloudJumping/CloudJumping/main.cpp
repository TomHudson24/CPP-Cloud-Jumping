#include <vector>
#include <iostream>

//naive solution 
/*
This does not account for all test cases, its a poor attempt
*/
#if 0
int jumpingOnClouds(std::vector<int> c) {
    int jumps = 0;
    for (int i = 0; i < c.size() - 1; i++) {
        //iterate through the list
        if (c[i] == 0 && c[i + 1] == 0) {
            jumps++;
        }
    }
    return jumps;
}
#endif

//better solution
/*
By which I mean it works.
First, identify any clouds we don't want to jump on, then using a range based for loop (for(declaration : range)) checking each element of the array, 
the % (modulo) and ^ (XOR) operators are used to check a) if the current element is even (or mod 2 == 0) and then if so then b) the found variable 
is XOR'd to reset it for the next iteration.

XOR table for reference:
-------------------------------------------
|   X     |       Y       |       X^Y     |
|---------|---------------|---------------|
|   0     |       0       |        0      |
|---------|---------------|---------------|
|   0     |       1       |        1      |
|---------|---------------|---------------|
|   1     |       0       |        1      |
|---------|---------------|---------------|
|   1     |       1       |        0      |
-------------------------------------------

*/
#if 1
int jumpingOnClouds(std::vector<int> c, int n)
{
    std::vector<int> badClouds;
    int goodClouds = 0;
    int jumps = 0;
    int found = 0;
    for(int c_i = 0; c_i < n; c_i++)
    {
        std::cin >> c[c_i];
        if (c[c_i] == 1) {
            badClouds.push_back(c_i);
        }
    }

    for( auto bc : badClouds)
    {
        if ((bc + found) % 2 == 0)
        {
            goodClouds++;
            found = found ^ 1;
        }     
    }
    goodClouds /= 2;
    jumps = n / 2 + goodClouds;

    return jumps;
}
#endif
int main() 
{
    int n = 7;
    int n2 = 6;

    std::vector<int> c = { 0, 0, 1, 0, 0, 1, 0 };
    std::vector<int> c2 = { 0, 0, 0, 0, 1, 0 };

    std::cout << jumpingOnClouds(c2, n2) << std::endl;

	return 0;

}