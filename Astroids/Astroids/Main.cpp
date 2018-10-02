#include "OpenGL.h"
#include "GL/glut.h"
#include "GL/GL.h"
#include "Ship.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


void draw() {
	manager.Update();
	static float t = 0;
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	manager.Draw();
}

int main(int argc, char** argv) {
	srand(time(0));
	//SceneManager::AddObject(&SceneManager::Player2);
	AttachKeyHandle('w', &manager.Player1.accelCommand);
	AttachKeyHandle('a', &manager.Player1.leftCommand);
	AttachKeyHandle('d', &manager.Player1.rightCommand);
	AttachKeyHandle(' ', &manager.Player1.shootCommand);
	AttachKeyHandle('8', &manager.Player2.accelCommand);
	AttachKeyHandle('4', &manager.Player2.leftCommand);
	AttachKeyHandle('6', &manager.Player2.rightCommand);
	AttachKeyHandle('0', &manager.Player2.shootCommand);
	RunOpenGL(argc, argv, draw);
}
