#include <fstream>
#include <ranges>
#include <iostream>
#include <map>
#include <vector>

#include "day1.h"

 std::map <std::string, int> textToNumber = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6},
                                             {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}};

 int day1::part1() {
    std::ifstream file("solutions/day1/input");
    std::string line;
    int sum = 0;
    while (std::getline(file, line)) {
        std::string number;
        for (char &c: line) {
            if (c - '0' >= 0 && c - '0' <= 9) {
                number += c;
                break;
            }
        }
        for (char &c: std::ranges::reverse_view(line)) {
            if (c - '0' >= 0 && c - '0' <= 9) {
                number += c;
                break;
            }
        }

        sum += std::stoi(number);
    }
    return sum;
}

int day1::part2() {
    std::ifstream file("solutions/day1/input");
    std::string line;
    int sum = 0;

    // get keys of map
    std::vector<std::string> keys;

    for (auto const& imap: textToNumber) {
        keys.push_back(imap.first);
    }

    // numbers can also be spelled out
    while (std::getline(file, line)) {
        // check if numbers are spelled out and get their indices
        std::vector<int> indices;
        std::vector<int> numbers;
        std::string number;
        for (int i = 0; i < line.size(); i++) {
            for (const std::string& key: keys) {
                if (line.substr(i, key.size()) == key) {
                    indices.push_back(i);
                    numbers.push_back(textToNumber[key]);
                }
            }
        }

        // find first number
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] - '0' >= 0 && line[i] - '0' <= 9) {
                if (indices.empty()) {
                    number += line[i];
                    break;
                }
                if (i < indices[0]) {
                    number += line[i];
                } else {
                    number += std::to_string(numbers[0]);
                }
                break;
            }
        }

        // find last number
        for (int i = line.size() - 1; i >= 0; --i) {
            if (line[i] - '0' >= 0 && line[i] - '0' <= 9) {
                if (indices.empty()) {
                    number += line[i];
                    break;
                }
                if (i > indices[indices.size() - 1]) {
                    number += line[i];
                } else {
                    number += std::to_string(numbers[numbers.size() - 1]);
                }
                break;
            }
        }

        sum += std::stoi(number);

    }

    return sum;
}
