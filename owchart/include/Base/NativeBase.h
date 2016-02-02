/*****************************************************************************\
*                                                                             *
* NativeBase.h -Base functions, types, and definitions                        *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*               Check right 2016/9/17 by Todd.                                *
*                                                                             *
*******************************************************************************/

#ifndef __NATIVEBASE_H__
#define __NATIVEBASE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "Control.h"
#include "CStr.h"
#include "CPaint.h"
#include "CMathLib.h"
#include "GdiPaint.h"
#include "GdiPlusPaint.h"
#include "ControlHost.h"
#include "WinformControlHost.h"

namespace OwLib
{
	typedef enum SORTTYPE
	{
		SORTTYPE_NONE,
		SORTTYPE_ASC,
		SORTTYPE_DESC
	};

	class ControlA;
	class ControlHost;
	class WinformControlHost;
	class NativeBase
	{
	private:
		bool m_allowScaleSize;
		SIZE m_displaySize;
		POINT m_drawBeginPoint;
		RECT m_dragBeginRect;
		ControlA *m_draggingControl;
		POINT m_dragStartOffset;
		ControlA *m_exportingControl;
		ControlA *m_focusedControl;
		ControlHost *m_host;
		float m_opacity;
		CPaint *m_paint;
		ControlA *m_mouseDownControl;
		POINT m_mouseDownPoint;
		ControlA *m_mouseMoveControl;
		wstring m_resourcePath;
		SIZE m_scaleSize;
		map<int, ControlA*> m_timers;
		ControlA* FindControl(const POINT& mp, vector<ControlA*> *controls);
		ControlA* FindControl(const wstring& name, vector<ControlA*> *controls);
		ControlA* FindWindow(ControlA *control);
		float GetPaintingOpacity(ControlA *control);
		wstring GetPaintingResourcePath(ControlA *control);
		bool GetSortedControls(ControlA *parent, vector<ControlA*> *sortedControls);
		void GetTabStopControls(ControlA *control, vector<ControlA*> *tabStopControls);
		bool IsPaintEnabled(ControlA *control);
		void RenderControls(const RECT& rect, vector<ControlA*> *controls, wstring resourcePath, float opacity);
		void SetCursor(ControlA *control);
		void SetPaint(int offsetX, int offsetY, const RECT& clipRect, wstring resourcePath, float opacity);
	public:
		vector<ControlA*> m_controls;
		NativeBase();
		virtual ~NativeBase();
		bool AllowScaleSize();
		void SetAllowScaleSize(bool allowScaleSize);
		CursorsA GetCursor();
		void SetCursor(CursorsA cursor);
		SIZE GetDisplaySize();
		void SetDisplaySize(SIZE displaySize);
		ControlA* GetFocusedControl();
		void SetFocusedControl(ControlA *focusedControl);
		ControlHost* GetHost();
		void SetHost(ControlHost *host);
		ControlA* GetHoveredControl();
		POINT GetMousePoint();
		float GetOpacity();
		void SetOpacity(float opacity);
		CPaint* GetPaint();
		void SetPaint(CPaint *paint);
		ControlA* GetPushedControl();
		wstring GetResourcePath();
		void SetResourcePath(const wstring& resourcePath);
		SIZE GetScaleSize();
		void SetScaleSize(SIZE scaleSize);
	public:
		void AddControl(ControlA *control);
		void BringToFront(ControlA *control);
		void CancelDragging();
		void ClearControls();
		int ClientX(ControlA *control);
		int ClientY(ControlA *control);
		bool ContainsControl(ControlA *control);
        void ExportToImage(const wstring& exportPath);
        void ExportToImage(const wstring& exportPath, ControlA *control);
		ControlA* FindControl(const POINT& mp);
		ControlA* FindControl(const POINT& mp, ControlA *parent);
		ControlA* FindControl(const wstring& name);
		vector<ControlA*> GetControls();
		void InsertControl(int index, ControlA *control);
		void Invalidate();
		void Invalidate(ControlA *control);
		bool OnChar(wchar_t key);
		void OnDoubleClick(MouseButtonsA button, int clicks, int delta);
		void OnKeyDown(char key);
		void OnKeyUp(char key);
		void OnMouseDown(MouseButtonsA button, int clicks, int delta);
		void OnMouseLeave(MouseButtonsA button, int clicks, int delta);
		void OnMouseMove(MouseButtonsA button, int clicks, int delta);
		void OnMouseUp(MouseButtonsA button, int clicks, int delta);
		void OnMouseWheel(MouseButtonsA button, int clicks, int delta);
		void OnPaint(const RECT& rect);
		void OnPreviewKeyDown(char key, bool *handle);
		void OnResize();
		void OnTimer(int timerID);
		void RemoveControl(ControlA *control);
		void SendToBack(ControlA *control);
		void SetAnchor(vector<ControlA*> *controls, SIZE oldSize);
		void SetDock(vector<ControlA*> *controls);
		void StartTimer(ControlA *control, int timerID, int interval);
		void StopTimer(int timerID);
		void Update();
	};
}
#endif