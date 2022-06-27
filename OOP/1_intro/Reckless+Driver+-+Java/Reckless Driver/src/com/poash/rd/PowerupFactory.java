package com.poash.rd;

public class PowerupFactory {

	public static Powerup CreatePowerup(int key) {
		switch(key) {
		case -1:
			return new NoPowerup() ;
		case 0:
			return new HealthKit() ;
		case 1:
			return new Armor() ;
		}
		return null ;
	}
}
