/* LargestSumCalories.cpp
  Author: Kian Dadkhah
  Date: 2023-03-13
  Description: This program reads a file containing a list of calories held by each 'elf" in a group. The file is formatted such that each line contains the calories held by one elf, and each group of elves is separated by a blank line. The program then calculates the sum of calories held by each group of elves, and prints the maximum sum.
  
  Example input file:
  100
  200
  300

  400
  500
  600

  700

  800
  900
  1000
  1100


  Example output:
  Max sum: 2100
  

  Note: This program assumes that the input file is formatted correctly. It does not check for errors in the input file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
  // declare vector to hold sums
  vector<int> sumCalories;
  // declare variable to hold max sum
  int maxSum = 0;

  // open file
  ifstream inFile("input.txt");
  // check if file opened successfully
  if (!inFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }

  // read input file line by line
  string line;
  int sum = 0;
  while (getline(inFile, line)) {
    // if line is empty, add sum to vector and reset sum
    if (line.empty()) {
      sumCalories.push_back(sum);
      sum = 0;
    } else {
      // add calories to sum
      sum += stoi(line);
    }
  }
  // add last sum to vector
  sumCalories.push_back(sum);

  // close file
  inFile.close();

  // find max sum
  for (int i = 0; i < sumCalories.size(); i++) {
    if (sumCalories[i] > maxSum) {
      maxSum = sumCalories[i];
    }
  }

  // print max sum
  cout << "Max sum: " << maxSum << endl;

  return 0;
}