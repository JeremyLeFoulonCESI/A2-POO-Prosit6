#pragma once
#include "Services.DBClientManager.h"
#include "Services.DBAddressManager.h"


namespace Services {
	value struct Address {
		String^ streetNumber;
		String^ street;
		String^ city;
		int postalCode;
	};


	ref class ClientManager
	{
		DBClientManager^ clients;
		DBAddressManager^ addresses;
		Components::DataBaseWrapper^ database;

	public:
		ClientManager();
		String^ getFirstName(int id_client);
		String^ getLastName(int id_client);
		Address getDeliveryAddress(int id_client);
		Address getFacturationAddress(int id_client);
		int getClientCount();
		int addClient(String^ fname, String^ lname, Address delivery, Address facturation);
		bool editClient(int id_client, String^ fname, String^ lname, Address delivery, Address facturation);
		bool removeClient(int id_client);
		DataSet^ enumerate();
	};
}

