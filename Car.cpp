#include <iostream>
#include <cstring>
#include "Car.h"
#define  _CRT_SECURE_NO_WARNINGS

using namespace std;

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "������ id: " << gamerID << endl;
	cout << "���ᷮ" << fuelGauge << "%" << endl;
	cout << "����ӵ�" << curSpeed << "km/s" << endl;

}

void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPEED)
	{
		curSpeed = CAR_CONST::MAX_SPEED;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}