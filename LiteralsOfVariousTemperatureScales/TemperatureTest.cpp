#include "Temperature.h"

int main()
{
    using namespace temperature;
    using namespace temperature_scale_literals;

    auto t1{ 36.5_deg };
    auto t2{ 79.0_f };
    auto t3{ 100.0_k };

    {
        auto tf = temperature_cast<scale::fahrenheit>(t1);
        auto tc = temperature_cast<scale::celsius>(tf);
        assert(t1 == tc);
    }

    {
        auto tk = temperature_cast<scale::kelvin>(t1);
        auto tc = temperature_cast<scale::celsius>(tk);
        assert(t1 == tc);
    }

    {
        auto tc = temperature_cast<scale::celsius>(t2);
        auto tf = temperature_cast<scale::fahrenheit>(tc);
        assert(t2 == tf);
    }

    {
        auto tk = temperature_cast<scale::kelvin>(t2);
        auto tf = temperature_cast<scale::fahrenheit>(tk);
        assert(t2 == tf);
    }

    {
        auto tc = temperature_cast<scale::celsius>(t3);
        auto tk = temperature_cast<scale::kelvin>(tc);
        assert(t3 == tk);
    }

    {
        auto tf = temperature_cast<scale::fahrenheit>(t3);
        auto tk = temperature_cast<scale::kelvin>(tf);
        assert(t3 == tk);
    }
}
