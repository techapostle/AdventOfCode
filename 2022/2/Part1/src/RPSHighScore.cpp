/*
RPSHighScore.cpp - Program for calculating Rock Paper Scissors High Score.
Author: Kian Dadkhah
Date: 2023-03-13

This program calculates the high score of a Rock Paper Scissors game.

The program will take an input text file called input,txt with the following format:
A Y
B X
C Y

Where A, B, and C are the shapes played by the opponent and X, Y, and Z are the shapes played by the player.
A, B, and C can be either Rock, Paoer, or Scissors.
X, Y, and Z can be either Rock, Paoer, or Scissors.

Each line of the input file represents a round of the game. The first shape is the shape played by the opponent and the second shape is the shape played by the player.
The score of each round is calculated by taking the value of each shape and adding it to the value given by the outcome of the round.
The key value pair of each shape is as follows: Rock = 1, Paper = 2, Scissors = 3.
The key value pairs given by the outcome of the round is as follows: Loss = 0, Draw = 3, Win = 6.

The program will store each score obtained by the player in a vector and then output the sum of all the scores in the vector.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

int main() {
  // Create a vector to store the scores
  std::vector<int> scores;
  // Create an unordered map to store the key value pairs of the shapes
  std::unordered_map<std::string, int> shapes = {{"Rock", 1}, {"Paper", 2}, {"Scissors", 3}};
  // Create an unordered map to store the key value pairs of the outcomes
  std::unordered_map<std::string, int> outcomes = {{"Loss", 0}, {"Draw", 3}, {"Win", 6}};

  // Open the input file
  std::ifstream input("input.txt");
  // Check if the file is open
  if (input.is_open()) {
    // Create a string to store the line
    std::string line;
    // Loop through the file
    while (std::getline(input, line)) {
      // Create a string stream to store the line
      std::stringstream ss(line);
      // Create a string to store the opponent's shape
      std::string opponentShape;
      // Create a string to store the player's shape
      std::string playerShape;
      // Get the opponent's shape
      ss >> opponentShape;
      // Get the player's shape
      ss >> playerShape;
      
      // Store the opponent's shape in a temporary string as either "Rock", "Paper", or "Scissors"
      std::string opponentShapeTemp;
      if (opponentShape == "A") {
        opponentShapeTemp = "Rock";
      } else if (opponentShape == "B") {
        opponentShapeTemp = "Paper";
      } else if (opponentShape == "C") {
        opponentShapeTemp = "Scissors";
      }
      // Store the player's shape in a temporary string as either "Rock", "Paper", or "Scissors"
      std::string playerShapeTemp;
      if (playerShape == "X") {
        playerShapeTemp = "Rock";
      } else if (playerShape == "Y") {
        playerShapeTemp = "Paper";
      } else if (playerShape == "Z") {
        playerShapeTemp = "Scissors";
      }

      // Create a string to store the outcome of the round
      std::string outcome;
      // check the outcome of the round by comparing playerShapeTemp and opponentShapeTemp
      if (playerShapeTemp == opponentShapeTemp) {
        outcome = "Draw";
      } else if (playerShapeTemp == "Rock" && opponentShapeTemp == "Scissors") {
        outcome = "Win";
      } else if (playerShapeTemp == "Rock" && opponentShapeTemp == "Paper") {
        outcome = "Loss";
      } else if (playerShapeTemp == "Paper" && opponentShapeTemp == "Rock") {
        outcome = "Win";
      } else if (playerShapeTemp == "Paper" && opponentShapeTemp == "Scissors") {
        outcome = "Loss";
      } else if (playerShapeTemp == "Scissors" && opponentShapeTemp == "Paper") {
        outcome = "Win";
      } else if (playerShapeTemp == "Scissors" && opponentShapeTemp == "Rock") {
        outcome = "Loss";
      }

      // Calculate the score of the round
      int score = shapes[playerShapeTemp] + outcomes[outcome];
      // Add the score to the vector
      scores.push_back(score);
    }
    // Close the file
    input.close();
  }

  // Create an integer to store the sum of the scores
  int sum = 0;
  // Loop through the vector
  for (int i = 0; i < scores.size(); i++) {
    // Add the score to the sum
    sum += scores[i];
  }
  // Output the sum
  std::cout << sum << std::endl;

  return 0;
}