#include <stdio.h>
#include <math.h>

int main() {
    double alpha;
    double z1, z2;

    printf("Enter value a (in  radian): ");
    scanf("%lf", &alpha);

    z1 = 2 * pow(sin(3*M_PI - 2*alpha), 2) * pow(cos(5*M_PI + 2*alpha), 2);
    z2 = 0.25 - 0.25 * sin((5.0*M_PI)/2.0 - 8*alpha);

    printf("z1 = %lf\n", z1);
    printf("z2 = %lf\n", z2);

    return 0;
}
