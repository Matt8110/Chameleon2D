#pragma once

class CMathUtils
{
public:
    //time = 0.0 - 1.0
    static float interp(float start, float end, float& current, float speed);
};