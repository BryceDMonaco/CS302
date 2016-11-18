/**
*	@file Event.h
*
*	@brief This is the header of the Event class
*
*	@author Bryce Monaco
*
*	@details This file contains the header of the Event class
*
*	@version 1.0
*
*	@note This header does not have an implementation file.
*/

class Event
{
	public:
		Event ();
		Event (bool type, int time);
		~Event ();

		int GetTime ();
		bool IsArrival ();

	private:
		bool isArrival;

		int eventTime;
		int eventLength;

};