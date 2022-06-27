#pragma once
namespace RecklessDriver{
class Powerup ;
class PowerupFactory
{
public:
	static Powerup * CreatePowerup(int key) ;
};
}

