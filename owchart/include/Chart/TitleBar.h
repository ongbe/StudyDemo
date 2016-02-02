/*****************************************************************************\
*                                                                             *
* TitleBar.h -  Title Bar functions, types, and definitions                   *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __TITLEBAR_H__
#define __TITLEBAR_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CPaint.h"
#include "CTable.h"
#include "Enums.h"
#include "CList.h"

namespace OwLib
{
	class CTitle : public CProperty
	{
	private:
		int m_digit;
		int m_fieldName;
		wstring m_fieldText;
		TextMode m_fieldTextMode;
		wstring m_fieldTextSeparator;
		_int64 m_textColor;
		bool m_visible;
	public:
		CTitle(int fieldName, const wstring& fieldText, _int64 color, int digit, bool visible);
		int GetDigit();
		void SetDigit(int digit);
		int GetFieldName();
		void SetFieldName(int fieldName);
		wstring GetFieldText();
		void SetFieldText(const wstring& fieldText);
		TextMode GetFieldTextMode();
		void SetFieldTextMode(TextMode fieldTextMode);
		wstring GetFieldTextSeparator();
		void SetFieldTextSeparator(const wstring& fieldTextSeparator);
		_int64 GetTextColor();
		void SetTextColor(_int64 textColor);
		bool IsVisible();
		void SetVisible(bool visible);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};

	class TitleBar : public CProperty
	{
	private:
		FONT *m_font;
		_int64 m_foreColor;
		int m_height;
		int m_maxLine;
		bool m_showUnderLine;
		wstring m_text;
		_int64 m_underLineColor;
		bool m_visible;
	public:
		TitleBar();
		virtual ~TitleBar();
		vector<CTitle*> Titles;
		FONT* GetFont();
		void SetFont(FONT *font);
		_int64 GetForeColor();
		void SetForeColor(_int64 foreColor);
		int GetHeight();
		void SetHeight(int height);
		int GetMaxLine();
		void SetMaxLine(int maxLine);
		bool ShowUnderLine();
		void SetShowUnderLine(bool showUnderLine);
		wstring GetText();
		void SetText(const wstring& text);
		_int64 GetUnderLineColor();
		void SetUnderLineColor(_int64 underLineColor);
		bool IsVisible();
		void SetVisible(bool visible);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}
#endif