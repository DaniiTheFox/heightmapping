class Obj_terrain{
	private:
		int mapping[17][17];
		int g_parts = 17,g_size = 40;
	public:
		Obj_terrain(int map[17][17]);
		void bg_create_terrain();
};

Obj_terrain::Obj_terrain(int map[17][17]){
	for(int z = 0; z < g_parts; z++){
		for(int x = 0; x < g_parts; x++){
			mapping[x][z] = map[x][z];
		}
	}
}

void Obj_terrain::bg_create_terrain(){
	 for(int z = 0; z < g_parts-1; z++){
	 	for(int x = 0; x < g_parts-1; x++){
		 	glPushMatrix();
	 		glTranslatef(x*4,0,z*4);
			 glBegin(GL_QUADS);
	 	 	  glTexCoord2d(0.0,0.0);glVertex3f( 2, mapping[x+1][z] ,   -2);
     		  glTexCoord2d(0.0,0.5);glVertex3f(-2, mapping[x][z],  -2);
     		  glTexCoord2d(0.5,0.5);glVertex3f(-2, mapping[x][z+1], 2);
     		  glTexCoord2d(0.5,0.0);glVertex3f( 2, mapping[x+1][z+1],   2);
     		 glEnd();
     		glPopMatrix();
	 	}
	 }
}
