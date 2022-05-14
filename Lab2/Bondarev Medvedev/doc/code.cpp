#include <iostream>
using namespace std;

enum class Event
{
	PUSH_ON,
	PUSH_OFF,
	GETTINGCOORDINATES,
	Move,
	Turn_Right,
	Turn_Left,
	Paint_Wall,
	Paint_Floor,
	Return_Place

};

enum class States
{
	ON,
	OFF,
	GETTINGCOORDINATED,
	MoveForward,
	TurnRight,
	TurnLeft,
	PaintWall,
	PaintFloor,
	ReturnPlace

};

class Robot 
{
	States state;
public:
	void pevent(const Event& e)
	{
		switch (e)
		{
		case Event::Move:
			move();
			state = States::MoveForward;
			break;

		case Event::Turn_Left:
			turnLeft();
			state = States::TurnLeft;
			break;
		case Event::Turn_Right:
			turnRight();
			state = States::TurnRight;
			break;
		case Event::Paint_Floor:
			paint_floor();
			state = States::PaintFloor;
			break;
		case Event::Paint_Wall:
			paint_wall();
			state = States::PaintWall;
			break;
		case Event::GETTINGCOORDINATES:
			getting_coordinated();
			state = States::GETTINGCOORDINATED;
			break; 
		case Event::PUSH_OFF:
			off();
			state = States::OFF;
			break;
		case Event::PUSH_ON:
			on();
			state = States::ON;
			break;
		case Event::Return_Place:
			return_on_his_place();
			state = States::ReturnPlace;
			break;
		}
	}

	void on() 
	{
		state = States::ON;
	}

	void off() 
	{
		state = States::OFF;
	}

	void getting_coordinated() 
	{
		state = States::GETTINGCOORDINATED;
	}

	void move() 
	{
		state = States::MoveForward;
	}


	{
		state = States::TurnLeft;
	}

	void turnRight() 
	{
		state = States::TurnRight;
	}

	void paint_wall() 
	{
		state = States::PaintWall;

	}

	void paint_floor() 
	{
		state = States::PaintFloor;

	}

	void return_on_his_place() 
	{
		state = States::ReturnPlace;

	}

};

class CameraSystem
{
	States state;
public:
	void detected_graffiti() 
	{
		state = States::GETTINGCOORDINATED;
	}

	void call_user() 
	{
		state = States::GETTINGCOORDINATED;
	}

	void call_robot_coordinates() 
	{
		state = States::GETTINGCOORDINATED;
	}
}
;
class StrategyCommand
{
public:
	virtual Event getEvent() = 0;
};

class InternetCommand : public StrategyCommand
{
public:
	Event getEvent()
	{
		return Event::PUSH_OFF;
	}
};

class ConsoleCommand : public StrategyCommand
{
public:
	Event getEvent()
	{
		char c;
        while (true)
        {
	        cin >> c;
	        switch (c)
	        {
	        case 'm':
		        return Event::Move;

	        case 'l':
		        return Event::Turn_Left;

	        case 'r':
		        return Event::Turn_Right;

	        case 'f':
		       return Event::Paint_Floor;

	        case 'w':
		        return Event::Paint_Wall;

	        case 'g':
		        return Event::GETTINGCOORDINATES;

	        case '0':
		        return Event::PUSH_OFF;

	        case '1':
		        return Event::PUSH_ON;

	        case 't':
		        return Event::Return_Place;
	        default:
		        cout << "incorrect";
	        }
        } 
     }
};


int main() 
{

	Robot r;
	StrategyCommand* cmd;
	cmd = new ConsoleCommand();

	while (true)
	{
		Event e = cmd->getEvent();
		r.pevent(e);
	}
}
	