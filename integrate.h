#pragma once
/**
*Authors: Anthony Benes & Jack Arens
*
*Date: 11/17/17
*
*Description: integrate.c contains several functions used to calculate the integral of a range given a number of sub-sections
*/

/**
*linear is a function that takes in a value and returns it, as x = x
*
*Input: x
*
*Output: x
*/
double linear(double x);

/**
*quadratic is a function that takes in a value and returns the square of it
*
*Input: x
*
*Output: x^2
*/
double quadratic(double x);

/**
*sinByX is a function that takes in a value and returns the sin of that value divided by itself
*
*Input: x
*
*Output: sin(x) / x
*/
double sinByX(double x);

/**
*rectangleIntegration computes the integral of a function between a and b using rectangular integration and n sub-intervals
*
*Input: double a, double b, double n, funciton pointer
*
*Output: rectangular integration (double)
a*/
double rectangleIntegration(double a, double b, double n, double(*f)(double));

/**
*trapezoidIntegration computes the integral of a function between a and b using trapezoidal integration and n sub-intervals
*
*Input: double a, double b, double n, funciton pointer
*
*Output: trapezoidal integration (double)
a*/
double trapazoidIntegration(double a, double b, double n, double(*f)(double));

/**
*simpsonIntegration computes the integral of a function between a and b using simpson integration and n sub-intervals
*
*Input: double a, double b, double n, funciton pointer
*
*Output: simpson integration (double)
a*/
double simpsonIntegration(double a, double b, double n, double(*f)(double));