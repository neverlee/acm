Charles Petzold �ġ� Programming Windows ����
����    Win32 �� OpenGL �����Ҫ�Ĳ�������
ȫ��Դ������ҵķ��� Google Code �ϵ� blog-sample-code �� 2009-9-27\Win32OpenGLTemplate Ŀ¼��ȡ�ط�ʽ����������˵����

// GLOBALS ////////////////////////////////////////////////
HWND ghWnd ; // ���ھ��
HINSTANCE ghInstance ; // ����ʵ�����
HDC ghDC ;             // GDI �豸�������
HGLRC ghRC ;           // ��Ⱦ�������

1.       ͷ�ļ�

#include <windows.h>
// OpenGL ��Ҫ��ͷ�ļ�
#include <GL/gl.h>
#include <GL/glu.h>
#pragma comment ( lib , "opengl32.lib" )
#pragma comment ( lib , "glu32.lib" ) 

 

3. ���ظ�ʽ (Pixel Format) ����

��Ҫ�õ��ĺ�����ԭ�ͣ�

int ChoosePixelFormat(HDC hdc, CONST PIXELFORMATDESCRIPTOR *ppfd);
BOOL SetPixelFormat(HDC hdc, int iPixelFormat, CONST PIXELFORMATDESCRIPTOR *ppfd);
	// �������ظ�ʽ
	PIXELFORMATDESCRIPTOR pfd;
	int iFormat;
	ghDC = GetDC(ghWnd);
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof ( pfd ); 
	pfd.nVersion = 1;      // �汾��һ����Ϊ
	pfd.dwFlags =   PFD_DRAW_TO_WINDOW | // һ��������ػ������Եı�־λ
	PFD_SUPPORT_OPENGL ;
	pfd.iPixelType = PFD_TYPE_RGBA ;   // ����������������RGBA ������ɫ����;
	pfd.cColorBits = 32; // ÿ����ɫ����������ɫλƽ�����Ŀ������ɫ������ʽ�ǻ�������С
	pfd.iLayerType = PFD_MAIN_PLANE ; // �����ԣ�Ϊ��һ���Զ�������
	iFormat = ChoosePixelFormat ( ghDC , & pfd ); // ѡ��һ�����ظ�ʽ
	SetPixelFormat(ghDC, iFormat, &pfd); // ���õ�DC ��
 
//����˫�ػ������Ĵ��롣
PIXELFORMATDESCRIPTOR pfd;
ZeroMemory( &pfd, sizeof( pfd ) );
pfd.nSize = sizeof( pfd );
pfd.nVersion = 1;
pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
              PFD_DOUBLEBUFFER;
pfd.iPixelType = PFD_TYPE_RGBA;
pfd.cColorBits = 32;
pfd.cDepthBits = 32;
pfd.iLayerType = PFD_MAIN_PLANE;
int iFormat = ChoosePixelFormat( hDC, &pfd );
SetPixelFormat( hDC, iFormat, &pfd );
 
4.       ��Ⱦ������ (Render Context) ����

���� wglCreateContext �� wglMakeCurrent ���� ���������������� Windows ��Ϊ�˼��� OpenGL ���ر��ṩ�Ľӿڣ��� wgl ��ͷ��

����ԭ�ͣ�

HGLRC wglCreateContext(HDC hdc);
BOOL wglMakeCurrent(HDC hdc, HGLRC hglrc);
//���÷�ʽ���£�
ghRC = wglCreateContext(ghDC);    // ������Ⱦ����
wglMakeCurrent(ghDC , ghRC);     // ʹ֮��Ϊ��ǰ��Ⱦ����
 

5.       ʵ�ʻ���

������־���һ��� OpenGL һ�£��ں�������չ��������

 

//6.�ͷ���Դ����ȡ����ǰ����Ⱦ����ѡ�У�Ȼ������ɾ����Ⱦ�������豸������
BOOL wglDeleteContext(HGLRC hglrc);
// ȡ��OpenGL ���ڳ������ǰ���ã��ͷ���Ⱦ�������豸�����Լ����մ��ھ����
void DisableOpenGL ()
{
       wglMakeCurrent ( NULL , NULL );
       wglDeleteContext ( ghRC );
       ReleaseDC ( ghWnd , ghDC );
}
�ġ�    ������ OpenGL �������
//OpenGL ��ʼ����ʼ
void SceneInit(int w, int h)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);      // ��ɫ����

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
 
