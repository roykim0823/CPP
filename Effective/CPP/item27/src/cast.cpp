#include "window.h"
#include <vector>
#include <memory>

int main() {
	// test for static_cast
	SpecialWindow spW;
	spW.onResize(200);

	// tests for dynamic_cast
	/* Not Working
	typedef std::vector<std::shared_ptr<Window>> VPW;
	VPW winPtrs;

	for(VPW::iterator iter = winPtrs.begin(); iter!=winPtrs.end(); ++iter) {
		// undesirable code: uses dynamic_case
		if(SpecialWindow *psw = dynamic_cast<SpecialWindow*>(iter->get()))
			psw->blink();
	}
	*/
	/*
	typedef std::vector<std::shared_ptr<SpecialWindow>> VPW;
	VPW winPtrs;

	for(VPW::iterator iter = winPtrs.begin(); iter!=winPtrs.end(); ++iter) {
		// undesirable code: uses dynamic_case
		(*iter)->blink();
	}
	*/

}
