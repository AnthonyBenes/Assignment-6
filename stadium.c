#include"stadium.h"
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#define M_PI 3.14159265358979323846
#define toDegrees(a) (a * 180 / M_PI)
#define toRadians(a) (a * M_PI / 180)
#define RAD_EARTH 6371

//builder function for a stadium struct
Stadium * createStadium(const char *name, const char *teamName, const char *city, const char *state, int yearBuilt, double latitude, double longitude) {
	Stadium *newStadium = (Stadium *)malloc(sizeof(Stadium));
	newStadium->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newStadium->name, name);
	newStadium->teamName = (char *)malloc(sizeof(char) * (strlen(teamName) + 1));
	strcpy(newStadium->teamName, teamName);
	newStadium->city = (char *)malloc(sizeof(char) * (strlen(city) + 1));
	strcpy(newStadium->city, city);
	newStadium->state = (char *)malloc(sizeof(char) * (strlen(state) + 1));
	strcpy(newStadium->state, state);
	newStadium->yearBuilt = yearBuilt;
	if (latitude > -180 && latitude < 180) { //ensures latitude is valid
		newStadium->latitude = latitude;
	}
	else {
		newStadium->latitude = 0;
	}
	if (longitude > -180 && longitude < 180) { //ensures longitude is valid
		newStadium->longitude = longitude;
	}
	else {
		newStadium->longitude = 0;
	}
	return newStadium;
}

//this function returns a string that contains all the information specific to the passed in stadium
char * stadiumToString(const Stadium *s) {
	int size = snprintf(NULL, 0, "%s, home of the %s, (%d) %s, %s (%f, %f)", s->name, s->teamName, s->yearBuilt, s->city, s->state, s->latitude, s->longitude) + sizeof(char);
	char *outPut = (char *)malloc(size);
	size = snprintf(outPut, size, "%s, home of the %s, (%d) %s, %s (%f, %f)", s->name, s->teamName, s->yearBuilt, s->city, s->state, s->latitude, s->longitude);
	return outPut;
}

//using two stadium functions, this function returns the air distance between the two
double getAirDistance(const Stadium *s1, const Stadium *s2) {
	return acos(sin(toRadians(s1->latitude)) * sin(toRadians(s2->latitude)) + cos(toRadians(s1->latitude)) * cos(toRadians(s2->latitude)) * cos(toRadians(s2->longitude) - toRadians(s1->longitude))) * RAD_EARTH;
}

//when passed an array of stadium structs of size n, this function calculates and returns the air distance between every one.
double getAirDistances(const Stadium *stadiums, int n) {
	int i;
	double distance = 0;
	for (i = 0; i < n - 1; i++) {
		distance += getAirDistance(&(stadiums[i]), &(stadiums[i + 1])); //#reusecode
	}
	return distance;
}

//name comparator
int cmpStadiumByName(const void *s1, const void *s2) {
	Stadium *x = (Stadium *)s1;
	Stadium *y = (Stadium *)s2;
	return strcmp(x->name, y->name);
}

//team name comparator
int cmpStadiumByTeamName(const void*s1, const void*s2) {
	Stadium *x = (Stadium *)s1;
	Stadium *y = (Stadium *)s2;
	return strcmp(x->teamName, y->teamName);
}

//age comparator
int cmpStadiumByAge(const void*s1, const void*s2) {
	Stadium *x = (Stadium *)s1;
	Stadium *y = (Stadium *)s2;
	return ((x->yearBuilt - y->yearBuilt) == 0) ? 0 : ((x->yearBuilt - y->yearBuilt) / abs(x->yearBuilt - y->yearBuilt));
}

//reverse age comparator
int cmpStadiumByAgeNewestFirst(const void*s1, const void*s2) {
	return cmpStadiumByAge(s2, s1);
}

//state, then city comparator
int cmpStadiumByStateCity(const void*s1, const void*s2) {
	Stadium *x = (Stadium *)s1;
	Stadium *y = (Stadium *)s2;
	int returnValue = strcmp(x->state, y->state);
	return (!returnValue) ? strcmp(x->city, y->city) : returnValue;
}

//latitude comparator
int cmpStadiumByLatitude(const void*s1, const void*s2) {
	Stadium *x = (Stadium *)s1;
	Stadium *y = (Stadium *)s2;
	return ((x->latitude - y->latitude) == 0.0) ? 0 : (int)((x->latitude - y->latitude) / fabs(x->latitude - y->latitude));
}

//longitude comparator
int cmpStadiumByLongitude(const void*s1, const void*s2) {
	Stadium *x = (Stadium *)s1;
	Stadium *y = (Stadium *)s2;
	return ((x->longitude - y->longitude) == 0.0) ? 0 : (int)((x->longitude - y->longitude) / fabs(x->longitude - y->longitude));
}

//sorts the array of stadiums using the Order value and the above comparators 
void sortStadiums(Stadium *stadiums, int n, Order order) {
	int(*comparator)(const void*s1, const void*s2);
	switch (order) //sets comparator
	{
	case NAME:
		comparator = cmpStadiumByName;
		break;
	case TEAM:
		comparator = cmpStadiumByTeamName;
		break;
	case AGE:
		comparator = cmpStadiumByAge;
		break;
	case AGE_NEWEST:
		comparator = cmpStadiumByAgeNewestFirst;
		break;
	case STATE_CITY:
		comparator = cmpStadiumByStateCity;
		break;
	case LATITUDE:
		comparator = cmpStadiumByLatitude;
		break;
	case LONGITUDE:
		comparator = cmpStadiumByLongitude;
		break;
	default:
		printf("Error, please input an order\n");
		return;
	}
	qsort(stadiums, n, sizeof(Stadium), comparator);  //default sorting
}
