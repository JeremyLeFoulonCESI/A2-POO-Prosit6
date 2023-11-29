#pragma once
#include "Services.DBTableManager.h"

namespace Services {
	using namespace System::Collections::Generic;
	ref class DBAddressManager : public DBTableManager
	{
	public:
		DBAddressManager(Components::DataBaseWrapper^ db);
		int add(String^ streetNumber, String^ street, String^ city, int postalCode);
		bool set(int id, String^ streetNumber, String^ street, String^ city, int postalCode);
		String^ getStreetNumber(int id);
		String^ getStreet(int id);
		String^ getCity(int id);
		int getPostalCode(int id);
		List<int>^ search(String^ streetNumber, String^ street, String^ city, int postalCode);
	};
}

