#include<stdlib.h>
#include<stdio.h>
#include<math.h>

double linear(double x) {
	return x;
}

double quadratic(double x) {
	return x * x;
}

double sinByX(double x) {
	if (x == 0) {
		//Returns one because the limit as x approaches 0 is equal to 1
		return 1;
	}
	return sin(x) / x;
}

double rectangleIntegration(double a, double b, double n, double(*f)(double)) {
	if (f == NULL) {
		//returns b - a because we are assuming no function inputted means that f(x) = 1
		return b - a;
	}
	else if (n <= 0) {
		//returns 0 because you need positive sub-intervals, and a positive or negative number is a sum
		return 0;
	}
	double h = (b - a) / n, sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += h * f(a + i * h);
	}
	return sum;
}

double trapazoidIntegration(double a, double b, double n, double(*f)(double)) {
	if (f == NULL) {
		//returns b - a because we are assuming no function inputted means that f(x) = 1
		return b - a;
	}
	else if (n <= 0) {
		//returns 0 because you need positive sub-intervals, and a positive or negative number is a sum
		return 0;
	}
	double h = (b - a) / n, sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += h * ((f(a + i * h) + f(a + (i + 1) * h)) / 2);
	}
	return sum;
}

double simpsonIntegration(double a, double b, double n, double(*f)(double)) {
	if (f == NULL) {
		//returns b - a because we are assuming no function inputted means that f(x) = 1
		return b - a;
	}
	else if (n <= 0) {
		//returns 0 because you need positive sub-intervals, and a positive or negative number is a sum
		return 0;
	}
	double h = (b / n - a / n), sum = 0.0;
	int i;
	for (i = 0; i < n; i++) {
		sum += h / (double)6 * (f(a + (double)i * h) + (double)4 * f((a + (double)i * h + a + (double)(i + 1) * h) / 2.0) + f(a + (double)(i + 1) * h));
	}
	return sum;
}