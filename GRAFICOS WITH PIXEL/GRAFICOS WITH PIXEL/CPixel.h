#pragma once
class CPixel
{
public:
	CPixel();
	~CPixel();
	enum { TF_R8 = 0, TF_R8G8, TF_R8G8B8, TF_R8G8B8A8, TF_R32G32B32A32 }TYPE_FORMAT;
	union
	{
		int m_color;
		struct
		{
			unsigned char R8, G8, B8, A8;
		};
	};
	//	to be able to make the conversion more easily
	float R32, G32, B32, A32;
};
