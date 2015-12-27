# Overall architecture

A *simulation* consists of a *world*, which has a vector of *vehicles*.

The simulation is responsible for handling output of debugging messages, output of the world state periodically, etc.

The world holds what we might think of as the 'global' variable of the world, e.g. the current time.
Its purpose is to act as a container that ensures updates etc. are consistent.
It may later be extended to allow the inclusion of ficticous forces - i.e. it will be responsbile for enforcing the fact thaet we are not in an inertial frame.

The simulation should not try to access a vehicle directly - it should always call a method of the world, e.g. `update`, which will act on all vehicles in the world.
