#include <assert.h>

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

#include "Game.h"

//using namespace std;

/*****************************
// make
// ./main
// ./main 2>errors/error.log
*****************************/

#include <memory>
#include <algorithm>
#include <utility>
#include <functional>
#include <initializer_list>
#include <type_traits>

/*
class Bands
{
public:
	Bands();
	Bands(std::initializer_list<std::string> initl) {this->_bands = initl;}
	void printList() {for(auto &x : this->_bands) {std::cout << x << endl;}}
	std::initializer_list<std::string> _bands;
private:
};
*/

/* ------------------------- main ---------------------------- */
int main()
{
	/*****************************/
		// testovaci itemy

		//return 0;
	/*****************************/
	/*
	Bands b {"Slayer", "Metallica", "Kreator", "Cannibal corpse"};
	b.printList();

	if( std::any_of(b._bands.begin(), b._bands.end(), [](std::string s){return s.length() > 6;}) )
		std::cout << "ok" << std::endl;

	int length = 0;
	std::for_each(b._bands.begin(), b._bands.end(), [](std::string s){std::cout << s << endl;});
	std::cout << length << std::endl;

	std::vector<std::string> vect(std::make_move_iterator(begin(b._bands)),
						std::make_move_iterator(end(b._bands)) );

	std::cout << std::endl;
	for(auto &x: vect) std::cout << x << std::endl;

	int a(10);
	std::cout << a << std::endl;

	std::function<bool(std::string)> e1 = &std::string::empty;
	std::cout << e1(vect[1]) << std::endl;

	std::function<int(std::string)> test = [](std::string s)->int {return s.length();};
	auto 					 test2 = [](std::string s)->int {return s.length();};
	std::cout << test("makefile") << std::endl;
	std::cout << test2("makefile") << std::endl;
	*/


	Game game;
	game.createPlayer("Valgrut");
	game._player->drawPlayer(game);
	game.render();

	bool isStair = false;
	bool isItem  = false;

	/* gameloop */

	char c = '0';
	while(1)
	{
	     system("/bin/stty raw");
          c = getchar();
          system("/bin/stty cooked");

		// konec
		if(game.state() == "Start")
		{
			if(c == '9') return 0;
		}

		// handle input depending on current state
		game._stateMachine->current()->handleInput(c);

		// vykreslime mapu
		game.render();
	}
	

	return 0;
}
