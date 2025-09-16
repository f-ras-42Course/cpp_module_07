#include <iostream>
#include <string>
#include <iomanip>
#include "iter.hpp"

// helpers
void banner(const std::string &x) {
	std::cout << "<<" << x << ">> ";
}

void cryMotto(const std::string &motto) {
	std::cout << '"' << motto << '"' << " -- For the realm! ";

}
void announceHouse(const std::string &house) {
	std::cout << "House " << house << ": ";
}

void lowerCaseName(std::string &name) {
	for (char &c : name) c = static_cast<char>(std::tolower(c));
}

void tallyHonor(int &honor) {
	honor += 10; // each deed grants 10 honor points
}

void decimate(int &n) {
	n = n > 0 ? n - 1 : 0; // lose one soldier
}


int main() {
	// Houses and mottos
	std::string houses[] = {"Stark", "Lannister", "Targaryen", "Greyjoy"};
	size_t total_houses = sizeof(houses) / sizeof(houses[0]);

	std::cout << "Banners raised: ";
	iter(houses, total_houses, banner);
	std::cout << '\n';

	std::string mottos[] = {"Winter is Coming", "Hear Me Roar", "Fire and Blood", "We Do Not Sow"};
	size_t total_motos = sizeof(mottos) / sizeof(mottos[0]);
	std::cout << "Mottos: ";
	iter(mottos, total_motos, cryMotto);
	std::cout << '\n';

	// Soldiers count per house (mutable)
	int soldiers[] = {500, 1200, 300, 450};
	size_t total_soldiers = sizeof(soldiers) / sizeof(soldiers[0]);
	std::cout << "Soldiers initially: ";
	iter(soldiers, total_soldiers, [](int x){ std::cout << x << ' '; });
	std::cout << '\n';

	// A battle: lose one soldier per house
	iter(soldiers, total_soldiers, decimate);
	std::cout << "After skirmish: ";
	iter(soldiers, total_soldiers, [](int x){ std::cout << x << ' '; });
	std::cout << '\n';

	// Honor points earned
	int honor[] = {0, 20, 5, 10};
	size_t total_honor = sizeof(honor) / sizeof(honor[0]);
	iter(honor, total_honor, tallyHonor);
	std::cout << "Honor tally: ";
	iter(honor, total_honor, [](int x){ std::cout << x << ' '; });
	std::cout << '\n';

	// Demonstrate lowercase conversion
	std::cout << "Houses lowercased: ";
	iter(houses, total_houses, lowerCaseName);
	iter(houses, total_houses, [](const std::string &s){ std::cout << s << ' '; });
	std::cout << '\n';

	return 0;
}
