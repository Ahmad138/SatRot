#ifndef APPA_H
#define APPA_H



#pragma once

// example class to test
class appa
{
public:
        appa(int a = 0, int b = 0) : mA(a), mB(b) { }

        int GetA() const { return mA; }
        void SetA(int a) { mA = a; }
        int GetB() const { return mB; }
        void SetB(int b) { mB = b; }

        int Sum() const { return mA + mB; }
        int Diff() const { return mA - mB; }
        int Mult() const { return mA * mB; }
        int Div() const { return mA / mB; }

private:
        int mA;
        int mB;
};
#endif // APPA_H
