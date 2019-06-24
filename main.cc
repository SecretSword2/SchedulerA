#include <iostream>
#include <array>

#define FRAMESIZE 10

std::array<char, FRAMESIZE> getFrame() {
	std::array<char, FRAMESIZE> frame = std::array<char, FRAMESIZE>();
	frame[0] = 'A';
	frame[8] = 'Z';
	return frame;
}

void decFrame(std::array<char, FRAMESIZE> frame, int i) {
	char& data = frame.at(i);
	std::cout << data << std::endl;
}

int main(int argc, char const *argv[]) {
	std::array<char, FRAMESIZE> frame;
	frame = getFrame();
	for (int i = 0; i < FRAMESIZE; i++) {
		decFrame(frame, i);
	}
	
	return 0;
}
