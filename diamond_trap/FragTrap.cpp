/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:09:11 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 23:47:33 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

//	CTOR-DEFAULT ------------------------------------------------------------
clp::FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Frag: Ctor: Default" << std::endl;
	damage_ = FRG_DMG_DFLT;
	energy_ = FRG_ENRG_DFLT;
	name_ += FRG_NAME_DFLT;
}

//	DTOR-DEFAULT ------------------------------------------------------------
clp::FragTrap::~FragTrap() 
{
	std::cout << "Frag: Dtor" << std::endl;
}

//	COPY-CTOR ---------------------------------------------------------------
clp::FragTrap::FragTrap(const clp::FragTrap& rhs) : ClapTrap(rhs)
{
	std::cout << "Frag: Copy: Ctor" << std::endl;
}

//	COPY-ASSIGNMENT ---------------------------------------------------------
clp::FragTrap& clp::FragTrap::operator=(const clp::FragTrap& rhs)
{
	std::cout << "Frag: Copy: Assignement operator" << std::endl;
	if (this == &rhs) 
		return (*this);
		
	ClapTrap::operator=(rhs);

	return (*this);
}

//	CTOR-NAME ---------------------------------------------------------
clp::FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	damage_ = FRG_DMG_DFLT;
	energy_ = FRG_ENRG_DFLT;
	std::cout << "Frag: Ctor: Name" << std::endl;
}

//	ACCESSORS ---------------------------------------------------------

//	FUNCTIONS ---------------------------------------------------------
void	clp::FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " + name_ + " invites you to high five!" << std::endl;	
}

// void	clp::ClapTrap::attack(const std::string& target) override 
void	clp::FragTrap::attack(const std::string& target)
{
	if (energy_)
	{
		std::cout << "FragTrap " + name_ +  " attacks " + target + ", causing " << damage_ << " points of damage!" << std::endl;
		--energy_;
	}
	else
		std::cout << "FragTrap " + name_ +  " can't attacks " + target + ", as the current energy is 0" << std::endl;
}