#pragma once

#include <windows.h>
#include <math.h>
#include <vector>

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

#define R 50
#define SPEED 10
/*
#define PI 3.1415926
#define RADIAN(X) (X) * PI / 180
*/

class Object //모든 물체는 원으로 함 
{
protected:
	POINT _pos;
	int _r;
	double _angle;
	double _speed;

public:
	void MoveAngleToDir();

	void Rotate(double);
	void SetAngle(double);

	POINT GetPos() { return _pos; }
	void SetPos(POINT pos) { _pos = pos; }
	int GetR() { return _r; }

	bool IsCollide(Object);
	bool IsCollide(Object*);

	void Draw(HDC hdc, RECT rtWindow);
};

class BulletObj : public Object
{
	int _damage;
public:
	BulletObj(int, int, double, POINT);

	int GetDamage() { return _damage; }

	void MoveOneFrame();
};

class MobObj : public Object
{
	int _hp;
	int _damage;
public:
	MobObj(int, int, POINT);

	int GetDamage() { return _damage; }
	int GetHp() { return _hp; }
	void SetHp(int hp) { _hp = hp; }

	void MoveOneFrame();
};

class BarrierObj : public Object
{
	int _damage;
public:
	void MovePos(POINT);
};

void Init();
bool MoveFrame();