#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
//#include<windows.h>
#include<time.h>
#include<math.h>
#include "Assets/Texture/textures.c"
#include "Assets/const_d.c"
#include "Assets/glb_var.c"
#include "Assets/aux_lib.h"
#include "Assets/obj_cam.c"
#include "Assets/hgt_map.c"
Obj_player player(8,1.5,8,135,0);
Obj_terrain heightmap(image);
#include "Assets/key_lib.h"
#include "Assets/dsp_lib.h"
int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	bg_create_window(640,480,64,"Heightmap");
	glIni();
	glutDisplayFunc(display);
	glutKeyboardFunc(keybd);
	glutPassiveMotionFunc(ms_look);
	glutIdleFunc(standf);
	glutMainLoop();
	system("pause");
	return EXIT_SUCCESS;
}
