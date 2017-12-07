package unl.cse;

import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Stadium {

    String name;
    String teamName;
    String city;
    String state;
    int yearBuilt;
    double latitude;
    double longitude;

    public Stadium(String name,
                   String teamName,
                   String city,
                   String state,
                   int yearBuilt,
                   double latitude,
                   double longitude) {
        this.name = name;
        this.teamName = teamName;
        this.city = city;
        this.state = state;
        this.yearBuilt = yearBuilt;
        if(latitude > -180 && latitude < 180){
            this.latitude = latitude;
        }else{
            this.latitude = 0;
        }
        if(longitude > -180 && longitude < 180){
            this.longitude = longitude;
        }else{
            this.longitude = 0;
        }
    }

    public String getName(){
        return this.name;
    }

    public String getTeamName(){
        return this.teamName;
    }

    public String getCity(){
        return this.city;
    }

    public String getState(){
        return this.state;
    }

    public int getYearBuilt(){
        return this.yearBuilt;
    }

    public double getLatitude(){
        return this.latitude;
    }

    public double getLongitude(){
        return this.longitude;
    }

    @Override
    public String toString() {
        String outPut = name + ", home of the " + teamName + ", (" + yearBuilt
                + ") " + city + ", " + state + " (" + latitude + ", " + longitude + ")";
        return outPut;
    }

    public double getAirDistance(Stadium destination) {
        return Math.acos(Math.sin(Math.toRadians(this.latitude)) * Math.sin(Math.toRadians(destination.latitude))
                + Math.cos(Math.toRadians(this.latitude)) * Math.cos(Math.toRadians(destination.latitude))
                * Math.cos(Math.toRadians(destination.longitude) - Math.toRadians(this.longitude))) * 6371;
    }

    public static double getAirDistances(List<Stadium> stadiums) {
        double distance = 0;
        for(int i = 1; i < stadiums.size(); i++){
            distance += stadiums.get(i - 1).getAirDistance(stadiums.get(i));
        }
        return distance;
    }

    public static final Comparator<Stadium> byName = new Comparator<Stadium>() {
        @Override
        public int compare(Stadium arg0, Stadium arg1) {
            return arg0.getName().compareTo(arg1.getName());
        }
    };

    public static final Comparator<Stadium> byTeamName = new Comparator<Stadium>() {
        @Override
        public int compare(Stadium arg0, Stadium arg1) {
            return arg0.getTeamName().compareTo(arg1.getTeamName());
        }
    };

    public static final Comparator<Stadium> byAge = new Comparator<Stadium>() {
        @Override
        public int compare(Stadium arg0, Stadium arg1) {
            return Integer.compare(arg0.getYearBuilt(), arg1.getYearBuilt());
        }
    };

    public static final Comparator<Stadium> byAgeNewestFirst = new Comparator<Stadium>() {
        @Override
        public int compare(Stadium arg0, Stadium arg1) {
            return Integer.compare(arg1.getYearBuilt(), arg0.getYearBuilt());
        }
    };

    public static final Comparator<Stadium> byStateCity = new Comparator<Stadium>() {
        @Override
        public int compare(Stadium arg0, Stadium arg1) {
            int value = arg0.getState().compareTo(arg1.getState());
            if(value != 0){
                return value;
            }else{
                return arg0.getCity().compareTo(arg1.getCity());
            }
        }
    };

    public static final Comparator<Stadium> byLatitude = new Comparator<Stadium>() {
        @Override
        public int compare(Stadium arg0, Stadium arg1) {
            return Double.compare(arg0.getLatitude(), arg1.getLatitude());
        }
    };

    public static final Comparator<Stadium> byLongitude = new Comparator<Stadium>() {
        @Override
        public int compare(Stadium arg0, Stadium arg1) {
            return Double.compare(arg0.getLongitude(), arg1.getLongitude());
        }
    };

    public static void sortStadiums(List<Stadium> stadiums, Order order) {
        switch (order)
        {
            case NAME:
                Collections.sort(stadiums, byName);
                break;
            case TEAM:
                Collections.sort(stadiums, byTeamName);
                break;
            case AGE:
                Collections.sort(stadiums, byAge);
                break;
            case AGE_NEWEST:
                Collections.sort(stadiums, byAgeNewestFirst);
                break;
            case STATE_CITY:
                Collections.sort(stadiums, byStateCity);
                break;
            case LATITUDE:
                Collections.sort(stadiums, byLatitude);
                break;
            case LONGITUDE:
                Collections.sort(stadiums, byLongitude);
                break;
            default:
                System.out.println("Error, please input an order");
                return;
        }
    }

}