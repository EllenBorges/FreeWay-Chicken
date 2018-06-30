/*
Computacao Grafica - Projeto Final - main
Ellen Priscila Borges Oliveira
Versao: 1.9
*/

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
//#include "loadTexture.h"
#define DEFAULT_WINDOW_SIZE_W 1500.0
#define DEFAULT_WINDOW_SIZE_H 1000.0
#define MADEIRA 3
#define MATO 2
#define PISTA 1

GLfloat angle;
int width, heigth;
float s, s_Carro,xView,yView;
float rX_Carro, rY_Carro, rZ_Carro, rZ_rodas;
float tX_Carro,tY_Carro, tZ_Carro;
float tX_CarroVerde, tZ_CarroVerde,tX_CarroAzul,tZ_CarroAzul,tX_CarroCinza,tZ_CarroCinza;
float time, ComprimentoPista,LarguraPista,LarguraMato, PontoInicialX, InicioArvore;

//camera
float PosicaoCameraX, PosicaoCameraY, PosicaoCameraZ, PRefX,PRefY, PRefZ, Vx, Vy, Vz; 
GLfloat fAspect;
int modoCamera;

//jogabilidade

int start;
int pause;
float quantidadeArvore;
float quantidadeCarros;

//textura

typedef struct BMPImagem
{   
	int   width;
    int   height;
    char *data;
}BMPImage;
GLuint texture_id[30];
/*-------------------------------------------Variaveis de Inicializacao---------------------------------*/

