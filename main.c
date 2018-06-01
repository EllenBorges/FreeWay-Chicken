/*
Computação Gráfica - Projeto Final - main
Versão: 1.2
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_WINDOW_SIZE_W 800.0
#define DEFAULT_WINDOW_SIZE_H 800.0

GLfloat angle;
int width, heigth;
float s,s_Carro,s_Cenario;

float rX_Carro, rY_Carro, rZ_Carro;
float rX_Cenario, rY_Cenario, rZ_Cenario;

float tX_Carro,tY_Carro, tZ_Carro;
float tX_Cenario,tY_Cenario, tZ_Cenario;
float time;
GLfloat fAspect;



/*-------------------------------------------Variaveis de Inicializacao---------------------------------*/

void inicializar() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  time = 1.0;
  rX_Carro = 0.0;
  rY_Carro = 0.0;
  rZ_Carro = 0.0;
  tX_Carro = 0.0;
  tY_Carro = 0.0;
  tZ_Carro = 0.0;
  
  rX_Cenario = 0.0;
  rY_Cenario = 0.0;
  rZ_Cenario = 0.0;
  tX_Cenario = 0.0;
  tY_Cenario = 0.0;
  tZ_Cenario = 0.0;
  
  s_Carro = 1.0;
  s_Cenario = 1.0;
  s = 1.0;
  angle = 45;
  glMatrixMode(GL_PROJECTION);
  //glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_MAP2_VERTEX_3);
}

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

/*------------------------------------------Funcoes auxiliares------------------------------------------*/


void corCorrente(GLfloat r, GLfloat g, GLfloat b){
	glColor3f(r, g, b);
}

/*-------------------------------------------Iluminacao-------------------------------------------------*/

void SetupRC(void) {
    GLfloat luzAmbiente[4]={0.5, 0.5, 0.5, 1.0};
    GLfloat luzDifusa[4]={0.5, 0.7, 0.7, 1.0};
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
    GLfloat posicaoLuz[4]={500.0, -50.0, 50.0, 0.0};
    GLfloat posicaoLuz2[4]={0.0, -5000.0, 0.0, 0.0};
    GLfloat light1_Direcao [4] = {0.0, 0.0, -1.0, 1.0};
    GLfloat objeto_ambiente[4] = {0.5, 0.0, 0.0, 1.0};
    GLfloat objeto_difusa[4] = {1.0, 0.0, 0.0, 1.0};

	/* Capacidade de brilho do material */
    GLfloat especularidade[4]={1.0, 1.0, 1.0, 1.0};
    GLint especMaterial = 20;

/* Especifica que a cor de fundo da janela será branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

/* Ativa o uso da luz ambiente */
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

/* Define os parâmetros da luz de número 0 */
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

/*glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light1_Direcao);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.0);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 8.0);*/


/* define as propriedades do material */
    glMaterialfv (GL_FRONT_AND_BACK, GL_AMBIENT, objeto_ambiente);
    glMaterialfv (GL_FRONT_AND_BACK, GL_DIFFUSE, objeto_difusa);
/* Define a refletância do material */
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
/* Define a concentração do brilho */
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

/* Habilita a definição da cor do material a partir da cor corrente */
    glEnable(GL_COLOR_MATERIAL);
/* Habilita o uso de iluminação*/
    glEnable(GL_LIGHTING);
/* Habilita a luz de número 0 */
    glEnable(GL_LIGHT0);
/* Habilita o depth-buffering */
    glEnable(GL_DEPTH_TEST);
/*glShadeModel(GL_FLAT);*/

}

/*-------------------------------------------Visualizacao-------------------------------------------------*/


/* Função usada para especificar o volume de visualização */
void Viewing(void)	{
	/* Especifica sistema de coordenadas de projeção */
	glMatrixMode(GL_PROJECTION);
	/* Inicializa sistema de coordenadas de projeção */
	glLoadIdentity();

	/* Especifica a projeção perspectiva */
	gluPerspective(angle, fAspect, 0.1, 1000);

	/* Especifica sistema de coordenadas do modelo */
	glMatrixMode(GL_MODELVIEW);
	/* Inicializa sistema de coordenadas de projeção */
	glLoadIdentity();

	/* Especifica posição do observador e do alvo */
	gluLookAt(-300, 300, 0, 0, 0, 0, 0, 1, 0);
}


/*-------------------------------------------Redimensionamento--------------------------------------------*/


/* Chamada pela GLUT quando a janela é redimensionada */
void ChangeSize(GLsizei w, GLsizei h){
	/* Para previnir uma divisão por zero */
	if(h == 0) h = 1;

	if(w <= h){
		heigth = 80.0 * h / w;
		width = 80.0;
	}
	if(h <= w){
		width = 80.0 * w / h;
		heigth = 80.0;
	}

	/* Especifica o tamanho da viewport */
	glViewport(0, 0, w, h);

	/* Calcula a correção de aspecto */
	fAspect = (GLfloat)w / (GLfloat)h;

	Viewing();
}

