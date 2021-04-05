#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<forward_list>
#include<iterator>


using namespace std;
struct point
{
	int x, y;
};
class Title
{
protected:
	forward_list<point>T{ {1,1}, {1,0}, {0,1}, {2,1} }; //kszta�t T
	forward_list<point>J{ {0,1}, {1,1}, {2,1}, {2,0} }; //kszta�t J
	forward_list<point>L{ {0,0}, {0,1}, {1,1}, {2,1} }; //kszta�t L 
	forward_list<point>Z{ {0,0}, {1,0}, {1,1}, {2,1} }; //kszta�t Z 
	forward_list<point>S{ {0,1}, {1,1}, {1,0}, {2,0} }; //kszta�t S
	forward_list<point>O{ {0,0}, {0,1}, {1,0}, {1,1} }; //kszta�t kwadrat
	forward_list<point>I{ {0,1}, {1,1}, {2,1}, {3,1} }; // kszta�t I
	forward_list<point> axis[7] = { T,J,L, Z, S,O,I };
	forward_list<point>::iterator iter;
	
public:
	Title();
	Title(Title&&) = default;
	forward_list<point>rotation(int figure, forward_list<point> axis, vector<vector<int>>map);
	forward_list<point> get_list(int x, forward_list<point>b);
};
