#ifndef _QUATERNION_HPP_
#define _QUATERNION_HPP_

class Quaternion
{
    private :
        double *components;
    public :
        Quaternion();
        Quaternion(double q0, double q1, double q2, double q3);
        Quaternion(double *components);
        Quaternion(const Quaternion &other);   // Copy constructor
        ~Quaternion();
        bool operator==(const Quaternion &other);  // Equality
        Quaternion operator+(const Quaternion &other);
        Quaternion operator-(const Quaternion &other);
        Quaternion operator*(const Quaternion &other);
        Quaternion operator=(const Quaternion &other); // Assignment
        double squared_norm();
        double squared_distance(const Quaternion &other); 
};

#endif
