// OpenGL3D.h: interface for the OpenGL3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGL3D_H__6C62B786_FED6_43A5_8721_EB86E3C74A5C__INCLUDED_)
#define AFX_OPENGL3D_H__6C62B786_FED6_43A5_8721_EB86E3C74A5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class OpenGL3D  
{
public:
 	float m_TranslateX;//设置平移参数
    float m_TranslateY;
 	float m_TranslateZ;

	BOOL CreateTexture(UINT &texture, LPSTR strFileName);
	void Draw3D(int *m_pEle,int m_nCol ,int m_nRow,int MaxHeight,int MinHeight);
	void InitLightMat();
	void DrawScene();

	HGLRC m_hRC;
	UINT g_Texture[1000];//保存纹理数据

//   static	float m_RotateX;//设置动态旋转参数
 //  static	float m_RotateY;
  // static   float m_RotateZ;
	    float m_RotateAngle;//设置旋转角度

	void Init(CDC *pDC);
	OpenGL3D();
	virtual ~OpenGL3D();

protected:
};
   float m_RotateX=1;//静态变量的初始化
   float m_RotateY=1;
   float m_RotateZ=1;

#endif // !defined(AFX_OPENGL3D_H__6C62B786_FED6_43A5_8721_EB86E3C74A5C__INCLUDED_)

