

namespace Components {
	using namespace System;
	using namespace System::Data;
	using namespace System::Collections::Generic;
	using namespace MySql::Data::MySqlClient;

#pragma once
	ref class DataBaseWrapper
	{
		String^ connection_str;
		
		bool runEdit(String^ cmd);
		int last_inserted_id();

	public:
		DataBaseWrapper(String^ ip, String^ db, String^ user, String^ pwd);
		MySqlDataAdapter^ runQuery(String^ cmd);
		DataSet^ enumerate(String^ tableName);
		DataRow^ get(String^ tableName, int id);
		int count(String^ tableName);
		int insert(String^ tableName, String^ columns, String^ values);
		bool update(String^ tableName, String^ assignments, int id);
		bool remove(String^ tableName, int id);
		List<DataRow^>^ select(String^ tableName, String^ columns);
		List<int>^ search(String^ tableName, String^ condition);
	};

}

