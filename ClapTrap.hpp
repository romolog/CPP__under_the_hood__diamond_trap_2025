/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:12:17 by rponomar          #+#    #+#             */
/*   Updated: 2025/06/06 20:09:56 by rponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <limits>

typedef unsigned int uint;

#define CLP_DMG_DFLT 0
#define CLP_ENRG_DFLT 10
#define CLP_HLTH_DFLT 100
#define CLP_NAME_DFLT "CLAP_DFLT_"

namespace clp
{
	class ClapTrap
	{
		public:
			ClapTrap();
			virtual ~ClapTrap();
			ClapTrap(const ClapTrap&);			
			ClapTrap&		operator=(const ClapTrap&);
		public:
			ClapTrap(const std::string& name);		
		public:
			uint			damage(void) const;			
			uint			energy(void) const;
			uint			health(void) const;
			std::string		name(void) const;
		public:
			void			attack(const std::string& target);
			void			takeDamage(const uint amount);
			void			beRepaired(const uint amount);
		protected:
			uint			damage_;
			uint			energy_;
			uint			health_;
			std::string		name_;
		// protected:
		// 	std::string		type_;
	};
}