package com.poash;

public class Lamp {
	private boolean off = true;

	public void SwitchOn() {
		if (off) {
			System.out.println("Lamp is switched on");
			off = false;
		} else {
			System.out.println("Lamp is already switched on");
		}
	}

	public void SwitchOff() {
		if (off) {
			System.out.println("Lamp is already switched off");
		} else {
			System.out.println("Lamp is switched off");
			off = true;
		}

	}
}
