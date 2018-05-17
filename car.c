/*Ellen Priscila Borges Oliveira RA 69554
O programa cria uma forma tridimensiona utilizando Splines e uma fonte de luz. 
*/
#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>



GLfloat angle=45;
GLfloat fAspect;
GLint eixox=0, eixoy=0, eixoz=0;

/*-------------------------------------------Pontos de controle-----------------------------------------*/

                             
GLfloat ctrlpointsinterno1[4][4][3] = {
				  {{-4,3,0}, {-4,3,0}, {4,3,0}, {4,3,0}},
				  { { -8,4,0 }, { -4,4, 3 }, {4,4,    3 }, { 8,4,0 } },
				  { { -8,-4,0}, {  -4,-4,  3 }, { 4,-4,   3 }, {8,-4,0 } },
				  { {-10,-6,-4 }, {-6,-4,0 }, {6,-4,0 }, { 10,-6,-4}} 

};
GLfloat ctrlpointsinterno2[4][4][3] = {
				  {{-6,4,0}, {-6,4,0}, {6,4,0}, {6,4,0}},
				  { { -6,4,0 }, { -4,4, 2 }, {4,4,    2 }, { 6,4,0 } },
				  { { -6,-4,0}, {  -4,-4,  2 }, { 4,-4,   2 }, {6,-4,0 } },
				  { {-8,-4,-4 }, {-6,-4,0 }, {6,-4,0 }, {8,-4,-4}} 

};
GLfloat ctrlpointsporta[4][4][3] = {
				  {{-4,3,0}, {-4,3,0}, {4,3,0}, {4,3,0}},
				  { { -8,4,0 }, { -4,4, -3 }, {4,4,    -3 }, { 6,4,0 } },
				  { { -8,-4,0}, {  -4,-4,  -3 }, { 4,-4,   -3 }, {6,-4,0 } },
				  { {-8,-6,0 }, {-4,-6,0 }, { 4,-6,0 }, { 6,-6,0}} 

};
GLfloat ctrlpointslateralesquerda[4][4][3] = {
				  {{-4,3,3}, {-4,3,0}, {4,3,0}, {7,3,1}},
				  { { -5,4,3 }, { -4,4, -1 }, {4,4,    -1 }, { 7,4,0 } },
				  { { -9,-5,4}, {  -4,-4,  -1 }, { 4,-4,   -1 }, {7,-4,0 } },
				  { {-12.5,-5.5,4 }, {-4,-6,-6 }, { 4,-6,0 }, {10,-6,0}} 

};
	
GLfloat ctrlpointslateraldireita[4][4][3] = {					
				  {{-7,-3,-1}, {-4,-3,0}, {4,-3,0}, {4,-3,-3}},
				  { {  -7,-4,0 }, { -4,-4,    -1 }, {4,-4, -1 }, { 5,-4,-3 } },
				  { { -7,4,0}, {  -4,4,  -1 }, { 4,4,  -1  }, {9,5,-4} },
				  { {-10,6,0 }, {-4,6,0}, { 4,6,6 }, { 12.5,5.5,-4 }} 

};

GLfloat ctrlpointslateralesquerdafrente[4][4][3] = {
				   {{-9,3,0}, {-4,3,3}, {4,3,3}, {8,-5,5}},
				  { { -6,4,0 }, { -4,4, -5 }, {4,4,    -5 }, { 9,4,0 } },
				  { { -9,-5,3}, {  -4,-4,  -5 }, { 4,-4,   -5 }, {9,-4,0 } },
				  { {-12.5,-5.5,0 }, {-4,-6,-0 }, { 4,-6,3 }, {5,-6,0}} 
};

GLfloat ctrlpointslateraldireitafrente[4][4][3] = {
				  {{-8,5,-5}, {-4,-3,-3}, {4,-3,-3}, {9,-3,0}},
				  { { -9,-4,0 }, {-4, -4, 5}, {4,-4, 5 }, { 6,-4,0 } },
				  { { -9,-4,0}, {  -4,4,   5}, { 4,4,  5 }, {9,5,-3 } },
				  { {-5,6,0 }, { -4,6,-3 }, { 4,6,0}, {12.5,5.5,0}}

};



GLfloat ctrlpointsteto[4][4][3] = {
				  {{-14,8,6}, {-6,10,0}, {6,10,0}, {6,9,0}},
				  { { -8,4,2 }, { -4,4, -6 }, {4,4, -6 }, { 10,4,0 } },
				  { { -8,-4,2}, {  -4,-4,  -6 }, { 4,-4,   -6 }, {10,-4,0 } },
				  { {-14,-8,6 }, {-6,-10,0 }, {6,-10,0 }, { 6,-9,0}} 

};

GLfloat ctrlpointscapodianteiro[4][4][3] = {
				  {{-12,10,0}, {-4,6,0}, {4,8,0}, {5,5,2}},
				  { { -8,6,0 }, { -4,4, -4 }, {4,4,    -4 }, { 8,4,2 } },
				  { { -8,-6,0}, {  -4,-4, - 4 }, { 4,-4,   -4 }, {8,-4,2 } },
				  { {-12,-10,0 }, {-4,-6,0 }, { 4,-8,0 }, { 5,-5,2}} 

};

