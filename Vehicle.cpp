#include "Vehicle.hpp"

Vehicle::Vehicle(World *world, std::string name, double com_x_m, double com_y_m, double com_z_m) :
world(world),
name(name),
com_x_m(com_x_m), com_y_m(com_y_m), com_z_m(com_z_m),
debugging(debugging)
{
    string message = "Vechicle " + name + " was created.";
    debugging_message(message);
}

void Vehicle::debugging_message(std::string message)
{
    std::string message_to_world = name + ":\t" + message;
    world->debugging_message(message_to_world);
}

// Accessor methods
std::string Vehicle::getName(){
    return name;
}

// Settor methods
void enable_debugging(){
    debugging = true;
}

void disable_debugging(){
    debugging = false;
}
