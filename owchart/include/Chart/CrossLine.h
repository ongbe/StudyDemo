/*****************************************************************************\
*                                                                             *
* CrossLine.h - Cross line functions, types, and definitions                  *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __CROSSLINE_H__
#define __CROSSLINE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "Enums.h"

namespace OwLib
{
	class CrossLine : CProperty
	{
	private:
		bool m_allowDoubleClick;
		AttachVScale m_attachVScale;
		_int64 m_lineColor;
	public:
		CrossLine();
		virtual ~CrossLine();
		bool AllowDoubleClick();
		void SetAllowDoubleClick(bool allowDoubleClick);
		AttachVScale GetAttachVScale();
		void SetAttachVScale(AttachVScale attachVScale);
		_int64 GetLineColor();
		void SetLineColor(_int64 lineColor);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}
#endif