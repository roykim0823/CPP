package com.poash.rd;

public abstract class Powerup extends GameObject {
	private static final int DURATION=5 ;
	protected int countdown = DURATION ;
	public static final int POWERUP_COUNT = 2 ;
	public abstract void ApplyPowerup(Player player, int damage, int cash) ;
	public boolean IsActive() {return true ;}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "DEFAULT" ;
	}
}
