#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
	int rowPosition;
	int colPosition;
public:
	Position();
	int getRowPosition()const;
	int getColPosition()const;
	void setRowPosition(int);
	void setColPosition(int);
	
};

#endif
