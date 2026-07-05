/* Program that calculates the value of a sphere
 * with a 10m radius using the formula
 * V = (4/3)pi(r^3)
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    const float pi = 3.14159;
    int radius = 10;
    float volume = (4.0f/3.0f) * pi * (radius * radius * radius); 
    printf("A sphere with a radius of %d units has a volume of %0.2f units.\n", radius, volume);
}
