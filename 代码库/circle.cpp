#define _CRT_SECURE_NO_WARNINGS
#include"circle.h"

void circle::setr(int r)
{
	m_r = r;
}
int circle::getr()
{
	return m_r;
}
void circle::setcenter(Point center)
{
	m_center = center;
}
Point circle::getcenter()
{
	return m_center;
}
