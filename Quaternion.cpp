#include "Quaternion.hpp"

#include <cmath>

Quaternion::Quaternion()
{
    components = new double[4];
    for (int i=0; i<4; i++) {components[i] = 0.0;}
}

Quaternion::Quaternion(double *components)
{
    this->components = new double[4];
    for (int i=0; i<4; i++) {this->components[i] = components[i];}
}

Quaternion::Quaternion(double q0, double q1, double q2, double q3)
{
    components = new double[4];
    components[0] = q0;
    components[1] = q1;
    components[2] = q2;
    components[3] = q3;
}

Quaternion::Quaternion(const Quaternion &other)
{
    components = new double[4];
    components[0] = other.components[0];
    components[1] = other.components[1];
    components[2] = other.components[2];
    components[3] = other.components[3];
}

Quaternion::~Quaternion()
{
    delete components;
}

bool Quaternion::operator==(const Quaternion &other)
{
    if (   this->components[0] == other.components[0]
        && this->components[1] == other.components[1]
        && this->components[2] == other.components[2]
        && this->components[3] == other.components[3]
       ) {
        return true;
    } else {
        return false;
    }
}

Quaternion Quaternion::operator+(const Quaternion &other)
{
    double q0 = this->components[0] + other.components[0];
    double q1 = this->components[1] + other.components[1];
    double q2 = this->components[2] + other.components[2];
    double q3 = this->components[3] + other.components[3];

    return Quaternion(q0, q1, q2, q3);
}

Quaternion Quaternion::operator-(const Quaternion &other)
{
    double q0 = this->components[0] - other.components[0];
    double q1 = this->components[1] - other.components[1];
    double q2 = this->components[2] - other.components[2];
    double q3 = this->components[3] - other.components[3];

    return Quaternion(q0, q1, q2, q3);
}

Quaternion Quaternion::operator*(const Quaternion &other)
{
    double x0 = this->components[0]; double x1 = this->components[1];
    double x2 = this->components[2]; double x3 = this->components[3];

    double y0 = other.components[0]; double y1 = other.components[1];
    double y2 = other.components[2]; double y3 = other.components[3];

    double q0 = x0*y0 - x1*y1 - x2*y2 - x3*y3;
    double q1 = x2*y3 - x3*y2 + x0*y1 + x1*y0;
    double q2 = x3*y1 - x1*y3 + x0*y2 + x2*y0;
    double q3 = x1*y2 - x2*y1 + x0*y3 + x3*y0;

    return Quaternion(q0, q1, q2, q3);
}

Quaternion Quaternion::operator=(const Quaternion &other)   // Assignment
{
    components[0] = other.components[0];
    components[1] = other.components[1];
    components[2] = other.components[2];
    components[3] = other.components[3];
}

double Quaternion::squared_norm()
{
    double x0 = this->components[0]; double x1 = this->components[1];
    double x2 = this->components[2]; double x3 = this->components[3];
    
    return (x0*x0 + x1*x1 + x2*x2 + x3*x3);
}

double Quaternion::squared_distance(const Quaternion &other)
{
    double x0 = this->components[0] - other.components[0];
    double x1 = this->components[1] - other.components[1];
    double x2 = this->components[2] - other.components[2];
    double x3 = this->components[3] - other.components[3];

    return (x0*x0 + x1*x1 + x2*x2 + x3*x3);
}
