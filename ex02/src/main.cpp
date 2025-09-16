#include <iostream>
#include <string>
#include "Array.hpp"

// The Walking Dead themed tester: survivors vs walkers
int main() {
    try {
        std::cout << "=== TWD: Array Tester ===\n";

        Array<std::string> survivors(4);
        survivors[0] = "Rick";
        survivors[1] = "Michonne";
        survivors[2] = "Daryl";
        survivors[3] = "Carol";

        std::cout << "Survivors roster (original): ";
        for (size_t i = 0; i < survivors.size(); ++i)
            std::cout << survivors[i] << (i + 1 < survivors.size() ? ", " : "\n");

        // Copy the roster to a new camp (cloning all survivors)
        Array<std::string> camp = survivors;
        std::cout << "Camp roster (after copy) -- survivors being cloned: ";
        for (size_t i = 0; i < camp.size(); ++i)
            std::cout << camp[i] << (i + 1 < camp.size() ? ", " : "\n");

        // A walker bites Rick in the original roster
        survivors[0] = "Rick (walker)";
        std::cout << "After the bite, survivors: ";
        for (size_t i = 0; i < survivors.size(); ++i)
            std::cout << survivors[i] << (i + 1 < survivors.size() ? ", " : "\n");

        // Ensure camp is unaffected (deep copy)
        std::cout << "Camp remains unchanged: ";
        for (size_t i = 0; i < camp.size(); ++i)
            std::cout << camp[i] << (i + 1 < camp.size() ? ", " : "\n");

        // Assignment to another group
        Array<std::string> supplyRun;
        supplyRun = camp;
        std::cout << "Supply run team (assigned): ";
        for (size_t i = 0; i < supplyRun.size(); ++i)
            std::cout << supplyRun[i] << (i + 1 < supplyRun.size() ? ", " : "\n");

        // Bounds check: try to access an invalid index
        try {
            std::cout << "Attempting to read beyond the fence: " << survivors[survivors.size()] << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Caught fence breach: " << e.what() << std::endl;
        }

        std::cout << "All tests complete. Survivors keep fighting.\n";
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
