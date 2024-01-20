#include "libft.h"

void	ft_ungetchar(char ch)
{
	struct termios	oldt;
	struct termios	newt;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ioctl(STDIN_FILENO, TIOCSTI, &ch);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
