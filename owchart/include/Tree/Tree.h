/*********************************************************************************\
*                                                                                 *
* Tree.h -      Tree functions, types, and definitions                            *
*                                                                                 *
*               Version 4.00 ¡ï¡ï¡ï¡ï¡ï                                           *
*                                                                                 *
*               Copyright (c) 2016-2016, Todd's true. All rights reserved.        *
*               Check 2016/9/23 by Todd.                                          *
*                                                                                 *
***********************************************************************************/

#ifndef __TREE_H__
#define __TREE_H__
#pragma once
#include "..\\..\\stdafx.h"
#include "..\\Grid\\Grid.h"
#include "..\\Grid\\GridColumn.h"
#include "..\\Grid\\GridRow.h"
#include "..\\Grid\\GridCell.h"
#include "..\\Grid\\GridCellExtends.h"
#include "TreeNode.h"

namespace OwLib
{
	class TreeNodeA;

	class TreeA:public GridA
	{
	private:
		bool m_checkBoxes;
		SIZE m_checkBoxSize;
		wstring m_checkedImage;
		wstring m_collapsedNodeImage;
		wstring m_expendedNodeImage;
		TreeNodeA *m_movingNode;
		SIZE m_nodeSize;
		wstring m_unCheckedImage;
	public:
		vector<TreeNodeA*> m_nodes;
		TreeA();
		virtual ~TreeA();
		bool HasCheckBoxes();
		void SetCheckBoxes(bool checkBoxes);
		SIZE GetCheckBoxSize();
		void SetCheckBoxSize(SIZE checkBoxSize);
		wstring GetCheckedImage();
		void SetCheckedImage(const wstring& checkedImage);
		wstring GetCollapsedNodeImage();
		void SetCollapsedNodeImage(const wstring& collapsedNodeImage);
		wstring GetExpendedNodeImage();
		void SetExpendedNodeImage(const wstring& expendedNodeImage);
		SIZE GetNodeSize();
		void SetNodeSize(SIZE nodeSize);
		wstring GetUnCheckedImage();
		void SetUnCheckedImage(const wstring& unCheckedImage);
	public:
		void AppendNode(TreeNodeA *node);
		void ClearNodes();
		vector<TreeNodeA*> GetChildNodes();
		virtual wstring GetControlType();
		int GetNodeIndex(TreeNodeA *node);
		virtual void GetProperty(const wstring& name, wstring *value, wstring *type);
		virtual vector<wstring> GetPropertyNames();
		void InsertNode(int index, TreeNodeA *node);
		virtual void OnCellMouseDown(GridCell *cell, const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnCellMouseMove(GridCell *cell, const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnCellMouseUp(GridCell *cell, const POINT& mp, MouseButtonsA button, int clicks, int delta);
		virtual void OnPaintForeground(CPaint *paint, const RECT& clipRect);
		virtual void OnPaintEditTextBox(GridCell *cell, CPaint *paint, const RECT& rect, const RECT& clipRect);
		void RemoveNode(TreeNodeA *node);
		virtual void SetProperty(const wstring& name, const wstring& value);
	};
}

#endif