// ����������еĻ�ͼ����
void SceneShow(GLvoid )   
{
	glClear( GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.75, 0.25, 0.0);
	glVertex3f(0.75, 0.75, 0.0);
	glVertex3f(0.25, 0.75, 0.0);
	glEnd();
	glFlush();
}

2. ������ʾ��һ����ת�ľ���
// �����OpenGL ����
void EnableOpenGL ()
{
	PIXELFORMATDESCRIPTOR pfd ;
	int iFormat ;
	ghDC = GetDC ( ghWnd );
	ZeroMemory ( & pfd , sizeof ( pfd ) );
	pfd . nSize = sizeof ( pfd ); 
	pfd . nVersion = 1;      // �汾��һ����Ϊ
	// һ��������ػ������Եı�־λ
	pfd . dwFlags =   PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER ;
	pfd . iPixelType = PFD_TYPE_RGBA ;   // ����������������RGBA ������ɫ����;
	pfd . cColorBits = 32; // ÿ����ɫ����������ɫλƽ�����Ŀ������ɫ������ʽ�ǻ�������С
	pfd . cDepthBits = 16;
	pfd . iLayerType = PFD_MAIN_PLANE ; // �����ԣ�Ϊ��һ���Զ�������
	iFormat = ChoosePixelFormat ( ghDC , & pfd ); // ѡ��һ�����ظ�ʽ
	SetPixelFormat ( ghDC , iFormat , & pfd ); // ���õ�DC ��
	ghRC = wglCreateContext ( ghDC );    // ������ͼ������
	wglMakeCurrent ( ghDC , ghRC );     // ʹ֮��Ϊ��ǰ��ͼ������
}
 
//OpenGL ��ʼ����ʼ
void SceneInit ( int w , int h )
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);      // ��ɫ����
	glColor3f(1.0f, 1.0f, 1.0f);
	glShadeModel( GL_FLAT );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(-50.0f, 50.0f, -50.0f, 50.0f, -1.0f, 1.0f);
}
 
  // ����������еĻ�ͼ����
void SceneShow ( GLvoid )       
{
	// ��ת�Ƕ�
	static float fSpin = 0.0f;
	fSpin += 2.0f;
	if ( fSpin > 360.0f)
	{
		fSpin -= 360.0f;
	}
	glClear ( GL_COLOR_BUFFER_BIT );
	glPushMatrix ();
	// ��ת���ε���Ҫ����
	glRotatef ( fSpin , 0.0f, 0.0f, 1.0f);
	glRectf (-25.0, -25.0, 25.0, 25.0);
	glPopMatrix ();
	// ����������
	SwapBuffers ( ghDC );
} 

 

�塢    �ο�����
1. OpenGL Reference Manual ���� OpenGL �ο��ֲ�

2. �� OpenGL ���ָ�ϡ����� OpenGL Programming Guide ������ Dave Shreiner �� Mason Woo �� Jackie Neider �� Tom Davis �����첨�룬��е��ҵ������

3.    Win32 �����µ� OpenGL ��� ����֣���������ִ����Ӽ��������վ��״�ѧԺ

4.   �� Win32 ��ʹ�� OpenGL ��

5.  �� OpenGL Win32 Tutorial ����������Ƚ�͸����

6.      MSDN �����˾��ȵ��� MSDN ���бȽ������� OpenGL �ο����ϣ����һ��кܶ��ǽ� X Window �� OpenGL �� -_-!

 

����    ���˵��
���������д��루����еĻ��������� Mercurial �� Google Code �����ء�

�����Բ��ķ�������ڷ�Ŀ¼��ţ����ص�ַΪ��

http://code.google.com/p/jtianling/source/checkout?repo=blog-sample-code

Mercurial ʹ�÷������� �ֲ�ʽ�ģ���һ���汾����ϵͳ Mercurial�Ľ��ܼ���Ҫ���� ��