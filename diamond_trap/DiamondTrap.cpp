/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:11:44 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 23:53:43 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

//	CTOR-DEFAULT ------------------------------------------------------------
clp::DiamondTrap::DiamondTrap()
{
	std::cout << "Diamond: Ctor: Default" << std::endl;
	name_ += DMD_NAME_DFLT;
}

clp::DiamondTrap::ProxyFragDamage::ProxyFragDamage() 
{
	std::cout << "ProxyFragDamageDamage: Ctor: Default: frag_damage = " << damage_ << std::endl;
}	

//	DTOR-DEFAULT ------------------------------------------------------------
clp::DiamondTrap::~DiamondTrap() 
{
	std::cout << "Diamond: Dtor" << std::endl;
}

clp::DiamondTrap::ProxyFragDamage:: ~ProxyFragDamage() {}


//	COPY-CTOR ---------------------------------------------------------------
clp::DiamondTrap::DiamondTrap(const clp::DiamondTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "Diamond: Copy: Ctor" << std::endl;
}

clp::DiamondTrap::ProxyFragDamage::ProxyFragDamage(const clp::DiamondTrap::ProxyFragDamage& rhs) : FragTrap(rhs) {}

//	COPY-ASSIGNMENT ---------------------------------------------------------
clp::DiamondTrap& clp::DiamondTrap::operator=(const clp::DiamondTrap& rhs)
{
	std::cout << "Diamond: Copy: Assignement operator" << std::endl;
	if (this == &rhs) 
		return (*this);

	name_ = rhs.name_;
	energy_ =  rhs.energy_;
	health_ = rhs.health_;
	damage_ = rhs.damage_;

	return (*this);
}

clp::DiamondTrap::ProxyFragDamage& clp::DiamondTrap::ProxyFragDamage::operator=(const clp::DiamondTrap::ProxyFragDamage& rhs)
{
	if (this == &rhs) 
		return (*this);

	FragTrap::operator=(rhs);

	return (*this);
}


//	CTOR-NAME ---------------------------------------------------------
clp::DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << "Diamond: Ctor: Name" << std::endl;
	ProxyFragDamage proxy_frag;
	damage_ = proxy_frag.damage_;
	name_ = name;
	// this->name_ = name;
	ClapTrap::name_ = name + "_clap_name";
}

//	FUNCTIONS ---------------------------------------------------------

void	clp::DiamondTrap::attack(const std::string& target, const std::string&)
{
	if (energy_)
	{
		std::cout << "DiamondTrap " + name_ +  " attacks " + target + ", causing " << damage_ << " points of damage!" << std::endl;
		--energy_;
	}
	else
		std::cout << "DiamondTrap " + name_ +  " can't attacks " + target + ", as the current energy is 0" << std::endl;
}

void	clp::DiamondTrap::whoAmI(void)
{
		std::cout << "DiamondTrap Name = " + this->name_ +  " : ClapTrap::name_ = " + ClapTrap::name_ << std::endl;
}
