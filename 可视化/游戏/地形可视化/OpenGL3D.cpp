// OpenGL3D.cpp: implementation of the OpenGL3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Frame.h"
#include "OpenGL3D.h"

#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OpenGL3D::OpenGL3D()//初始化旋转参数
{
	m_RotateAngle=0;
//	m_RotateX=1.0;
//	m_RotateY=1.0;
//	m_RotateZ=1.0;

}

OpenGL3D::~OpenGL3D()//释放RC
{
	wglDeleteContext(m_hRC);

}

void OpenGL3D::Init(CDC *pDC)         //OpenGL的初始化
{
	PIXELFORMATDESCRIPTOR pfd=
	{
	sizeof(PIXELFORMATDESCRIPTOR),	
		1,									
		PFD_DRAW_TO_WINDOW |					
		PFD_SUPPORT_OPENGL |				
		PFD_DOUBLEBUFFER,						
		PFD_TYPE_RGBA,						
		24,										
		0, 0, 0, 0, 0, 0,						
		0,									
		0,									
		0,										
		0, 0, 0, 0,							
		16,										
		0,										
		0,									
		PFD_MAIN_PLANE,					
		0,									
		0, 0, 0	
	};
	
	int pixelFormat=ChoosePixelFormat(pDC->m_hDC,&pfd);
	BOOL success=SetPixelFormat(pDC->m_hDC ,pixelFormat,&pfd);
	m_hRC=wglCreateContext(pDC->m_hDC );
}

void OpenGL3D::DrawScene()//渲染地景,这个也还没有写,没时间完成了,等下学期
{

}

void OpenGL3D::InitLightMat()//定义光照和材质
{

	GLfloat Light_Ambient[]={0.0,0.5,0.5,1.0};
	GLfloat Light_Position[]={0.0,1.0,0.0};

	glLightfv(GL_LIGHT0,GL_AMBIENT,Light_Ambient);
	glLightfv(GL_LIGHT0,GL_POSITION,Light_Position);
/*
	glEnable(GL_LIGHTING);         //我把启用光照注释掉了,因为如果打开光照那么就没有
	glEnable(GL_LIGHT0);*/         //根据高程所设的颜色了
  
	glShadeModel(GL_SMOOTH);						
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				
	glClearDepth(1.0f);								
	glEnable(GL_DEPTH_TEST);						
	glDepthFunc(GL_LEQUAL);						
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	 


	

}
//主要的程序
void OpenGL3D::Draw3D(int *m_pEle, int m_nCol, int m_nRow, int MaxHeight, int MinHeight)
{
	float x1,y1,z1;
	float x2,y2,z2;
	x1=y1=z1=x2=y2=z2=0;

	float colorR,colorG,colorB;
    InitLightMat();//初始化光照材质
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(m_RotateAngle,m_RotateX,m_RotateY,m_RotateZ);//动态旋转
//	glBegin(GL_TRIANGLE_STRIP);         //三角面片法,但实现速度太慢,不适合实时生成地形

//	glBegin(GL_POINTS);                //直接画点
	for(int i=0;i<m_nRow-1;i++)
       {
		glBegin(GL_LINE_STRIP);        //按行将点连接成直线
		for(int j=0;j<m_nCol-1;j++)
		{
			x1=1.6f*(float)(j)/m_nCol-0.8f;
		
            z1=1.6f*(float)(i)/m_nRow-0.8f;
		
			y1=(float)(m_pEle[i*m_nCol+j])/1800000.f;
          
			colorR=y1+0.4;//设置颜色
			colorG=1.0f-colorR;
			colorB=1.0f;

            glColor3f(colorR,colorG,colorB);
			glVertex3f(x1,y1,z1);
		}
		glEnd();
	}/*
	for(int j=0;j<m_nCol-1;j++)
       {
		glBegin(GL_LINE_STRIP);
		for(int i=0;i<m_nRow-1;i++)
		{
			x1=1.6f*(float)(j)/m_nCol-0.8f;
		
            z1=1.6f*(float)(i)/m_nRow-0.8f;
		

			y1=(float)(m_pEle[i*m_nCol+j])/1800000.f;
        
			colorR=y1+0.2;
			colorG=1.0f-colorR;
			colorB=1.0f;

            glColor3f(colorR,colorG,colorB);
			glVertex3f(x1,y1,z1);
		}
		glEnd();
	}*/
			
			
}

//这个程序现在还没有用,是用来将现有的*.bmp文件作为纹理贴到地表上的
BOOL OpenGL3D::CreateTexture(UINT &texture, LPSTR strFileName)
{
	AUX_RGBImageRec *pImage = NULL;
	FILE *pFile = NULL;

	if(!strFileName) 
		return false;

	// 以只读模式打开文件 
	if((pFile = fopen(strFileName, "rb")) == NULL) 
	{
		// 如果文件无法打开，则显示错误信息
	
		return NULL;
	}

	// 装入位图
	pImage = auxDIBImageLoad(strFileName);				

	// 确保位图数据已经装入
	if(pImage == NULL)								
		return false;

	// 生成纹理
	glGenTextures(1, &texture);

	// 设置像素格式
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	// 捆绑纹理
	glBindTexture(GL_TEXTURE_2D, texture);
	
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pImage->sizeX, 
					  pImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pImage->data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//  释放位图数据占据的内存资源
	if (pImage)	
	{
		if (pImage->data)	
		{
			free(pImage->data);
		}

		free(pImage);	
	}

	// 返回true
	return true;

}
