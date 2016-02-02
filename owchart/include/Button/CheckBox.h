/*****************************************************************************\
*                                                                             *
* CheckBox.h -  Check box functions, types, and definitions                   *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's button. All rights reserved.  *
*               Checked 2016/10/8 by Todd.                                    *
*                                                                             *
*******************************************************************************/

#ifndef __CHECKBOX_H__
#define __CHECKBOX_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CStr.h"
#include "Button.h"

namespace OwLib
{
	class CheckBoxA : public ButtonA
	{
	private:
		_int64 m_buttonBackColor;
		_int64 m_buttonBorderColor;
		SIZE m_buttonSize;
		bool m_checked;
		wstring m_checkedBackImage;
		wstring m_checkHoveredBackImage;
		wstring m_checkPushedBackImage;
		wstring m_disableCheckedBackImage;
		HorizontalAlignA m_horizontalAlign;
	protected:
		virtual _int64 GetPaintingBackColor();
		virtual _int64 GetPaintingButtonBackColor();
		virtual _int64 GetPaintingButtonBorderColor();
		virtual wstring GetPaintingBackImage();
	public:
		CheckBoxA();
		virtual ~CheckBoxA();
		_int64 GetButtonBackColor();
		void SetButtonBackColor(_int64 buttonBackColor);
		_int64 GetButtonBorderColor();
		void SetButtonBorderColor(_int64 buttonBorderColor);
		SIZE GetButtonSize();
		void SetButtonSize(SIZE buttonSize);
		bool IsChecked();
		void SetChecked(bool checked);
		wstring GetCheckedBackImage();
		void SetCheckedBackImage(const wstring& checkedBackImage);
		wstring GetCheckHoveredBackImage();
		void SetCheckHoveredBackImage(const wstring& checkHoveredBackImage);
		wstring GetCheckPushedBackImage();
		void SetCheckPushedBackImage(const wstring& checkPushedBackImage);
		wstring GetDisableCheckedBackImage();
		void SetDisableCheckedBackImage(const wstring& disableCheckedBackImage);
		HorizontalAlignA GetHorizontalAlign();
		void SetHorizontalAlign(HorizontalAlignA horizontalAlign);
	public:
		virtual wstring GetControlType();
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void OnCheckedChanged();
		virtual void OnClick(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnPaintBackground(CPaint *paint, const RECT& clipRect);
		virtual void OnPaintCheckButton(CPaint *paint, const RECT& clipRect);
		virtual void OnPaintForeground(CPaint *paint, const RECT& clipRect);
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}

#endif