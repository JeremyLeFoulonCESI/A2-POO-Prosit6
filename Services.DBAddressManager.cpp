#include "pch.h"
#include "Services.DBAddressManager.h"


namespace Services {
	DBAddressManager::DBAddressManager(Components::DataBaseWrapper^ db) :
		DBTableManager("Addresses", db)
	{}

	int DBAddressManager::add(String^ streetNumber, String^ street, String^ city, int postalCode) {
		return this->database->insert(
			this->table_name,
			"street_number, street, city, postal_code",
			"\"" + streetNumber + "\", \"" + street + "\", \"" + city + "\", " + Convert::ToString(postalCode)
		);
	}
	bool DBAddressManager::set(int id, String^ streetNumber, String^ street, String^ city, int postalCode) {
		return this->database->update(
			this->table_name,
			"street_number = \"" + streetNumber + "\", street = \"" + street + "\", city = \"" + city + \
				"\", postal_code = " + Convert::ToString(postalCode),
			id
		);
	}
	String^ DBAddressManager::getStreetNumber(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[1];
		return Convert::ToString(o);
	}
	String^ DBAddressManager::getStreet(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[2];
		return Convert::ToString(o);
	}
	String^ DBAddressManager::getCity(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[3];
		return Convert::ToString(o);
	}
	int DBAddressManager::getPostalCode(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[3];
		return Convert::ToInt32(o);
	}
	List<int>^ DBAddressManager::search(String^ streetNumber, String^ street, String^ city, int postalCode) {
		String^ condition = "street_number = \"" + streetNumber + "\", street = \"" + street + "\", city = \"" + city + "\", postalCode = " + \
			Convert::ToString(postalCode);
		return this->database->search(
			this->table_name,
			condition
		);
	}

}

