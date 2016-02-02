/*****************************************************************************\
*                                                                             *
* ScaleGrid.h -     Scale grid functions, types, and definitions              *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __SCALEGRID_H__
#define __SCALEGRID_H__
#pragma once
#include "..\\..\\stdafx.h"

namespace OwLib
{
	class ScaleGrid : public CProperty
	{
	private:
		int m_distance;
		_int64 m_gridColor;
		int m_lineStyle;
		bool m_visible;
	public:
		ScaleGrid();
		virtual ~ScaleGrid();
		int GetDistance();
		void SetDistance(int distance);
		_int64 GetGridColor();
		void SetGridColor(_int64 gridColor);
		int GetLineStyle();
		void SetLineStyle(int lineStyle);
		bool IsVisible();
		void SetVisible(bool visible);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}
#endif