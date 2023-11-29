#pragma once
#include "Components.DataBaseWrapper.h"


namespace Services {
	using namespace System;
	using namespace System::Data;

	ref class DBTableManager
	{
	protected:
		String^ table_name;
		Components::DataBaseWrapper^ database;

		DBTableManager(String^ table_name, Components::DataBaseWrapper^ db);

	public:
		int count();
		DataSet^ enumerate();
		bool remove(int id);
	};
}

