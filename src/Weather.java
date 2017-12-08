import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

public class Weather {
    public static void main(String arg[]){
       
        //ensures two file names are passed in
        if(arg.length != 2){
            System.out.println("Error, Please Input 2 Files");
            System.exit(0);
        }
        try {
            
            //opens files and establishes scanners to read them
            File f1 = new File(arg[0]);
            Scanner s1 = new Scanner(f1);
            File f2 = new File(arg[1]);
            Scanner s2 = new Scanner(f2);
            
            //reads the size of each file/list and creats a String List to hold the info all together
            int size1 = Integer.parseInt(s1.nextLine());
            List<String> station1 = new ArrayList<>(size1);
            for(int i = 0; i < size1; i++) {
                station1.add(i, s1.nextLine());
            }
            int size2 = Integer.parseInt(s2.nextLine());
            List<String> station2 = new ArrayList<>(size2);
            for(int i = 0; i < size2; i++) {
                station2.add(i, s2.nextLine());
            }
            
            //closes files
            s1.close();
            s2.close();
            
            //creates hashmap with the dates as keys
            Map<String, Double> stationData1 = new HashMap<String, Double>(station1.size());
            Map<String, Double> stationData2 = new HashMap<String, Double>(station2.size());
            String[] temporaryDate;
            for(int i = 0; i < station1.size(); i++){
                temporaryDate = station1.get(i).split(" ");  //splits the date from the temp and logs them in the hashmap
                stationData1.put(temporaryDate[0], Double.parseDouble(temporaryDate[1]));
                station1.set(i, temporaryDate[0]);
            }
            for(int i = 0; i < station2.size(); i++){
                temporaryDate = station2.get(i).split(" ");  //splits the date from the temp and logs them in the hashmap
                stationData2.put(temporaryDate[0], Double.parseDouble(temporaryDate[1]));
                station2.set(i, temporaryDate[0]);
            }
            
            //storts the String List
            Collections.sort(station1);
            Collections.sort(station2);
            
            //compares the string list dates. If dates are the same, keys from the hashmap are used to compare temps.
            //If not, the "behind" date is incremented and the loop is repeated. Inconsistencies/errors are printed
            int i = 0, j = 0, compareVal;
            while(i < station1.size() && j < station2.size()){
                compareVal = station1.get(i).compareTo(station2.get(j));
                if(compareVal == 0){
                    if(stationData1.get(station1.get(i)).compareTo(stationData2.get(station2.get(j))) != 0){
                        System.out.println("Inconsistent Data (" + station1.get(i) + "): A: " + stationData1.get(station1.get(i))
                                + " B: " + stationData2.get(station2.get(j)));
                    }
                    i++;
                    j++;
                }
                else if(compareVal <= -1){
                    System.out.println("Missing Data (" + station1.get(i) + ") in data set A but not in B");
                    i++;
                }
                else if(compareVal >= 1){
                    System.out.println("Missing Data (" + station2.get(j) + ") in data set B but not in A");
                    j++;
                }
            }
        } catch(FileNotFoundException fnfe) {  //file input validation
            throw new RuntimeException(fnfe);
        }
    }
}
