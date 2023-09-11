Charles Petzold 的《 Programming Windows 》。
三、    Win32 下 OpenGL 编程需要的操作步骤
全部源代码见我的放在 Google Code 上的 blog-sample-code 中 2009-9-27\Win32OpenGLTemplate 目录。取回方式见本文最后的说明。

// GLOBALS ////////////////////////////////////////////////
HWND ghWnd ; // 窗口句柄
HINSTANCE ghInstance ; // 程序实例句柄
HDC ghDC ;             // GDI 设备环境句柄
HGLRC ghRC ;           // 渲染环境句柄

1.       头文件

#include <windows.h>
// OpenGL 需要的头文件
#include <GL/gl.h>
#include <GL/glu.h>
#pragma comment ( lib , "opengl32.lib" )
#pragma comment ( lib , "glu32.lib" ) 

 

3. 像素格式 (Pixel Format) 设置

需要用到的函数的原型：

int ChoosePixelFormat(HDC hdc, CONST PIXELFORMATDESCRIPTOR *ppfd);
BOOL SetPixelFormat(HDC hdc, int iPixelFormat, CONST PIXELFORMATDESCRIPTOR *ppfd);
	// 设置像素格式
	PIXELFORMATDESCRIPTOR pfd;
	int iFormat;
	ghDC = GetDC(ghWnd);
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof ( pfd ); 
	pfd.nVersion = 1;      // 版本，一般设为
	pfd.dwFlags =   PFD_DRAW_TO_WINDOW | // 一组表明象素缓冲特性的标志位
	PFD_SUPPORT_OPENGL ;
	pfd.iPixelType = PFD_TYPE_RGBA ;   // 明象素数据类型是RGBA 还是颜色索引;
	pfd.cColorBits = 32; // 每个颜色缓冲区中颜色位平面的数目，对颜色索引方式是缓冲区大小
	pfd.iLayerType = PFD_MAIN_PLANE ; // 被忽略，为了一致性而包含的
	iFormat = ChoosePixelFormat ( ghDC , & pfd ); // 选择一个像素格式
	SetPixelFormat(ghDC, iFormat, &pfd); // 设置到DC 中
 
//设置双重缓冲区的代码。
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
 
4.       渲染器环境 (Render Context) 创建

调用 wglCreateContext 与 wglMakeCurrent 函数 ，这两个函数都是 Windows 下为了兼容 OpenGL 而特别提供的接口，以 wgl 开头。

函数原型：

HGLRC wglCreateContext(HDC hdc);
BOOL wglMakeCurrent(HDC hdc, HGLRC hglrc);
//调用方式如下：
ghRC = wglCreateContext(ghDC);    // 创建渲染环境
wglMakeCurrent(ghDC , ghRC);     // 使之成为当前渲染环境
 

5.       实际绘制

这个部分就与一般的 OpenGL 一致，在后面慢慢展开讲述。

 

//6.释放资源首先取消当前的渲染环境选中，然后依次删除渲染环境与设备环境。
BOOL wglDeleteContext(HGLRC hglrc);
// 取消OpenGL ，在程序结束前调用，释放渲染环境，设备环境以及最终窗口句柄。
void DisableOpenGL ()
{
       wglMakeCurrent ( NULL , NULL );
       wglDeleteContext ( ghRC );
       ReleaseDC ( ghWnd , ghDC );
}
四、    真正的 OpenGL 相关内容
//OpenGL 初始化开始
void SceneInit(int w, int h)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);      // 黑色背景

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
 
// 这里进行所有的绘图工作
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

2. 动画演示：一个旋转的矩形
// 激活创建OpenGL 窗口
void EnableOpenGL ()
{
	PIXELFORMATDESCRIPTOR pfd ;
	int iFormat ;
	ghDC = GetDC ( ghWnd );
	ZeroMemory ( & pfd , sizeof ( pfd ) );
	pfd . nSize = sizeof ( pfd ); 
	pfd . nVersion = 1;      // 版本，一般设为
	// 一组表明象素缓冲特性的标志位
	pfd . dwFlags =   PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER ;
	pfd . iPixelType = PFD_TYPE_RGBA ;   // 明象素数据类型是RGBA 还是颜色索引;
	pfd . cColorBits = 32; // 每个颜色缓冲区中颜色位平面的数目，对颜色索引方式是缓冲区大小
	pfd . cDepthBits = 16;
	pfd . iLayerType = PFD_MAIN_PLANE ; // 被忽略，为了一致性而包含的
	iFormat = ChoosePixelFormat ( ghDC , & pfd ); // 选择一个像素格式
	SetPixelFormat ( ghDC , iFormat , & pfd ); // 设置到DC 中
	ghRC = wglCreateContext ( ghDC );    // 创建绘图描述表
	wglMakeCurrent ( ghDC , ghRC );     // 使之成为当前绘图描述表
}
 
//OpenGL 初始化开始
void SceneInit ( int w , int h )
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);      // 黑色背景
	glColor3f(1.0f, 1.0f, 1.0f);
	glShadeModel( GL_FLAT );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(-50.0f, 50.0f, -50.0f, 50.0f, -1.0f, 1.0f);
}
 
  // 这里进行所有的绘图工作
void SceneShow ( GLvoid )       
{
	// 旋转角度
	static float fSpin = 0.0f;
	fSpin += 2.0f;
	if ( fSpin > 360.0f)
	{
		fSpin -= 360.0f;
	}
	glClear ( GL_COLOR_BUFFER_BIT );
	glPushMatrix ();
	// 旋转矩形的主要函数
	glRotatef ( fSpin , 0.0f, 0.0f, 1.0f);
	glRectf (-25.0, -25.0, 25.0, 25.0);
	glPopMatrix ();
	// 交换缓冲区
	SwapBuffers ( ghDC );
} 

 

五、    参考资料
1. OpenGL Reference Manual 》， OpenGL 参考手册

2. 《 OpenGL 编程指南》（《 OpenGL Programming Guide 》）， Dave Shreiner ， Mason Woo ， Jackie Neider ， Tom Davis 著，徐波译，机械工业出版社

3.    Win32 环境下的 OpenGL 编程 》，郑竞华，《现代电子技术》，空军雷达学院

4.   《 Win32 下使用 OpenGL 》

5.  《 OpenGL Win32 Tutorial 》，（讲解比较透彻）

6.      MSDN ，让人惊讶的是 MSDN 中有比较完整的 OpenGL 参考资料，并且还有很多是讲 X Window 的 OpenGL 的 -_-!

 

六、    最后说明
本文中所有代码（如果有的话）都能用 Mercurial 在 Google Code 中下载。

文章以博文发表的日期分目录存放，下载地址为：

http://code.google.com/p/jtianling/source/checkout?repo=blog-sample-code

Mercurial 使用方法见《 分布式的，新一代版本控制系统 Mercurial的介绍及简要入门 》