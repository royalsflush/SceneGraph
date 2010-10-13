#ifndef SWITCH_H
#define SWITCH_H

class Switch {
	int lightMask;	
	static Switch* curr;

	public:
	Switch();
	static Switch* getCurr();
	void setCurr(Switch* s);
	void turnOn(int index);
	void turnOff(int index);
	bool isOn(int index);
	static void handleKeys(unsigned char k, int x, int y);
};

#endif /* SWITCH_H */
