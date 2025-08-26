/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:26:18 by hsim              #+#    #+#             */
/*   Updated: 2025/08/26 21:27:36 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	user_a("Bob");
	ScavTrap	user_b("James");

	user_a.attack("James");
	user_b.takeDamage(10);
	user_b.beRepaired(10);
	user_b.guardGate();
	// user_b.attack("Bob");
	// user_a.takeDamage(20);
	// user_a.beRepaired(10);
	return (0);
}