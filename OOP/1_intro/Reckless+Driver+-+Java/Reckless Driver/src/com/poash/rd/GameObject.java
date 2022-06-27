package com.poash.rd;

public class GameObject {
	private boolean enabled ;
	private String name ;
	private String tag ;
	public final boolean isEnabled() {
		return enabled;
	}
	public final void setEnabled(boolean enabled) {
		this.enabled = enabled;
	}
	public final String getName() {
		return name;
	}
	public final void setName(String name) {
		this.name = name;
	}
	public final String getTag() {
		return tag;
	}
	public final void setTag(String tag) {
		this.tag = tag;
	}
	public void OnCollision(GameObject other){
		
	}
}

/*
 * 1. Prevent name conflicts
 * 2. Divide the application into manageable modules
 * 3. Makes searching/locating classes/interfaces easier
 * 4. Provide controlled access to classes/interfaces
 */
