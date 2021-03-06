#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap () {

    std::cout << "Default constructor called DiamondTrap" << std::endl;

}

DiamondTrap::DiamondTrap (  std::string name ) {

    this->name = name;
    ClapTrap::setName(this->name + "_clap_name");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(30);
    std::cout << "DiamondTrap constructor" << std::endl;

}

DiamondTrap::~DiamondTrap() {

    std::cout << "Diamond Trap destructor called" << std::endl;

}

DiamondTrap::DiamondTrap ( const DiamondTrap & diamondTrap ) : ClapTrap( diamondTrap ), ScavTrap(diamondTrap), FragTrap(diamondTrap) {

    std::cout << "Copy constructor DiamondTrap" << std::endl;

}

DiamondTrap & DiamondTrap::operator = ( const DiamondTrap & diamondTrap ) {

    ClapTrap::operator=(diamondTrap);
    std::cout << "Assignment operator DiamondTrap" << std::endl;
    return  *this;

}

void DiamondTrap::whoAmI() {

    std::cout << "I am " << this->name << " clapTrap name : " <<
              ClapTrap::getName() << " HP : " << this->getHitPoints() << " Energy: " <<
              this->getEnergyPoints() << " attackDamage: " << this->getAttackDamage() <<
              std::endl;

}
