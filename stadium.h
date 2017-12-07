
/**
 * Structure that models a Major League Baseball Stadium
 */
typedef struct {
	char *name;
	char *teamName;
	char *city;
	char *state;
	int yearBuilt;
	double latitude;
	double longitude;
} Stadium;

typedef enum {
  NAME,
  TEAM,
  AGE,
  AGE_NEWEST,
  STATE_CITY,
  LATITUDE,
  LONGITUDE,
} Order;

/**
 * A builder function to create an instance of a Stadium with
 * the provided values.  
 */
Stadium * createStadium(const char *name,
			const char *teamName,
			const char *city,
			const char *state,
			int yearBuilt,
			double latitude,
			double longitude);

/**
 * A function to convert a Stadium instance to a human-readable
 * string representation.
 */
char * stadiumToString(const Stadium *s);

/**
 * Returns the air distance (using the Spherical Law of Cosines
 * between the two stadiums based on their latitude/longitude.
 */
double getAirDistance(const Stadium *s1, const Stadium *s2);

/**
 * Returns the total air distance between each contiguous 
 * stadium in the given array containing n stadiums.
 */
double getAirDistances(const Stadium *stadiums, int n);

/**
 * Comaprator function that orders stadiums by their name (alphabetic order)
 */
int cmpStadiumByName(const void *s1, const void *s2);

/**
 * Comaprator function that orders stadiums by their team name (alphabetic order)
 */
int cmpStadiumByTeamName(const void*s1, const void*s2);

/**
 * Comaprator function that orders stadiums by their age (oldest first)
 */
int cmpStadiumByAge(const void*s1, const void*s2);

/**
 * Comaprator function that orders stadiums by their age (newest first)
 */
int cmpStadiumByAgeNewestFirst(const void*s1, const void*s2);

/**
 * Comaprator function that orders stadiums by first by their state
 * then by their city (alphabetic order)
 */
int cmpStadiumByStateCity(const void*s1, const void*s2);

/**
 * Comaprator function that orders stadiums by their name latitude, (south to north)
 */
int cmpStadiumByLatitude(const void*s1, const void*s2);

/**
 * Comaprator function that orders stadiums by their name longitude (west to east)
 */
int cmpStadiumByLongitude(const void*s1, const void*s2);

/**
 * A function that sorts the given array of stadiums (containing n elements) according
 * to the specified order.  
 */
void sortStadiums(Stadium *stadiums, int n, Order order);
