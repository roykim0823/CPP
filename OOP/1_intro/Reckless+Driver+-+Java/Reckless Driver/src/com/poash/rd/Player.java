package com.poash.rd;

public class Player extends GameObject {
	public Player(int health, PlayerVehicle vehicle) {
		super();
		playerHealth.SetUnits(health);
		this.vehicle = vehicle;
	}
	public boolean IsAlive(){
		return playerHealth.GetPlayerState() != PlayerState.DEAD ;
	}
	public void ApplyDamage(int damage, int cash){
		powerup.ApplyPowerup(this, damage, cash);
		
	}
	public void Drive() {
		// TODO Auto-generated method stub
		System.out.printf("\nPlayer is driving [Health:%d][%s]\n", playerHealth.GetUnits(), powerup);
		for(int i = 0 ; i  < 10 ;++i){
			try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.print(".");
		}
		System.out.println("");
	}
	public void Accelerate(){
		vehicle.Up();
		
	}
	public void Brake(){
		vehicle.Down();
	}
	public void SteerLeft(){
		vehicle.Left();
	}
	public void SteerRight(){
		vehicle.Right();
	}
	public PlayerHealth GetPlayerHealth() {
		return playerHealth ;
	}
	public PlayerVehicle GetPlayerVehicle() {
		return vehicle ;
	}
	public void SetPowerup(Powerup p) {
		powerup = p ;
	}
	private PlayerHealth playerHealth = new PlayerHealth() ;
	private PlayerVehicle vehicle ;
	private Powerup powerup = PowerupFactory.CreatePowerup(-1) ;
	public Powerup GetPowerup() {
		// TODO Auto-generated method stub
		return powerup;
	}
	
}
