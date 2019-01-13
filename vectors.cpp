#include "vectors.h"
#include "stdio.h"
#include <math.h>


/*API void Print(v2 v)
{
    fprintf(stdout, "v2{x: %.2f, y: %.2f}\n", v.x, v.y);
}

float Magnitude(v2 v)
{
    return sqrtf((v.x * v.x) + (v.y * v.y));
}

API v2 Normalize(v2 v)
{
    float m = Magnitude(v);
    v.x = v.x/m;
    v.y = v.y/m;
    return v;
}


API v2  operator+(v2 a, v2 b)
{
    v2 r = {};
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

API v2  operator+=(v2 &a, v2 b)
{
    a = a + b;
    return a;
}
*/

float CALL_CONVENTION Magnitude(v3 v)
{
    return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

API v3 CALL_CONVENTION Normalize(v3 v)
{
    float m = Magnitude(v);
    v.x = v.x/m;
    v.y = v.y/m;
    v.z = v.z/m;
    return v;
}


v3 CALL_CONVENTION  operator+(v3 a, v3 b)
{
    v3 r = {};
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}



v3 CALL_CONVENTION  operator+=(v3 &a, v3 b)
{
    a = a + b;
    return a;
}

API void CALL_CONVENTION PrintOneTwoThree()
{
    fprintf(stdout, "OneTwoThree: v3{x: %.2f, y: %.2f, z: %.2f}\n", oneTwoThree.x, oneTwoThree.y, oneTwoThree.z);
}


API void CALL_CONVENTION Print(v3 v)
{
    fprintf(stdout, "v3{x: %.2f, y: %.2f, z: %.2f}\n", v.x, v.y, v.z);
}
