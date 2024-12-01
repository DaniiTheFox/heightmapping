void display(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	bg_set_fog(19,60,12,0.8,0.8,1.0);
	
	GLuint ghm_tex;
 	glGenTextures(1,&ghm_tex);
	glBindTexture(GL_TEXTURE_2D,ghm_tex);
	createTexture(gm_tex.bytes_per_pixel,gm_tex.width,gm_tex.height,gm_tex.pixel_data);
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	player.draw_camera();
	player.calculate_cam();
	
	heightmap.bg_create_terrain();
	
	
	glFlush();
	glutSwapBuffers();
}

