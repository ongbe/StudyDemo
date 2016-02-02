/*****************************************************************************\
*                                                                             *
* SelectArea.h -Select Area functions, types, and definitions                 *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __SELECTAREA_H__
#define __SELECTAREA_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace OwLib
{
	class SelectArea : public CProperty
	{
	private:
		_int64 m_backColor;
		RECT m_bounds;
		bool m_canResize;
		bool m_enabled;
		_int64 m_lineColor;
		bool m_visible;
	public:
		SelectArea();
		virtual ~SelectArea();
		_int64 GetBackColor();
		void SetBackColor(_int64 backColor);
		RECT GetBounds();
		void SetBounds(RECT bounds);
		bool CanResize();
		void SetCanResize(bool canResize);
		bool IsEnabled();
		void SetEnabled(bool enabled);
		_int64 GetLineColor();
		void SetLineColor(_int64 lineColor);
		bool IsVisible();
		void SetVisible(bool visible);
	public:
		void Close();
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);

	};
}
#endif