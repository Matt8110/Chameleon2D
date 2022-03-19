#include "MathUtils.h"

float CMathUtils::interp(float start, float end, float& current, float speed)
{
    float offset = start - end;
    float result = start + (current * offset);

    current += speed;

    if (current > 1.0f)
        current = 1.0f;

    if (current < 0.0f)
        current = 0.0f;

    return result;
}