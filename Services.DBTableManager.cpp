#include "pch.h"
#include "Services.DBTableManager.h"


namespace Services {
	DBTableManager::DBTableManager(String^ table_name, Components::DataBaseWrapper^ db) :
		table_name(table_name), database(db)
	{}
	int DBTableManager::count() {
		return this->database->count(this->table_name);
	}
	DataSet^ DBTableManager::enumerate() {
		return this->database->enumerate(this->table_name);
	}
	bool DBTableManager::remove(int id) {
		return this->database->remove(this->table_name, id);
	}
}

