#include "World.hpp"

World::World(Simulation *simulation) :
time_ms(0),
simulation(simulation)
{
       debugging_message("World created.");
}

void World::attach_vehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
    debugging_message("Added vehicle " + vehicle->getName() + " to the world.");
}

void World::debugging_message(std::string message)
{
    simulation->debugging_message(message);
}
