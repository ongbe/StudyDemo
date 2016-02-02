/*****************************************************************************\
*                                                                             *
* Button.h -  Button functions, types, and definitions                        *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's button. All rights reserved.  *
*               Checked 2016/10/8 by Todd.                                    *
*                                                                             *
*******************************************************************************/

#ifndef __BUTTON_H__
#define __BUTTON_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CStr.h"

namespace OwLib
{
	class ButtonA:public ControlA
	{
	private:
		wstring m_disabledBackImage;
		wstring m_hoveredBackImage;
		wstring m_pushedBackImage;
		ContentAlignmentA m_textAlign;
	protected:
		virtual _int64 GetPaintingBackColor();
		virtual wstring GetPaintingBackImage();
	public:
		ButtonA();
		virtual ~ButtonA();
		wstring GetDisabledBackImage();
		void SetDisabledBackImage(const wstring& disabledBackImage);
		wstring GetHoveredBackImage();
		void SetHoveredBackImage(const wstring& hoveredBackImage);
		wstring GetPushedBackImage();
		void SetPushedBackImage(const wstring& pushedBackImage);
		ContentAlignmentA GetTextAlign();
		void SetTextAlign(ContentAlignmentA textAlign);
	public:
		virtual wstring GetControlType();
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void OnMouseDown(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnMouseEnter(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnMouseLeave(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnMouseUp(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnPaintForeground(CPaint *paint, const RECT& clipRect);
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}

#endif