void inicializar() {

  glClearColor(0.3f, 0.8f, 1.0f, 1.0f);
  time = 1.0;
  LarguraPista = 1;
  ComprimentoPista = 1000;
  LarguraMato = 400;
  InicioArvore = 1.9;
  PontoInicialX = 10-ComprimentoPista;
  PosicaoCameraX = 11-ComprimentoPista;
  PosicaoCameraY = 5;
  PosicaoCameraZ = 0;
  PRefX = 11 - ComprimentoPista;
  PRefY = 0;
  PRefZ = 0;
  Vx = 1;
  Vy = 0;
  Vz = 0;	
  xView = 0;
  yView = 0;
  rX_Carro = 0.0;
  rY_Carro = 0.0;
  rZ_Carro = 0.0;
  tX_Carro = PontoInicialX;
  tY_Carro = 0.0;
  tZ_Carro = 0.0;

  tX_CarroVerde = PontoInicialX;
  tZ_CarroVerde = 0;
  tX_CarroAzul = PontoInicialX-15;
  tZ_CarroAzul =  0.8;
  tX_CarroCinza = PontoInicialX;
  tZ_CarroCinza = -0.8; 
  s_Carro = 1.0;
  s = 1.0;
  angle = 45;
  start = 0;
  pause  = 0;
  modoCamera = 1; //default vista superior
  glMatrixMode(GL_PROJECTION);
  glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  glEnable(GL_MAP2_VERTEX_3);
  quantidadeArvore = 200;
  quantidadeCarros = 15;

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

/* Especifica que a cor de fundo da janela serÃ¡ azul clara */
	glClearColor(0.3f, 0.8f, 1.0f, 1.0f);
/* Ativa o uso da luz ambiente */
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

/* Define os parâmetros da luz de número 0 */
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

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
void Camera()
{
		//ponto inicial da camera
	gluLookAt(PosicaoCameraX, PosicaoCameraY, PosicaoCameraZ, PRefX, PRefY, PRefZ, Vx, Vy, Vz);
}

/* Função usada para especificar o volume de visualização */
void Viewing(void)	{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	/* Especifica posiÃ§Ã£o do observador e do alvo */
	
    Camera();
	
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
	glViewport(xView, yView, w, h);

	/* Calcula a correção de aspecto */
	fAspect = (GLfloat)w / (GLfloat)h;
	Viewing();

}
/*-------------------------------------------Funçoes de Textura--------------------------------------------*/

void getBitmapImageData( char *pFileName, BMPImage *pImage )
{
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
	int i;

    if( (pFile = fopen(pFileName, "rb") ) == NULL )
		printf("ERROR: getBitmapImageData - %s not found.\n", pFileName);

    // Seek forward to width and height info
    fseek( pFile, 18, SEEK_CUR );

    if( (i = fread(&pImage->width, 4, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read width from %s.\n ", pFileName);

    if( (i = fread(&pImage->height, 4, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read height from %s.\n ", pFileName);

    if( (fread(&nNumPlanes, 2, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read plane count from %s.\n", pFileName);

    if( nNumPlanes != 1 )
		printf("ERROR: getBitmapImageData - Plane count from %s.\n ", pFileName);

    if( (i = fread(&nNumBPP, 2, 1, pFile)) != 1 )
		printf( "ERROR: getBitmapImageData - Couldn't read BPP from %s.\n ", pFileName);

    if( nNumBPP != 24 )
		printf("ERROR: getBitmapImageData - BPP from %s.\n ", pFileName);

    // Seek forward to image data
    fseek( pFile, 24, SEEK_CUR );

	// Calculate the image's total size in bytes. Note how we multiply the
	// result of (width * height) by 3. This is becuase a 24 bit color BMP
	// file will give you 3 bytes per pixel.
    int nTotalImagesize = (pImage->width * pImage->height) * 3;

    pImage->data = (char*) malloc( nTotalImagesize );

    if( (i = fread(pImage->data, nTotalImagesize, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read image data from %s.\n ", pFileName);

    //
	// Finally, rearrange BGR to RGB
	//

	char charTemp;
    for( i = 0; i < nTotalImagesize; i += 3 )
	{
		charTemp = pImage->data[i];
		pImage->data[i] = pImage->data[i+2];
		pImage->data[i+2] = charTemp;
    }
}

void Texture1(){
	/* textura */
	BMPImage imagemTextura,imagemTexturaPista ;
    getBitmapImageData("asfalto2.bmp", &imagemTextura);
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &texture_id[0]);
    glBindTexture(GL_TEXTURE_2D, texture_id[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imagemTextura.width,imagemTextura.height, 0, GL_RGB, GL_UNSIGNED_BYTE,imagemTextura.data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//ampliacao de acordo com a media dos pontos
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //reducao de acordo com a media dos pontos
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //repeticao na horizontal
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //repeticao na vertical
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

}
void carregaTextura(char *nome, int i)
{
    BMPImage imagemTextura;

    texture_id[i]=i;
    glBindTexture(GL_TEXTURE_2D, texture_id[i]);
    getBitmapImageData(nome, &imagemTextura);
    gluBuild2DMipmaps (GL_TEXTURE_2D, 3, imagemTextura.width, imagemTextura.height, GL_RGB,GL_UNSIGNED_BYTE, imagemTextura.data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);

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
				glRotatef(rZ_rodas,0,0,1);
				glutSolidTorus(2.0,3.5,50.0,50.0);
				corCorrente(0.5, 0.5, 0.5);
				glutSolidSphere(2.0, 100.0, 20.0);
			 glPopMatrix();

			glPushMatrix();
				glColor4f(0.0, 0.0, 0.0,0.5);
				glTranslatef(-12.0,0.0,12.0);
				glRotatef(rZ_rodas,0,0,1);
				glutSolidTorus(2.0,3.5,50.0,50.0);
				corCorrente(0.5, 0.5, 0.5);
				glutSolidSphere(2.0, 100.0, 20);
			 glPopMatrix();
			
			glPushMatrix();
				glColor4f(0.0, 0.0, 0,0.5);
				glTranslatef(-12.0,0.0,-12.0);
				glRotatef(rZ_rodas,0,0,1);
				glutSolidTorus(2.0,3.5,50.0,50.0);
				corCorrente(0.5, 0.5, 0.5);
				glutSolidSphere(2.0, 100.0, 20);
				
			 glPopMatrix();

			glPushMatrix();
				glColor4f(0.0, 0.0, 0,0.5);
				glTranslatef(12.0,0.0,-12.0);
				glRotatef(rZ_rodas,0,0,1);
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
				corCorrente(0.0, 0.0, 0.0);
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

void arvore(GLfloat x, GLfloat z){
    GLfloat arvoreX = x;
    GLfloat arvoreZ = z;
    //arvore
        glPushMatrix();
             glTranslatef(arvoreX,0,arvoreZ);
             glScaled(0.05,0.05,0.05);
            //tronco       
            corCorrente(1,1,1);
			glEnable(GL_TEXTURE_2D);
	 		glBindTexture(GL_TEXTURE_2D, texture_id[MADEIRA]);
            glPushMatrix();
                 glTranslatef(0,2,0);
                 glRotatef(90,0.5,0,0);
                 GLUquadric* qobj = gluNewQuadric();
                   gluQuadricNormals(qobj, GLU_SMOOTH);
                 gluCylinder(qobj,0.5, 1.5, 5,50, 10);
            glPopMatrix();
			glDisable(GL_TEXTURE_2D); 
            //folhas   
			corCorrente(0.0,0.3,0.0);
            glPushMatrix();
                glTranslatef(0,2,0);
                glRotatef(-90,1,0,0);
                glutSolidCone(2, 5,50, 10);
                glTranslatef(0,0,1);
                glutSolidCone(2, 5,50, 10);
                glTranslatef(0,0,1);
                glutSolidCone(2, 5,50, 10);
            glPopMatrix();
        glPopMatrix();
    glutPostRedisplay();
}

void mato(){
	 //corCorrente(0.0,0.1,0.0);
	 glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D, texture_id[MATO]);
	 glPushMatrix();
		 //esquerda
		 glBegin(GL_POLYGON);
			glVertex3f(ComprimentoPista,0.0,-LarguraMato);
			glVertex3f(ComprimentoPista,0.0,-LarguraPista);
			glVertex3f(-ComprimentoPista,0.0,-LarguraPista);
			glVertex3f(-ComprimentoPista,0.0,-LarguraMato);
		 glEnd();

		 //direita
		 glBegin(GL_POLYGON);
			glVertex3f(-ComprimentoPista,0.0,LarguraMato);
			glVertex3f(-ComprimentoPista,0.0,LarguraPista);
			glVertex3f(ComprimentoPista,0.0,LarguraPista);
			glVertex3f(ComprimentoPista,0.0,LarguraMato);
		 glEnd();
	glPopMatrix();
    glDisable(GL_TEXTURE_2D); 
}


void pista(){
	
     corCorrente(1.0,1.0,1.0);
	 glEnable(GL_TEXTURE_2D);
	 glBindTexture(GL_TEXTURE_2D, texture_id[PISTA]);
     glBegin(GL_POLYGON);
        glVertex3f(ComprimentoPista,0.0,-LarguraPista);
        glVertex3f(ComprimentoPista,0.0,LarguraPista);
        glVertex3f(-ComprimentoPista,0.0,LarguraPista);
        glVertex3f(-ComprimentoPista,0.0,-LarguraPista);
     glEnd();
	 glDisable(GL_TEXTURE_2D); 
	
}
void desenha_Carro(){

	glPushMatrix();	  
	   glScaled(0.01,0.01,0.01);
	   carro(0.7,0.0,0.0);//vermelho
	glPopMatrix();
	glutPostRedisplay();
}

void desenha_Carros(float tX,GLfloat r, GLfloat g, GLfloat b){
	int i,x1;
	
	glPushMatrix();
		glScaled(0.01,0.01,0.01);
		for(i=0; i<quantidadeCarros; i++){
			 glTranslatef(tX, 0.0, 0.0);
			 carro(r,g,b);			 
		}
	glPopMatrix();
	glutPostRedisplay();
}


void desenha_Cenario(){
	int i, x1,x2, x3, z, xCarros;
	mato();
	pista();
	
	glPushMatrix();
		x1 = 0;
		x2 = 2;
		x3 = 3;
		//xCarros = tX_Carros;
		z = -InicioArvore;
		// Floresta Lado Esquerdo
		for(i=0; i<quantidadeArvore; i++){		
			arvore(x1,z);
			arvore(x2,z+2);
			arvore(x3,z+3);
			arvore(x2,z+4);
			arvore(x1,z+6);	
			arvore(x3,z+8);
			arvore(x1,z+10);
			arvore(x2,z+12);		
			x1 = x1-5;
			x2 = x2-5;
			x3 = x3-5;
		}
		x1 = 0;
		x2 = 2;
	    x3 = 3;
		z = InicioArvore; 
		// Floresta Lado Direito
		for(i=0; i<quantidadeArvore; i++){	
			arvore(x1,z);
			arvore(x2,z-2);
			arvore(x3,z-3);
			arvore(x2,z-4);
			arvore(x1,z-6);		
			arvore(x3,z-8);
			arvore(x1,z-10);
			arvore(x2,z-12);		
			x1 = x1-5;
			x2 = x2-5;
			x3 = x3-5;		
		}	

	glPopMatrix();
	glutPostRedisplay();
}




/*---------------------------------------Funcoes de Interacao--------------------------------------------*/

void setCameraLateral(){
			if(modoCamera!=4){
				modoCamera = 4;
				PosicaoCameraX = tX_Carro;
				PRefX = tX_Carro;
				PosicaoCameraY = 0.009;
				PRefY = 0.4;
				PosicaoCameraZ = -1;
				PRefZ = 0;
				Vx = 0;
				Vy = 0;
				Vz = -1;
				Viewing();
				glutPostRedisplay();
			}	
}

void setCameraFrontal(){
	if(modoCamera!=3){
				modoCamera = 3;
				PosicaoCameraX = tX_Carro+10;
				PRefX=tX_Carro;
				PosicaoCameraY = 5;
				PRefY = 0;
				PosicaoCameraZ = 0;
				PRefZ = 0;
				Vx = -1;
				Vy = 0;
				Vz = 0;		
				Viewing();
				glutPostRedisplay();
	}
}
void setCameraTraseira(){
	if(modoCamera!=2){
				modoCamera = 2;
				PosicaoCameraX = tX_Carro-10;
				PRefX=tX_Carro;
				PosicaoCameraY = 5;
				PRefY = 0;
				PosicaoCameraZ = 0;
				PRefZ = 0;
				Vx = 1;
				Vy = 0;
				Vz = 0;		
				Viewing();
				glutPostRedisplay();
	}
}
void setCameraSuperior(){
		if(modoCamera!=1){
				modoCamera = 1;
				PosicaoCameraX = tX_Carro+1;
				PRefX = tX_Carro +1;
				PosicaoCameraY = 5;
				PRefY = 0;
				PosicaoCameraZ = 0;
				PRefZ = 0;
				Vx = 1;
				Vy = 0;
				Vz = 0;		
				Viewing();
				glutPostRedisplay();
		}
}

void SpecialKeyboard(int key, int x, int y){

	switch(key){
	case GLUT_KEY_LEFT:
	    if (tZ_Carro > -LarguraPista+0.4) tZ_Carro-=0.1;
		break;

	case GLUT_KEY_UP:
	    if (tX_Carro < ComprimentoPista) 
		{
			start = 1;
			pause = 0;
			tX_Carro+=0.2;
			
		}
		break;

	case GLUT_KEY_RIGHT:
	    if (tZ_Carro < LarguraPista-0.4) tZ_Carro+=0.1;
		break;

	case GLUT_KEY_DOWN:
	    if (tX_Carro > -ComprimentoPista) 
		{
			tX_Carro-=0.2;
			
		}
		break;
	default:
		break;

	}
	

}
void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'x':
			rX_Carro += 0.5;
			break;
		case 'X':
			rX_Carro -= 0.5;
			break;
		case 'y':
			rY_Carro += 0.5;
			break;
		case 'Y':
			rY_Carro -= 0.5;
			break;
		case 'z':
			rZ_Carro += 0.5;
			break;
		case 'Z':
			rZ_Carro -= 0.5;
			break;
		case '+':
			//implementar aqui zoomin para as quatro perspectivas
			break;
		case '-':		
			//implementar aqui zoomout para as quatro perspectivas
			break;
		case 'l':
		case 'L':
			setCameraLateral();
			break;
		case 'f':
		case 'F':
			setCameraFrontal();
			break;
		case 't':
		case 'T':
			setCameraTraseira();
			break;
		case 's':
		case 'S':
			setCameraSuperior();
			break;
		case 8:
			pause = 1;
			break;
		case 27:
    		exit(0);
    		break;
		default:
   			break;
	}
}

void ProcessMenu(int value)
{ 
    switch(value)
        {
        case 1:
            exit(0);
            break;
		case 2:
			pause = 1;
			break;
		case 3:
			pause = 0;
			start = 1;
			break;	
		case 4:
			setCameraLateral();
			break;
		case 5:
			setCameraFrontal();
			break;
		case 6:
			setCameraTraseira();
			break;
		case 7:
			setCameraSuperior();
			break;
        }

    glutPostRedisplay();  

}
void  menu(){
		
	glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("Finalizar",1);
	glutAddMenuEntry("Pausar",2);
	glutAddMenuEntry("Iniciar",3);
	glutAddMenuEntry("Camera Lateral",4);
	glutAddMenuEntry("Camera Frontal",5);
	glutAddMenuEntry("Camera Traseira",6);
	glutAddMenuEntry("Camera Superior",7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutPostRedisplay();
}
/*-------------------------------------------Animacao----------------------------------------------------*/

void animacao(){

	if(start==1 && pause==0){
			//velocidade constante
			tX_Carro+=0.7;
			PosicaoCameraX+=0.7;
			PRefX+=0.7;
			rZ_rodas+=0.7;
		    tX_CarroVerde+=0.02;
			tX_CarroAzul+=0.1;
		    tX_CarroCinza+=0.02;
			Viewing();
			glutPostRedisplay();
	}
}
void timer(int i){
	glutPostRedisplay();
	glutTimerFunc(time, timer, 1);
}
/*-------------------------------------------Display----------------------------------------------------*/

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
 
	glPushMatrix();
		glPushMatrix();
			desenha_Cenario();
		glPopMatrix();
	
		glPushMatrix();
	        glTranslatef(tX_CarroVerde, 0.0, 0.0);
			glTranslatef(0.0, 0.0, tZ_CarroVerde);
			glRotatef(180, 0.0, 1.0, 0.0);
			desenha_Carros(tX_CarroVerde,0,0.7,0);
		glPopMatrix();
	 	
		glPushMatrix();
	        glTranslatef(tX_CarroAzul, 0.0, 0.0);
	        glTranslatef(0.0, 0.0, tZ_CarroAzul);
			glRotatef(180, 0.0, 1.0, 0.0);
			desenha_Carros(tX_CarroAzul,0,0.0,0.7);
		glPopMatrix();
	
		glPushMatrix();
	        glTranslatef(tX_CarroCinza, 0.0, 0.0);
	        glTranslatef(0.0, 0.0, tZ_CarroCinza);
			glRotatef(180, 0.0, 1.0, 0.0);
			desenha_Carros(tX_CarroCinza,0.5,0.5,0.5);
		glPopMatrix();
	
		glPushMatrix();
			glTranslatef(tX_Carro, 0.0, 0.0);
			glTranslatef(0.0, tY_Carro, 0.0);
			glTranslatef(0.0, 0.0, tZ_Carro);
			glScalef(s_Carro,s_Carro,s_Carro);
			glRotatef(rX_Carro, 1.0, 0.0, 0.0);
			glRotatef(rY_Carro, 0.0, 1.0, 0.0);
			glRotatef(rZ_Carro, 0.0, 0.0, 1.0);
			desenha_Carro();
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
	SetupRC();
	carregaTextura("asfalto.bmp", PISTA);
	carregaTextura("mato.bmp", MATO);
	carregaTextura("madeira.bmp", MADEIRA);
	glutDisplayFunc(display);
	glutReshapeFunc(ChangeSize);	
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(SpecialKeyboard);
	glutIdleFunc(animacao);
	glutTimerFunc(time, timer, 1);
	menu();

	glutMainLoop();

  return 0;
}

