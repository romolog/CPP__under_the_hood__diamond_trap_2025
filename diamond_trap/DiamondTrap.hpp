/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diamond.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:12:17 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 02:58:17 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

#define DMD_NAME_DFLT "_DIAMOND_DEFAULT"

namespace clp
{
	class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
	{
		private:
			std::string					name_;

			class ProxyFragDamage: public FragTrap
			{
				public:
					using				FragTrap::damage_;
				public:
					ProxyFragDamage();
					~ProxyFragDamage();
					ProxyFragDamage(const ProxyFragDamage& rhs);
					ProxyFragDamage&	operator=(const ProxyFragDamage& rhs);
			};	
		public:
			DiamondTrap();
			~DiamondTrap();
			DiamondTrap(const DiamondTrap& rhs);
			DiamondTrap&				operator=(const DiamondTrap& rhs);
		public:
			DiamondTrap(const std::string& name);
		public:
			using						ScavTrap::attack;
			void						attack(const std::string& target, const std::string& );
			void						whoAmI(void);
	};


}