package com.poash.rd;

public class PlayerHealth {
	private int healthUnits = 100 ;
	private PlayerState playerState = PlayerState.HEALTHY ;
	private void UpdateState() {
		if(healthUnits > 70) {
			playerState = PlayerState.HEALTHY;
		}else if(healthUnits >= 25 && healthUnits <= 70) {
			playerState = PlayerState.INJURED ;
		}else if(healthUnits >=1 && healthUnits < 25) {
			playerState = PlayerState.CRITICAL ;
		}else {
			playerState = PlayerState.DEAD ;
		}
		System.out.println("Current state:" + playerState);
	}
	public int GetUnits() {
		return healthUnits ;
	}
	public void SetUnits(int units) {
		healthUnits = units < 0 ? 0 : units ;
		UpdateState();
	}
	public PlayerState GetPlayerState() {
		return playerState ;
	}
}
