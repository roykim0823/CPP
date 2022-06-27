package com.poash.rd;

public class Sedan extends Vehicle {
	public Sedan(int damage, int cash){
		super(damage, cash) ;
		setName("Sedan");
	}
	@Override
	public void OnCollision(GameObject other) {
		if(other.getTag().equals("Player")){
			Player player = (Player)other; 
				System.out.println("#### COLLISION ->[Sedan] Sparks flying");
				player.ApplyDamage(getDamage(), getCash());
		}
	}
}
