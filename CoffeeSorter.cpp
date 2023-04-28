#include <iomanip>
#include <iostream>
#include <fstream>

#include <utility>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <map>
#include <cmath>

using namespace std::chrono;

class Blend {
private:
    int year;
    std::string country;
    std::string region;
    std::string species;
    int altitude;
    int score;
public:
    Blend();
    Blend(int year, std::string country, std::string region, std::string species, int altitude, int score);



    //getters
    int getYear() { return year; }
    std::string getcountry() { return country; }
    std::string getregion() { return region; }
    std::string getspecies() { return species; }
    int getaltitude() { return altitude; }
    int getscore() { return score; }
};

//IMPLEMENTATION

//Default constructor
Blend::Blend() {
    this->year = 0;
    this->country = "NULL";
    this->region = "NULL";
    this->species = "NULL";
    this->altitude = 0;
    this->score = 0;
};

//Constructor
Blend::Blend(int year, std::string country, std::string region, std::string species, int altitude, int score) {
    this->year = year;
    this->country = country;
    this->region = region;
    this->species = species;
    this->altitude = altitude;
    this->score = score;
}

void dataLoader(std::string filePath, std::vector<Blend>& dataSet) {
    std::ifstream inFile(filePath);

    if (inFile.is_open()) {
        //read the heading data from the file
        std::string lineFromFile;
        std::getline(inFile, lineFromFile);

        //get all entries from the file, one line at a time
        while (getline(inFile, lineFromFile)) {

            std::istringstream stream(lineFromFile); //stream of data from a string

            int year;
            std::string country;
            std::string region;
            std::string species;
            int altitude;
            int score;

            std::string tempYear;
            std::string tempaltitude;
            std::string tempscore;
            
            getline(stream, country, '|');
            getline(stream, region, '|');
            getline(stream, tempaltitude, '|');
            altitude = stoi(tempaltitude);
            getline(stream, tempYear, '|');
            year = stoi(tempYear);
            getline(stream, species, '|');
            getline(stream, tempscore, '|');
            score = stoi(tempscore);

            Blend tempRow(year, country, region, species, altitude, score);
            dataSet.push_back(tempRow);
        }
    }
    else {
        std::cout << filePath << " is not open!" << std::endl;
    }
}

void printSelected(Blend show) {
    std::cout << "Year: " << show.getYear() << std::endl;
    std::cout << "Country: " << show.getcountry() << std::endl;
    std::cout << "Region: " << show.getregion() << std::endl;
    std::cout << "Species: " << show.getspecies() << std::endl;
    std::cout << "Altitude Grown (meters): " << show.getaltitude() << std::endl;
    std::cout << "Tasting Score: " << show.getscore() << std::endl << std::endl;
}

//Swaps two numbers around
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//takes last as pivot and arranges smaller elements to the left
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return(i + 1);

}

//Implements quicksort recursive function
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int partitionIndex = partition(arr, low, high);

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);

    }

}

