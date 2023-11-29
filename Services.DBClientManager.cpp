#include "pch.h"
#include "Services.DBClientManager.h"


namespace Services {
	DBClientManager::DBClientManager(Components::DataBaseWrapper^ db) :
		DBTableManager("Clients", db)
	{}
	int DBClientManager::add(String^ fname, String^ lname, int delivery, int facturation) {
		return this->database->insert(
			this->table_name,
			"first_name, last_name, id_address_delivery, id_address_facturation",
			"\"" + fname + "\", \"" + lname + "\", " + Convert::ToString(delivery) + ", " + Convert::ToString(facturation)
		);
	}
	bool DBClientManager::set(int id, String^ fname, String^ lname, int delivery, int facturation) {
		return this->database->update(
			this->table_name,
			"first_name = \"" + fname + "\", last_name = \"" + lname + "\", id_address_delivery = " + Convert::ToString(delivery) + \
				", id_address_facturation = " + Convert::ToString(facturation),
			id
		);
	}
	String^ DBClientManager::getFName(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[1];
		return Convert::ToString(o);
	}
	String^ DBClientManager::getLName(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[2];
		return Convert::ToString(o);
	}
	int DBClientManager::getDeliveryID(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[3];
		return Convert::ToInt32(o);
	}
	int DBClientManager::getFacturationID(int id) {
		DataRow^ row = this->database->get(this->table_name, id);
		Object^ o = row->ItemArray[4];
		return Convert::ToInt32(o);
	}
	List<int>^ DBClientManager::search(String^ fname, String^ lname) {
		return this->database->search(
			this->table_name,
			"first_name = \"" + fname + "\", last_name = \"" + lname + "\""
		);
	}
}

