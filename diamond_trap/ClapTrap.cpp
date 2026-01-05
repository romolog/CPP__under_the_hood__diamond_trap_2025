/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:11:44 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 19:41:58 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

//	CTOR-DEFAULT ------------------------------------------------------------
clp::ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap: Ctor: Default" << std::endl;
	damage_ = CLP_DMG_DFLT;
	energy_ = CLP_ENRG_DFLT;
	health_ = CLP_HLTH_DFLT;
	name_ = CLP_NAME_DFLT;
}

//	DTOR-DEFAULT ------------------------------------------------------------
clp::ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap: Dtor" << std::endl;
}

//	COPY-CTOR ---------------------------------------------------------------
clp::ClapTrap::ClapTrap(const clp::ClapTrap& rhs)
{
	std::cout << "ClapTrap: Copy: Ctor" << std::endl;
	damage_ = rhs.damage_;
	energy_ = rhs.energy_;
	health_ = rhs.health_;
	name_ = rhs.name_;
}

//	COPY-ASSIGNMENT ---------------------------------------------------------
clp::ClapTrap& clp::ClapTrap::operator=(const clp::ClapTrap& rhs)
{
	std::cout << "ClapTrap: Copy: Assignement operator" << std::endl;
	if (this == &rhs) 
		return (*this);
	damage_ = rhs.damage_;
	energy_ = rhs.energy_;
	health_ = rhs.health_;
	name_ = rhs.name_;
	return (*this);
}

//	CTOR-NAME ---------------------------------------------------------
clp::ClapTrap::ClapTrap(const std::string& name) : \
	damage_(CLP_DMG_DFLT), energy_(CLP_ENRG_DFLT), health_(CLP_HLTH_DFLT), name_(name)
{
	std::cout << "ClapTrap: Ctor: Name" << std::endl;
}

//	ACCESSORS ---------------------------------------------------------
std::string	clp::ClapTrap::name(void) const
{
	return (name_);
}

uint	clp::ClapTrap::health(void) const
{
	return (health_);
}


uint	clp::ClapTrap::energy(void) const
{
	return (energy_);
}


uint	clp::ClapTrap::damage(void) const
{
	return (damage_);
}


//	FUNCTIONS ---------------------------------------------------------
void	clp::ClapTrap::attack(const std::string& target)
{
	
	if (energy_)
	{
		std::cout << "ClapTrap " + name_ +  " attacks " + target + ", causing " << damage_ << " points of damage!" << std::endl;
		--energy_;
	}
	else
		std::cout << "ClapTrap " + name_ +  " can't attacks " + target + ", as the current energy is 0" << std::endl;
}

void	clp::ClapTrap::takeDamage(const uint amount)
{
	std::cout << name_ + " takes damage " << amount;
	if (health_ > amount)
		health_ -= amount;
	else
	{
		std::cout << " and dies, as health is less than demage";
		health_ = 0;
	}
	std::cout << std::endl;
}

void	clp::ClapTrap::beRepaired(const uint amount)
{
	if (energy_)
	{
		std::cout << name_ + " is repaired by " << amount << std::endl;
		--energy_;
		if (std::numeric_limits<uint>::max() - health_ > amount)
			health_ = std::numeric_limits<uint>::max();
		else
			health_ += amount;
	}
	else
		std::cout << name_ +  " can't be repaired, as the current energy is 0" << std::endl;

}