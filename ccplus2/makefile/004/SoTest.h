#ifndef SOTEST_H
#define SOTEST_H

#pragma once

class SoTest{
public:
        void func1();
        virtual void func2();
        virtual void func3() = 0;
};

#endif