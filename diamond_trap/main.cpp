/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:02:37 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 23:55:34 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <iomanip>
#include <typeinfo>

int	main(void)
{
	char prev = std::cout.fill('-');
	std::cout << std::endl << std::setw(30) << "" << std::endl;

	std::cout << "TESTS" << std::endl << std::endl;

	clp::ClapTrap adam("Adam");

	std::cout << "Here we try to cout data type name: " << typeid(adam).name() << std::endl;

	std::cout << "adam name:\t" << adam.name() << std::endl;
	std::cout << "adam damage:\t" << adam.damage() << std::endl;		
	std::cout << "adam energy:\t" << adam.energy() << std::endl;
	std::cout << "adam health:\t" << adam.health() << std::endl;

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	clp::ScavTrap mom("Mom");
	std::cout << "mom name:\t" << mom.name() << std::endl;
	std::cout << "mom damage:\t" << mom.damage() << std::endl;		
	std::cout << "mom energy:\t" << mom.energy() << std::endl;
	std::cout << "mom health:\t" << mom.health() << std::endl;

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	clp::FragTrap dad("Dad");
	std::cout << "dad name:\t" << dad.name() << std::endl;
	std::cout << "dad damage:\t" << dad.damage() << std::endl;		
	std::cout << "dad energy:\t" << dad.energy() << std::endl;
	std::cout << "dad health:\t" << dad.health() << std::endl;

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	clp::DiamondTrap son("Son");
	
	std::cout << std::endl << std::setw(30) << "" << std::endl;

	std::cout << "son name:\t" << son.name() << std::endl;
	std::cout << "Expected:\t" << "Son_clap_name" << std::endl;

	std::cout << std::endl << std::setw(30) << "" << std::endl;	

	std::cout << "son damage:\t" << son.damage() << std::endl;
	std::cout << "Expected:\t" << dad.damage() << std::endl;

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	std::cout << "son energy:\t" << son.energy() << std::endl;
	std::cout << "Expected:\t" << mom.energy() << std::endl;

	std::cout << std::endl << std::setw(30) << "" << std::endl;
	
	std::cout << "son health:\t" << son.health() << std::endl;
	std::cout << "Expected:\t" << adam.health() << std::endl;

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	clp::ClapTrap* ptr_adam = &son;
	ptr_adam->attack("Villain");
	std::cout << "\n\t>>clp::ClapTrap* ptr_adam = &son;\n\t>>ptr_adam->attack(\"Villain\");" << std::endl;	
	std::cout << "Expected:\t\n\tClapTrap Son_clap_name attacks ...\n";

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	son.attack("Villain");
	std::cout << "Expected:\t\n\tScavTrap Son_clap_name attacks...\n";

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	son.attack("Villain", "as Diamond");
	std::cout << "Expected:\t\n\tDiamondTrap Son attacks...\n";
	
	std::cout << std::endl << std::setw(30) << "" << std::endl;

	son.highFivesGuys();
	std::cout << "Expected:\t\n\t";
	dad.highFivesGuys();

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	son.guardGate();
	std::cout << "Expected:\t\n\t";
	mom.guardGate();

	std::cout << std::endl << std::setw(30) << "" << std::endl;

	son.whoAmI();
	std::cout << "Expected:\t\n\tDiamondTrap Name = Son : ClapTrap::name_ = Son_clap_name\n";
	
	std::cout << std::setw(30) << "" << std::endl << std::endl;
	std::cout.fill(prev);
	return 0;
}
