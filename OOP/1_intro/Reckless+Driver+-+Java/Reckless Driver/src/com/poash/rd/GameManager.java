package com.poash.rd;

public class GameManager {
	private int cash ;
	private GameManager(){
		
	}
	static GameManager instance=  new GameManager() ;
	public static GameManager getInstance(){
		return instance ;
	}
	public int GetCash(){
		return cash ;
	}
	public void AddCash(int amount){
		cash += amount ;
	}
	public void NewGame(){
		//Choose vehicle
		PlayerVehicle vehicle = new PlayerVehicle("Sedan", 5, 70, 4) ;
		//Create a player object
		Player player = new Player(100, vehicle) ;
		player.setTag("Player");
		//Prepare the scenery
		Scene scene = new Scene() ;
		scene.Start(player);
		//Run a loop
		while(player.IsAlive()){
			//Generate gameobject (sideobjects, traffic, etc)
			scene.Execute();
		
			//Player is driving the car
			player.Drive() ;
			//Collide with other objects
			
		//Repeat until health > 0
		}
		EndGame();
	}
	
	public void EndGame(){
		System.out.printf("Total cash accumulated : %d", cash);
	}
}
