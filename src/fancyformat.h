#ifndef FANCYFORMAT_H
#define FANCYFORMAT_H

#include <string>
using std::string;

namespace FancyFormat {
	extern const string RESET;

	extern const string BOLD;
	extern const string FAINT;
	extern const string ITALIC;
	extern const string UNDERLINE;
	extern const string STRIKE;
	extern const string DOUBLE_UNDERLINE;
	extern const string OVERLINE;

	extern const string REVERSE;
	extern const string DEFAULT_FG;
	extern const string DEFAULT_BG;

	extern const string NOT_INTENSITY;
	extern const string NOT_ITALIC;
	extern const string NOT_UNDERLINE;
	extern const string NOT_REVERSE;
	extern const string NOT_STRIKE;
	extern const string NOT_OVERLINE;

	namespace Color {
		enum class Target : unsigned short {
			FOREGROUND = 38, FG = FOREGROUND,
			BACKGROUND = 48, BG = BACKGROUND
		};
		/**
		* Gets an 8-bit. 8-bit colors are a pre-defined set of 256 colors:
		*   0-  7: standard colors (already predefined constants)
		*   8- 15: high intensity colors (same as above but brighter)
		*  16-231: 6 × 6 × 6 cube (216 colors): 16 + 36 × r + 6 × g + b (0 ≤ r, g, b ≤ 5)
		* 232-255: grayscale from black to white in 24 steps
		*
		* @param n - the value of the 8-bit color (0-255)
		*/
		const string color8bit(unsigned short, Target = Target::FOREGROUND);
		
		/**
		* Gets an 24-bit color (RGB)
		*
		* @param r - red component (0-255)
		* @param g - green component (0-255)
		* @param b - blue component (0-255)
		*/
		const string rgb(unsigned short, unsigned short, unsigned short, Target = Target::FOREGROUND);

		extern const string BLACK;
		extern const string RED;
		extern const string GREEN;
		extern const string YELLOW;
		extern const string BLUE;
		extern const string MAGENTA;
		extern const string CYAN;
		extern const string WHITE;

		extern const string BR_BLACK;
		extern const string BR_RED;
		extern const string BR_GREEN;
		extern const string BR_YELLOW;
		extern const string BR_BLUE;
		extern const string BR_MAGENTA;
		extern const string BR_CYAN;
		extern const string BR_WHITE;

		extern const string BG_BLACK;
		extern const string BG_RED;
		extern const string BG_GREEN;
		extern const string BG_YELLOW;
		extern const string BG_BLUE;
		extern const string BG_MAGENTA;
		extern const string BG_CYAN;
		extern const string BG_WHITE;

		extern const string BG_BR_BLACK;
		extern const string BG_BR_RED;
		extern const string BG_BR_GREEN;
		extern const string BG_BR_YELLOW;
		extern const string BG_BR_BLUE;
		extern const string BG_BR_MAGENTA;
		extern const string BG_BR_CYAN;
		extern const string BG_BR_WHITE;
	}
}

#endif
