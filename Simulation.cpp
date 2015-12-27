#include "Simulation.hpp"
#include <iostream>

Simulation::Simulation():
debugging_on(true)
{
    debugging_message("Simulation created.");
    world = new World(this);
}

void Simulation::debugging_message(std::string message)
{
    if (debugging_on) {std::cout << message << "\n";}
}
