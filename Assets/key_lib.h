void keybd(unsigned char key,int x,int y){
	switch(key){
		case 'f':exit(1);break;
		case ' ':player.jump_camera();break;
		case 'x':player.fall_camera();break;
		default:player.mov_forward(1);break;
	}
}


int adj,mx,my;
void ms_look(int x,int y){
	adj = 10;
	if(x >= 320+adj){
		player.mov_camera(CAM_LEFT);
		glutWarpPointer(320,240);
	}
	if(x <= 320-adj){
		player.mov_camera(CAM_RIGHT);
		glutWarpPointer(320,240);
	}
	if(y >= 240+adj){
		player.mov_camera(CAM_DOWN);
		glutWarpPointer(320,240);
	}
	if(y <= 240-adj){
		player.mov_camera(CAM_UP);
		glutWarpPointer(320,240);
	}
	mx = x; my = y;
}
