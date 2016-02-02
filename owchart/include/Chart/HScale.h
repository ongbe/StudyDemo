/*****************************************************************************\
*                                                                             *
* HScale.h -    Horizontal scale functions, types, and definitions            *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/


#ifndef __HSCALE_H__
#define __HSCALE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CPaint.h"
#include "Enums.h"
#include "CrossLineTip.h"

namespace OwLib
{
	class HScale : public CProperty
	{
	private:
		CrossLineTip *m_crossLineTip;
		map<DateType, _int64> m_dateColors;
		FONT *m_font;
		_int64 m_foreColor;
		int m_height;
		HScaleType m_hScaleType;
		int m_interval;
		_int64 m_scaleColor;
		vector<double> m_scaleSteps;
		bool m_visible;
	public:
		HScale();
		virtual ~HScale();
		CrossLineTip* GetCrossLineTip();
		_int64 GetDateColor(DateType dateType);
		void SetDateColor(DateType dateType, _int64 color);
		FONT* GetFont();
		void SetFont(FONT *font);
		_int64 GetForeColor();
		void SetForeColor(_int64 foreColor);
		int GetHeight();
		void SetHeight(int height);
		HScaleType GetHScaleType();
		void SetHScaleType(HScaleType hScaleType);
		int GetInterval();
		void SetInterval(int interval);
		_int64 GetScaleColor();
		void SetScaleColor(_int64 scaleColor);
		bool IsVisible();
		void SetVisible(bool visible);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		vector<double> GetScaleSteps();
		virtual void SetProperty(const wstring& name, const wstring& value);
		void SetScaleSteps(vector<double> scaleSteps);
	};
}
#endif