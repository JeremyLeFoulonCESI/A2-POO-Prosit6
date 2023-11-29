#pragma once
#include "Services.DBTableManager.h"


namespace Services {
	using namespace System::Collections::Generic;

	ref class DBClientManager : public DBTableManager
	{
	public:
		DBClientManager(Components::DataBaseWrapper^ db);
		int add(String^ fname, String^ lname, int delivery, int facturation);
		bool set(int id, String^ fname, String^ lname, int delivery, int facturation);
		String^ getFName(int id);
		String^ getLName(int id);
		int getDeliveryID(int id);
		int getFacturationID(int id);
		List<int>^ search(String^ fname, String^ lname);
	};
}

