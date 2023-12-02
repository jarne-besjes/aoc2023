//
// Created by Jarne Besjes on 02/12/2023.
//

#include "day2.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

int day2::part1() {
    int MAXRED = 12;
    int MAXGREEN = 13;
    int MAXBLUE = 14;

    int sum = 0;

    std::ifstream file("solutions/day2/input");
    std::string line;
    while (std::getline(file, line)) {
        std::string gameIdStr = line.substr(4, line.find_first_of(':') - 4);
        int gameId = std::stoi(gameIdStr);

        // string: "12 red, 5 green, 6 blue; 13 red, 4 green, 7 blue; 14 red, 3 green, 8 blue"
        std::string numbers = line.substr(line.find_first_of(':') + 2, line.size());

        std::vector<std::string> pulls;
        std::string temp;
        for (const char & c : numbers) {
            if (c == ';') {
                pulls.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        pulls.push_back(temp);

        bool possible = true;

        for (std::string& pull: pulls) {
            int red = 0;
            int green = 0;
            int blue = 0;

            // remove spaces
            pull.erase(std::remove(pull.begin(), pull.end(), ' '), pull.end());
            std::istringstream ss(pull);
            std::string token;

            // Create vectors to store the separated values
            std::vector<int> amounts;
            std::vector<std::string> colors;

            while (std::getline(ss, token, ',')) {
                std::istringstream tokenStream(token);
                int number;

                // Try to extract an integer
                if (tokenStream >> number) {
                    amounts.push_back(number);
                }
                std::string color;
                for (char &c: token) {
                    if (c - '0' >= 0 && c - '0' <= 9) {
                        continue;
                    }
                    color += c;
                }
                colors.push_back(color);
            }

            // Check if it's a possible pull
            for (int i = 0; i < colors.size(); ++i) {
                if (colors[i] == "red") {
                    red += amounts[i];
                } else if (colors[i] == "green") {
                    green += amounts[i];
                } else if (colors[i] == "blue") {
                    blue += amounts[i];
                }
            }

            if (red > MAXRED || green > MAXGREEN || blue > MAXBLUE) {
                possible = false;
                break;
            }
        }

        if (possible) {
            sum += gameId;
        }


    }

    return sum;
}

int day2::part2() {
    int sum = 0;

    std::ifstream file("solutions/day2/input");
    std::string line;
    while (std::getline(file, line)) {
        std::string gameIdStr = line.substr(4, line.find_first_of(':') - 4);
        int gameId = std::stoi(gameIdStr);

        // string: "12 red, 5 green, 6 blue; 13 red, 4 green, 7 blue; 14 red, 3 green, 8 blue"
        std::string numbers = line.substr(line.find_first_of(':') + 2, line.size());

        std::vector<std::string> pulls;
        std::string temp;
        for (const char &c: numbers) {
            if (c == ';') {
                pulls.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        pulls.push_back(temp);
        std::vector<std::vector<int>> powerAmounts; // Red, Green, Blue


        for (std::string &pull: pulls) {
            int red = 0;
            int green = 0;
            int blue = 0;

            // remove spaces
            pull.erase(std::remove(pull.begin(), pull.end(), ' '), pull.end());
            std::istringstream ss(pull);
            std::string token;

            // Create vectors to store the separated values
            std::vector<int> amounts;
            std::vector<std::string> colors;

            while (std::getline(ss, token, ',')) {
                std::istringstream tokenStream(token);
                int number;

                // Try to extract an integer
                if (tokenStream >> number) {
                    amounts.push_back(number);
                }
                std::string color;
                for (char &c: token) {
                    if (c - '0' >= 0 && c - '0' <= 9) {
                        continue;
                    }
                    color += c;
                }
                colors.push_back(color);
            }

            // add Red cubes
            for (int i = 0; i < colors.size(); ++i) {
                if (colors[i] == "red") {
                    red += amounts[i];
                } else if (colors[i] == "green") {
                    green += amounts[i];
                } else if (colors[i] == "blue") {
                    blue += amounts[i];
                }
            }

            powerAmounts.push_back({red, green, blue});
        }
        // get minimum amount of cubes of a color
        int minRed = 0;
        int minGreen = 0;
        int minBlue = 0;

        for (std::vector<int>& powerAmount: powerAmounts) {
            if (powerAmount[0] > minRed) {
                minRed = powerAmount[0];
            }
            if (powerAmount[1] > minGreen) {
                minGreen = powerAmount[1];
            }
            if (powerAmount[2] > minBlue) {
                minBlue = powerAmount[2];
            }
        }

        sum += minRed * minGreen * minBlue;

    }

    return sum;
}