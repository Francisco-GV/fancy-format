#include "fancyformat.h"
#include <stdexcept>
#include <string>


#define ESC "\033[" /* I usually avoid macros like this, but in this particular situation
					   I need it to be a char * literal to concatenate with other literals.*/

namespace FancyFormat {
	using std::string;

	namespace {
		string(&itos)(int) { std::to_string }; // Alias to std::to_string(int) function

		void checkRGB(string argName, unsigned x)
		{
			if (x < 0 || x > 255)
			{
				throw std::invalid_argument(argName + " value (" + itos(x) + ") out of range (0 - 255)");
			}
		}
	}

	inline const string RESET			{ ESC"0m" };

	inline const string BOLD			{ ESC"1m" };
	inline const string FAINT			{ ESC"2m" };
	inline const string ITALIC			{ ESC"3m" };
	inline const string UNDERLINE		{ ESC"4m" };
	inline const string STRIKE			{ ESC"9m" };
	inline const string DOUBLE_UNDERLINE{ ESC"21m" };
	inline const string OVERLINE		{ ESC"53m" };
	
	inline const string REVERSE			{ ESC"7m" };
	inline const string DEFAULT_FG		{ ESC"39m" };
	inline const string DEFAULT_BG		{ ESC"49m" };

	inline const string NOT_INTENSITY	{ ESC"22m" };
	inline const string NOT_ITALIC		{ ESC"23m" };
	inline const string NOT_UNDERLINE	{ ESC"24m" };
	inline const string NOT_REVERSE		{ ESC"27m" };
	inline const string NOT_STRIKE		{ ESC"29m" };
	inline const string NOT_OVERLINE	{ ESC"55m" };

	namespace Color {
		const string color8bit(unsigned short n, Target target)
		{
			checkRGB("n", n);

			string s(ESC + itos(static_cast<unsigned short>(target)) + ";5;");
			s += itos(n) + "m";

			return s;
		}

		const string rgb(unsigned short r, unsigned short g, unsigned short b, Target target)
		{
			checkRGB("r", r); checkRGB("g", g); checkRGB("b", b);

			string s(ESC + itos(static_cast<unsigned short>(target)) + ";2;");
			s += itos(r) + ";" + itos(g) + ";" + itos(b) + "m";

			return s;
		}

		inline const string BLACK		{ ESC"30m" };
		inline const string RED			{ ESC"31m" };
		inline const string GREEN		{ ESC"32m" };
		inline const string YELLOW		{ ESC"33m" };
		inline const string BLUE		{ ESC"34m" };
		inline const string MAGENTA		{ ESC"35m" };
		inline const string CYAN		{ ESC"36m" };
		inline const string WHITE		{ ESC"37m" };

		inline const string BR_BLACK	{ ESC"90m" };
		inline const string BR_RED		{ ESC"91m" };
		inline const string BR_GREEN	{ ESC"92m" };
		inline const string BR_YELLOW	{ ESC"93m" };
		inline const string BR_BLUE		{ ESC"94m" };
		inline const string BR_MAGENTA	{ ESC"95m" };
		inline const string BR_CYAN		{ ESC"96m" };
		inline const string BR_WHITE	{ ESC"97m" };

		inline const string BG_BLACK	{ ESC"40m" };
		inline const string BG_RED		{ ESC"41m" };
		inline const string BG_GREEN	{ ESC"42m" };
		inline const string BG_YELLOW	{ ESC"43m" };
		inline const string BG_BLUE		{ ESC"44m" };
		inline const string BG_MAGENTA	{ ESC"45m" };
		inline const string BG_CYAN		{ ESC"46m" };
		inline const string BG_WHITE	{ ESC"47m" };

		inline const string BG_BR_BLACK		{ ESC"100m" };
		inline const string BG_BR_RED		{ ESC"101m" };
		inline const string BG_BR_GREEN		{ ESC"102m" };
		inline const string BG_BR_YELLOW	{ ESC"103m" };
		inline const string BG_BR_BLUE		{ ESC"104m" };
		inline const string BG_BR_MAGENTA	{ ESC"105m" };
		inline const string BG_BR_CYAN		{ ESC"106m" };
		inline const string BG_BR_WHITE		{ ESC"107m" };

		//inline const string CC_GREEN{ "\033[38;2;176;255;194m" };
		//inline const string CC_YELLOW{ "\033[38;2;255;255;194m" };
		//inline const string CC_BLUE{ "\033[38;2;146;164;255m" };
		//inline const string CC_MAGENTA{ "\033[38;2;255;176;255m" };

		inline const string CC_GREEN	{ rgb(176, 255, 194) };
		inline const string CC_YELLOW	{ rgb(255, 255, 194) };
		inline const string CC_BLUE		{ rgb(146,164,255) };
		inline const string CC_MAGENTA	{ rgb(255,176,255) };
	}
}