GLfloat ctrlpointscapotraseiro[4][4][3] = {
				  {{-5,5,0}, {-4,8,0}, {4,8,0}, {6,8,0}},
				  { { -6,4,0 }, { -4,4, -4 }, {4,4,    -4 }, {6,8,0} },
				  { { -6,-4,0}, {  -4,-4, - 4 }, { 4,-4,   -4 }, {6,-8,0} },
				  { {-5,-5,0 }, {-4,-8,0 }, { 4,-8,0 }, { 6,-8,0}} 

};

GLfloat ctrlpointsbase[4][4][3] = {
				  {{-20,11,0}, {-8,12,0}, {4,12,0}, {20,10,0}},
				  { { -28,8,0 }, { -4,4, 0 }, {4,4,    0 }, { 26,8,0 } },
				  { { -28,-8,0}, {  -4,-4,  0 }, { 4,-4,   0 }, {26,-8,0 } },
				  { {-20,-11,0 }, {-8,-12,0 }, { 8,-12,0 }, { 20,-10,0}} 

};

GLfloat ctrlpointscalota[4][4][3] = {
				  {{-2.5,3,0}, {-2,4,0}, {2,4,0}, {2.5,3,0}},
				  { { -4,2,0 }, { -2,2, -6 }, {2,2,  -6 }, { 4,2,0 } },
				  { { -4,-2,0}, {  -2,-2, - 6 }, { 2,-2, -6 }, {4,-2,0 } },
				  { {-2.5,-3,0 }, {-2,-4,0 }, { 2,-4,0 }, { 2.5,-3,0}} 

};

/*-----------------------------------Funcao de desenho-------------------------------------*/

void desenha_carro(){

/*rodas*/
 	glPushMatrix();
		glPushMatrix();
  			glColor4f(0.0, 0.0, 0,0.5);
			glTranslatef(12,12,2.5);
			glRotatef(90,1,0,0);
			glutSolidTorus(2,3.5,50,50);

			glColor3f(0.5, 0.5, 0.5);
			glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscalota[0][0][0]);
			glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			
		 glPopMatrix();

		glPushMatrix();
			glColor4f(0.0, 0.0, 0,0.5);
			glTranslatef(-12,-12,2.5);
			glRotatef(-90,1,0,0);
			glutSolidTorus(2,3.5,50,50);

			glColor3f(0.5, 0.5, 0.5);
			glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscalota[0][0][0]);
			glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
		 glPopMatrix();
	
		glPushMatrix();
			glColor4f(0.0, 0.0, 0,0.5);
			glTranslatef(-12,12,2.5);
			glRotatef(90,1,0,0);
			glutSolidTorus(2,3.5,50,50);
			glColor3f(0.5, 0.5, 0.5);

			glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscalota[0][0][0]);
			glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
		 glPopMatrix();

		glPushMatrix();
			glColor4f(0.0, 0.0, 0,0.5);
			glTranslatef(12,-12,2.5);
			glRotatef(-90,1,0,0);
			glutSolidTorus(2,3.5,50,50);

			glColor3f(0.5, 0.5, 0.5);
			glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscalota[0][0][0]);
			glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
			glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
		 glPopMatrix();
	glPopMatrix();
/*base*/
	glPushMatrix();
		
		glColor3f(0.5,0.5,0.6);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsbase[0][0][0]);
		glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
		glTranslatef(0,0,-0.5);
		glRotatef(180,1,0,0);
		glColor3f(0.7, 0, 0);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsbase[0][0][0]);
		glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
	glPopMatrix();

/*capo dianteiro*/
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(18,0,-5);
		glRotatef(-22,0,1,0);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscapodianteiro[0][0][0]);
		glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
	glPopMatrix();
/*capo traseiras*/
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(-22.5,0,-3.5);
		glRotatef(52,0,1,0);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscapotraseiro[0][0][0]);
		glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
		
	glPopMatrix();


/*teto*/
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(-5,0,-14);
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsteto[0][0][0]);
		glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
	glPopMatrix();



/*porta*/
	//porta do passageiro
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(1,10,-3.3);
		glRotatef(90,1,0,0);		
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsporta[0][0][0]);
		glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			
	glPopMatrix();
        //porta do motorista
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(-1,-10,-3.3);
		glRotatef(90,1,0,0);
		glRotatef(180,0,1,0);			
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsporta[0][0][0]);
		glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);			
	glPopMatrix();


/*volante*/

	glPushMatrix();
  		glColor4f(0.0, 0.0, 0,0.5);
		glTranslatef(7,-5,-7);
		glRotatef(75,0,1,0);
		glutSolidTorus(0.2,2.5,50,50);
	
	glPopMatrix();


