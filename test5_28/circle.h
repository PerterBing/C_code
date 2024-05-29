#pragma once
#include<iostream>
using namespace std;
#include"point.h"
class circle
{
public:
	void setr(int r);
	int getr();
	void setcenter(Point center);
	Point getcenter();
private:
	int m_r;
	Point m_center;
};
