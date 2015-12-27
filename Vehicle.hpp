#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include <string>

#include "World.hpp"
class World;

class Vehicle
{
    private:
        // Physics
        double mass;
        double I_xx, I_yy, I_zz, I_xy, I_xz, I_yz;  // Components of the moment of intertia in the body frame
        double com_x_m, com_y_m, com_z_m;   // Position of the centre of mass of the vehicle
        double p_x, p_y, p_z;   // Linear momenta
        double quat_real, quat_i, quat_j, quat_k;   // Quaternion represenation of the orientation of the vehicle

        // Application
        World *world; // A vehicle must exist in a world - hold a pointer to that parent world
        std::string name;
        bool debugging; // Is debugging switched on for this vehicle?

        void debugging_message(std::string string);
    public:
        Vehicle(World *world, std::string name, double com_x_m, double com_y_m, double com_z_m, bool debugging);
        // Accessor methods
        std::string getName();
        // Settor methods
        void enable_debugging();
        void disable_debugging();
};

#endif
