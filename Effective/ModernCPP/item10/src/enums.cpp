
/*
 *   In C++98 style enums, the names of these unscoped enumerators belong to the
 *   scope containing the enum, and that means nothing else in that scope may
 *   have the same name:
 */
void unscoped_enums() {

	enum Color { black, white, red };  	// black, white, red are in same scope as Color

	//auto white = false;               // error! white already declared in this scope
}

/*
 *   In C++11, the names of scoped enums do not belong to the scope containing
 *   the enum.
 */
void scoped_enums() {

	enum class Color { black, white, red }; // black, white, red are scoped to Color

	auto white = false;              		// fine, no other "white" in scope

	//Color c1 = white;                 	// error! no enumerator named
                                 			// "white" is in this scope

	Color c2 = Color::white;          // fine
	auto c3 = Color::white;           // also fine (and in accord with Item4's advice)
}

int main() {
	unscoped_enums();
	scoped_enums();
}
