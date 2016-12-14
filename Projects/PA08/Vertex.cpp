#ifndef VERTEXHEADER
#define VERTEXHEADER

#include <iosteam>

template <class itemType>
class Vertex
{
	public:
		Vertex ();
		Vertex (itemType sentValue);
		~Vertex ();

		void SetValue (itemType value);

		itemType GetValue ();

	private:
		itemType value;

};

#endif