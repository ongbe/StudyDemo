/*****************************************************************************\
*                                                                             *
* VScale.h -    Vertical scale functions, types, and definitions              *
*                                                                             *
*               Version 4.00 ������                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __VSCALE_H__
#define __VSCALE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CPaint.h"
#include "Enums.h"
#include "CTable.h"
#include "CrossLineTip.h"

namespace OwLib
{
	class VScale : public CProperty
	{
	private:
		bool m_autoMaxMin;
		int m_baseField;
		CrossLineTip *m_crossLineTip;
		int m_digit;
		FONT *m_font;
		_int64 m_foreColor;
		_int64 m_foreColor2;
		int m_magnitude;
		int m_marginBottom;
		int m_marginTop;
		double m_midValue;
		NumberStyle m_numberStyle;
		bool m_reverse;
		_int64 m_scaleColor;
		vector<double> m_scaleSteps;
		VScaleSystem m_system;
		VScaleType m_type;
		double m_visibleMax;
		double m_visibleMin;
	public:
		VScale();
		virtual ~VScale();
		bool AutoMaxMin();
		void SetAutoMaxMin(bool autoMaxMin);
		int GetBaseField();
		void SetBaseField(int baseField);
		CrossLineTip* GetCrossLineTip();
		int GetDigit();
		void SetDigit(int digit);
		FONT* GetFont();
		void SetFont(FONT *font);
		_int64 GetForeColor();
		void SetForeColor(_int64 foreColor);
		_int64 GetForeColor2();
		void SetForeColor2(_int64 foreColor2);
		int GetMagnitude();
		void SetMagnitude(int magnitude);
		int GetMarginBottom();
		void SetMarginBottom(int marginBottom);
		int GetMarginTop();
		void SetMarginTop(int marginTop);
		double GetMidValue();
		void SetMidValue(double midValue);
		NumberStyle GetNumberStyle();
		void SetNumberStyle(NumberStyle numberStyle);
		bool IsReverse();
		void SetReverse(bool reverse);
		_int64 GetScaleColor();
		void SetScaleColor(_int64 scaleColor);
		VScaleSystem GetSystem();
		void SetSystem(VScaleSystem system);
		VScaleType GetType();
		void SetType(VScaleType type);
		double GetVisibleMax();
		void SetVisibleMax(double visibleMax);
		double GetVisibleMin();
		void SetVisibleMin(double visibleMin);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		vector<double> GetScaleSteps();
		virtual void SetProperty(const wstring& name, const wstring& value);
		void SetScaleSteps(vector<double> scaleSteps);
	};
}
#endif