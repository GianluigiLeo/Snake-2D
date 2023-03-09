#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "App/Application.hpp"

Application App(800, 600, "Snake 2D");

int main() {

    try {
        App.Run();
 
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;

    }

    return EXIT_SUCCESS;
}
