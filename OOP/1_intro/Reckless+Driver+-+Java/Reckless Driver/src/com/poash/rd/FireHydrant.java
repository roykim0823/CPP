package com.poash.rd;

public class FireHydrant extends SideObject {
	public FireHydrant(int damage, int cash) {
		super(damage, cash);
		setName("FireHydrant");
	}

	@Override
	public void OnCollision(GameObject other) {
		if(other.getTag().equals("Player")){
			Player player = (Player)other; 
			if(count == 0){
				System.out.println("#### COLLISION ->[FireHydrant] Fountain");
				player.ApplyDamage(getDamage(), getCash());
			}else{
				System.out.println("#### COLLISION ->[FireHydrant] Collided again");
				player.ApplyDamage(getDamage(), getCash() * count);
			}
		}
	}
}
