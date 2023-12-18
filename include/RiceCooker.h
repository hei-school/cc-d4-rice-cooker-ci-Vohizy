#ifndef RICECOOKER_H
#define RICECOOKER_H

#include <chrono>

class RiceCooker {
private:
    bool power;

public:
    RiceCooker();

    bool checkPower() const;
    void turnOn();
    void turnOff();
    void chooseFunction(int choice);
    void cookRice(int time);
    void heatWater();
    void heatFood();
    void sleep(int minutes);

private:
    virtual void printMessage(const std::string& message) const;
    virtual int getUserInput() const;
};

#endif // RICECOOKER_H
