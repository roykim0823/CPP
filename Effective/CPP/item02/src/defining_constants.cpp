//#define ASPECT_RATIO 1.653
// Don't use macro for const
// 1. ASPECT_RATIO may not get entered into the symbol table
// 2. It could result in multiple copies of 1.653 in your object code

// ... but use this:
const double ASPECT_RATIO = 1.653;


// To define a constant char*-based string in a header file, you have to
// write const twice:
const char * const authorName = "Scott Meyers";
const std::string authorName("Scott Meyers");	// better