/*lateral*/
	//esquerda
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(-13,-10.75,-6);
		glRotatef(90,1,0,0);
		glRotatef(180,1,0,0);				
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointslateralesquerda[0][0][0]);
		glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22); 
	glPopMatrix();
	//direita
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(-13,10.75,-6);
		glRotatef(90,1,0,0);	
		glRotatef(180,0,1,0);				
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointslateraldireita[0][0][0]);
		glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22); 
	glPopMatrix();
	

/*lateralfrente*/
	//esquerda
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(15,-10,-6);
		glRotatef(-90,1,0,0);
		
	
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4,&ctrlpointslateralesquerdafrente[0][0][0]);
		glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22); 			
		   
	glPopMatrix();
	//direita

	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(15,10,-6);
		glRotatef(90,1,0,0);
		glRotatef(180,0,1,0);
		
	
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4,&ctrlpointslateraldireitafrente[0][0][0]);
		glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22); 			
		   
	glPopMatrix();


/*interno*/
	glPushMatrix();
		glColor3f(0.7, 0, 0);
		glTranslatef(11,0,-3.5);
		glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);	
		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsinterno1[0][0][0]);
		glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
		glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
	glPopMatrix();

	


}
void init(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glTranslated(0,0,-2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_MAP2_VERTEX_3);
}

void Display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glPushMatrix();
        glRotatef(eixox, 1 ,0 ,0);
        glRotatef(eixoy, 0 ,1 ,0);
        glRotatef(eixoz, 0 ,0 ,1);
        desenha_carro();	
    glPopMatrix();
    glutSwapBuffers();
}

/*---------------------------------Funcoes de iluminacao-------------------------------------*/
void initlight(void){

    GLfloat luzAmbiente[4]={0.5,0.5,0.5,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat posicaoLuz0[4]={0.0, 2,1, 0};
    GLfloat mat_ambiente[4] = {0.5,0.0,0.0,1.0};
    GLfloat mat_difusa[4] = {1.0,0.0,0.0,1.0};
  
    GLfloat posicaoLuz1[4]={-150.0, -20.0, -1.0, 1.0};
    GLfloat spot_direcao[3] = { -1.0, -1.0, 0.0 };



/* Capacidade de brilho do material */
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
    GLint especMaterial = 20;


/* Especifica que a cor de fundo da janela será preta */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

/* Ativa o uso da luz ambiente */
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

/* Define os parâmetros da luz de número 0 */
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz0 );

/* Define os parâmetros da luz de número 1 */
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz1);

/* define as propriedades do material */
    glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambiente);
    glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, mat_difusa);
/* Define a refletância do material */
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
/* Define a concentração do brilho */
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

/*spot*/
   // glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 2.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direcao);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	

/* Habilitacao */
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT1);


}
/*-------------------------------Funcoes de visualizacao--------------------------------------------*/

void Viewing(void)	{
	/* Especifica sistema de coordenadas de projeção */
	glMatrixMode(GL_PROJECTION);
	/* Inicializa sistema de coordenadas de projeção */
	glLoadIdentity();

	/* Especifica a projeção perspectiva */
	gluPerspective(angle,fAspect,0.1,500);

	/* Especifica sistema de coordenadas do modelo */
	glMatrixMode(GL_MODELVIEW);
	/* Inicializa sistema de coordenadas de projeção */
	glLoadIdentity();

	/* Especifica posição do observador e do alvo */
	gluLookAt(0,-40,-80, 0,0,0, 0,1,0);

	

}
/*-------------------------------------------------------------------------------------*/
void Reshape(GLsizei w, GLsizei h)	{
	/* Para previnir uma divisão por zero */
	if ( h == 0 )
		h = 1;

	/* Especifica o tamanho da viewport */
	glViewport(0, 0, w, h);

	/* Calcula a correção de aspecto */
	fAspect = (GLfloat)w/(GLfloat)h;

	Viewing();
}

/*---------------------------Funcoes de interacao--------------------------------------*/
void HandleMouse(int button, int state, int x, int y)	{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			if (angle <= 130)
				angle += 5;
		}
	Viewing();
	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 'x':
    eixox = (eixox + 5) % 360;
    glutPostRedisplay();
    break;
  case 'y':
    eixoy = (eixoy + 5) % 360;
    glutPostRedisplay();
    break;
  case 'z':
    eixoz = (eixoz + 5) % 360;
    glutPostRedisplay();
    break;
  case 'X':
    eixox = (eixox - 5) % 360;
    glutPostRedisplay();
    break;
  case 'Y':
    eixoy = (eixoy - 5) % 360;
    glutPostRedisplay();
    break;
  case 'Z':
    eixoz = (eixoz - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

/*-------------------------------------main--------------------------------------------*/
int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize (700, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Car");
   glutDisplayFunc(Display);
   glutReshapeFunc(Reshape);
   glutMouseFunc(HandleMouse);
   glutKeyboardFunc(keyboard);
   init();
   initlight();
   glutMainLoop();
   return 0;
}
