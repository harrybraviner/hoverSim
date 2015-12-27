#include "Quaternion.hpp"

#include <iostream>
using namespace std;

int main(){
    
    cout << "Testing real multiplication..." << endl;
    
    {
    cout << "\t1 * 1 = 1..." << endl;
    Quaternion q1(1.0, 0.0, 0.0, 0.0); Quaternion q2(1.0, 0.0, 0.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(1.0, 0.0, 0.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\t4 * -7 = -28..." << endl;
    Quaternion q1(4.0, 0.0, 0.0, 0.0); Quaternion q2(-7.0, 0.0, 0.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(-28.0, 0.0, 0.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }

    cout << "Testing multiplication of imaginary units..." << endl;
    
    {
    cout << "\t1 * i = i..." << endl;
    Quaternion q1(1.0, 0.0, 0.0, 0.0); Quaternion q2(0.0, 1.0, 0.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 1.0, 0.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\t1 * j = j..." << endl;
    Quaternion q1(1.0, 0.0, 0.0, 0.0); Quaternion q2(0.0, 0.0, 1.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 0.0, 1.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\t1 * k = k..." << endl;
    Quaternion q1(1.0, 0.0, 0.0, 0.0); Quaternion q2(0.0, 0.0, 0.0, 1.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 0.0, 0.0, 1.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\ti * j = k..." << endl;
    Quaternion q1(0.0, 1.0, 0.0, 0.0); Quaternion q2(0.0, 0.0, 1.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 0.0, 0.0, 1.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\tj * i = -k..." << endl;
    Quaternion q1(0.0, 0.0, 1.0, 0.0); Quaternion q2(0.0, 1.0, 0.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 0.0, 0.0, -1.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\ti * k = -j..." << endl;
    Quaternion q1(0.0, 1.0, 0.0, 0.0); Quaternion q2(0.0, 0.0, 0.0, 1.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 0.0, -1.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\tk * i = j..." << endl;
    Quaternion q1(0.0, 0.0, 0.0, 1.0); Quaternion q2(0.0, 1.0, 0.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 0.0, 1.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\tj * k = i..." << endl;
    Quaternion q1(0.0, 0.0, 1.0, 0.0); Quaternion q2(0.0, 0.0, 0.0, 1.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, 1.0, 0.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\tk * j = -i..." << endl;
    Quaternion q1(0.0, 0.0, 0.0, 1.0); Quaternion q2(0.0, 0.0, 1.0, 0.0);
    Quaternion q3 = q1*q2;
    if (q3 == Quaternion(0.0, -1.0, 0.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }
    
    {
    cout << "\ti * j * k = -1..." << endl;
    Quaternion q1(0.0, 1.0, 0.0, 0.0); Quaternion q2(0.0, 0.0, 1.0, 0.0); Quaternion q3(0.0, 0.0, 0.0, 1.0);
    Quaternion q4 = q1*q2*q3;
    if (q4 == Quaternion(-1.0, 0.0, 0.0, 0.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }

    cout << "Testing addition..." << endl;;
    
    {
    cout << "\t(1 + 2*i + 3*j + 4*k) + (6 + 3*i + 7*j + k) = (7 + 5*i + 10*j + 5*k)..." << endl;
    Quaternion q1(1.0, 2.0, 3.0, 4.0); Quaternion q2(6.0, 3.0, 7.0, 1.0);
    Quaternion q3 = q1 + q2;
    if (q3 == Quaternion(7.0, 5.0, 10.0, 5.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }

    cout << "Testing subtraction..." << endl;;
    
    {
    cout << "\t(1 + 2*i + 3*j + 4*k) - (6 + 3*i + 7*j + k) = (-5 - 1*i - 4*j + 3*k)..." << endl;
    Quaternion q1(1.0, 2.0, 3.0, 4.0); Quaternion q2(6.0, 3.0, 7.0, 1.0);
    Quaternion q3 = q1 - q2;
    if (q3 == Quaternion(-5.0, -1.0, -4.0, 3.0)) { cout << "\tPassed." << endl; }
    else {cout << "\tFailed!" << endl; return 1; }
    }

    cout << "Passed all unit tests." << endl;

}
