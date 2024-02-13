#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

constexpr int FLOOR_TRAVEL_TIME = 10;

void printVec(const std::vector<int> &vec)
{
    for (int v : vec)
        std::cout << "," << v;
}

void splitVec(const int start, const std::vector<int> &vec, std::vector<int> &left, std::vector<int> &right)
{
    // there's something in <algorithm> but this specific application is simple enough that it's unnecessary
    for (int v : vec)
    {
        if (v < start)
            left.push_back(v);
        else
            right.push_back(v);
    }
}

void ElevatorProblemA(const int start, const std::vector<int> &floorInput)
{
    std::vector<int> lowerFloors, higherFloors;
    splitVec(start, floorInput, lowerFloors, higherFloors);

    std::sort(lowerFloors.begin(), lowerFloors.end(), std::greater<int>());
    std::sort(higherFloors.begin(), higherFloors.end());

    int time = 0;
    if (lowerFloors.size())
    {
        time += (start - lowerFloors.back());
        if (higherFloors.size())
            time += (higherFloors.back() - lowerFloors.back());
    }
    else if (higherFloors.size())
    {
        time += higherFloors.back() - start;
    }

    time *= FLOOR_TRAVEL_TIME;
    std::cout << time << " " << start;
    
    if (floorInput[0] < start) // directionality : down = true, up = false
    {
        printVec(lowerFloors);
        printVec(higherFloors);
    }
    else
    {
        printVec(higherFloors);
        printVec(lowerFloors);
    }

    std::cout << std::endl;
}

void ElevatorProblemB(const int start, const std::vector<int> &floorInput)
{
    int time = std::abs(start - floorInput.front());
    for (int i = 0, j = 1; j < floorInput.size(); ++i, ++j)
    {
        time += std::abs(floorInput[j] - floorInput[i]);
    }
    time *= FLOOR_TRAVEL_TIME;
    std::cout << time << " " << start;
    printVec(floorInput);
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc <= 2)
        return 1;

    std::vector<int> floorInput;
    for (int i = 2; i < argc; ++i) // i == 2 -- arg0 is executable name, arg1 is starting floor
    {
        floorInput.emplace_back(std::stoi(argv[i]));
    }

    int start = std::stoi(argv[1]);
    ElevatorProblemA(start, floorInput);
    ElevatorProblemB(start, floorInput);
}
