#include <iostream>
#include <array>

#define FRAMESIZE 10

#define HEADER 'H'
#define REQUEST 'Q'

std::array<char, FRAMESIZE> getFrame() {
	std::array<char, FRAMESIZE> frame = std::array<char, FRAMESIZE>();
	frame[0] = HEADER;
	frame[8] = REQUEST;
	return frame;
}

void decFrame(std::array<char, FRAMESIZE> frame, int i) {
	char& data = frame.at(i);
	std::cout << data << std::endl;
}

class UE {
private:
	int givenSlot;
	int currentSlot ;
	bool canSend;
	bool isJoined;
	char data;
	char sendBuff;

public:
	void listen(char data) {
		std::cout << "UE< " <<  data << std::endl;
		currentSlot = (data == HEADER) ? 0 : currentSlot  + 1;
		std::cout << currentSlot << std::endl;
		if (isJoined) {
			if (currentSlot == givenSlot) {
				this->data = data;
				canSend = true;
			}
		} else {
			if (data == REQUEST) {
				canSend = true;
			}
		}
	}

	void join() {
		if (!isJoined)
			sendBuff = REQUEST;
	}

	void calc() {
		sendBuff = 'S';
	}

	char send() {
		if (!isJoined)
			join();
		if (canSend)
			return sendBuff;
	}
};

int main(int argc, char const *argv[]) {
	std::array<char, FRAMESIZE> frame;
	frame = getFrame();
	
	UE* ue = new UE();

	for (int i = 0; i < FRAMESIZE; i++) {
		char& data = frame.at(i);
		ue->listen(data);
		std::cout << "UE> " << ue->send() << std::endl;
	}

	free(ue);
	
	return 0;
}
