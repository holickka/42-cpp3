/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:26:18 by hsim              #+#    #+#             */
/*   Updated: 2025/08/26 22:02:35 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	// ClapTrap	user_a("Bob");
	ScavTrap	user_a;
	ScavTrap	user_b("James");
	FragTrap	user_c("Furla");

	user_c.attack("James");
	user_b.takeDamage(10);
	user_b.beRepaired(10);
	user_b.guardGate();

	user_a = user_b;
	user_a.printStat();

	// user_b.attack("Bob");
	// user_a.takeDamage(20);
	// user_a.beRepaired(10);
	return (0);
}