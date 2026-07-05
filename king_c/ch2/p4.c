/* Calculate the volume of a sphere given a radius input */
#include <stdio.h>
#include <math.h>

int main(void)
{
    const float pi = 3.141592;
    float radius;
    printf("Enter radius: ");
    scanf("%f", &radius);
    float volume = (4.0f/3.0f) * pi * (radius * radius * radius); 
    float math_volume = (4.0f/3.0f) * pi * powf(radius, 3.0f);
    printf("Radius: %0.2f\n", radius);
    printf("Volume: %0.2f\n", volume);
    printf("Volume with pow: %0.2f\n", math_volume);
    return 0;
}
