#include "AgentProjApp.h"

int main() {
	
	auto app = new AgentProjApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}