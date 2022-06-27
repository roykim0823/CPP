package com.poash.rd;

public class SideObject extends GameObject {
	public int getDamage() {
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
	public SideObject(int damage, int cash) {
		super();
		this.damage = damage;
		this.cash = cash;
		count = 0 ;
	}
	private int damage ;
	private int cash ;
	protected int count ;
}
