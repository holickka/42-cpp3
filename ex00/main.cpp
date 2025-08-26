/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:26:18 by hsim              #+#    #+#             */
/*   Updated: 2025/08/26 18:03:36 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	user_a("Bob");
	ClapTrap	user_b("James");
	user_a.attack("James");
	user_a.takeDamage(10);
	user_a.beRepaired(10);
	return (0);
}