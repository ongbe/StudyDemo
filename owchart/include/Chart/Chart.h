/*****************************************************************************\
*                                                                             *  
* Chart.h -     Chart functions, types, and definitions                       *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __CHART_H__
#define __CHART_H_
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CStr.h"
#include "..\\Base\\CMathLib.h"
#include "CTable.h"
#include "CDiv.h"
#include "CPlot.h"
#include "BaseShape.h"
#include "VScale.h"

namespace OwLib
{
	class CDiv;
	class CPlot;
	class BaseShape;
	class BarShape;
	class PointShape;
	class CandleShape;
	class PolylineShape;
	class TextShape;
	class ControlA;
	class ChartA:public ControlA
	{
	private:
		bool m_autoFillHScale;
		int m_blankSpace;
		bool m_canMoveShape;
		bool m_canResizeV;
		bool m_canResizeH;
		bool m_canScroll;
		bool m_canZoom;
		CrossLineMoveMode m_crossLineMoveMode;
		int m_crossStopIndex;
		int m_cross_y;
		CTable *m_dataSource;
		vector<CDiv*> m_divs;
		int m_firstVisibleIndex;
		int m_hResizeType;
		wstring m_hScaleFieldText;
		double m_hScalePixel;
		bool m_isMouseMove;
		bool m_isScrollCross;
		POINT m_lastMouseMovePoint;
		POINT m_lastMouseClickPoint;
		double m_lastMouseMoveTime;
		bool m_lastRecordIsVisible;
		int m_lastUnEmptyIndex;
		double m_lastVisibleKey;
		int m_lastVisibleIndex;
		int m_leftVScaleWidth;
		int m_maxVisibleRecord;
		CPlot *m_movingPlot;
		BaseShape *m_movingShape;
		bool m_reverseHScale;
		int m_rightVScaleWidth;
		bool m_scrollAddSpeed;
		int m_scrollStep;
		bool m_showCrossLine;
		bool m_showingSelectArea;
		bool m_showingToolTip;
		int m_timerID;
		int m_tooltip_dely;
		CDiv *m_userResizeDiv;
		int m_workingAreaWidth;
		///////////////////////////////////////////////////////////////////////////////////////////////////
		void DrawThinLine(CPaint *paint, _int64 dwPenColor, int width, int x1, int y1, int x2, int y2);
		void DrawText(CPaint *paint, LPCWSTR strText, _int64 dwPenColor,FONT *font, int left, int top);
		vector<double> GetVScaleStep(double max, double min, CDiv *div, VScale *vScale);
		void OnPaintBar(CPaint *paint, CDiv *div, BarShape *bs);
		void OnPaintCandle(CPaint *paint, CDiv *div, CandleShape *cs);
		void OnPaintCandleEx(CPaint *paint, CDiv *div, CandleShape *cs, int visibleMaxIndex, double visibleMax, int visibleMinIndex, double visibleMin);
		void OnPaintCrossLine(CPaint *paint, CDiv *div);
		void OnPaintDivBackGround(CPaint *paint, CDiv *div);
		void OnPaintDivBorder(CPaint *paint, CDiv *div);
		void OnPaintHScale(CPaint *paint, CDiv *div);
		void OnPaintIcon(CPaint *paint);
		void OnPaintPlots(CPaint *paint, CDiv *div);
		void OnPaintPolyline(CPaint *paint, CDiv *div, PolylineShape *ls);
		void OnPaintPolyline(CPaint *paint, CDiv *div, _int64 lineColor, _int64 fillColor, int ciClr,
				int lineWidth, PolylineStyle lineStyle, double value, AttachVScale attachVScale,
				int scaleX, int lY, int i, vector<POINT> *points, int *x, int *y);
		void OnPaintResizeLine(CPaint *paint);
		void OnPaintSelectArea(CPaint *paint, CDiv *div);
		void OnPaintShapes(CPaint *paint, CDiv *div);
		void OnPaintText(CPaint *paint, CDiv *div, TextShape *ts);
		void OnPaintTitle(CPaint *paint, CDiv *div);
		void OnPaintToolTip(CPaint *paint);
		void OnPaintVScale(CPaint *paint, CDiv *div);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void CorrectVisibleRecord(int dataCount, int *first, int *last);
		void GetCandleMaxStringPoint(float scaleX, float scaleY, float stringWidth, float stringHeight, int actualWidth,
		int leftVScaleWidth, int rightVScaleWidth, float *x, float *y);
		void GetCandleMinStringPoint(float scaleX, float scaleY, float stringWidth, float stringHeight, int actualWidth,
		int leftVScaleWidth, int rightVScaleWidth, float *x, float *y);
		int GetChartIndex(int x, int leftScaleWidth, double hScalePixel, int firstVisibleIndex);
		float GetUpCandleHeight(double close, double open, double max, double min, float divPureV);
		float GetDownCandleHeight(double close, double open, double max, double min, float divPureV);
		void ScrollLeft(int step, int dateCount, double hScalePixel, int pureH, int *fIndex, int *lIndex);
		void ScrollRight(int step, int dataCount, double hScalePixel, int pureH, int *fIndex, int *lIndex);
		double GetVScaleValue(int y, double max, double min, float vHeight);
		int ResetCrossOverIndex(int dataCount, int maxVisibleRecord, int crossStopIndex, int firstL, int lastL);
		void ZoomIn(int pureH, int dataCount, int *findex, int *lindex, double *hScalePixel);
		void ZoomOut(int pureH,int dataCount, int *findex, int *lindex, double *hScalePixel);
	public:
		ChartA();
		virtual ~ChartA();
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool AutoFillHScale();
		void SetAutoFillHScale(bool autoFillHScale);
		int GetBlankSpace();
		void SetBlankSpace(int blankSpace);
		bool CanMoveShape();
		void SetCanMoveShape(bool canMoveShape);
		bool CanResizeV();
		void SetCanResizeV(bool canResizeV);
		bool CanResizeH();
		void SetCanResizeH(bool canResizeH);
		bool CanScroll();
		void SetCanScroll(bool canScroll);
		bool CanZoom();
		void SetCanZoom(bool canZoom);
		CrossLineMoveMode GetCrossLineMoveMode();
		void SetCrossLineMoveMode(CrossLineMoveMode crossLineMoveMode);
		int GetCrossStopIndex();
		void SetCrossStopIndex(int crossStopIndex);
		CTable* GetDataSource();
		void SetDataSource(CTable *dataSource);
		int GetFirstVisibleIndex();
		void SetFirstVisibleIndex(int firstVisibleIndex);
		wstring GetHScaleFieldText();
		void SetHScaleFieldText(const wstring& hScaleFieldText);
		double GetHScalePixel();
		void SetHScalePixel(double hScalePixel);
		int GetLastVisibleIndex();
		void SetLastVisibleIndex(int lastVisibleIndex);
		int GetLeftVScaleWidth();
		void SetLeftVScaleWidth(int leftVScaleWidth);
		int GetMaxVisibleRecord();
		void SetMaxVisibleRecord(int maxVisibleRecord);
		CPlot* GetMovingPlot();
		BaseShape* GetMovingShape();
		bool IsReverseHScale();
		void SetReverseHScale(bool reverseHScale);
		int GetRightVScaleWidth();
		void SetRightVScaleWidth(int rightVScaleWidth);
		bool IsScrollAddSpeed();
		void SetScrollAddSpeed(bool scrollAddSpeed);
		BaseShape* GetSelectedShape();
		void SetSelectedShape(BaseShape *baseShape);
		CPlot* GetSelectedPlot();
		void SetSelectedPlot(CPlot *selectedPlot);
		CDiv* GetSelectedDiv();
		void SetSelectedDiv(CDiv *selectedDiv);
		bool IsShowCrossLine();
		void SetShowCrossLine(bool showCrossLine);
		int GetWorkingAreaWidth();
	public:
		CDiv* AddDiv(int vPercent);
		CDiv* AddDiv();
		void Adjust();
		void AddPlot(CPlot *bpl, const POINT& mp, CDiv *div);
		void Clear();
		void ChangeChart(ScrollType scrollType, int limitStep);
		void CheckLastVisibleIndex();
		void CheckToolTip();
		void ClearSelectedShape();
		void ClearSelectedPlot();
		void ClearSelectedDiv();
		void CloseSelectArea();
		double DivMaxOrMin(int index, CDiv *div, int flag);
		CDiv* FindDiv(const POINT& mp);
		CDiv* FindDiv(BaseShape *shape);
		virtual wstring GetControlType();
		int GetDateType(DateType dateType);
		DateType GetDateType(int dateType);
		vector<CDiv*> GetDivs();
		void GetHScaleDateString(double date, double lDate, DateType *dateType, wchar_t *str);
		int GetIndex(const POINT& mp);
		int GetMaxVisibleCount(double hScalePixel, int pureH);
		CDiv* GetMouseOverDiv();
		int GetMouseOverIndex();
		double GetNumberValue(CDiv *div, const POINT& mp, AttachVScale attachVScale);
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		int GetShapesCount(int field);
		float GetX(int index);
		float GetY(CDiv *div,double value,AttachVScale attach);
		int GetVScaleBaseField(CDiv *div, VScale *vScale);
		double GetVScaleBaseValue(CDiv *div, VScale *vScale, int i);
		virtual bool IsOperating();
		void LocateCrossLine();
		void MoveShape(CDiv *div, BaseShape *shape);
		void ResetCrossOverIndex();
		void RemoveAll();
		bool ResizeDiv();
		void RemoveDiv(CDiv *div);
		void Reset();
		void ResetVisibleRecord();
		void ScrollLeft(int step);
		void ScrollLeftToBegin();
		void ScrollRight(int step);
		void ScrollRightToEnd();
		void ScrollCrossLineLeft(int step);
		void ScrollCrossLineRight(int step);
		BaseShape* SelectShape(int curIndex, int state);
		bool ChartA::SelectBar(CDiv *div, float mpY, int fieldName, int fieldName2, int styleField, AttachVScale attachVScale, int curIndex);
		bool SelectCandle(CDiv *div, float mpY, int highField, int lowField, int styleField, AttachVScale attachVScale, int curIndex);
		bool SelectPolyline(CDiv *div, const POINT& mp, int fieldName, int lineWidth, AttachVScale attachVScale, int curIndex);
		virtual void SetProperty(const wstring& name, const wstring& value);
		void SetVisibleIndex(int firstVisibleIndex, int lastVisibleIndex);
		virtual void Update();
		void ZoomIn();
		void ZoomOut();
	public:
		virtual void OnKeyDown(char key);
		virtual void OnLoad();
		virtual void OnMouseDown(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnMouseMove(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnMouseUp(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnMouseWheel(const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnKeyUp(char key);
		virtual void OnPaintForeground(CPaint *paint, const RECT& clipRect);
		virtual void OnTimer(int timerID);
	};
}
#endif