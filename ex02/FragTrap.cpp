/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 21:37:13 by hsim              #+#    #+#             */
/*   Updated: 2025/08/26 21:58:46 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "[FragTrap] Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "[FragTrap] Default constructor with name called" << std::endl;
	this->name = name;
	this->hit_point = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FragTrap] Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& old_obj)
{
    *this = old_obj;
	std::cout << "[FragTrap] Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& old_obj)
{
    if (this == &old_obj)
        return (*this);
	this->name = old_obj.name;
	this->attack_damage = old_obj.attack_damage;
	this->hit_point = old_obj.hit_point;
	this->energy_point = old_obj.energy_point;
	return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "Ready? Let's high five!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hit_point <= 0 || this->energy_point <= 0)
	{
		printError();
		return ;
	}

	std::cout	<< "FragTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->attack_damage
				<< " points of damage!"
				<< std::endl;
	this->energy_point -= 1;
	printStat();

}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "FragTrap " << this->name
				<< " takes in " << amount
				<< " points of damage!"
				<< std::endl;
	this->hit_point -= amount;
	printStat();
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point <= 0 || this->energy_point <= 0)
	{
		printError();
		return ;
	}
	std::cout	<< "FragTrap " << this->name
				<< " recovers " << amount
				<< " health points!"
				<< std::endl;

	this->hit_point += amount;
	this->energy_point -= 1;
	printStat();
}