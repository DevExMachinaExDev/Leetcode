# include <vector>
# include <algorithm>

// Solution does a binary search on possible answers and then 
int minEatingSpeed(std::vector<int>& piles, int h)
{
    int minimumSpeed = 1;
    int maximumSpeed = *max_element(piles.begin(), piles.end());

    while (minimumSpeed < maximumSpeed)
    {
        int currentSpeed = minimumSpeed + (maximumSpeed - minimumSpeed) / 2;

        long long hoursNeeded = 0;

        for (int pileSize : piles)
        {
            hoursNeeded += (pileSize + currentSpeed - 1) / currentSpeed;

            if (hoursNeeded > h)
            {
                minimumSpeed = currentSpeed + 1;
                break;
            }
        }

        if (hoursNeeded <= h)
            maximumSpeed = currentSpeed;
            
    }

    return minimumSpeed;
}
