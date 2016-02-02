/*****************************************************************************\
*                                                                             *
* CDiv.h -      Chart div functions, types, and definitions                   *
*                                                                             *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                       *
*                                                                             *
*               Copyright (c) 2016-2016, Todd's OwChart. All rights reserved. *
*                                                                             *
*******************************************************************************/

#ifndef __CDIV_H__
#define __CDIV_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Base\\CPaint.h"
#include "Enums.h"
#include "CrossLine.h"
#include "ScaleGrid.h"
#include "Chart.h"
#include "VScale.h"
#include "SelectArea.h"
#include "CToolTip.h"
#include "TitleBar.h"
#include "HScale.h"
#include "CPlot.h"
#include "BaseShape.h"

namespace OwLib
{
	class ChartA;
	class CPlot;
	class BaseShape;
	class NativeBase;
	class CDiv : public CProperty
	{
	private:
		vector<CPlot*> m_plots;
		vector<BaseShape*> m_shapes;
		_int64 m_backColor;
		_int64 m_borderColor;
		CrossLine *m_crossLine;
		FONT *m_font;
		ScaleGrid *m_hGrid;
		HScale *m_hScale;
		ChartA *m_chart;
		POINT m_location;
		VScale *m_leftVScale;
		int m_px;
		int m_py;
		VScale *m_rightVScale;
		SelectArea *m_selectArea;
		bool m_selected;
		bool m_showSelect;
		TitleBar *m_title;
		CToolTip *m_toolTip;
		int m_verticalPercent;
		ScaleGrid *m_vGrid;
		int m_workingAreaHeight;
		SIZE m_size;
	public:
		static bool ShapesAsc(BaseShape *x, BaseShape *y);
		static bool ShapesDesc(BaseShape *x, BaseShape *y);
		static bool PlotsAsc(CPlot *x, CPlot *y);
		static bool PlotsDesc(CPlot *x, CPlot *y);
	public:
		CDiv();
		virtual ~CDiv();
		_int64 GetBackColor();
		void SetBackColor(_int64 backColor);
		_int64 GetBorderColor();
		void SetBorderColor(_int64 borderColor);
		int GetBottom();
		RECT GetBounds();
		void SetBounds(RECT bounds);
		CrossLine* GetCrossLine();
		FONT* GetFont();
		void SetFont(FONT *font);
		int GetHeight();
		ScaleGrid* GetHGrid();
		HScale* GetHScale();
		ChartA* GetChart();
		void SetChart(ChartA *chart);
		int GetLeft();
		VScale* GetLeftVScale();
		POINT GetLocation();
		int GetPx();
		void SetPx(int px);
		int GetPy();
		void SetPy(int py);
		int GetRight();
		VScale* GetRightVScale();
		SelectArea* GetSelectArea();
		bool IsSelected();
		void SetSelected(bool selected);
		bool IsShowSelect();
		void SetShowSelect(bool showSelect);
		TitleBar* GetTitleBar();
		CToolTip* GetToolTip();
		int GetTop();
		int GetVerticalPercent();
		void SetVerticalPercent(int verticalPercent);
		int GetWidth();
		ScaleGrid* GetVGrid();
		int GetWorkingAreaHeight();
		void SetWorkingAreaHeight(int workingAreaHeight);
	public:
		void AddPlot(CPlot *plot);
		void AddShape(BaseShape *shape);
		bool ContainsShape(BaseShape *shape);
		vector<CPlot*> GetPlots(SORTTYPE sortType);
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		vector<BaseShape*> GetShapes(SORTTYPE sortType);
		VScale* GetVScale(AttachVScale attachVScale);
		void RemovePlot(CPlot *plot);
		void RemoveShape(BaseShape *shape);
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}
#endif