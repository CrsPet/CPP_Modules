#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {

private:

    std::string name;

public:

    void announce( void );

    Zombie();

    Zombie(std::string name) {
        this->name = name;
    }

    ~Zombie();
    
};

void randomChump(std::string name);
Zombie *newZombie( std:: string name);

#endif