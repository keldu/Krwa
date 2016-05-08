#pragma once

class Time{
public:

    static float gettime();
    static float getdeltatime();

    static void timeloop();

private:
    static float time, oldtime, deltatime;

};
