/*****************************************************************************\
*                                                                             *
* BaseShape.h - Base Shape functions, types, and definitions                  *
*                                                                             *
*               Version 4.00  ¡ï¡ï¡ï¡ï¡ï                                      *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __BASESHAPE_H__
#define __BASESHAPE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CPaint.h"
#include "Enums.h"
#include "Chart.h"
#include "CDiv.h"
#include "CTable.h"

namespace OwLib
{
	class CDiv;
	class ChartA;
	class BaseShape : CProperty
	{
	private:
		AttachVScale m_attachVScale;
	protected:
		bool m_selected;
		bool m_visible;
		int m_zOrder;
	public:
		BaseShape();
		virtual ~BaseShape();
		AttachVScale GetAttachVScale();
		void SetAttachVScale(AttachVScale attachVScale);
		bool IsSelected();
		void SetSelected(bool selected);
		bool IsVisible();
		void SetVisible(bool visible);
		int GetZOrder();
		void SetZOrder(int zOrder);
	public:
		virtual int GetBaseField();
		virtual wstring GetFieldText(int fieldName);
		virtual int* GetFields(int *length);
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual _int64 GetSelectedColor();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};

	class CandleShape:public BaseShape
	{
	private:
		int m_closeField;
		wstring m_closeFieldText;
		int m_colorField;
		_int64 m_downColor;
		int m_highField;
		wstring m_highFieldText;
		int m_lowField;
		wstring m_lowFieldText;
		int m_openField;
		wstring m_openFieldText;
		bool m_showMaxMin;
		CandleStyle m_style;
		int m_styleField;
		_int64 m_tagColor;
		_int64 m_upColor;
	public:
		CandleShape();
		int GetCloseField();
		void SetCloseField(int closeField);
		wstring GetCloseFieldText();
		void SetCloseFieldText(const wstring& closeFieldText);
		int GetColorField();
		void SetColorField(int colorField);
		_int64 GetDownColor();
		void SetDownColor(_int64 downColor);
		int GetHighField();
		void SetHighField(int highField);
		wstring GetHighFieldText();
		void SetHighFieldText(const wstring& highFieldText);
		int GetLowField();
		void SetLowField(int lowField);
		wstring GetLowFieldText();
		void SetLowFieldText(const wstring& lowFieldText);
		int GetOpenField();
		void SetOpenField(int openField);
		wstring GetOpenFieldText();
		void SetOpenFieldText(const wstring& openFieldText);
		bool GetShowMaxMin();
		void SetShowMaxMin(bool showMaxMin);
		CandleStyle GetStyle();
		void SetStyle(CandleStyle style);
		int GetStyleField();
		void SetStyleField(int styleField);
		_int64 GetTagColor();
		void SetTagColor(_int64 tagColor);
		_int64 GetUpColor();
		void SetUpColor(_int64 upColor);
	public:
		virtual int GetBaseField();
		virtual wstring GetFieldText(int fieldName);
		virtual int* GetFields(int *length);
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual _int64 GetSelectedColor();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};

	class BarShape:public BaseShape
	{
	private:
		int m_colorField;
		_int64 m_downColor;
		int m_fieldName;
		int m_fieldName2;
		wstring m_fieldText;
		wstring m_fieldText2;
		int m_lineWidth;
		BarStyle m_style;
		int m_styleField;
		_int64 m_upColor;
	public:
		BarShape();
		int GetColorField();
		void SetColorField(int colorField);
		_int64 GetDownColor();
		void SetDownColor(_int64 downColor);
		int GetFieldName();
		void SetFieldName(int fieldName);
		int GetFieldName2();
		void SetFieldName2(int fieldName2);
		wstring GetFieldText();
		void SetFieldText(const wstring& fieldText);
		wstring GetFieldText2();
		void SetFieldText2(const wstring& fieldText2);
		int GetLineWidth();
		void SetLineWidth(int lineWidth);
		BarStyle GetStyle();
		void SetStyle(BarStyle style);
		int GetStyleField();
		void SetStyleField(int styleField);
		_int64 GetUpColor();
		void SetUpColor(_int64 upColor);
	public:
		virtual int GetBaseField();
		virtual wstring GetFieldText(int fieldName);
		virtual int* GetFields(int *length);
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual _int64 GetSelectedColor();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};

	class PolylineShape:public BaseShape
	{
	private:
		_int64 m_color;
		int m_colorField;
		int m_fieldName;
		wstring m_fieldText;
		_int64 m_fillColor;
		PolylineStyle m_style;
		int m_width;
	public:
		PolylineShape();
		_int64 GetColor();
		void SetColor(_int64 color);
		int GetColorField();
		void SetColorField(int colorField);
		int GetFieldName();
		void SetFieldName(int fieldName);
		wstring GetFieldText();
		void SetFieldText(const wstring& fieldText);
		_int64 GetFillColor();
		void SetFillColor(_int64 fillColor);
		PolylineStyle GetStyle();
		void SetStyle(PolylineStyle style);
		int GetWidth();
		void SetWidth(int width);
	public:
		virtual int GetBaseField();
		virtual wstring GetFieldText(int fieldName);
		virtual int* GetFields(int *length);
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual _int64 GetSelectedColor();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};

	class TextShape:public BaseShape
	{
	private:
		int m_colorField;
		int m_fieldName;
		FONT *m_font;
		_int64 m_foreColor;
		int m_styleField;
		wstring m_text;
	public:
		TextShape();
		virtual ~TextShape();
		int GetColorField();
		void SetColorField(int colorField);
		int GetFieldName();
		void SetFieldName(int fieldName);
		FONT* GetFont();
		void SetFont(FONT *font);
		_int64 GetForeColor();
		void SetForeColor(_int64 foreColor);
		int GetStyleField();
		void SetStyleField(int styleField);
		wstring GetText();
		void SetText(const wstring& text);
	public:
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}
#endif