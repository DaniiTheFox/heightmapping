
void bg_create_window(int width,int height, int pos, char *name){
	glutInitWindowSize(width,height);
	glutInitWindowPosition(pos,pos);
	glutCreateWindow(name);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0);
}

void glIni(){
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glClearColor(0.7,0.7,1,0);
	glLoadIdentity();
	gluPerspective(60,1,1,50);
}

void standf(){
	usleep(33);
	glutPostRedisplay();
}

double degtorad(float deg){
	double rad = (deg * 3.14159)/180;
	return rad;
}
/*
int createTexture(int bpp,int width,int height,const void *data){
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
	gluBuild2DMipmaps( GL_TEXTURE_2D, bpp, width ,height,GL_RGBA, GL_UNSIGNED_BYTE,data );
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}*/

GLuint createTexture(int bpp, int w, int h, const void *data){
 GLuint tmp_txt;
 glGenTextures(1, &tmp_txt);                                                  // CREATION OF A NEW TEXTURE
 glBindTexture(GL_TEXTURE_2D, tmp_txt);
 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);                 // generate the default texture once again
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 gluBuild2DMipmaps(GL_TEXTURE_2D, bpp, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
 glEnable(GL_BLEND);
 return tmp_txt;
}

void bg_set_fog(float strt , float end ,float dens,float r,float g,float b){
	GLuint filter;
	GLfloat FogColor[4] = {r,g,b,1.0};
	glFogi(GL_FOG_MODE , GL_LINEAR);
	glFogfv(GL_FOG_COLOR , FogColor);
	glFogf(GL_FOG_DENSITY , dens );
	glHint(GL_FOG_HINT , GL_DONT_CARE);
	glFogf(GL_FOG_START , strt );
	glFogf(GL_FOG_END , end);
	glEnable(GL_FOG);
}
