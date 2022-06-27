package com.poash.rd;

public class NoPowerup extends Powerup {

	@Override
	public void ApplyPowerup(Player player, int damage, int cash) {
		// TODO Auto-generated method stub
		int newHealth = player.GetPlayerHealth().GetUnits()-damage - player.GetPlayerVehicle().getStrength() ;
		player.GetPlayerHealth().SetUnits(newHealth);
		GameManager.getInstance().AddCash(cash);
	}
	@Override
	public boolean IsActive() {
		// TODO Auto-generated method stub
		return false ;
	}
	

}
