#pragma once
enum class PlayerState {
	HEALTHY, // > 70
	INJURED, // >=25 && <=70
	CRITICAL,// >=1 && <25
	DEAD	//0
};