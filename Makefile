CPPFLAGS=-std=c++11
CPP=g++

freeTop : freeTop.cpp Simulation.o World.o Vehicle.o
	$(CPP) $(CPPFLAGS) -o freeTop $^

Simulation.o : Simulation.cpp Simulation.hpp World.hpp Vehicle.hpp
	$(CPP) $(CPPFLAGS) -c Simulation.cpp

World.o : World.cpp World.hpp Simulation.hpp World.hpp
	$(CPP) $(CPPFLAGS) -c World.cpp

Vehicle.o : Vehicle.cpp Vehicle.hpp World.hpp Simulation.hpp
	$(CPP) $(CPPFLAGS) -c Vehicle.cpp

quaternionUnitTests : quaternionUnitTests.cpp Quaternion.o Quaternion.hpp
	$(CPP) $(CPPFLAGS) -o quaternionUnitTests quaternionUnitTests.cpp Quaternion.o

Quaternion.o : Quaternion.cpp Quaternion.hpp
	$(CPP) $(CPPFLAGS) -c Quaternion.cpp

clean :
	rm -f *.o quaternionUnitTests
