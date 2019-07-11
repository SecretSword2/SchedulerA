#include <iostream>
#include <vector>
#include <map>

// Codes
#define ATTACH 'A'
#define DETACH 'D'

class NE{
public:
	virtual void in(char) = 0;
	virtual char out() = 0;
	virtual void tick() = 0;
};

class UE : NE {
private:
	int tock = 0;
	int id;
public:
	UE (int id) {
		this->id = id;
	}
	
	void in(char in) {
#ifdef DEBUG
		std::cout << "UE " << id << " << " << in << std::endl;
#endif
	};
	
	char out() {
		char buff = '\0';
#ifdef DEBUG
		std::cout << "UE " << id << " >> " << buff << std::endl;
#endif
		return buff;
	};
	
	void tick() {
		tock++;
	}
};

class NodeL : NE {
private:
	int id;
	std::vector<UE> ue;
	std::map<char, char> idMap;
	int tock = 0;

public:
	NodeL(int id) {
		this->id = id;
	};
	
	char out() {
		char buff = '\0';
		// Something
#ifdef DEBUG
		std::cout << "NodeL " << id << " >> " << buff << std::endl;
#endif
		return buff;
	};

	void in(char in) {
#ifdef DEBUG
		std::cout << "NodeL " << id << " << " << in << std::endl;
#endif

	};

	void tick() {
		this->tock++;
	}
};