/*-------------------------------------------Funçoes de Desenho--------------------------------------------*/


void carro(GLfloat r, GLfloat g, GLfloat b){

	glPushMatrix();
		glTranslatef(0.0,5.0,0.0);
		//rodas
		glPushMatrix();
			glPushMatrix();
				glColor4f(0.0, 0.0, 0,0.5);
				glTranslatef(12.0,0.0,12.0);
				glutSolidTorus(2.0,3.5,50.0,50.0);
				corCorrente(0.5, 0.5, 0.5);
				glutSolidSphere(2.0, 100.0, 20.0);
			 glPopMatrix();

			glPushMatrix();
				glColor4f(0.0, 0.0, 0.0,0.5);
				glTranslatef(-12.0,0.0,12.0);
				glutSolidTorus(2.0,3.5,50.0,50.0);
				corCorrente(0.5, 0.5, 0.5);
				glutSolidSphere(2.0, 100.0, 20);
			 glPopMatrix();

			glPushMatrix();
				glColor4f(0.0, 0.0, 0,0.5);
				glTranslatef(-12.0,0.0,-12.0);
				glutSolidTorus(2.0,3.5,50.0,50.0);
				corCorrente(0.5, 0.5, 0.5);
				glutSolidSphere(2.0, 100.0, 20);
			 glPopMatrix();

			glPushMatrix();
				glColor4f(0.0, 0.0, 0,0.5);
				glTranslatef(12.0,0.0,-12.0);
				glutSolidTorus(2.0,3.5,50.0,50.0);
				corCorrente(0.5, 0.5, 0.5);
				glutSolidSphere(2.0, 100.0, 20);
			 glPopMatrix();
		glPopMatrix();


		glPushMatrix();
		glRotatef(90,1,0,0);
		//base

			glPushMatrix();
				corCorrente(0.5,0.5,0.6);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsbase[0][0][0]);
				glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
				glTranslatef(0,0,-0.5);
				corCorrente(0.2, 0.2, 0.2);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsbase[0][0][0]);
				glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

		//capo dianteiro
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(18,0,-5);
				glRotatef(-22,0,1,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscapodianteiro[0][0][0]);
				glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

		//capo traseiras
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(-22.5,0,-3.5);
				glRotatef(52,0,1,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointscapotraseiro[0][0][0]);
				glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

		//teto
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(-5,0,-14);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsteto[0][0][0]);
				glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

		//porta
			//porta do passageiro
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(1,10,-3.3);
				glRotatef(90,1,0,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsporta[0][0][0]);
				glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

				//porta do motorista
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(-1,-10,-3.3);
				glRotatef(90,1,0,0);
				glRotatef(180,0,1,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsporta[0][0][0]);
				glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

		//volante
			glPushMatrix();
				glColor4f(0.0, 0.0, 0,0.5);
				glTranslatef(7,-5,-7);
				glRotatef(75,0,1,0);
				glutSolidTorus(0.2,2.5,50,50);
			glPopMatrix();

		//lateral
			//esquerda
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(-13,-10.75,-6);
				glRotatef(90,1,0,0);
				glRotatef(180,1,0,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointslateralesquerda[0][0][0]);
				glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();
			//direita
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(-13,10.75,-6);
				glRotatef(90,1,0,0);
				glRotatef(180,0,1,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointslateraldireita[0][0][0]);
				glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

		//lateralfrente
			//esquerda
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(15,-10,-6);
				glRotatef(-90,1,0,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4,&ctrlpointslateralesquerdafrente[0][0][0]);
				glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

			//direita
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(15,10,-6);
				glRotatef(90,1,0,0);
				glRotatef(180,0,1,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4,&ctrlpointslateraldireitafrente[0][0][0]);
				glMapGrid2f(22, .0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);

			glPopMatrix();

			//interno
			glPushMatrix();
				corCorrente(r, g, b);
				glTranslatef(11,0,-3.5);
				glRotatef(90,1,0,0);
				glRotatef(90,0,1,0);
				glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4, 0.0, 1.0, 12, 4, &ctrlpointsinterno1[0][0][0]);
				glMapGrid2f(22, 0.0, 1.0, 22, 0.0, 1.0);
				glEvalMesh2(GL_FILL, 0.0, 22, 0.0, 22);
			glPopMatrix();

		glPopMatrix();
		//farois
		//esquerdo
		glPushMatrix();
			corCorrente(1.0,1.0,0.5);
			glTranslatef(22,2.5,-8);
			glutSolidSphere(2.0, 100.0, 20.0);
		glPopMatrix();
		//direito
		glPushMatrix();
			corCorrente(1.0,1.0,0.5);
			glTranslatef(22,2.5,8);
			glutSolidSphere(2.0, 100.0, 20.0);
		glPopMatrix();

	glPopMatrix();

}

