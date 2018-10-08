// TODO: 
//   * second String example about conceptual constness.
//   * mutable example + trick example

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// const Member functions
class TextBlock {
public:

  TextBlock(const char *value): text(value)
  {
  }

  // operator[] for const objects
  const char& operator[](std::size_t position) const
  { return text[position]; }
 
  // operator[] for non-const objects
  /*
  char& operator[](int position)
  { return text[position]; }
  */

  // remove duplicated code by const casting
  char& operator[](int position)	// now just calls const op[]
  {
	  return const_cast<char&>(                         	// remove const
	  	static_cast<const TextBlock&>(*this)[position]);    // add const to use const op[]
  }
  
  operator const char *() { return text.c_str(); }
 
private:
  std::string text;
};


// bitwise constness (physical constness) and logical constness
class CTextBlock {
public:

  CTextBlock(const char *value)
  {
    if (value) {
      pText = new char[strlen(value) + 1];
      strcpy(pText, value);
    }
    else {
      pText = new char[1];
      *pText = '\0';
    }
  }

  // inappropriate (but bitwise const) declaration of operator[]
  char& operator[](std::size_t position) const
  { return pText[position]; }
 
  operator char *() const { return pText; }

  std::size_t length() const;
 
private:
	char *pText;
	// mutable variables are allowed to be changed in const member function
	mutable std::size_t textLength;	// last calculated length of textblock
	mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const {
	if(!lengthIsValid) {
		textLength = std::strlen(pText);
		lengthIsValid = true;
	}
	return textLength;
}


// a pointer itself can be const, the data it points to can be const, both, neither
// const appears to the left of the asterisk 	-> what's pointed to is constant
// const appears to the right of the asterisk  	-> the pointer itself is constant
void constForPointers() {

	char greeting[] = "Hello";

	char *p = greeting;					// non-const pointer, non-const data
	const char *p_cont = greeting; 		// non-const pointer, const data
	
	char *const cont_p = greeting;		// const pointer, non-const data
	// char const *cont_p = greeting;   // const pointer, non-const data
	
	const char *const const_p_const = greeting;		// const pointer, const data
	// const char const *const_p_const = greeting; 	// const pointer, const data
}

void constForIter() {
	std::vector<int> vec{5};

	const std::vector<int>::iterator iter = 	// iter acts like a T* const
		vec.begin();	
	*iter=10;								  	// Ok, changes what iter points to  	
   	//++iter;										// Error, iter is const

	std::vector<int>::const_iterator citer = 	// iter acts like a const T* 
		vec.begin();	
	//*citer=10;								  	// Error, citer is const  	
   	++citer;	   								// fine, changes citer
}


int main()
{

	constForPointers();
	constForIter();

	TextBlock tb("Hello");
	std::cout << tb[0] << endl;  	// calls non-const TextBlock::operator[]

	const TextBlock ctb("World");
	std::cout << ctb[0] << endl;; 	// call const TextBlock::operator[]

	tb[0] = 'x';					// fine - writing a non-const string
	//ctb[0] = 'x';					// error! - writing a const String
    cout << tb << endl;

	// bitwise const can be broken
	const CTextBlock cctb("Hello");
	char *pc = &cctb[0];
	*pc = 'J';
	cout << cctb << endl;

}
