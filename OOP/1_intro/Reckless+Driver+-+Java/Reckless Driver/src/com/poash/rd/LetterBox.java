package com.poash.rd;

public class LetterBox extends SideObject {

	public LetterBox(int damage, int cash) {
		super(damage, cash);
		setName("LetterBox") ;
	}

	@Override
	public void OnCollision(GameObject other) {
		if(other.getTag().equals("Player")){
			Player player = (Player)other; 
			if(count == 0){
				System.out.println("#### COLLISION ->[Letterbox] Letters falling");
				player.ApplyDamage(getDamage(), getCash());
			}else{
				System.out.println("#### COLLISION ->[Letterbox] Collided again");
				player.ApplyDamage(getDamage(), getCash() * count);
			}
		}
	}
}
