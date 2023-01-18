// Copyright (c) 2023 Kaitlyn Ip All rights reserved
//
// Created by: Kaitlyn Ip
// Created on: Jan 2023
// This program prints the odd numbers in a list

#include <iostream>
#include <list>
#include <random>

std::list<int> FindOddPositions(std::list<int> listOfNumbers) {
    // this function prints the odd numbers
    std::list<int> oddNums;
    int loopCounter = 1;

    for (int listItem : listOfNumbers) {
        if (loopCounter % 2 != 0) {
            oddNums.push_back(listItem);
        }
        loopCounter += 1;
    }
    return oddNums;
}

int main() {
    // this function creates 10 random numbers in a list
    std::list<int> listOfNumbers;
    std::random_device rseed;
    std::mt19937 rgen(rseed());                        // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 100);  // [1, 100]
    int loopCounter = 0;
    int randomNum;
    int numberOfElements;
    int length;
    std::list<int> oddNums;
    std::string sNumberOfElements;

    // input, process & output
    std::cout << "# of random numbers you want : ";
    std::cin >> sNumberOfElements;
    try {
        numberOfElements = std::stoi(sNumberOfElements);
        if (numberOfElements > 0) {
            for (int loopCounter = 0; loopCounter < numberOfElements;
                 loopCounter++) {
                randomNum = idist(rgen);
                listOfNumbers.push_back(randomNum);
                std::cout << "The random number " << loopCounter + 1 << " is : "
                          << randomNum << std::endl;
            }
            oddNums = FindOddPositions(listOfNumbers);
            length = oddNums.size();

            std::cout << "\nThe numbers in odd positions in the list are : ";
            for (int listItem : oddNums) {
                std::cout << listItem << " ";
            }
        } else {
            std::cout << "\nThat is a negative number."
                      << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "\nThat is not a valid input." << std::endl;
    }

    std::cout << "" << std::endl;
    std::cout << "\nDone." << std::endl;
}
