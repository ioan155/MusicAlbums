#include <iostream>
#include "Controller.h"
#include "Repository.h"
#include "UI.h"
#include "Album.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {
	Repository repo;
	Controller controller{ repo };
	UI ui{ controller };

	ui.initialize();
	_CrtDumpMemoryLeaks();
	return 0;
}