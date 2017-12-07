#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"integrate.h"

int main(int argc, char **argv) {
	{
		//Testing for rectangularIntegration
		double b = 10;
		double a = 0;
		double n = 10;
		double answer = rectangleIntegration(a, b, n, linear);
		printf("Linear:\nExpected Answer: 45\nActual Answer:   %f\n", answer);

		b = 1.9;
		a = -1;
		n = 29;
		answer = rectangleIntegration(a, b, n, quadratic);
		printf("Quadratic:\nExpected Answer: 2.494\nActual Answer:   %f\n", answer);

		b = 8.9;
		a = -10;
		n = 100;
		answer = rectangleIntegration(a, b, n, sinByX);
		printf("Sin By X:\nExpected Answer: 3.30727\nActual Answer:   %f\n", answer);

		b = 100;
		a = 0;
		n = 400;
		answer = rectangleIntegration(a, b, n, sqrt);
		printf("Square Root:\nExpected Answer: 665.391\nActual Answer:   %f\n", answer);

		b = 25;
		a = 0;
		n = 250;
		answer = rectangleIntegration(a, b, n, sin);
		printf("Sin of X:\nExpected Answer: 0.015407\nActual Answer:   %f\n", answer);

		b = 25;
		a = -25;
		n = 500;
		answer = rectangleIntegration(a, b, n, fabs);
		printf("Absolute Value:\nExpected Answer: 625\nActual Answer:   %f\n\n\n", answer);
	}
	{
		//Testing for trapezoidIntegration
		double b = 10;
		double a = 0;
		double n = 10;
		double answer = trapezoidIntegration(a, b, n, linear);
		printf("Linear:\nExpected Answer: 50\nActual Answer:   %f\n", answer);

		b = 1.9;
		a = -1;
		n = 29;
		answer = trapezoidIntegration(a, b, n, quadratic);
		printf("Quadratic:\nExpected Answer: 2.6245\nActual Answer:   %f\n", answer);

		b = 8.9;
		a = -10;
		n = 100;
		answer = trapezoidIntegration(a, b, n, sinByX);
		printf("Sin By X:\nExpected Answer: 3.317739\nActual Answer:   %f\n", answer);

		b = 100;
		a = 0;
		n = 400;
		answer = trapezoidIntegration(a, b, n, sqrt);
		printf("Square Root:\nExpected Answer: 666.641\nActual Answer:   %f\n", answer);

		b = 25;
		a = 0;
		n = 250;
		answer = trapezoidIntegration(a, b, n, sin);
		printf("Sin of X:\nExpected Answer: 0.008790\nActual Answer:   %f\n", answer);

		b = 25;
		a = -25;
		n = 500;
		answer = trapezoidIntegration(a, b, n, fabs);
		printf("Absolute Value:\nExpected Answer: 625\nActual Answer:   %f\n\n\n", answer);
	}
	{
		//Testing for simpsonIntegration
		double b = 10;
		double a = 0;
		double n = 10;
		double answer = simpsonIntegration(a, b, n, linear);
		printf("Linear:\nExpected Answer: 50\nActual Answer:   %f\n", answer);

		b = 1.9;
		a = -1;
		n = 29;
		answer = simpsonIntegration(a, b, n, quadratic);
		printf("Quadratic:\nExpected Answer: 2.61967\nActual Answer:   %f\n", answer);

		b = 8.9;
		a = -10;
		n = 100;
		answer = simpsonIntegration(a, b, n, sinByX);
		printf("Sin By X:\nExpected Answer: 3.31828\nActual Answer:   %f\n", answer);

		b = 100;
		a = 0;
		n = 400;
		answer = simpsonIntegration(a, b, n, sqrt);
		printf("Square Root:\nExpected Answer: 666.663\nActual Answer:   %f\n", answer);

		b = 25;
		a = 0;
		n = 250;
		answer = simpsonIntegration(a, b, n, sin);
		printf("Sin of X:\nExpected Answer: 0.008797\nActual Answer:   %f\n", answer);

		b = 25;
		a = -25;
		n = 500;
		answer = simpsonIntegration(a, b, n, fabs);
		printf("Absolute Value:\nExpected Answer: 625\nActual Answer:   %f\n\n\n", answer);
	}
	return 0;
}