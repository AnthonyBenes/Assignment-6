#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct{
	char *date;
	double temp;
} WeatherData;

WeatherData ** createDate(FILE *f, int *size) {
	int i, errorCheck;
	char *temp = (char *)malloc(sizeof(char) * 2);
	*size = atoi(fgets(temp, 9 * sizeof(char), f));
	WeatherData **outPut = (WeatherData **)malloc(sizeof(WeatherData *) * (*size));
	for (i = 0; i < (*size); i++) {
		outPut[i] = (WeatherData *)malloc(sizeof(WeatherData));
		outPut[i]->date = (char *)malloc(sizeof(char) * 18);
		errorCheck = fscanf(f, "%s %lf", outPut[i]->date, &(outPut[i]->temp));
		if (errorCheck != 2) {
			return NULL;
		}
	}
	return outPut;
}

int compareStationDates(const void *stationA, const void *stationB) {
	WeatherData *dateA = *(WeatherData **)stationA;
	WeatherData *dateB = *(WeatherData **)stationB;
	//printf("%s, %s\n", dateA->date, dateB->date);
	return strcmp(dateA->date, dateB->date);
}

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Error, please input 2 file names\n");
		return 0;
	}
	FILE *f1 = fopen(argv[1], "r");
	FILE *f2 = fopen(argv[2], "r");
	if (f1 == NULL || f2 == NULL) {
		printf("Error in reading files\n");
		fclose(f1);
		fclose(f2);
		return 0;
	}
	int size1, size2, a = 0, b = 0;
	WeatherData **stationData1 = createDate(f1, &size1);
	WeatherData **stationData2 = createDate(f2, &size2);
	qsort(stationData1, size1, sizeof(WeatherData *), compareStationDates);
	qsort(stationData2, size2, sizeof(WeatherData *), compareStationDates);
	while (a < size1 && b < size2) {
		if (strcmp(stationData1[a]->date, stationData2[b]->date) == 0) {
			if (stationData1[a]->temp != stationData2[b]->temp) {
				printf("Inconsistent Data (%s): A: %.2lf B: %.2lf\n", stationData1[a]->date, stationData1[a]->temp, stationData2[b]->temp);
			}
			a++;
			b++;
		}
		else if (strcmp(stationData1[a]->date, stationData2[b]->date) <= -1) {
			printf("Missing Data (%s) in data set A but not in B\n", stationData1[a]->date);
			a++;
		}
		else if (strcmp(stationData1[a]->date, stationData2[b]->date) >= 1) {
			printf("Missing Data (%s) in data set B but not in A\n", stationData2[b]->date);
			b++;
		}
	}
	fclose(f1);
	fclose(f2);
	return 0;
}