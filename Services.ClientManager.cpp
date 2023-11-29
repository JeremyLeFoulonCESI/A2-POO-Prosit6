#include "pch.h"
#include "Services.ClientManager.h"
#include "MysqlPassword.h"


namespace Services {
	using namespace System::Collections::Generic;
	using namespace MySql::Data::MySqlClient;

	const char* user = "root";
	const char* ip = "127.0.0.1";
	const char* db_name = "a2_poo_prosit6";

	ClientManager::ClientManager() {
		Components::DataBaseWrapper^ db = gcnew Components::DataBaseWrapper(
			gcnew String(ip),
			gcnew String(db_name),
			gcnew String(user),
			gcnew String(mysql_password)
		);
		this->clients = gcnew DBClientManager(db);
		this->addresses = gcnew DBAddressManager(db);
		this->database = db;
	}

	String^ ClientManager::getFirstName(int id_client) {
		return this->clients->getFName(id_client);
	}

	String^ ClientManager::getLastName(int id_client) {
		return this->clients->getLName(id_client);
	}
	
	Address ClientManager::getDeliveryAddress(int id_client) {
		int id_address = this->clients->getDeliveryID(id_client);
		return {
			this->addresses->getStreetNumber(id_address),
			this->addresses->getStreet(id_address),
			this->addresses->getCity(id_address),
			this->addresses->getPostalCode(id_address)
		};
	}

	Address ClientManager::getFacturationAddress(int id_client) {
		int id_address = this->clients->getFacturationID(id_client);
		return {
			this->addresses->getStreetNumber(id_address),
			this->addresses->getStreet(id_address),
			this->addresses->getCity(id_address),
			this->addresses->getPostalCode(id_address)
		};
	}

	int ClientManager::getClientCount() {
		return this->clients->count();
	}

	int ClientManager::addClient(String^ fname, String^ lname, Address delivery, Address facturation) {

		// create delivery address if it doesn't exist
		int delivery_id;
		List<int>^ found_deliveries = this->addresses->search(
			delivery.streetNumber, delivery.street, delivery.city, delivery.postalCode
		);
		if (found_deliveries && found_deliveries->Count) {
			delivery_id = found_deliveries[0];
		}
		else {
			delivery_id = this->addresses->add(delivery.streetNumber, delivery.street, delivery.city, delivery.postalCode);
		}

		// create facturation address if it doesn't exist
		int facturation_id;
		List<int>^ found_facturations = this->addresses->search(
			facturation.streetNumber, facturation.street, facturation.city, facturation.postalCode
		);
		if (found_deliveries && found_deliveries->Count) {
			facturation_id = found_facturations[0];
		}
		else {
			facturation_id = this->addresses->add(facturation.streetNumber, facturation.street, facturation.city, facturation.postalCode);
		}

		return this->clients->add(fname, lname, delivery_id, facturation_id);
	}

	bool ClientManager::editClient(int id_client, String^ fname, String^ lname, Address delivery, Address facturation) {
		// create delivery address if it doesn't exist
		int delivery_id;
		List<int>^ found_deliveries = this->addresses->search(
			delivery.streetNumber, delivery.street, delivery.city, delivery.postalCode
		);
		if (found_deliveries && found_deliveries->Count) {
			delivery_id = found_deliveries[0];
		}
		else {
			delivery_id = this->addresses->add(delivery.streetNumber, delivery.street, delivery.city, delivery.postalCode);
		}

		// create facturation address if it doesn't exist
		int facturation_id;
		List<int>^ found_facturations = this->addresses->search(
			facturation.streetNumber, facturation.street, facturation.city, facturation.postalCode
		);
		if (found_deliveries && found_deliveries->Count) {
			facturation_id = found_facturations[0];
		}
		else {
			facturation_id = this->addresses->add(facturation.streetNumber, facturation.street, facturation.city, facturation.postalCode);
		}

		return this->clients->set(id_client, fname, lname, delivery_id, facturation_id);
	}
	bool ClientManager::removeClient(int id_client) {
		return this->clients->remove(id_client);
	}
	DataSet^ ClientManager::enumerate() {
		String^ query = "select first_name as 'Prénom', last_name as 'Nom', delivery as 'Adresse de livraison', facturation as 'Adresse de facturation' from \
			( \
				select first_name, last_name, delivery, idb from \
				(select first_name, last_name, id_address_delivery as ida, id_address_facturing as idb from Clients) as _clients \
				cross join \
				(select id as ida, concat(street_number, \" rue \", street, \", \", postal_code, \" \", city) as delivery from Addresses) as _delivery_str \
				on _clients.ida = _delivery_str.ida \
				) as _delivery_list \
			cross join \
			(select*, id as idb, concat(street_number, \" rue \", street, \", \", postal_code, \" \", city) as facturation from Addresses) as _facturing_str \
			on _delivery_list.idb = _facturing_str.idb; ";

		MySqlDataAdapter^ adapter = this->database->runQuery(query);
		DataSet^ data = gcnew DataSet;
		adapter->Fill(data);
		return data;
	}

}

