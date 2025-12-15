/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:12:17 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 23:46:55 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <string>

#define SCV_DMG_DFLT 20
#define SCV_ENRG_DFLT 50
#define SCV_NAME_DFLT "SCAV_DEFAULT"

namespace clp
{
	class ScavTrap : virtual public ClapTrap
	{
		public:
			ScavTrap();
			virtual ~ScavTrap();
			ScavTrap(const ScavTrap&);
			ScavTrap&		operator=(const ScavTrap&);
		public:
			ScavTrap(const std::string& name);
		public:
			void			attack(const std::string& target);			
			void			guardGate(void);
	};
}