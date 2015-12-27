#ifndef _SIMULATION_HPP_
#define _SIMULATION_HPP_

#include <string>

#include "World.hpp"
class World;

class Simulation
{
    private:
        World *world;   // A simulation should have a single world attached to it
        bool debugging_on;  // Is debugging switched on?
    public:
        Simulation();   // Default constructor for now - WARNING: I may change what this does later
        void debugging_message(std::string message);
};

#endif
