#pragma once
class cFLUIDO {
protected:
	unsigned int volumen;
public:
	cFLUIDO(unsigned int volumen);
	~cFLUIDO();

	void set_volumen(unsigned int volumen);
	unsigned int get_volumen();
};