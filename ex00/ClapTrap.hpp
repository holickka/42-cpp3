/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:26:30 by hsim              #+#    #+#             */
/*   Updated: 2025/08/26 21:39:08 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	private:
		std::string	name;
		int			hit_point;
		int			energy_point;
		int			attack_damage;
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &old_obj);
		ClapTrap&	operator=(const ClapTrap &old_obj);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		printStat(void);
		void		printError(void);
};


#endif