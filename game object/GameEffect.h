/****************************************************************************
**
** GameEffect.h
**
** Copyright (C) September 2015 Hotride
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
*****************************************************************************
*/
//---------------------------------------------------------------------------
#ifndef GameEffectH
#define GameEffectH
//--------------------------------------------------------------------------
//������� ������
class TGameEffect : public TRenderWorldObject
{
//private:
protected:
	EFFECT_TYPE m_EffectType; //��� �������

	DWORD m_DestSerial; //�������� ����������
	WORD m_DestX; //���������� ���������� �� ��� X
	WORD m_DestY; //���������� ���������� �� ��� Y
	char m_DestZ; //���������� ���������� �� ��� Z

	BYTE m_Speed; //��������
	DWORD m_Duration; //����� �����
	bool m_FixedDirection; //�������� ����������� �������� ��� ������ �������?
	bool m_Explode; //�������� �� ���������� ����?
	DWORD m_RenderMode; //����� ����������� �������

	int m_AnimIndex; //������ ��������
	int m_Increment; //�������� �� �������� �������
	DWORD m_LastChangeFrameTime; //��������� ����� ��������� ��������
public:
	TGameEffect();
	virtual ~TGameEffect();

	SETGET(EFFECT_TYPE, EffectType);
	SETGET(DWORD, DestSerial);
	SETGET(WORD, DestX);
	SETGET(WORD, DestY);
	SETGET(char, DestZ);
	SETGET(BYTE, Speed);
	SETGET(DWORD, Duration);
	SETGET(bool, FixedDirection);
	SETGET(bool, Explode);
	SETGET(DWORD, RenderMode);
	
	SETGET(int, AnimIndex);
	SETGET(int, Increment);
	SETGET(DWORD, LastChangeFrameTime);

	virtual int Draw(bool &mode, int &drawX, int &drawY, DWORD &ticks);

	//�������� ������� ������ ��������
	WORD GetCurrentGraphic();

	//��������� ������� ������ ��������
	WORD CalculateCurrentGraphic();

	//���������� ������ �����������
	void ApplyRenderMode();

	//������ ������ �����������
	void RemoveRenderMode();

	bool IsEffectObject() {return true;}

	virtual void Update() {}
};
//--------------------------------------------------------------------------
//������ ����������� ��������
class TGameEffectDrag : public TGameEffect
{
//private:
protected:
	int m_OffsetX; //�������� �� ��� X
	int m_OffsetY; //�������� �� ��� Y
public:
	TGameEffectDrag();
	virtual ~TGameEffectDrag();

	SETGET(int, OffsetX);
	SETGET(int, OffsetY);

	virtual void Update();
};
//--------------------------------------------------------------------------
//���������� ������
class TGameEffectMoving : public TGameEffectDrag
{
//private:
protected:
	float m_Angle;
	int m_OffsetZ;
public:
	TGameEffectMoving();
	virtual ~TGameEffectMoving();

	SETGET(float, Angle);
	SETGET(int, OffsetZ);

	virtual void Update();
};
//---------------------------------------------------------------------------
#endif