/**
 * Appcelerator Titanium - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2009 Appcelerator, Inc. All Rights Reserved.
 */
#ifndef _MENU_H_
#define _MENU_H_
#include <kroll/kroll.h>
namespace ti
{
	class Menu : public StaticBoundObject
	{
	public:
		// Platform-independent implementation
		Menu();
		~Menu();

		void _AppendItem(const ValueList& args, SharedValue result);
		void _GetItemAt(const ValueList& args, SharedValue result);
		void _InsertItemAt(const ValueList& args, SharedValue result);
		void _RemoveItemAt(const ValueList& args, SharedValue result);
		void _GetLength(const ValueList& args, SharedValue result);
		void _Clear(const ValueList& args, SharedValue result);

		void Menu::AppendItem(SharedMenuItem item);
		SharedMenuItem Menu::GetItemAt(size_t index);
		void Menu::InsertItemAt(SharedMenuItem item, size_t index);
		void Menu::RemoveItemAt(size_t index);

		// Platform-specific implementation
		virtual void AppendItemImpl(SharedMenuItem item) = 0;
		virtual void InsertItemAtImpl(SharedMenuItem item, unsigned int index) = 0;
		virtual void RemoveItemAtImpl(unsigned int index) = 0;
		virtual void ClearImpl() = 0;

	protected:
		std::vector<SharedMenuItem> children;
	};
}
#endif