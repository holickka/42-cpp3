/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:28:06 by hsim              #+#    #+#             */
/*   Updated: 2025/08/26 21:28:10 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "[ScavTrap] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "[ScavTrap] Default constructor with name called" << std::endl;
	this->name = name;
	this->hit_point = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[ScavTrap] Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &old_obj)
{
	*this = old_obj;
	std::cout << "[ScavTrap] Copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& old_obj)
{
	std::cout << "[ScavTrap] Copy assignment operator called" << std::endl;
	this->name = old_obj.name;
	this->hit_point = old_obj.hit_point;
	this->energy_point = old_obj.energy_point;
	this->attack_damage = old_obj.attack_damage;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout	<< "ScavTrap " << this->name
				<< " is now in Gatekeeper mode!"
				<< std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_point <= 0 || this->energy_point <= 0)
	{
		printError();
		return ;
	}

	std::cout	<< "ScavTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->attack_damage
				<< " points of damage!"
				<< std::endl;
	this->energy_point -= 1;
	printStat();

}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "ScavTrap " << this->name
				<< " takes in " << amount
				<< " points of damage!"
				<< std::endl;
	this->hit_point -= amount;
	printStat();
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point <= 0 || this->energy_point <= 0)
	{
		printError();
		return ;
	}
	std::cout	<< "ScavTrap " << this->name
				<< " recovers " << amount
				<< " health points!"
				<< std::endl;

	this->hit_point += amount;
	this->energy_point -= 1;
	printStat();
}