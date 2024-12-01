class Obj_player{
	private:
		float x,y,z;
		float xf,yf,zf;
		float xt,yt,zt;
		int dir,dirY;
	public:
		Obj_player(float,float,float,int,int);
		void calculate_cam();	
		void mov_camera(int);	
		void mov_forward(float);
		void fall_camera();
		void jump_camera();
		void draw_camera();
		float cam_debug_get_val(int);
		void cam_debug_position(float,float,float,int,int);
};

Obj_player::Obj_player(float _x,float _y,float _z,int _d,int _dy){
	x = _x; y = _y; z = _z;
	dir = _d; dirY = _dy;
}

void Obj_player::calculate_cam(){
	xf = x; yf = y; zf = z;
	xt = x + cos(degtorad(dir));
	yt = y - sin(degtorad(dirY));
	zt = z - sin(degtorad(dir));
}

void Obj_player::mov_camera(int ac){
	switch(ac){
		case 0:if(dirY < 90 ){dirY++;}break; // move camera down ++
		case 1:if(dirY > -90){dirY--;}break; // move camera up --
		case 2:dir--;break; // move camera left --
		case 3:dir++;break; // move camera right ++
	}
	if(dir <= 0){dir = 359;}else if(dir >= 360){dir = 0;}
}

void Obj_player::mov_forward(float speed){
	x = (x + cos(degtorad(dir))) * speed;
	z = (z - sin(degtorad(dir))) * speed;
}

void Obj_player::fall_camera(){
	y--;
}

void Obj_player::jump_camera(){
	y++;
}


void Obj_player::draw_camera(){
	gluLookAt(xf,yf,zf,xt,yt,zt,0,1,0);
}

float Obj_player::cam_debug_get_val(int val){
	float dirf;
	switch(val){
		case 0:return x;break;
		case 1:return y;break;
		case 2:return z;break;
		case 3:dirf = dir;return dirf;break;
		case 4:dirf = dirY;return dirf;break;
	}
}

void Obj_player::cam_debug_position(float _x,float _y,float _z,int _d,int _dy){
	x = _x; y = _y; z = _z;
	dir = _d; dirY = _dy;
}
