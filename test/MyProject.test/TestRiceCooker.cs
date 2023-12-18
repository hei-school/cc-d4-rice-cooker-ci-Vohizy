using System;
using Xunit;

namespace MyProject.Test
{
    public class TestRiceCooker
    {
        [Fact]
        public void TestTurnOn()
        {
            var riceCooker = new RiceCooker();
            riceCooker.TurnOn();
            Assert.True(riceCooker.CheckPower());
        }

        [Fact]
        public void TestTurnOff()
        {
            var riceCooker = new RiceCooker();
            riceCooker.TurnOn();
            riceCooker.TurnOff();
            Assert.False(riceCooker.CheckPower());
        }

        [Fact]
        public void TestCookRice()
        {
            var riceCooker = new RiceCooker();
            riceCooker.TurnOn();
            riceCooker.CookRice(10);
        }

        [Fact]
        public void TestHeatWater()
        {
            var riceCooker = new RiceCooker();
            riceCooker.TurnOn();
            riceCooker.HeatWater();
        }

        [Fact]
        public void TestHeatFood()
        {
            var riceCooker = new RiceCooker();
            riceCooker.TurnOn();
            riceCooker.HeatFood();
        }
    }
}
