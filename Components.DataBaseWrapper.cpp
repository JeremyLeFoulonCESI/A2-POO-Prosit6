#include "pch.h"
#include "Components.DataBaseWrapper.h"


namespace Components {
	MySqlDataAdapter^ DataBaseWrapper::runQuery(String^ query) {
		MySqlConnection^ connection;
		try {
			connection = gcnew MySqlConnection(this->connection_str);
			connection->Open();
			MySqlCommand^ cmd = connection->CreateCommand();
			cmd->CommandText = query;
			return gcnew MySqlDataAdapter(cmd);
		}
		finally {
			if (connection != nullptr)
				connection->Close();
		}
	}
	bool DataBaseWrapper::runEdit(String^ cmd_str) {
		MySqlConnection^ connection;
		try {
			connection = gcnew MySqlConnection(this->connection_str);
			connection->Open();
			MySqlCommand^ cmd = connection->CreateCommand();
			cmd->CommandText = cmd_str;
			return cmd->ExecuteNonQuery() > 0;
		}
		finally {
			if (connection != nullptr)
				connection->Close();
		}
	}
	int DataBaseWrapper::last_inserted_id() {
		MySqlConnection^ connection;
		try {
			connection = gcnew MySqlConnection(this->connection_str);
			connection->Open();
			MySqlCommand^ cmd = connection->CreateCommand();
			cmd->CommandText = "select LAST_INSERT_ID()";
			Object^ o = cmd->ExecuteScalar();
			return Convert::ToInt32(o);
		}
		finally {
			if (connection != nullptr)
				connection->Close();
		}
	}

	DataBaseWrapper::DataBaseWrapper(String^ ip, String^ db, String^ user, String^ pwd) {
		this->connection_str = "server=" + ip + ";uid=" + user + ";pwd=" + pwd + ";database=" + db;
	}
	DataSet^ DataBaseWrapper::enumerate(String^ tableName) {
		String^ command_str = "select * from " + tableName;
		DataSet^ res = gcnew DataSet;
		this->runQuery(command_str)->Fill(res);
		return res;
	}
	int DataBaseWrapper::count(String^ tableName) {
		MySqlConnection^ connection;
		try {
			connection = gcnew MySqlConnection(this->connection_str);
			connection->Open();
			MySqlCommand^ cmd = connection->CreateCommand();
			cmd->CommandText = "select count(*) from " + tableName;
			Object^ res = cmd->ExecuteScalar();
			if (res != nullptr)
				return Convert::ToInt32(res);
			return -1;
		}
		finally {
			if (connection != nullptr)
				connection->Close();
		}
	}
	DataRow^ DataBaseWrapper::get(String^ tableName, int id) {
		String^ command_str = "select * from " + tableName + " where id = " + (gcnew Int32(id))->ToString();
		DataTable^ table = gcnew DataTable;
		this->runQuery(command_str)->Fill(table);
		if (!table->Rows->Count)
			return nullptr;
		return table->Rows[0];
	}
	int DataBaseWrapper::insert(String^ tableName, String^ columns, String^ values) {
		String^ command_str = "insert into " + tableName + " (" + columns + ") values (" + values + ")";
		bool success = this->runEdit(command_str);
		if (!success)
			return 0;
		return this->last_inserted_id();
	}
	bool DataBaseWrapper::update(String^ tableName, String^ assignments, int id) {
		String^ command_str = "update " + tableName + " set " + assignments + " where id = " + (gcnew Int32(id))->ToString();
		return this->runEdit(command_str);
	}
	bool DataBaseWrapper::remove(String^ tableName, int id) {
		String^ command_str = "delete from " + tableName + " where id = " + (gcnew Int32(id))->ToString();
		return this->runEdit(command_str);
	}
	List<DataRow^>^ DataBaseWrapper::select(String^ tableName, String^ columns) {
		String^ command_str = "select " + columns + " from " + tableName;
		DataTable^ table = gcnew DataTable;
		this->runQuery(command_str)->Fill(table);
		List<DataRow^>^ res = gcnew List<DataRow^>();
		for each (DataRow^ o in table->Rows) {
			res->Add(o);
		}
		return res;
	}
	List<int>^ DataBaseWrapper::search(String^ tableName, String^ condition) {
		String^ command_str = "select * from " + tableName + " where " + condition;
		DataTable^ table = gcnew DataTable;
		this->runQuery(command_str)->Fill(table);
		List<int>^ result = gcnew List<int>;
		for each (DataRow^ row in table->Rows) {
			result->Add(Convert::ToInt32(row->ItemArray[0]));
		}
		return result;
	}
}

