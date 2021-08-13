// https://leetcode.com/problems/trapping-rain-water/solution/

/*
*Brute Force Method**

left k max point nikalo quki utna highest pani bhar sakta hai, right ka maximum pani nikalo kyuki highest pani bhar sakta hai, then dono ka minimum lo kyuki highest level of water minimum vli height jitna hoga. 

iske basis p iterate karlo 
O(n * n)
```
*/
int ans = 0;
for (int i = 0; i < height.size(); i++)
{

    int leftMax = 0, rightMax = 0;
    for (int j = i; j < height.size(); j++)
    {
        rightMax = max(rightMax, height[j]);
    }

    int j = i;
    while (j >= 0)
    {
        leftMax = max(leftMax, height[j]);
        j--;
    }
    ans += min(leftMax, rightMax) - height[i];
}
/*```

**optimizing the above approach **

Instead of using innerLoops let's use an array which increases space complexity by 2n but reduce time by n
Humme pta hai kee leftMax chaiye and rightMax chaiye harr point p 
toh dono ko leftMax and rightMax arrays mein store kar lete hein taaki Humare pass ek hee iteration mein dono ho 

Isse humari space complexity increase ho jayegi kyuki hum array mein store kar rhay hein 

```*/

int rightMax[n], leftMax[n], lMax, rMax;
lMax = rMax = 0;

for (int i = 0; i < height.size(); i++)
{
    lMax = max(lMax, height[i]);
    leftMax[i] = lMax;
}

for (int j = n - 1; j >= 0; j--)
{
    rMax = max(rMax, height[j]);
    rightMax[j] = rMax;
}

for (int i = 0; i < n; i++)
{
    ans += min(leftMax[i], rightMax[i]) - height[i];
}

return ans;
/*
 ```

**3rd Approach using Stack optimize space complexity**

Ab space complexity ko kam karna hai toh yeh sochna hoga kee arrays kee jagah aur lya lia jaye toh humme yaad aaya kee Stack ek acha option hai leftMax and rightMax store karne ka 

Ab Stack mein kya hoga kee humare pass harr last smaller save rahega jab tak bada tower nhi aata aate hee last small ko uthaye uss tak ka pani calculate karo
aur chr do

*/

stack<int> lastSmallerHeight;
int current = 0;
while (current < n)
{

    while (!lastSmallerHeight.empty() && height[current] > height[lastSmallerHeight.top()])
    {

        int top = lastSmallerHeight.top();
        lastSmallerHeight.pop();

        if (lastSmallerHeight.empty())
            break;

        int previousHeightIdx = lastSmallerHeight.top();
        int distance = current - previousHeightIdx - 1;
        int boundaryHeight = min(height[current], height[previousHeightIdx]) - height[top];

        ans += distance * boundaryHeight;
    }
    lastSmallerHeight.push(current++);
}