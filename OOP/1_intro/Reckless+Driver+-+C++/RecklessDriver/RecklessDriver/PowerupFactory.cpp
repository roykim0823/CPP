#include "PowerupFactory.h"


#include "Armor.h"
#include "HealthKit.h"
#include "NoPowerup.h"

RecklessDriver::Powerup* RecklessDriver::PowerupFactory::CreatePowerup(int key) {
	switch(key) {
	case -1:
		return new NoPowerup{} ;
	case 0:
		return new HealthKit{} ;
	case 1:
		return new Armor{} ;
	}
	return nullptr ;
}
