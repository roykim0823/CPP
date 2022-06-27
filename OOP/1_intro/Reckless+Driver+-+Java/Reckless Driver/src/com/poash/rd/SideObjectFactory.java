package com.poash.rd;

import java.util.HashMap;

public class SideObjectFactory {
	private HashMap<Integer, Callback> callbacks = new HashMap<>() ;
	private static SideObjectFactory instance = new SideObjectFactory() ;
	private SideObjectFactory() {
		
	}
	public void RegisterCallback(int key, Callback callback) {
		callbacks.put(key, callback) ;
	}
	public SideObject CreateSideObject(int key) {
		Callback cb = callbacks.get(key) ;
		return cb.Create() ;
	}
	public static SideObjectFactory GetInstance() {
		return instance ;
	}
}
