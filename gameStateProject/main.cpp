#include "gameStateProjectApp.h"

int main() {
	
	auto app = new gameStateProjectApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}