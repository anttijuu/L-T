#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

double adjustHeading(double target, double current);
double adjustHeading2(double target, double current);

const double nudgeClockwise = 0.01;
const double nudgeAntiClockwise = -0.05;

int main() {
   double targetHeading = 275.21;
   double currentHeading = 23.0;

   printf("Starting to adjust current heading %.10lf towards target %.10lf\n", currentHeading, targetHeading);
   // Using the not good adjustHeading, try changing to better adjustHeading2.
   currentHeading = adjustHeading(targetHeading, currentHeading);
   printf("Current heading is %.10lf towards target %.10lf\n", currentHeading, targetHeading);

   return 0;
}

double adjustHeading(double target, double current) {
   while (current != target) {
      if (current < target) {
         current += nudgeClockwise;
      } else {
         current += nudgeAntiClockwise;
      }
      if (current > 360.0) {
         current = 0.01;
      } else if (current < 0.0) {
         current = 359.95;
      }
      printf("...current %.10lf target %.10lf\n", current, target);
   }
   return current;
}

const double TOLERANCE = 0.10;

double adjustHeading2(double target, double current) {
   while (fabs(current - target) > TOLERANCE) {
      if (current < target) {
         current += nudgeClockwise;
      } else {
         current += nudgeAntiClockwise;
      }
      if (current > 360.0) {
         current = 0.01;
      } else if (current < 0.0) {
         current = 359.95;
      }
      printf("...current %.10lf target %.10lf\n", current, target);
   }
   return current;
}
