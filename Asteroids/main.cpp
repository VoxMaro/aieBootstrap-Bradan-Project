////////////////////////////////////////////////////////////////////////////////////////////////////////////
////																									
////		Name:		Bootstrap asteroids															
////																									
////		Purpose:	Main program																	
////																									
////		Author:		Bradan Lean 21/3/17 																	
////																									
////////////////////////////////////////////////////////////////////////////////////////////////////////////

// What three changes have you made to this program?
// 1. -
// 2. -
// 3. -

#include "AsteroidsApp.h"
#include <time.h>

int main() {
	srand((unsigned int)time(NULL));
	auto app = new AsteroidsApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}