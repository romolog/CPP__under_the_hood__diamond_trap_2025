/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:09:25 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 23:47:25 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <string>

#define FRG_DMG_DFLT 30
#define FRG_ENRG_DFLT 100
#define FRG_NAME_DFLT "FRAG_DEFAULT"

typedef unsigned int uint;

namespace clp
{
	class FragTrap : virtual public ClapTrap
	{
		public:
			FragTrap();
			virtual ~FragTrap();
			FragTrap(const FragTrap&);
			FragTrap&		operator=(const FragTrap&);
		public:
			FragTrap(const std::string& name);
		public:
			// using			ClapTrap::attack;
			void			attack(const std::string& target);
			void			highFivesGuys(void);
	};
}