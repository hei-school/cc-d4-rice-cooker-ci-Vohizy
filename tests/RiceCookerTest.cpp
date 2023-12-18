#include "RiceCooker.h"
#include "gtest/gtest.h"

class MockRiceCooker : public RiceCooker {
public:
    MOCK_METHOD(void, printMessage, (const std::string&), (const override));
    MOCK_METHOD(int, getUserInput, (), (const override));
};

TEST(RiceCookerTest, TurnOn) {
    MockRiceCooker riceCooker;
    EXPECT_CALL(riceCooker, printMessage("The rice cooker is turned on."));
    riceCooker.turnOn();
    EXPECT_TRUE(riceCooker.checkPower());
}

TEST(RiceCookerTest, TurnOff) {
    MockRiceCooker riceCooker;
    EXPECT_CALL(riceCooker, printMessage("The rice cooker is turned off."));
    riceCooker.turnOff();
    EXPECT_FALSE(riceCooker.checkPower());
}