//Merge sort implementation
void merge(int arr[], int left, int mid, int right)
{
    //merge function inspired by the sorting lecture implementation
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //subarrys big enough for the data
    int X[50000], Y[50000];

    for (int i = 0; i < n1; i++) {
        X[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        Y[j] = arr[mid + 1 + j];
    }
    //merge the arrays X and Y into arr
    int i, j, k;
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (X[i] <= Y[j])
        {
            arr[k] = X[i];
            i++;
        }
        else
        {
            arr[k] = Y[j];
            j++;
        }
        k++;
    }
    //when X or Y runs out of elements, put the rest of the remaining in the array
    while (i < n1)
    {
        arr[k] = X[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = Y[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        //m is the point where the array is divided into two subarrays
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        //merge sorted sub arrays
        merge(arr, left, mid, right);
    }
}

//Bubble Sort implementation
std::vector<Blend> bubbleSort(std::vector<Blend> dataSet, int input) {
    int optionalCounter = 0;
    bool swap = true;
    switch (input) {
    case 1:
        while (swap) {
            swap = false;
            for (unsigned int i = 0; i < dataSet.size() - 95000; i++) {
                if (dataSet[i].getscore() < dataSet[i + 1].getscore()) {
                    std::swap(dataSet[i], dataSet[i + 1]);
                    swap = true;
                }
            }
            optionalCounter++;
            if (optionalCounter % 500 == 0) std::cout << optionalCounter << " passes." << std::endl;
        }
        break;
    case 3:
        while (swap) {
            swap = false;
            for (unsigned int i = 0; i < dataSet.size() - 95000; i++) {
                if (dataSet[i].getYear() < dataSet[i + 1].getYear()) {
                    std::swap(dataSet[i], dataSet[i + 1]);
                    swap = true;
                }
            }
            optionalCounter++;
            if (optionalCounter % 500 == 0) std::cout << optionalCounter << " passes." << std::endl;
        }
        break;
    case 2:
        while (swap) {
            swap = false;
            for (unsigned int i = 0; i < dataSet.size() - 95000; i++) {
                if (dataSet[i].getaltitude() < dataSet[i + 1].getaltitude()) {
                    std::swap(dataSet[i], dataSet[i + 1]);
                    swap = true;
                }
            }
            optionalCounter++;
            if (optionalCounter % 500 == 0) std::cout << optionalCounter << " passes." << std::endl;
        }
        break;
    default:
        std::cout << "Invalid input selectiong for Bubble sort!" << std::endl;
        break;
    }


    return dataSet;
}

int main() {
    std::vector<Blend> dataSet;
    std::map<int, std::string> unsorted;
    std::map<int, std::string> unsorted2;
    std::map<int, std::string> unsorted3;

    std::cout << "Thank you for choosing 'Searching for Java' Coffee sorter!\nPlease wait while we get brewing...\n" << std::endl;

    dataLoader("coffee_100k.CSV", dataSet);

    int input = 0;

    while (input != 8) {
        std::cout << "Coffee Database Menu" << std::endl;
        std::cout << "Choose an option" << std::endl;
        std::cout << "1. Print a country's coffee stats" << std::endl;
        std::cout << "2. Sort data using Quick Sort" << std::endl;
        std::cout << "3. Sort data using Merge Sort" << std::endl;
        std::cout << "4. Sort data using Bubble Sort" << std::endl;
        std::cout << "5. Search how many coffees are produced by a given country." << std::endl;
        std::cout << "6. Search for highest scoring coffee in YEAR" << std::endl;
        std::cout << "7. Search for the highest altitude coffee was grown in YEAR" << std::endl;
        std::cout << "8. Exit" << std::endl;



        std::cin >> input;
        std::string name;;

        if (input == 1) {
            std::cout << "Type the name of the desired country" << std::endl;
            std::cin >> name;
            for (int i = 0; i < dataSet.size(); i++) {
                if (dataSet[i].getcountry() == name) {
                    printSelected(dataSet[i]);
                    break;
                }
            }
        }
        else if (input == 2) {
            std::cout << "Choose an option" << std::endl;
            std::cout << "1. Print the top 5 coffees' countries sorted by score" << std::endl;
            std::cout << "2. Print the top 5 coffees' countries sorted by altitude" << std::endl;
            std::cout << "3. Print the top 5 coffees' countries sorted by year" << std::endl;
            std::cin >> input;

            if (input == 1) {
                //quicksort score

                for (int i = 0; i < 100000; i++) {
                    unsorted[dataSet.at(i).getscore()] = dataSet.at(i).getcountry();
                }
                int* score = new int[100000];

                for (int i = 0; i < 100000; i++) {
                    score[i] = dataSet.at(i).getscore();
                }

                auto start = high_resolution_clock::now();	//Clock referenced from https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
                quickSort(score, 0, unsorted.size() - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                for (int i = 97280 - 6; i < 97280 - 1; i++) {
                    std::cout << unsorted.find(score[i])->second;       //match sorted items to countrys
                    //std::cout << " - " << score[i];
                    //if (score[i] != 2947172) {
                        std::cout << std::endl;
                    //}

                }
                std::cout << "\n" << std::endl;
                std::cout << "Time taken by function: " << duration.count() << " microseconds\n" << std::endl;
            }
            else if (input == 2) {
                //quicksort altitude
                for (int i = 0; i < 100000; i++) {
                    unsorted2[dataSet.at(i).getaltitude()] = dataSet.at(i).getcountry();
                }
                int* altitude = new int[100000];
                for (int i = 0; i < 100000; i++) {
                    altitude[i] = dataSet.at(i).getaltitude();
                }

                auto start = high_resolution_clock::now();	//time calculation
                quickSort(altitude, 0, unsorted2.size() - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                for (int i = 97280 - 6; i < 97280 - 1; i++) {
                    std::cout << unsorted2.find(altitude[i])->second;       //match sorted items to countrys
                    //std::cout << " - " << altitude[i] << " in altitude";
                    if (altitude[i] != 9652) {
                        std::cout << std::endl;
                    }

                }
                std::cout << "\n" << std::endl;
                std::cout << "Time taken by function: " << duration.count() << " microseconds\n" << std::endl;
            }
            else if (input == 3) {
                //quicksort year

                for (int i = 0; i < 100000; i++) {
                    unsorted3[dataSet.at(i).getYear()] = dataSet.at(i).getcountry();
                }
                int* year = new int[100000];
                for (int i = 0; i < 100000; i++) {
                    year[i] = dataSet.at(i).getYear();
                }

                auto start = high_resolution_clock::now();	//time calculation
                quickSort(year, 0, unsorted3.size() - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                for (int i = 97280 - 6; i < 97280 - 1; i++) {
                    std::cout << unsorted3.find(year[i])->second;       //match sorted items to countrys
                    //std::cout << " - " << year[i];
                    if (year[i] != 2015) {
                        std::cout << std::endl;
                    }
                    if (year[i] == 2015) {
                        break;
                    }

                }
                std::cout << "\n" << std::endl;
                std::cout << "Time taken by function: " << duration.count() << " microseconds\n" << std::endl;
            }
        }
        else if (input == 3) {
            std::cout << "Choose an option" << std::endl;
            std::cout << "1. Print top 5 coffees' countries sorted by score" << std::endl;
            std::cout << "2. Print top 5 coffees' countries sorted by altitude" << std::endl;
            std::cout << "3. Print top 5 coffees' countries sorted by year from 2010 - 2018" << std::endl;
            std::cin >> input;
            if (input == 1) {
                for (int i = 0; i < 100000; i++) {
                    unsorted[dataSet.at(i).getscore()] = dataSet.at(i).getcountry();
                }
                int* score = new int[100000];

                for (int i = 0; i < 100000; i++) {
                    score[i] = dataSet.at(i).getscore();
                }

                auto start = high_resolution_clock::now();	//time calculation
                mergeSort(score, 0, unsorted.size() - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                for (int i = 97280 - 6; i < 97280 - 1; i++) {
                    std::cout << unsorted.find(score[i])->second;       //match sorted items to countrys
                    //std::cout << " - " << score[i];
                    if (score[i] != 2947172) {
                        std::cout << std::endl;
                    }

                }
                std::cout << "\n" << std::endl;
                std::cout << "Time taken by function: " << duration.count() << " microseconds\n" << std::endl;
            }
            else if (input == 2) {
                for (int i = 0; i < 100000; i++) {
                    unsorted2[dataSet.at(i).getaltitude()] = dataSet.at(i).getcountry();
                }
                int* altitude = new int[100000];
                for (int i = 0; i < 100000; i++) {
                    altitude[i] = dataSet.at(i).getaltitude();
                }

                auto start = high_resolution_clock::now();	//time calculation
                mergeSort(altitude, 0, unsorted2.size() - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                for (int i = 97280 - 6; i < 97280 - 1; i++) {
                    std::cout << unsorted2.find(altitude[i])->second;       //match sorted items to countrys
                    //std::cout << " - " << altitude[i] << " in altitude";
                    if (altitude[i] != 9652) {
                        std::cout << std::endl;
                    }

                }
                std::cout << "\n" << std::endl;
                std::cout << "Time taken by function: " << duration.count() << " microseconds\n" << std::endl;
            }

            else if (input == 3) {
                for (int i = 0; i < 100000; i++) {
                    unsorted3[dataSet.at(i).getYear()] = dataSet.at(i).getcountry();
                }
                int* year = new int[100000];
                for (int i = 0; i < 100000; i++) {
                    year[i] = dataSet.at(i).getYear();
                }

                auto start = high_resolution_clock::now();	//time calculation
                mergeSort(year, 0, unsorted3.size() - 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                for (int i = 97280 - 6; i < 97280 - 1; i++) {
                    std::cout << unsorted3.find(year[i])->second;       //match sorted items to countrys
                    //std::cout << " - " << year[i];
                    if (year[i] != 2015) {
                        std::cout << std::endl;
                    }
                    if (year[i] == 2015) {
                        break;
                    }

                }
                std::cout << "Time taken by function: " << duration.count() << " microseconds\n" << std::endl;
            }
        }
        else if (input == 4) {
            std::cout << "Hmm, not a great choice. It'll take a long time to sort all of these!\nHow about just the first 5,000?\n" << std::endl;
            std::cout << "Choose an option" << std::endl;
            std::cout << "1. Print the top 5 coffees' countries sorted by score" << std::endl;
            std::cout << "2. Print the top 5 coffees' countries sorted by altitude" << std::endl;
            std::cout << "3. Print the top 5 coffees' countries sorted by year" << std::endl;
            std::cin >> input;

            std::vector<Blend> bubbleSorted;

            if (input == 1) {
                //bubble sort score
                auto start = high_resolution_clock::now();	//time calculation
                bubbleSorted = bubbleSort(dataSet, 1);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                for (unsigned int i = 0; i < 5; i++) {
                    std::cout << i + 1 << ": " << std::endl;
                    printSelected(bubbleSorted[i]);
                }
                double adjustedDuration = (duration_cast<microseconds>(stop - start)).count();
                adjustedDuration = adjustedDuration / 1000000;
                std::cout << "Time taken by function: " << adjustedDuration << " seconds\n" << std::endl;
                adjustedDuration = pow(((sqrt(adjustedDuration) / 5000) * 100000), 2);
                std::cout << "Estimated time taken to sort all coffees: " << adjustedDuration / 60 << " minutes\n" << std::endl;
            }
            else if (input == 2) {
                //bubble sort altitude
                auto start = high_resolution_clock::now();	//time calculation
                bubbleSorted = bubbleSort(dataSet, 2);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                for (unsigned int i = 0; i < 5; i++) {
                    std::cout << i + 1 << ": " << std::endl;
                    printSelected(bubbleSorted[i]);
                }
                double adjustedDuration = (duration_cast<microseconds>(stop - start)).count();
                adjustedDuration = adjustedDuration / 1000000;
                std::cout << "Time taken by function: " << adjustedDuration << " seconds\n" << std::endl;
                adjustedDuration = pow(((sqrt(adjustedDuration) / 5000) * 100000), 2);
                std::cout << "Estimated time taken to sort all coffees: " << adjustedDuration / 60 << " minutes\n" << std::endl;
            }
            else if (input == 3) {
                //bubble sort year
                auto start = high_resolution_clock::now();	//time calculation
                bubbleSorted = bubbleSort(dataSet, 3);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                for (unsigned int i = 0; i < 5; i++) {
                    std::cout << i + 1 << ": " << std::endl;
                    printSelected(bubbleSorted[i]);
                }
                double adjustedDuration = (duration_cast<microseconds>(stop - start)).count();
                adjustedDuration = adjustedDuration / 1000000;
                std::cout << "Time taken by function: " << adjustedDuration << " seconds\n" << std::endl;
                adjustedDuration = pow(((sqrt(adjustedDuration) / 5000) * 100000), 2);
                std::cout << "Estimated time taken to sort all coffees: " << adjustedDuration / 60 << " minutes\n" << std::endl;
            }
            else {
                std::cout << "Please select a valid menu option" << std::endl;
            }

        }
        else if (input == 5) {
            std::cout << "Type the name of the desired country" << std::endl;
            std::cin >> name;
            int count = 0;
            for (int i = 0; i < dataSet.size(); i++) {
                if (dataSet[i].getcountry() == name) {
                    count += 1;
                }
            }
            std::cout << name << " has produced " << count << " coffees in the dataset." << std::endl << std::endl;
        }
        else if (input == 6) {
            std::cout << "Enter year" << std::endl;
            int year;
            std::cin >> year;
            int max = 0;
            std::string countryName;
            int count = 0;
            for (int i = 0; i < dataSet.size(); i++) {
                if (dataSet[i].getYear() == year) {
                    if (dataSet[i].getscore() > max) {
                        max = dataSet[i].getscore();
                        countryName = dataSet[i].getcountry();
                    }
                }
            }
            std::cout << "Highest scoring coffee in " << year << " is from " << countryName << " with a score of: " << max << std::endl << std::endl;
        }
        else if (input == 7) {
            std::cout << "Enter year" << std::endl;
            int year;
            std::cin >> year;
            int max = 0;
            std::string countryName;
            int count = 0;
            for (int i = 0; i < dataSet.size(); i++) {
                if (dataSet[i].getYear() == year) {
                    if (dataSet[i].getaltitude() > max) {
                        max = dataSet[i].getaltitude();
                        countryName = dataSet[i].getcountry();
                    }
                }
            }
            std::cout << "Highest growing altitude in " << year << " is from " << countryName << " with a height of " << max << " meters.\n" << std::endl;
        }
        else if (input == 8) {
            std::cout << "Thank you for using 'Searching for Java' coffee sorter! Goodbye!" << std::endl;
        }



        else {
            std::cout << "Please select a valid menu option" << std::endl;
        }

    }
    return 0;
}