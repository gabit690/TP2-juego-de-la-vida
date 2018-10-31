#ifndef SRC_COLOR_H_
#define SRC_COLOR_H_

class Color {
private:

	int red;
	int green;
	int blue;

public:
	Color(int red, int green, int blue);
	virtual ~Color();

	int getBlue() const;

	void setBlue(int blue);

	int getGreen() const;

	void setGreen(int green);

	int getRed() const;

	void setRed(int red);
};

#endif /* SRC_COLOR_H_ */
