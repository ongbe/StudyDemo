/**********************************************************************************\
*                                                                                 *
* Div.h -     Div functions, types, and definitions                               *
*                                                                                 *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                           *
*                                                                                 *
*               Copyright (c) 2016-2016, Todd's scroll bar. All rights reserved.  *
*               Check right 2016/9/22 by Todd.                                    *
*                                                                                 *
***********************************************************************************/


#ifndef __DIV_H__
#define __DIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\Control.h"
#include "..\\ScrollBar\\ScrollBar.h"
#include "..\\ScrollBar\\HScrollBar.h"
#include "..\\ScrollBar\\VScrollBar.h"

namespace OwLib
{
	class HScrollBarA;
	class VScrollBarA;

	class DivA : public ControlA
	{
	private:
		HScrollBarA *m_hScrollBar;
		ControlKeyEvent m_scrollButtonKeyDownEvent;
		ControlMouseEvent m_scrollButtonMouseWheelEvent;
		bool m_showHScrollBar;
		bool m_showVScrollBar;
		VScrollBarA *m_vScrollBar;
		ControlEvent m_vScrollBarScrolledEvent;
		static void ScrollButtonKeyDown(void *sender, char key, void *pInvoke);
		static void ScrollButtonMouseWheel(void *sender, const POINT& mp, MouseButtonsA button, int clicks, int delta, void *pInvoke);
	public:
		DivA();
		virtual ~DivA();
		HScrollBarA* GetHScrollBar();
		bool ShowHScrollBar();
		void SetShowHScrollBar(bool showHScrollBar);
		bool ShowVScrollBar();
		void SetShowVScrollBar(bool showVScrollBar);
		VScrollBarA* GetVScrollBar();
	public:
		virtual int GetContentHeight();
		virtual int GetContentWidth();
		virtual wstring GetControlType();
		virtual POINT GetDisplayOffset();
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		virtual void LineDown();
		virtual void LineLeft();
		virtual void LineRight();
		virtual void LineUp();
		virtual void OnDragReady(POINT *startOffset);
		virtual void OnKeyDown(char key);
		virtual void OnMouseWheel(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void PageDown();
		virtual void PageLeft();
		virtual void PageRight();
		virtual void PageUp();
		virtual void SetProperty(const wstring& name, const wstring& value);
		virtual void Update();
	};
}

#endif