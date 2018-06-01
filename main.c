/*
Computação Gráfica - Projeto Final - main
Versão: 1.0
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_WINDOW_SIZE_W 800.0
#define DEFAULT_WINDOW_SIZE_H 800.0

GLfloat angle = 45;
int width, heigth;
float rX, rY, rZ, tX, tY, tZ, s;
float time;
GLfloat fAspect;
double tempo = 1.0;

void inicializar() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  time = 1.0;
  rX = 0.0;
  rY = 0.0;
  rZ = 0.0;
  tX = 0.0;
  tY = 0.0;
  tZ = 0.0;
  s = 1.0;
}

void corCorrente(GLfloat r, GLfloat g, GLfloat b){
	glColor3f(r, g, b);
}


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


/* Especifica que a cor de fundo da janela será preta */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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
	gluLookAt(0, 20, 200, 0, 0, 0, 0, 1, 0);
}


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

void pontocentral(){

	glPushMatrix();
		corCorrente(1.0,0.0,0.0);		
		glutSolidTeapot(5.0);
	glPopMatrix();	
	glutPostRedisplay();

		
}

	
void animacao(){
	

	glutPostRedisplay();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glPushMatrix();
		glTranslatef(tX, 1.0, 0.0);
	  	glTranslatef(0.0, tY, 0.0);
	 	glScalef(s,s,s);
		glRotatef(rX, 1.0, 0.0, 0.0);
	  	glRotatef(rY, 0.0, 1.0, 0.0);
	  	glRotatef(rZ, 0.0, 0.0, 1.0);
	  	pontocentral();
		
	glPopMatrix();
	
	glutSwapBuffers();
}

void timer(int i){
	glutPostRedisplay();
	glutTimerFunc(time, timer, 1);
}
void SpecialKeyboard(int key, int x, int y){
	
	switch(key){
	case GLUT_KEY_LEFT:
		tX-=5;
		break;
	
	case GLUT_KEY_UP:
		tY+=5;	
		break;

	case GLUT_KEY_RIGHT:
		tX+=5;
		break;

	case GLUT_KEY_DOWN:
		tY-=5;
		break;
			
	default:
		break;
			
	}
	
}
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'x': 
			rX += 5; 
			break;
			
		case 'X': 
			rX -= 5; 
			break;
		case 'y': 
			rY += 5; 
			break;
		case 'Y': 
			rY -= 5; 
			break;
		case 'z': 
			rZ += 5; 
			break;
		case 'Z': 
			rZ -= 5; 
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

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(DEFAULT_WINDOW_SIZE_W, DEFAULT_WINDOW_SIZE_H);
	glutCreateWindow("Projeto");
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