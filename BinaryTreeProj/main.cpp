#include "BinaryTreeProjApp.h"

int main() {
	
	auto app = new BinaryTreeProjApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}