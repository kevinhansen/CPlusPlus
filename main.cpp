#include <fstream>
#include <iostream>
#include <string>

const int dayspermonth = 30;
const int monthsperyear = 12;
const std::string weatherConditions[5] = {"\tRainy\t\t", "Flooding\t",
                                          "Cloudy\t\t", "Sunny\t\t", "Armegeddon"};
void readWeatherFile(std::ifstream &, char [monthsperyear][dayspermonth]);
void countConditions(char [monthsperyear][dayspermonth],
                     int monthlyTally[monthsperyear][5],
                      int yearTally[5], int & monthMostSunny);
void printReport(int monthlyTally[monthsperyear][5],
                 int yearTally[5], int monthMostSunny);
int main() {
  std::ifstream infile("C:\\Users\\kdiander"
                               "\\CLionProjects\\untitled\\RainOrShine.txt");
  char weatherArr[monthsperyear][dayspermonth];
  int monthlyTally[monthsperyear][5];
  int yearTally[5];
  int monthMostSunny;
  readWeatherFile(infile, weatherArr);
  countConditions(weatherArr, monthlyTally, yearTally, monthMostSunny);
  printReport(monthlyTally, yearTally, monthMostSunny);
  return 0;
}
void readWeatherFile(std::ifstream & infile,
                     char weatherArr[monthsperyear][dayspermonth]) {
  for(int i = 0; i < monthsperyear; ++i) {
    for(int j = 0; j < dayspermonth; ++j) {
	   	infile >> weatherArr[i][j];
	}
  }
}
void countConditions(char weatherArray[monthsperyear][dayspermonth],
                     int monthlyTally[monthsperyear][5],
                     int yearTally[5], int & monthMostSunny) {
	for(int j = 0; j < 5; ++j) {
        yearTally[j] = 0;
    }
  for(int i = 0; i < monthsperyear; ++i) {
    for(int j = 0; j < 5; ++j) {
		monthlyTally[i][j] = 0;
    }
    for(int j = 0; j < dayspermonth; ++j) {
	   	if (weatherArray[i][j] == 'R') {
         	++monthlyTally[i][0];
          	++yearTally[0];
        } else if (weatherArray[i][j] == 'F') {
         	++monthlyTally[i][1]; 
          	++yearTally[1];
        } else if (weatherArray[i][j] == 'C') {
         	++monthlyTally[i][2]; 
          	++yearTally[2];
        } else if (weatherArray[i][j] == 'S') {
         	++monthlyTally[i][3]; 
          	++yearTally[3];
        } else if (weatherArray[i][j] == 'A') {
         	++monthlyTally[i][4]; 
          	++yearTally[4];
        }      
	 }
  }
   monthMostSunny = 0;
   for(int i = 1; i < monthsperyear; ++i) {
	   if (monthlyTally[i][3] > monthlyTally[monthMostSunny][3]) {
           monthMostSunny = i;
       }
   }
}
void printReport (int monthlyTally[monthsperyear][5],
                  int yearTally[5], int monthMostSunny) {
    std::string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int i = 0; i < 5; ++i) {
        std::cout << weatherConditions[i];
    }
    std::cout << std::endl;
  for(int i = 0; i < monthsperyear; ++i) {
    std::cout << month[i];
    for(int j = 0; j < 5; ++j) {
      	std::cout << '\t'
                  << monthlyTally[i][j] << '\t';
    }
      std::cout << std::endl;
  }
    std::cout << "Total\t";
	for(int j = 0; j < 5; ++j) {
		std::cout << yearTally[j] << '\t' << '\t';
	}
    std::cout << "\nThe sunniest month is: " << month[3]
              << " with 12 days of Sun." << std::endl;
    std::cout << "press Enter to continue";
}