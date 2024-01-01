#include "Game.h"

std::vector <BulletObj* > bullets;
std::vector<MobObj*> enemys;
MobObj* player;
BarrierObj* barrier;
int coolTime=100;

void Object::MoveAngleToDir()
{
	_pos.x += (double)cos(_angle) * _speed;
	_pos.y += (double)sin(_angle) * _speed;
}

void Object::Rotate(double angle)
{
	_angle += angle;
}
void Object::SetAngle(double angle)
{
	_angle = angle;
}

bool Object::IsCollide(Object t)
{
	POINT tpos = t.GetPos();
	long long int dis = (_pos.x - tpos.x) * (_pos.x - tpos.x) + (_pos.y - tpos.y) * (_pos.y - tpos.y);
		return dis <= (_r + t.GetR());
}
bool Object::IsCollide(Object* t)
{
	POINT tpos = t->GetPos();
	long long int dis = (_pos.x - tpos.x) * (_pos.x - tpos.x) + (_pos.y - tpos.y) * (_pos.y - tpos.y);
		return dis <= (_r + t->GetR());
}

void Object::Draw(HDC hdc, RECT rtWindow)
{
	Ellipse(hdc, (_pos.x - R) - rtWindow.left, (_pos.y - R) - rtWindow.top, (_pos.x + R) - rtWindow.left, (_pos.y + R) - rtWindow.top);
}

BulletObj::BulletObj(int damage, int speed, double angle, POINT pos)
{
	_damage = damage;
	_speed = speed;
	_angle = angle;
	_pos = pos;
}
void BulletObj::MoveOneFrame()
{
	MoveAngleToDir();
}


MobObj::MobObj(int hp, int damage, POINT pos)
{
	_hp = hp;
	_damage = damage;
	_pos = pos;
}
void MobObj::MoveOneFrame()
{
	MoveAngleToDir();
}


void BarrierObj::MovePos(POINT pos)
{
	_pos = pos;
}


void Init()
{
	player = new MobObj(10, 10, {100,100});
}

bool MoveFrame()
{
	for (auto i : bullets) {
		i->MoveOneFrame();
	}
	for (auto i : enemys) {
		i->MoveOneFrame();
	}/*
	for (auto i : bullets) {
		for (auto j : enemys) {
			if (i->IsCollide(j)) {
				int hp = j->GetHp();
				j->SetHp(hp - (i->GetDamage()));
			}
		} 
	}
	for (auto i : enemys) {
		if (i->IsCollide(player)) {
			int hp = player->GetHp();
			player->SetHp(hp - (i->GetDamage()));
			if (player->GetHp() <= 0)return false;
		}
	}*/

	return true;
}