package com.poash.rd;

public class Program {
	private static void Initialize() {
		SideObjectFactory.GetInstance().RegisterCallback(0, ()-> {return new LetterBox(8, 13);});
		SideObjectFactory.GetInstance().RegisterCallback(1, ()-> {return new FireHydrant(5, 10);});
	}
	public static void main(String[] args) {
		Initialize();
		GameManager.getInstance().NewGame();
	}

}
