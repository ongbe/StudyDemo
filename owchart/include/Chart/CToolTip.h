/*****************************************************************************\
*                                                                             *
* CToolTip.h -  Tooltip functions, types, and definitions                     *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/


#ifndef __CTOOLTIP_H__
#define __CTOOLTIP_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CPaint.h"

namespace OwLib
{
	class CToolTip : public CProperty
	{
	private:
		_int64 m_backColor;
		_int64 m_borderColor;
		FONT *m_font;
		_int64 m_foreColor;
	public:
		CToolTip();
		virtual ~CToolTip();
		_int64 GetBackColor();
		void SetBackColor(_int64 backColor);
		_int64 GetBorderColor();
		void SetBorderColor(_int64 borderColor);
		FONT* GetFont();
		void SetFont(FONT *font);
		_int64 GetForeColor();
		void SetForeColor(_int64 foreColor);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}
#endif