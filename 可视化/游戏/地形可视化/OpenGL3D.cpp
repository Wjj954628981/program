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

OpenGL3D::OpenGL3D()//��ʼ����ת����
{
	m_RotateAngle=0;
//	m_RotateX=1.0;
//	m_RotateY=1.0;
//	m_RotateZ=1.0;

}

OpenGL3D::~OpenGL3D()//�ͷ�RC
{
	wglDeleteContext(m_hRC);

}

void OpenGL3D::Init(CDC *pDC)         //OpenGL�ĳ�ʼ��
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

void OpenGL3D::DrawScene()//��Ⱦ�ؾ�,���Ҳ��û��д,ûʱ�������,����ѧ��
{

}

void OpenGL3D::InitLightMat()//������պͲ���
{

	GLfloat Light_Ambient[]={0.0,0.5,0.5,1.0};
	GLfloat Light_Position[]={0.0,1.0,0.0};

	glLightfv(GL_LIGHT0,GL_AMBIENT,Light_Ambient);
	glLightfv(GL_LIGHT0,GL_POSITION,Light_Position);
/*
	glEnable(GL_LIGHTING);         //�Ұ����ù���ע�͵���,��Ϊ����򿪹�����ô��û��
	glEnable(GL_LIGHT0);*/         //���ݸ߳��������ɫ��
  
	glShadeModel(GL_SMOOTH);						
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				
	glClearDepth(1.0f);								
	glEnable(GL_DEPTH_TEST);						
	glDepthFunc(GL_LEQUAL);						
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	 


	

}
//��Ҫ�ĳ���
void OpenGL3D::Draw3D(int *m_pEle, int m_nCol, int m_nRow, int MaxHeight, int MinHeight)
{
	float x1,y1,z1;
	float x2,y2,z2;
	x1=y1=z1=x2=y2=z2=0;

	float colorR,colorG,colorB;
    InitLightMat();//��ʼ�����ղ���
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(m_RotateAngle,m_RotateX,m_RotateY,m_RotateZ);//��̬��ת
//	glBegin(GL_TRIANGLE_STRIP);         //������Ƭ��,��ʵ���ٶ�̫��,���ʺ�ʵʱ���ɵ���

//	glBegin(GL_POINTS);                //ֱ�ӻ���
	for(int i=0;i<m_nRow-1;i++)
       {
		glBegin(GL_LINE_STRIP);        //���н������ӳ�ֱ��
		for(int j=0;j<m_nCol-1;j++)
		{
			x1=1.6f*(float)(j)/m_nCol-0.8f;
		
            z1=1.6f*(float)(i)/m_nRow-0.8f;
		
			y1=(float)(m_pEle[i*m_nCol+j])/1800000.f;
          
			colorR=y1+0.4;//������ɫ
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

//����������ڻ�û����,�����������е�*.bmp�ļ���Ϊ���������ر��ϵ�
BOOL OpenGL3D::CreateTexture(UINT &texture, LPSTR strFileName)
{
	AUX_RGBImageRec *pImage = NULL;
	FILE *pFile = NULL;

	if(!strFileName) 
		return false;

	// ��ֻ��ģʽ���ļ� 
	if((pFile = fopen(strFileName, "rb")) == NULL) 
	{
		// ����ļ��޷��򿪣�����ʾ������Ϣ
	
		return NULL;
	}

	// װ��λͼ
	pImage = auxDIBImageLoad(strFileName);				

	// ȷ��λͼ�����Ѿ�װ��
	if(pImage == NULL)								
		return false;

	// ��������
	glGenTextures(1, &texture);

	// �������ظ�ʽ
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);

	// ��������
	glBindTexture(GL_TEXTURE_2D, texture);
	
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pImage->sizeX, 
					  pImage->sizeY, GL_RGB, GL_UNSIGNED_BYTE, pImage->data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//  �ͷ�λͼ����ռ�ݵ��ڴ���Դ
	if (pImage)	
	{
		if (pImage->data)	
		{
			free(pImage->data);
		}

		free(pImage);	
	}

	// ����true
	return true;

}