void pista(){
     glColor3f(0.3,0.3,0.3);
     glBegin(GL_POLYGON);
        glVertex3f(300.0,0.0,-200.0);
        glVertex3f(300,0.0,200);
        glVertex3f(-300,0.0,200);
        glVertex3f(-300,0.0,-200);
     glEnd();
}

void desenha_Cenario(){

	glPushMatrix();
		corCorrente(1.0,0.0,0.0);
		pista();
	glPopMatrix();
	glutPostRedisplay();
}

void desenha_Carros(){

	glPushMatrix();
		corCorrente(1.0,0.0,0.0);
		//desenha_carro(0.7,0.0,0.0);//vermelho
		carro(0.0,0.7,0.0);//verde
		//desenha_carro(0.0,0.0,0.7);//azul
	glPopMatrix();
	glutPostRedisplay();
}
/*-------------------------------------------Animacao----------------------------------------------------*/

void animacao(){
	//implementar aqui incrementos nas flags
	glutPostRedisplay();
}
void timer(int i){
	glutPostRedisplay();
	glutTimerFunc(time, timer, 1);
}

/*---------------------------------------Funcoes de Interacao--------------------------------------------*/


void SpecialKeyboard(int key, int x, int y){

	switch(key){
	case GLUT_KEY_LEFT:
	    if (tZ_Carro > -200) tZ_Carro-=5;
		break;

	case GLUT_KEY_UP:
	    if (tX_Carro < 300) tX_Carro+=5;
		break;

	case GLUT_KEY_RIGHT:
	    if (tZ_Carro < 200) tZ_Carro+=5;
		break;

	case GLUT_KEY_DOWN:
	    if (tX_Carro > -300) tX_Carro-=5;
		break;

	case GLUT_KEY_F1:
		tX_Cenario+=5;
		break;

	case GLUT_KEY_F2:
		tX_Cenario-=5;
		break;
	case GLUT_KEY_F3:
		tY_Cenario+=5;
		break;

	case GLUT_KEY_F4:
		tY_Cenario-=5;
		break;
		
	case GLUT_KEY_F5:
		tZ_Cenario+=5;
		break;

	case GLUT_KEY_F6:
		tZ_Cenario-=5;
		break;

	default:
		break;

	}

}
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'x':
			rX_Carro += 5;
			break;

		case 'X':
			rX_Carro -= 5;
			break;
		case 'y':
			rY_Carro += 5;
			break;
		case 'Y':
			rY_Carro -= 5;
			break;
		case 'z':
			rZ_Carro += 5;
			break;
		case 'Z':
			rZ_Carro -= 5;
			break;
		case '+':
			if(s<4.0)
				s += 0.5;
			break;
		case '-':
			if(s>0.5)
				s -= 0.5;
			break;
		case 27:
			exit(0);
			break;
    	default:
			break;
	}
}

/*-------------------------------------------Display----------------------------------------------------*/

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	glPushMatrix();
	
		glScalef(s,s,s);//zoom in out

		glPushMatrix();
			glTranslatef(tX_Cenario, 0.0, 0.0);
			glTranslatef(0.0, tY_Cenario, 0.0);
			glTranslatef(0.0, 0.0, tZ_Cenario);
			glScalef(s_Cenario,s_Cenario,s_Cenario);
			glRotatef(rX_Cenario, 1.0, 0.0, 0.0);
			glRotatef(rY_Cenario, 0.0, 1.0, 0.0);
			glRotatef(rZ_Cenario, 0.0, 0.0, 1.0);
			desenha_Cenario();
		glPopMatrix();

		glPushMatrix();   
			glTranslatef(tX_Carro, 0.0, 0.0);
			glTranslatef(0.0, tY_Carro, 0.0);
			glTranslatef(0.0, 0.0, tZ_Carro);
			glScalef(s_Carro,s_Carro,s_Carro);
			glRotatef(rX_Carro, 1.0, 0.0, 0.0);
			glRotatef(rY_Carro, 0.0, 1.0, 0.0);
			glRotatef(rZ_Carro, 0.0, 0.0, 1.0);
			desenha_Carros();
		glPopMatrix();
	
	glPopMatrix();

	glutSwapBuffers();
}
/*-----------------------------------------------Main-------------------------------------------------*/

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(DEFAULT_WINDOW_SIZE_W, DEFAULT_WINDOW_SIZE_H);
	glutCreateWindow("SpeedWay 3D");
	inicializar();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutDisplayFunc(display);
	//glutIdleFunc(animacao);
	//glutTimerFunc(time, timer, 1);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();

  return 0;
}
