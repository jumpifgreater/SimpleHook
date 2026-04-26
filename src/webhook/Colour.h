#pragma once
#include <algorithm>

struct Colour
{
	int r, g, b;

	static int round(int v)
	{
		return std::clamp(v, 0, 255);
	}

	Colour(int r, int g, int b) 
	: r(round(r)), g(round(g)), b(round(b))
	{}

	static const Colour white;
	static const Colour& WHITE;
	static const Colour lightGray;
	static const Colour& LIGHT_GRAY;
	static const Colour gray;
	static const Colour& GRAY;
	static const Colour darkGray;
	static const Colour& DARK_GRAY;
	static const Colour black;
	static const Colour& BLACK;
	static const Colour red;
	static const Colour& RED;
	static const Colour pink;
	static const Colour& PINK;
	static const Colour orange;
	static const Colour& ORANGE;
	static const Colour yellow;
	static const Colour& YELLOW;
	static const Colour green;
	static const Colour& GREEN;
	static const Colour magenta;
	static const Colour& MAGENTA;
	static const Colour cyan;
	static const Colour& CYAN;
	static const Colour blue;
	static const Colour& BLUE;
};

inline const Colour Colour::white = Colour(255, 255, 255);
inline const Colour& Colour::WHITE = Colour::white;
inline const Colour Colour::lightGray = Colour(192, 192, 192);
inline const Colour& Colour::LIGHT_GRAY = Colour::lightGray;
inline const Colour Colour::gray = Colour(128, 128, 128);
inline const Colour& Colour::GRAY = Colour::gray;
inline const Colour Colour::darkGray = Colour(64, 64, 64);
inline const Colour& Colour::DARK_GRAY = Colour::darkGray;
inline const Colour Colour::black = Colour(0, 0, 0);
inline const Colour& Colour::BLACK = Colour::black;
inline const Colour Colour::red = Colour(255, 0, 0);
inline const Colour& Colour::RED = Colour::red;
inline const Colour Colour::pink = Colour(255, 175, 175);
inline const Colour& Colour::PINK = Colour::pink;
inline const Colour Colour::orange = Colour(255, 200, 0);
inline const Colour& Colour::ORANGE = Colour::orange;
inline const Colour Colour::yellow = Colour(255, 255, 0);
inline const Colour& Colour::YELLOW = Colour::yellow;
inline const Colour Colour::green = Colour(0, 255, 0);
inline const Colour& Colour::GREEN = Colour::green;
inline const Colour Colour::magenta = Colour(255, 0, 255);
inline const Colour& Colour::MAGENTA = Colour::magenta;
inline const Colour Colour::cyan = Colour(0, 255, 255);
inline const Colour& Colour::CYAN = Colour::cyan;
inline const Colour Colour::blue = Colour(0, 0, 255);
inline const Colour& Colour::BLUE = Colour::blue;