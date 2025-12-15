/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:11:44 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 23:47:07 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

//	CTOR-DEFAULT ------------------------------------------------------------
clp::ScavTrap::ScavTrap()
{
	std::cout << "Scav: Ctor: Default" << std::endl;
	damage_ = SCV_DMG_DFLT;
	energy_ = SCV_ENRG_DFLT;
	name_ += SCV_NAME_DFLT;
}

//	DTOR-DEFAULT ------------------------------------------------------------
clp::ScavTrap::~ScavTrap() 
{
	std::cout << "Scav: Dtor" << std::endl;
}

//	COPY-CTOR ---------------------------------------------------------------
clp::ScavTrap::ScavTrap(const clp::ScavTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "Scav: Copy: Ctor" << std::endl;
}

//	COPY-ASSIGNMENT ---------------------------------------------------------
clp::ScavTrap& clp::ScavTrap::operator=(const clp::ScavTrap& rhs)
{
	std::cout << "Scav: Copy: Assignement operator" << std::endl;
	if (this == &rhs) 
		return (*this);

	name_ = rhs.name_;
	energy_ =  rhs.energy_;
	health_ = rhs.health_;
	damage_ = rhs.damage_;

	return (*this);
}

//	CTOR-NAME ---------------------------------------------------------
clp::ScavTrap::ScavTrap(const std::string& name)	: ClapTrap(name)
{
	std::cout << "Scav: Ctor: Name" << std::endl;
	damage_ = SCV_DMG_DFLT;
	energy_ = SCV_ENRG_DFLT;
}

//	FUNCTIONS ---------------------------------------------------------
void	clp::ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap" + name_ + " is in Gate Keeper mode" << std::endl;	
}

// void	clp::ClapTrap::attack(const std::string& target)
void	clp::ScavTrap::attack(const std::string& target)
{
	if (energy_)
	{
		std::cout << "ScavTrap " + name_ +  " attacks " + target + ", causing " << damage_ << " points of damage!" << std::endl;
		--energy_;
	}
	else
		std::cout << "ScavTrap " + name_ +  " can't attacks " + target + ", as the current energy is 0" << std::endl;
}