#include "RiceCooker.h"
#include <iostream>

RiceCooker::RiceCooker() : power(false) {}

bool RiceCooker::checkPower() const {
    return power;
}

void RiceCooker::turnOn() {
    power = true;
    printMessage("The rice cooker is turned on.");
}

void RiceCooker::turnOff() {
    power = false;
    printMessage("The rice cooker is turned off.");
}

void RiceCooker::chooseFunction(int choice) {
    if (!power) {
        printMessage("The rice cooker is not turned on.");
        return;
    }

    int userChoice;
    while (true) {
        printMessage("Choose a function (1 to cook rice, 2 to heat water, 3 to heat food, 4 to turn off): ");

        if (!(std::cin >> userChoice)) {
            printMessage("Error: Please enter an integer.");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (userChoice < 1 || userChoice > 4) {
            printMessage("Error: Invalid choice. Please choose a number between 1 and 4.");
            continue;
        }

        break;
    }

    switch (userChoice) {
        case 1:
            int time;
            while (true) {
                printMessage("Enter the cooking duration in minutes: ");
                if (!(std::cin >> time)) {
                    printMessage("Error: Please enter an integer.");
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                break;
            }
            cookRice(time);
            break;
        case 2:
            heatWater();
            break;
        case 3:
            heatFood();
            break;
        case 4:
            turnOff();
            break;
        default:
            printMessage("Unrecognized choice.");
    }
}

void RiceCooker::cookRice(int time) {
    printMessage("Cooking rice in progress...");
    sleep(time);
    printMessage("The rice is ready!");
}

void RiceCooker::heatWater() {
    printMessage("Heating water in progress...");
    int temperature = 0;
    while (temperature < 100) {
        temperature += 10;
        sleep(1);
        printMessage("Water temperature: " + std::to_string(temperature) + "°C");
    }
    printMessage("Water has reached 100°C. Automatically turning off.");
}

void RiceCooker::heatFood() {
    printMessage("Heating food in progress...");
    printMessage("The food is heated and ready to be consumed!");
}

void RiceCooker::sleep(int minutes) {
    std::chrono::milliseconds milliseconds(minutes * 60 * 1000);
    auto startTime = std::chrono::system_clock::now();
    while (std::chrono::system_clock::now() < startTime + milliseconds);
}

void RiceCooker::printMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

int RiceCooker::getUserInput() const {
    int userInput;
    std::cin >> userInput;
    return userInput;
}
