package com.poash.rd;

public class Vehicle extends GameObject {
	private int damage ;
	private int cash ;
	public Vehicle(int damage, int cash){
		this.damage = damage ;
		this.cash = cash ;
	}
	public final int getDamage() {
		return damage;
	}
	public final void setDamage(int damage) {
		this.damage = damage;
	}
	public final int getCash() {
		return cash;
	}
	public final void setCash(int cash) {
		this.cash = cash;
	}
	
}
