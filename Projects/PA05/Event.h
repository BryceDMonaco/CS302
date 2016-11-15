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