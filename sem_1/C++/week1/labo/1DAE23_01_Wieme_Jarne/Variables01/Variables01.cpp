// Wieme, Jarne - 1DAE23
// Variables01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

int main()
{
    //color [0, 255] to color [0.0f, 1.0f]
    std::cout << "Give an RGBA color code in [0, 255] values." << std::endl;
    int colorR{}, colorG{}, colorB{}, colorA{};
    std::cin >> colorR >> colorG >> colorB >> colorA;
    float colorRf = colorR / 255.f;
    float colorGf = colorG / 255.f;
    float colorBf = colorB / 255.f;
    float colorAf = colorA / 255.f;
    std::cout << "The given RGBA color code in [0.0f, 1.0f] values:\n" << colorRf << '\n' << colorGf << '\n' << colorBf << '\n' << colorAf << '\n' << std::endl;
    
    //Distance in km to distance in m and cm
    std::cout << "Give a distance in km.\n";
    float distance{};
    std::cin >> distance;
    float distanceM = distance * 1000;
    float distanceCm = distanceM * 100;
    std::cout << "The given distance in m and cm:\n" << distanceM << " m\n" << distanceCm << " cm\n" << std::endl;

    //angle in radians to angle in degrees
    std::cout << "Give an angle in radians.\n";
    float angleR{};
    std::cin >> angleR;
    double angleD = angleR * (180 / M_PI);
    std::cout << "The given angle in degrees: \n" << angleD << " degrees\n" << std::endl;

    //angle in degrees to angle in radians
    std::cout << "Give an angle in degrees.\n";
    angleR = 0;
    std::cin >> angleR;
    angleD = angleR * (M_PI / 180);
    std::cout << "The given angle in radians: \n" << angleD << " radians\n" << std::endl;

    //calculate angular velocity in degrees/seconds with seconds as user input
    std::cout << "Give a number of seconds for one complete rotation of an object.\n";
    int seconds{};
    std::cin >> seconds;
    float angularVelocity = 360.f / seconds;
    std::cout << "The angular velocity is " << angularVelocity << " degrees/second if it takes " << seconds << " seconds for one complete rotation.\n" << std::endl;

    //Distance in meters done after the elapsed time with speed(in km/h) and elapsed time (minutes) as user input
    std::cout << "Give a number for speed in km/h.\n";
    int speed{};
    std::cin >> speed;
    std::cout << "Give a number for the elapsed time.\n";
    int elapsedTime{};
    std::cin >> elapsedTime;
    distance = 0.f;
    distance = (speed * ( elapsedTime / 60.f ) ) * 1000;
    std::cout << "The distance in meters done in the elapsed time is " << distance << " m.\n" << std::endl;

    //The velocity of an object after the entered number of seconds supposing there is no air resistance with seconds as user input.
    std::cout << "Give a number of seconds for how long an object falls.\n";
    int fallingTime{};
    std::cin >> fallingTime;
    float velocity = 9.8f * fallingTime;
    std::cout << "The velocity of the object is " << velocity << " m/s after " << fallingTime << " seconds of falling supposing there is no air resistance.\n" << std::endl;
    
    //circumference and area of a circle with radius as user input
    std::cout << "Give the radius of a circle.\n";
    double radius{};
    std::cin >> radius;
    double circumferenceC = M_PI * 2 * radius;
    double areaC = M_PI * (radius * radius);
    std::cout << "The circumference of the circle is " << circumferenceC << " and the area is " << areaC << ".\n" << std::endl;

    //circumference and area of a rectangle with width and height as user input
    std::cout << "Give the width of a rectangle.\n";
    int width{};
    std::cin >> width;
    std::cout << "Give the height of the rectangle.\n";
    int heightR{};
    std::cin >> heightR;
    int circumferenceR = ( width + heightR ) * 2;
    int areaR = width * heightR;
    std::cout << "The circumference of the rectangle is " << circumferenceR << " and the area is " << areaR << ".\n" << std::endl;

    //area of a triangle with base and height as user input
    std::cout << "Give the base lenght of a triangle.\n";
    float base{};
    std::cin >> base;
    std::cout << "Give the height of the triangle.\n";
    float heightT{};
    std::cin >> heightT;
    float area = (base * heightR) / 2;
    std::cout << "The area of the triangle is " << area << ".\n" << std::endl;
    std::cout << "Press enter key to exit the program.";
    std::cin;

    return 0;
}