
#include "Chess.hpp"

void	Chess::show_figures(std::map <string, char> figures)
{
	map<string, char>::iterator it;

	it = figures.begin();
	while (it != figures.end())
	{
		std::cout << "key:["<< it->first << "] val:[" << it->second << "] \n";
		it++;
	}
}

void	Chess::updateFigureSpot(std::map <string, char> &figures)
{
	char		tempFigure;
	string		exSpot;
	string		newSpot;
	string		color = "color";

	exSpot = currPos;
	newSpot = destPos;
	tempFigure = figures[exSpot];
	figures.erase(exSpot);
	figures[newSpot] = tempFigure;
	if (figures[color] == black)
		figsWhite.erase(destPos);
	else
		figsBlack.erase(destPos);
}

bool	Chess::putFigureOnBoard(char figure, std::map <string, char> &figures)
{
	board[moveFrom[Y]][moveFrom[X]] = '\0';
	board[moveTo[Y]][moveTo[X]] = figure;
	if (bot.isBotActive())
		bot.saveMove((const char *)currPos, (const char *)destPos);
	boardPrint();
	updateFigureSpot(figures);
	if (checkToBlack)
		std::cout << BLUE << "  ** Check to black! **" << RESET << '\n';
	else if (checkToWhite)
		std::cout << BLUE << "  ** Check to white! **" << RESET <<'\n';
	return (true);
}
