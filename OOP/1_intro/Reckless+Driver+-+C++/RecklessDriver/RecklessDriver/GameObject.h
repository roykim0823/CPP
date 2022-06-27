#pragma once
#include <string>
namespace RecklessDriver {
	class GameObject
	{
		std::string name;
		std::string tag;
		bool enabled;
	public:
		void SetName(const std::string &name) {
			this->name = name;
		}
		void SetTag(const std::string &tag) {
			this->tag = tag;
		}
		void SetEnabled(bool enabled) {
			this->enabled = enabled;
		}

		const std::string &GetName()const {
			return name;
		}
		const std::string &GetTag()const {
			return tag;
		}
		bool IsEnabled() {
			return enabled;
		}
		virtual void OnCollision(GameObject * other) {

		}
	};
}

/*
1. Prevent name clashes
2. Divide the application into manageable chunks
3. Searching/locating classes or other types
*/