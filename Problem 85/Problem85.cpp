#include <iostream>


#define N 2000000
#define upper 20000 //upper limit on the collumns allowed for 2000000 rectangles to even be possible

int main()

{
    long long total_ways = 0;
    int l1 = 1, l2 = 1;
    int closest_dimensions[2] = {0, 0};
    int closest_value = 0;
    while (true) {
        total_ways = 0;
        for (int width = 1; width <= l1; width++)
        {
            for (int height = 1; height <= l2; height++)
            {
                total_ways += (l1 - width + 1) * (l2 - height +1);
            }
        }
        
        if (l1 >= upper) break;
        
        if (total_ways > closest_value && total_ways < N) {
            closest_value = total_ways;
            closest_dimensions[0] = l1; closest_dimensions[1] = l2;
        }

        if (l1 == l2 || total_ways >= N) {
            l1 ++;
            l2 = 1;
        } else {
            l2 ++;
        }

        
        
    }
    std::cout << closest_value << std::endl;
    std::cout << closest_dimensions[0] << " : " << closest_dimensions[1] << std::endl; 
    std::cout << closest_dimensions[0] * closest_dimensions[1] << std::endl;
    return 0;
}