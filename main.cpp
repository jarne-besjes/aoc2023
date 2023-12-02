#include <iostream>
#include "solutions/day1/day1.h"
#include "solutions/day2/day2.h"

int DAY = 2;

int main() {
    switch(DAY) {
        case 1:
            std::cout << "Part 1: " << day1::part1() << std::endl;
            std::cout << "Part 2: " << day1::part2() << std::endl;
            break;
        case 2:
            std::cout << "Part 1: " << day2::part1() << std::endl;
            std::cout << "Part 2: " << day2::part2() << std::endl;
    }
}

