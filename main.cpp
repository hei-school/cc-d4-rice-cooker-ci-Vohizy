#include "RiceCooker.h"

int main() {
    RiceCooker myRiceCooker;

    
    std::cout << "Hello! You are using the rice cooker. Do you want to turn it on? (1 for yes / 2 for no): ";
    int userDecision;

    while (true) {
        if (!(std::cin >> userDecision)) {
            std::cout << "Error: Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (userDecision != 1 && userDecision != 2) {
            std::cout << "Error: Invalid choice. Please choose 1 for yes or 2 for no." << std::endl;
            continue;
        }

        break;
    }

    if (userDecision == 1) {
        myRiceCooker.turnOn();
        while (myRiceCooker.checkPower()) {
            myRiceCooker.chooseFunction();
        }
    } else {
        std::cout << "Rice cooker remains off." << std::endl;
    }

    return 0;
    
}
