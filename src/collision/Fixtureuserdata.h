#pragma once

enum class FUDtype{
    Floor = 0,
    Astronaut,
    Ship,
    Tester
};

class FixtureUserData
{
public:
    virtual FUDtype getType(){ return m_type; }
protected:
    FixtureUserData(FUDtype a_type);
private:
    FUDtype m_type;
};
