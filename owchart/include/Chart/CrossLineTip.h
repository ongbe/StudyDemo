/*****************************************************************************\
*                                                                             *
* CrossLineTip.h - Cross line tip functions, types, and definitions           *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __CROSSLINETIP_H__
#define __CROSSLINETIP_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CPaint.h"

namespace OwLib
{
	class CrossLineTip
	{
	private:
		_int64 m_backColor;
		FONT *m_font;
		_int64 m_foreColor;
		bool m_visible;
	public:
		CrossLineTip();
		virtual ~CrossLineTip();
		_int64 GetBackColor();
		void SetBackColor(_int64 backColor);
		FONT* GetFont();
		void SetFont(FONT *font);
		_int64 GetForeColor();
		void SetForeColor(_int64 foreColor);
		bool IsVisible();
		void SetVisible(bool visible);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}
#endif