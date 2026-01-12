#include "Serialize.hpp"

int main()
{
	Data database;

	database.name = "Soulaymane Ouaourikt";
	database.username = "souaouri";
	database.age = 20;
	database.level = 9;

	uintptr_t raw;
	Data *db;

	raw = Serialize::serialize(&database);
	db = Serialize::deserialize(raw);

	std::cout << "name : " << db->name << std::endl;
	std::cout << "username : " << db->username << std::endl;
	std::cout << "age : " << db->age << std::endl;
	std::cout << "level : " << db->level << std::endl;
}